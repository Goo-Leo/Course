//
// Created by 10633 on 2022/7/12.
//

#ifndef INDIGOS_RINGBUFFER_H
#define INDIGOS_RINGBUFFER_H

typedef struct ringbuffer {
    char buffer[5];
    /* data */
    char *wrptr;
    char *rdptr;
    /* pointer */
} ringbuffer;


//由规则2，容易推断出判空的原则：读写指针相等
int lsempty(ringbuffer *rb) {
    if (rb->rdptr == rb->wrptr)
        return 1;
    return 0;
}

int lsfull(ringbuffer *rb) {
    if (((rb->rdptr - rb->wrptr) == 1) || ((rb->wrptr - rb->rdptr) == (sizeof(rb->buffer))))
        return 1;
    return 0;
}

void rstbuffer(ringbuffer *rb) {
    rb->wrptr = rb->rdptr = rb->buffer;
}

//由规则1知道写入函数的逻辑
void writebuffer(ringbuffer *rb, char ch) {
    while (!lsfull(rb)) {
        if ((rb->wrptr) == (rb->buffer) + sizeof(rb->buffer) + 1) {
            rb->wrptr = rb->buffer;
            continue;
        }
        *(rb->wrptr) = ch;
        (rb->wrptr)++;
        break;
    }
}

//读取：从读取指针的当前位置开始，直到写指针为止，若写指针前于读指针，则到尾再从存储块的头开始
void readbuffer(ringbuffer *rb) {
    while (!lsempty(rb)) {
        if ((rb->rdptr) == (rb->buffer) + sizeof(rb->buffer) + 1) {
            rb->rdptr = rb->buffer;
            continue;
        }
        putchar(*(rb->rdptr));
        rb->rdptr++;
    }
}

#endif //INDIGOS_RINGBUFFER_H
