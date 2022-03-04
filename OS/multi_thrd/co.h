#include <stdio.h>

//start a coroutine
struct co *co_start(const char *name ,void(*fuc(void *)), void *arg);

//switch coroutines
void co_field();

//wait for coroutine's return
void co_wait(struct co *co);

