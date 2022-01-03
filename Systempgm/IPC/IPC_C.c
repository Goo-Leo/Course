#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/msg.h>
#include <sys/ipc.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define FIFO 	0
#define MSG	0
#define Socket 	1

int main(int argc, char *argv[]){

	char readbuffer[1024] = {};
	char sendbuffer[1024] = {};
	int fd1,fd2;


#if	FIFO
	pid_t mypid;
	pid_t other;
	ssize_t wr,rd;
	if(mkfifo("./myfifo",0666)){ 
		exit(1);
		perror(" make fifo failed !")
	}

	if((fd1 = open("./myfifo" , O_WRONLY| O_APPEND ｜O_NOBLOCK , 0666) == -1)){
		perror("/***** fifo error in opening *****/\r\n");
		exit(1);
	}
	sprintf(sendbuffer ,"%d: ", getpid());
	if((pid = fork()) == -1 ){
		perror ("/***** fork error *****/\r\n");
		exit(1);}
	for(;;){
		scanf("%s",sendbuffer + 7);
		if((wr = write(fd , sendbuffer , sizeof(sendbuffer))) == -1) {
			perror("send failed!\r\n");
			exit(1);
		}
		rd = read (fd , readbuffer , sizeof(readbuffer));
	}
#endif

#if	MSG
	key_t key;
	if(msgget(key,0666)){
		exit(1);
		perror(" make massage quene failed !")
	}
#endif

#if	Socket

	int is = socket(AF_INET , SOCK_STREAM , 0);				//creat socket
	
	struct sockaddr_in addr;						//IPv4 socket address 	
	memset(&addr,0,sizeof(struct sockaddr_in));
	addr.sin_family = AF_INET;
	addr.sin_addr.s_addr = inet_addr(argv[1]);
	addr.sin_port = htons(2222);
	
	if(!(bind(is,(struct sockaddr *)&addr, sizeof(struct sockaddr_in))))
		perror("This port might been occupyed");	//failure might be caused by a occupyed port number
	connect(is,(struct sockaddr *)&addr,sizeof(struct sockaddr_in));
	printf("connectted with %s \r\n",argv[1]);

	for(;;){
		scanf("%s",sendbuffer);
		send(is,sendbuffer,sizeof(sendbuffer),O_RDWR);
		recv(is,readbuffer,sizeof(readbuffer),O_RDWR | MSG_DONTWAIT);
		puts(readbuffer);
	}

#endif

	return 0;
}
