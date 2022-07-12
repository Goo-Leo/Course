#include "stdio.h"
#include "inc/ringbuffer.h"

int main(void) {
    ringbuffer A;
    rstbuffer(&A);
    for (int i = 0; i < 5; ++i) {
        writebuffer(&A, 'y');
        writebuffer(&A, 'e');
        writebuffer(&A, 's');
        writebuffer(&A, 's');
        writebuffer(&A, 'i');
        readbuffer(&A);
        printf("\r\n");
        writebuffer(&A, 'r');
        readbuffer(&A);
        printf("\r\n");
    }
    return 0;
}

