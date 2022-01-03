#include "unistd.h"			//unix standard lib
#include "sys/types.h"			
#include "sys/stat.h"
#include "fcntl.h"			//file contorl
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
int main (int argc , char* argv[]) {

	if(argc < 2){
		printf("need argument: A content");
		exit(1);
	}

	int fd;				//Return value of syscall func, as the discriptor of a file
	ssize_t wr;
	ssize_t rd;

	char* readbuffer = (char*)malloc(1024*sizeof(char));   	//apply a heap space for read func··
	
	if (readbuffer == NULL)	exit(1);

	if((fd = open("test.md" , O_CREAT | O_RDWR , 0777)) < 0){
		perror("/*** open exited ***/\r\n");
		exit(1);
	}

	lseek(fd, 0, SEEK_END);		
	if((wr = write(fd, argv[1], strlen(argv[1]))) < 0){
		perror("/*** write failed ***/");
		exit(1);
	}

	printf("%d bytes had been writen\r\n/*** reading ***/\r\n",strlen(argv[1]));

	lseek(fd , 0 , SEEK_SET);
	if ((rd = read(fd , readbuffer , 1024)) < 0){
		perror("/*** read failed ***/\r\n");
		exit(1);
	}
	printf("/*** Read OK ***/\r\n:");
	puts(readbuffer);
	
	close(fd);
	free(readbuffer);

	return 0;
}
