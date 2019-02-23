#ifndef _ARRAY_H
#define _ARRAY_H

typedef struct {
	int capacity;
	int count;
	void **items;
} array_t;


array_t *arrayCreate(void);
void arrayInit(array_t * s);
void arrayClean(array_t * s);
void arrayDestroy(array_t * s);
void arrayAppend(array_t * s, void *obj);
void arrayInsert(array_t * s, void *obj, int position);
void arrayPreAppend(array_t * s, int app_count);
void arrayShrink(array_t *a, int new_count);

#endif


