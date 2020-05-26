#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "setdata.h"

#define TAGSET_INIT_SIZE (1)
#define MP3TAG_INIT_SIZE (10)

TagSet_t *setCreate( void ){

	TagSet_t* set = (TagSet_t*)calloc(TAGSET_INIT_SIZE,sizeof(TagSet_t));
	
	if(set == NULL)
		return NULL;
	
	set->size = TAGSET_INIT_SIZE;
	set->count = 0;
	
	set->data = calloc(MP3TAG_INIT_SIZE,sizeof(MP3Tag_t));

	if(!set->data){
		free(set);
		return NULL;
	}

	set->aux = calloc(MP3TAG_INIT_SIZE,sizeof(MP3Tag_t));

	if(!set->aux){
		free(set->data);
		free(set);
		return NULL;
	}

	return set;
}

void setAdd( TagSet_t *set, MP3Tag_t *tag ){

	if(set->size <= set->count)
	{
		set->data = realloc(set->data,(set->count) + MP3TAG_INIT_SIZE * sizeof(MP3Tag_t));
		
		if(!set->data){
			return ;
		}

		set->aux = realloc(set->aux,(set->count) + MP3TAG_INIT_SIZE * sizeof(MP3Tag_t));
		
		if(!set->aux){
			free(set->data);
			return ;
		}
		set->size = (set->count) + MP3TAG_INIT_SIZE;
	}

	memcpy(set->data,tag,sizeof(MP3Tag_t));	
	memcpy(set->aux,tag,sizeof(MP3Tag_t));

	set->count += 1;

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

/*static int compare_album(void* pa, void* pb){
	
	MP3Tag_t * a = (MP3Tag_t*)pa;
	MP3Tag_t * b = (MP3Tag_t*)pb;

	return strcmp(a->album, b->album);
}

static int compare_title(void* pa, void* pb){
	
	MP3Tag_t * a = (MP3Tag_t*)pa;
	MP3Tag_t * b = (MP3Tag_t*)pb;

	return strcmp(a->title, b->title);
}*/

void setReady( TagSet_t *set ){

	//a- ordenar pro artist -> album -> title


	//t- ordenar title-> artist->album


	return;
}

void setCommand( TagSet_t *set, char *cmdLine ){
	return;
}

void setDelete( TagSet_t *set ){
	return;
}