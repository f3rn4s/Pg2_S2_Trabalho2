#include <stdio.h>
#include "vectorint.h"


static void int_print(void* p)
{
	int* i = (int*)p;
	printf("%d",*i);
}

static int int_comparer(void* pa, void* pb)
{
	int* a = (int*) pa;
	int* b = (int*) pb;
	
	return *a - *b;
}

int vector_int_add(Vector* v, int data)
{
	return vector_add(v, &data);
}
void vector_int_print(Vector* v)
{
	vector_print(v, int_print);
}
int* vector_int_find(Vector* v, int key)
{
	return vector_find(v, &key, int_comparer);
}
int vector_int_get_element_index(Vector* v, int key)
{
	return vector_get_element_index(v, &key, int_comparer);
}
