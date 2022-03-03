#include <stdio.h>
#include "thread.h"

int *globalptr;

void thread1(void){
	int num = 3000;
	globalptr = &num;
}
   
void thread2(void){
	printf("thread1's number is %d\r\n",*globalptr);
}

int main(void){
	create(thread1);
	create(thread2);
	return 0;
}
