#ifndef _STACK_H
#define _STACK_H

#include "array.h"

typedef array_t http_stack_t;

#define stackCreate arrayCreate
#define stackInit arrayInit
#define stackClean arrayClean
#define stackDestroy arrayDestroy
#define stackPush arrayAppend
#define stackPrePush arrayPreAppend
void *stackTop(http_stack_t * s);
void *stackPop(http_stack_t * s);



#endif
