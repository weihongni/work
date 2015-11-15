#ifndef __QQ_NET_H__
#define __QQ_NET_H__

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>

#include <sys/types.h>
#include <sys/socket.h>

#include <net/if.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#include "list.h"

#define QUIT_STR "quit"
#define SERV_IP  "192.168.7.4"
#define SERV_PORT 5002
#define BACKLOG 5



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

#endif
