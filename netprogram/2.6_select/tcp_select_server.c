
/*select 服务器的的演示程序 */
#include <assert.h>

#include "list.h"
#include "debug.h"
#include "net.h"
void cli_data_handler (struct cli_info *pinfo, struct cli_info *head);

int main (void)
{

	int fd = -1;

	/* 定义一个内核链表 */
	struct cli_info mylist;
	struct sockaddr_in sin;

	/*1. 建立套接字 */
	if ((fd = socket (AF_INET, SOCK_STREAM, 0)) < 0)	//ipV4的TCP编程
	{
		perror ("socket");
		exit (1);
	}
	/* 允许地址快速重用 * */
	int b_reuse = 1;
	setsockopt (fd, SOL_SOCKET, SO_REUSEADDR, &b_reuse, sizeof (int));

	/*2.绑定本机IP和端口号 */

	/* 2.1 填充sockaddr_In结构体 */
	bzero (&sin, sizeof (sin));
	sin.sin_family = AF_INET;
	sin.sin_port = htons (SERV_PORT);
	sin.sin_addr.s_addr = INADDR_ANY;	/* 绑定在本机的任意IP上 */

	/*2.2 绑定 */
	if (bind (fd, (struct sockaddr *) &sin, sizeof (sin)) < 0) {
		perror ("shyi- bind error");
		exit (1);
	}

	/*3.把套接字变为被动套接字 */
	if (listen (fd, BACKLOG) < 0) {
		perror ("listen");
		exit (1);
	}


	printf ("Server starting....OK!\n");

	// 初始化链表
	INIT_LIST_HEAD (&mylist.list);	/*初始化链表头 */

	int maxfd;					/*所有关系的文件描述符中最大的那个文件描述符 */
	fd_set rset;				/* 读集合 */

	while (1) {

		struct cli_info *tmp = NULL;
		struct list_head *pos, *q;

		FD_ZERO (&rset);		//清空集合

		/* 把fd 加到读集合中 */
		FD_SET (fd, &rset);
		maxfd = fd;

		/*遍历内核链表mylist, 把已经建立好连接的那些文件描述符加到集合中 */
		list_for_each_safe (pos, q, &mylist.list) {
			tmp = list_entry (pos, struct cli_info, list);	//tmp指向遍历到的某一项结构体数据
			FD_SET (tmp->cli_fd, &rset);
			if (maxfd < tmp->cli_fd) {
				maxfd = tmp->cli_fd;
			}
		}


		select (maxfd + 1, &rset, NULL, NULL, NULL);	//阻塞直到所监控的rset中的某一个或几个fd上有数据

		if (FD_ISSET (fd, &rset)) {	/* 被动套接字上有数据： 也就是有新的客户端连接请求 */

			int newfd = -1;
			struct sockaddr_in cin;
			socklen_t cli_len = sizeof (cin);

			newfd = accept (fd, (struct sockaddr *) &cin, &cli_len);
			if (newfd < 0) {
				perror ("accept error");
				continue;
			}
			//分配一项cli_info
			if ((tmp = (struct cli_info *) malloc (sizeof (struct cli_info))) < 0) {
				perror ("malloc error");
				continue;
			}
			tmp->cli_fd = newfd;
			/* 把客户端信息复制到 tmp->cin */
			memcpy (&tmp->cin, &cin, sizeof (cin));

			/*把tmp加入到内核链表中 */
			list_add (&(tmp->list), &(mylist.list));
		}

		/* 遍历内核链表，查看每一项中的cli_fd上是否有数据并处理 */
		list_for_each_safe (pos, q, &mylist.list) {
			tmp = list_entry (pos, struct cli_info, list);	//tmp指向遍历到的某一项结构体数据

			if (FD_ISSET (tmp->cli_fd, &rset)) {	/* 已经建立了连接的客户端上有发送数据过来 */
				cli_data_handler (tmp, &mylist);
			}
		}
	}

	return 0;
}

void cli_data_handler (struct cli_info *pinfo, struct cli_info *head)
{
	int ret, conn_fd = -1;
	struct sockaddr_in cin;
	char buf[BUFSIZ];
	char cli_ip_addr[16];

	if (!pinfo || !head)
		return;


	conn_fd = pinfo->cli_fd;
	memcpy (&cin, &pinfo->cin, sizeof (cin));


	if (inet_ntop (AF_INET, (void *) &cin.sin_addr, cli_ip_addr, sizeof (cin)) == NULL) {
		perror ("inet_ntop() error");
	}

	bzero (buf, BUFSIZ);
	do {
		ret = read (conn_fd, buf, BUFSIZ - 1);
	} while (ret < 0 && EINTR == errno);

	if (ret < 0) {
		perror ("read error");
		//exit (1);                       //FIXME!!!!, there is a bug
	}
	if (ret == 0) {
		pr_debug("Client(ip =%s, port =%d) is exited.",cli_ip_addr, ntohs (cin.sin_port));
	}
	//..根据消息的类型，看是群聊或私聊或其他的
	pr_debug("Received data(ip =%s, port =%d): %s\n", cli_ip_addr, ntohs (cin.sin_port), buf);
	//swith(tpye) {case ....}
	//群聊
	//...遍历内核链表，给每项中的fd发送数据


	if (!strncasecmp (buf, QUIT_STR, strlen (QUIT_STR))) {	/* 用户输入了quit */
	        struct cli_info *tmp = NULL;
                struct list_head *pos, *q;

		//..遍历链表，给每个客户端通知XXX用户要退出了
                list_for_each_safe (pos, q, &head->list) {
                        tmp = list_entry (pos, struct cli_info, list);  //tmp指向遍历到的某一项结构体数据
			if(tmp->cli_fd != conn_fd) {
				 //... 给每个客户端发此客户端退出消息
				 bzero(buf, BUFSIZ);
				 sprintf(buf, "Client(ip=%s,port=%d) is exited!", cli_ip_addr, ntohs(cin.sin_port)); 	
				 if(write(tmp->cli_fd, buf, strlen(buf)) < 0) {
			        	pr_debug("Write quit info to fd=%d is error!\n", tmp->cli_fd); 
				}
			} 	
		}
		//..删除相应用户所占用内核链表项
	        list_for_each_safe (pos, q, &head->list) {
                        tmp = list_entry (pos, struct cli_info, list);  //tmp指向遍历到的某一项结构体数据
			if(tmp->cli_fd == conn_fd) {
				list_del(pos);	
				free(tmp); 
				tmp = NULL;	
				close(conn_fd);
			}
		}			
	}

	return;
}
