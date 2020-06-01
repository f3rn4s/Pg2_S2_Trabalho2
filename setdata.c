#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "setdata.h"

#define TAGSET_INIT_SIZE (1)
#define MP3TAG_LIST_SIZE (10)
#define MP3TAG_INIT_SIZE (10)

TagSet_t* setCreate(){

	TagSet_t* set = (TagSet_t*)calloc(TAGSET_INIT_SIZE,sizeof(TagSet_t));
	
	if(set == NULL)
		return NULL;
	
	set->size = MP3TAG_LIST_SIZE;
	set->count = 0;
	
	set->data = (MP3Tag_t**)calloc(MP3TAG_INIT_SIZE,sizeof(MP3Tag_t));

	if(!set->data){
		free(set);
		return NULL;
	}

	set->aux = (MP3Tag_t**)calloc(MP3TAG_INIT_SIZE,sizeof(MP3Tag_t));

	if(!set->aux){
		free(set->data);
		free(set);
	return NULL;
	}

	/*MP3Tag_t* arr_data = (MP3Tag_t*)calloc(MP3TAG_INIT_SIZE,sizeof(MP3Tag_t));

	if(!arr_data){
		free(set);
		return NULL;
	}

	set->data = &arr_data;

	MP3Tag_t* arr_aux = (MP3Tag_t*)calloc(MP3TAG_INIT_SIZE,sizeof(MP3Tag_t));

	if(!arr_aux){
		free(*set->data);
		free(set);
		return NULL;
	}

	set->aux = &arr_aux;*/

	//******************** 2 *********************
	/*set->data = (MP3Tag_t**)calloc(MP3TAG_LIST_SIZE,sizeof(MP3Tag_t*));

	if(!set->data){
		free(set);
		return NULL;
	}

	*set->data= (MP3Tag_t*)calloc(MP3TAG_INIT_SIZE,sizeof(MP3Tag_t));

	if(!set->data){
		free(set->data);
		free(set);
		return NULL;
	}

	set->aux = (MP3Tag_t**)calloc(MP3TAG_LIST_SIZE,sizeof(MP3Tag_t*));

	if(!set->aux){
		free(*set->data);
		free(set->data);
		free(set);
	}

	*set->aux = (MP3Tag_t*)calloc(MP3TAG_INIT_SIZE,sizeof(MP3Tag_t));

	if(!set->aux){
		free(set->aux);
		free(*set->data);
		free(set->data);
		free(set);
		return NULL;
	}*/

	//************************** 3 ************************
	/*set->data = (MP3Tag_t**)calloc(1,sizeof(MP3Tag_t*));

	if(!set->data){
		free(set);
		return NULL;
	}

	for (int i = 0; i < MP3TAG_LIST_SIZE; ++i)
	{
		set->data[i] = (MP3Tag_t*)calloc(MP3TAG_INIT_SIZE,sizeof(MP3Tag_t));
		if(!set->data[i]){
			for (int j = 0; j < i; ++i)
			{
				free(set->data[j]);
			}
			free(set->data);
			free(set);
			return NULL;
		}
	}

	set->aux = (MP3Tag_t**)calloc(1,sizeof(MP3Tag_t*));

	for (int i = 0; i < MP3TAG_LIST_SIZE; ++i)
	{
		set->aux[i] = (MP3Tag_t*)calloc(MP3TAG_INIT_SIZE,sizeof(MP3Tag_t));
		if(!set->aux[i]){
			for (int j = 0; j < i; ++i)
			{
				free(set->aux[j]);
			}
			for (int j = 0; j < MP3TAG_INIT_SIZE; ++j)
			{
				free(set->data[i]);
			}
			free(set->data);
			free(set);
			return NULL;
		}
	}*/

	printf("All Good !!!\n" );
	return set;
}

void setAdd( TagSet_t *set, MP3Tag_t *tag ){

	if(set->size <= set->count)
	{
		set->data = (MP3Tag_t**)realloc(set->data,(set->count) + MP3TAG_INIT_SIZE * sizeof(MP3Tag_t));

		if (!set->data)
		{
			return;
		}

		set->aux = (MP3Tag_t**)realloc(set->aux,(set->count) + MP3TAG_INIT_SIZE * sizeof(MP3Tag_t));
		
		if (!set->aux)
		{
			free(set->data);
			return;
		}

		/**set->aux = realloc(*set->aux,(set->count) + MP3TAG_INIT_SIZE * sizeof(MP3Tag_t));
		if(!set->aux){

			return ;
		}

		*set->data = realloc(*set->data,(set->count) + MP3TAG_INIT_SIZE * sizeof(MP3Tag_t));

		if(!(*set->data)){
			return ;
		}

		set->data = realloc(set->data,(set->count) + MP3TAG_INIT_SIZE * sizeof(MP3Tag_t*));
		
		if(!set->data){
			return ;
		}
		

		
		set->aux = realloc(set->aux,(set->count) + MP3TAG_INIT_SIZE * sizeof(MP3Tag_t*));

		if(!set->aux){
			return;
		}*/

		set->size = (set->count) + MP3TAG_INIT_SIZE;
	}

	printf("setAdd Here1\n" );
	printf("before pointer:%p\n",set->data[set->count]);
	//memcpy(set->data[set->count], tag , sizeof(MP3Tag_t));
	set->data[set->count] = tag;	
	
	printf("after pointer:%p\n",set->data[set->count]);
	//memcpy(set->aux[set->count], tag , sizeof(MP3Tag_t));
	set->aux[set->count] = tag;

	printf("setAdd Here2\n" );

	//free(tag);

	set->count ++;

	return;
}

static int compare_artist_album_title(void* pa, void* pb){
	
	MP3Tag_t * a = (MP3Tag_t*)pa;
	MP3Tag_t * b = (MP3Tag_t*)pb;

	int cmp = 0; 

	if(!(cmp = strcmp(a->artist, b->artist))){
		if(!(cmp = strcmp(a->album, b->album))){
			if(!(cmp = strcmp(a-> title, b->title))){
				return cmp;
			}
			else{
				return cmp;
			}
		}else{
			return cmp;
		}
	}else{
		return cmp;
	}

}

static int compare_title_artist_album(void* pa, void* pb){
	
	MP3Tag_t * a = (MP3Tag_t*)pa;
	MP3Tag_t * b = (MP3Tag_t*)pb;

	int cmp = 0; 

	if(!(cmp = strcmp(a->title, b->title))){
		if(!(cmp = strcmp(a->artist, b->artist))){
			if(!(cmp = strcmp(a->album, b->album))){
				return cmp;
			}
			else{
				return cmp;
			}
		}else{
			return cmp;
		}
	}else{
		return cmp;
	}

}

void setReady( TagSet_t *set ){

	//a- ordenar pro artist -> album -> title
	qsort(set->data, set->count,sizeof(MP3Tag_t*),(int (*)(const void*, const void*))compare_artist_album_title);
	
	memcpy(set->aux, set->data, sizeof(MP3Tag_t));

	//t- ordenar title-> artist->album
	qsort(set->aux, set->count,sizeof(MP3Tag_t*),(int (*)(const void*, const void*))compare_artist_album_title);

	return;
}

void setCommand( TagSet_t *set, char *cmdLine ){
	return;
}

void setDelete( TagSet_t *set ){
	return;
}