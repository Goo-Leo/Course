#include <stdio.h>
#include "co.h"

//define a structure as abstract coroutine
typedef struct co{
        int co_id;

}co;

struct co * co_start(const char *name ,void(*fuc(void *)), void *arg){
	
};

void co_field(){
	
};

void co_wait(struct co *co){
	
};

