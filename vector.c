#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "vector.h"


Vector* vector_create(int initialLength, int sizeOfElement)
{
	Vector* vector = (Vector*)malloc(sizeof(Vector));
	
	if(vector == NULL)
		return NULL;
	
	vector->length = initialLength;
	vector->nrOfElements = 0;
	vector->sizeOfElement = sizeOfElement;
	
	vector->arr = malloc(initialLength * sizeOfElement);
	
	if(vector->arr == NULL)
	{
		free(vector);
		return NULL;
	}
	
	
	return vector;
}

void vector_destroy(Vector* v)
{
	free(v->arr);
	free(v);
	
	/*
	void* aux = v->arr;
	
	free(v);
	free(aux);
	*/
}

//
//	Doubles vector capacity
//
static bool vector_increase(Vector* v)
{
	int nextLength = v->length * 2;
	
	void * newAllocation = realloc(v->arr, nextLength * v->sizeOfElement);
	
	if(newAllocation == NULL)
		return false;
	
	v->length*=2;
	v->arr = newAllocation;
	
	return true;
}

int vector_add(Vector* v, void* data)
{
	if(v->length <= v->nrOfElements)
	{
		//
		//	Vector is full
		//
		if(vector_increase(v) == false)
		{
			return -1;
		}		
	}
	
	// Vector has space
	int currIdx = v->nrOfElements;
	
	void* currIdxPtr = v->arr + currIdx * v->sizeOfElement;
	
	/*	memcpy
	char* dst = (char*)currIdxPtr;
	char* src = (char*) data;
	for(int i = 0; i < v->sizeOfElement; ++i)
		dst[i] = src[i];
	*/
	memcpy(currIdxPtr, data, v->sizeOfElement);
	
	return v->nrOfElements++;
}

void vector_print(Vector* v, void (*print)(void*))
{
	void* base = v->arr;
	for(int i = 0; i < v->nrOfElements; ++i)
	{
		printf("[%d] = ", i);
		print(base);
		base += v->sizeOfElement;
		printf("\n");
	}
}

void* vector_get(Vector* v, int idx)
{
	if(idx >= v->nrOfElements)
		return NULL;
		
	
	return v->arr + idx * v->sizeOfElement;
}

void* vector_find(Vector* v, void* key, int (*comparator)(void*,void*))
{
	for(int i = 0; i < v->nrOfElements; ++i)
	{
		void * currElem = vector_get(v,i);
		if(comparator(key,currElem)  == 0) 
			return currElem;
	}
	
	return NULL;
}

int vector_get_element_index(Vector* v, void* key, int (*comparator)(void*,void*))
{
	void* elem = vector_find(v, key, comparator);
	
	if(elem == NULL)
		return -1;
		
	return (elem - v->arr) / v->sizeOfElement;
}

void vector_sort(Vector* v, int (*comparator)(void*,void*))
{
	qsort(v->arr, v->nrOfElements,v->sizeOfElement,(int (*)(const void*, const void*))comparator);
}

int vector_getNrOfElements(Vector* v)
{
	return v->nrOfElements;
}
