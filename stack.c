#include <assert.h>
#include <string.h>
#include "util.h"
#include "stack.h"


void *
stackPop(http_stack_t * s)
{
    assert(s != NULL);
    return s->count ? s->items[--s->count] : NULL;
}

void *
stackTop(http_stack_t * s)
{
    assert(s != NULL);
    return s->count ? s->items[s->count - 1] : NULL;
}

