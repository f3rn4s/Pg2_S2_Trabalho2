#ifndef M_VECTORINT
#define M_VECTORINT



#include "vector.h"

#define vector_int_create(initalLength) vector_create(initalLength, sizeof(int))
#define vector_int_destroy(v) vector_destroy(v)
int vector_int_add(Vector* v, int data);
void vector_int_print(Vector* v);
#define vector_int_get(v, idx) ((int*)vector_get(v,idx))
int* vector_int_find(Vector* v, int key);
int vector_int_get_element_index(Vector* v, int key);
#define vector_int_getNrOfElements(v) vector_getNrOfElements(v)
#define vector_int_sort(v, comparator) vector_sort(v,comparator)


#endif
