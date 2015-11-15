#include<stdio.h>

int main(void)
{
	char buf[BUFSIZ];
	int bu[100];
	int ret = -1;
	pit_t pid = -1;
	int fd[2]

		if(pipe(fd)<0){
			perror("pipe");
			exit(EXIT_FAILURE);
		}
	if((pid=fork())<0){
		perror("fork");
		exit("EXIT_FAILURE");
	}

	switch(pid){
		case 0:
			{
				close(fd[1]);	
				while(1){
					bzero(buf,BUFSIZ);
					printf("%d + %d",a+b);	
					do {
						ret = read (fd[0], buf, BUFSIZ - 1);
					} while (ret < 0 && EINTR == errno);
					if (ret < 0) {
						perror ("read");
						continue;
					}
					if (!ret) {
						printf ("pipe is closed.\n");
						break;
					}

					printf ("Parent: read %s\n", buf);
					if (!strncasecmp (buf, QUIT_STR, strlen (QUIT_STR))) {	//用户输入了quit
						break;
					}
					close(fd[0]);
				}
			}
		default:
			{
				close(fd[0]);
				while(1){
					fprintf(stderr,"Please input two integers!\n");
					bzero (buf, BUFSIZ);
					if(fgets (buf, BUFSIZ - 1, stdin) == NULL) {	//从标准键盘上获取数据    
						continue;
					}
					//buf[BUFSIZ-1] = '\0';
					do {
						ret = write (fd[1], buf, strlen (buf));
					} while (ret < 0 && EINTR == errno);

					if (!strncasecmp (buf, QUIT_STR, strlen (QUIT_STR))) {	//用户输入了quit
						close (fd[1]);
						break;
					}


				}
			}
	}

	return 0;
}
