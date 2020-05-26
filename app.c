#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "listfiles.h"
#include "tag.h"
#include "setdata.h"


int main(int argc, char* argv[])
{
	int* p = (int*)calloc(1,sizeof(int));

	//char* fileName = "samplefilescopy/samples/sample0001.mp3";
	char* fileName = argv[1];

	tagRead(fileName, p);

	char * aartist = "artist";
	char * bartist = "artist";
	char * aalbum  = "albuma";
	char * balbum  = "album";
	char * atitle  = "title";
	char * btitle  = "title";
	int cmp = 0; 

	if(!(cmp = strcmp(aartist, bartist))){
		if(!(cmp = strcmp(aalbum, balbum))){
			if(!(cmp = strcmp(atitle, btitle))){
				printf("here1\n");
			}
			else{
				printf("here2\n");
			}
		}else{
			printf("here3\n");
		}
	}else{
		printf("here4\n");
	}
 	
 	printf("%d\n",cmp );

	return 0;
}