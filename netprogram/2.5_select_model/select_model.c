
/* 服务器的select()用法的原型 */

struct cli_info
{
	struct list_head list;		/* 内核链表 */
	/* 数据 */
	int cli_fd;
	struct sockaddr_in cin;
	//....
	//...QQ号
	//...name[], age, sex       
};

int main (void)
{

	int listen_fd = -1;

	/* 定义一个内核链表 */
	struct cli_info mylist;


	listen_fd = socket ( ...);

	/* 填充被绑定的服务器的IP地址和端口号 */
	//...

	/*绑定 */
	bind (listen_fd, ....);

	/*把套接字变成被动套接字 */
	listen (listen_fd, ...);

	// 初始化链表
	INIT_LIST_HEAD (&mylist.list);	/*初始化链表头 */

	int maxfd;					/*所有关系的文件描述符中最大的那个文件描述符 */
	fd_set rset;				/* 读集合 */

	while (1) {
		FD_ZERO (&rset);		//清空集合

		/* 把listen_fd 加到读集合中 */
		FD_SET (listen_fd, &rset);
		/*遍历内核链表mylist, 把已经建立好连接的那些文件描述符加到集合中 */
		//....

		maxfd = n;				//...listen_fd和已经建立连接的那些fd中的最大的那个
		
		select (maxfd + 1, &rset, NULL, NULL, NULL);	//阻塞直到所监控的rset中的某一个或几个fd上有数据

		if (FD_ISSET (listen_fd, &rset)) {	/* 被动套接字上有数据： 也就是有新的客户端连接请求 */
			struct cli_info *tmp = NULL;

			newfd = accept (listen_fd, ...);	//accept()它这时候就不会阻塞   
			//分配一项cli_info
			if ((tmp = (struct cli_info *) malloc (sizeof (struct cli_info))) < 0) {
				//...
			}
			tmp->cli_fd = newfd;
			/* 把客户端信息复制到 tmp->cin */
			//...   
			/*把tmp加入到内核链表中 */
			list_add (&(tmp->list), &(mylist.list));
		}

		/* 遍历内核链表，查看每一项中的cli_fd上是否有数据并处理 */
		//....

	}

	return 0;
}
