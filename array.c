#include "array.h"
#include <assert.h>
#include <string.h>
#include "util.h"
#include "mem.h"

static void arrayGrow(array_t * a, int min_capacity);

array_t * arrayCreate(void)
{
	array_t *a = mem_alloc("array", sizeof(array_t));
	arrayInit(a);
	return a;
}

void arrayInit(array_t * a)
{
	assert(a != NULL);
	memset(a, 0, sizeof(array_t));
}

void arrayClean(array_t * a)
{
	assert(a != NULL);
	/* could also warn if some objects are left */
	if(a->items)
		mem_free(a->items);
	a->items = NULL;
}

void arrayDestroy(array_t * a)
{
	assert(a != NULL);
	arrayClean(a);
	mem_free(a);
}

void arrayAppend(array_t * a, void *obj)
{
	assert(a != NULL);
	if (a->count >= a->capacity)
		arrayGrow(a, a->count + 1);
	a->items[a->count++] = obj;
}

void arrayInsert(array_t *a, void *obj, int position)
{
	assert(a != NULL);
	if (a->count >= a->capacity)
		arrayGrow(a, a->count + 1);
	if (position > a->count)
		position = a->count;
	if (position < a->count)
		memmove(&a->items[position + 1], &a->items[position], (a->count - position) * sizeof(void *));
	a->items[position] = obj;
	a->count++;
}

/* if you are going to append a known and large number of items, call this first */
void arrayPreAppend(array_t * a, int app_count)
{
	assert(a != NULL);
	if (a->count + app_count > a->capacity)
		arrayGrow(a, a->count + app_count);
}

/* grows internal buffer to satisfy required minimal capacity */
static void arrayGrow(array_t * a, int min_capacity)
{
	const int min_delta = 16;
	int delta;
	assert(a->capacity < min_capacity);
	delta = min_capacity;
	/* make delta a multiple of min_delta */
	delta += min_delta - 1;
	delta /= min_delta;
	delta *= min_delta;
	/* actual grow */
	assert(delta > 0);
	a->capacity += delta;
	if(a->items){
		void *tmp = mem_alloc("array_item", a->capacity*sizeof(void *));
		memcpy(tmp, a->items, a->count*sizeof(void *));
		mem_free(a->items);
		a->items = tmp;
	}
	else{
		a->items = mem_alloc("array_item", a->capacity*sizeof(void *));
	}
	memset(a->items + a->count, 0, (a->capacity - a->count) * sizeof(void *));
}

void arrayShrink(array_t *a, int new_count)
{
	assert(new_count <= a->capacity);
	assert(new_count >= 0);
	a->count = new_count;
}


