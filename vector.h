#ifndef PG2_M_VECTOR
#define PG2_M_VECTOR

typedef struct m_vector
{
	void* arr;
	int length;
	int nrOfElements;
	int sizeOfElement;
}Vector;


Vector* vector_create(int initialLength, int sizeOfElement);
void vector_destroy(Vector* v);
int vector_add(Vector* v, void* data);
void vector_print(Vector* v, void (*print)(void*));
void* vector_get(Vector* v, int idx);
void* vector_find(Vector* v, void* key, int (*comparator)(void*,void*));
int vector_get_element_index(Vector* v, void* key, int (*comparator)(void*,void*));
int vector_getNrOfElements(Vector* v);
void vector_sort(Vector* v, int (*comparator)(void*,void*));

#endif
