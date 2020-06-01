#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "listfiles.h"


int main(int argc, char* argv[])
{
	int* p = (int*)calloc(1,sizeof(int));

	//char* fileName = "samplefilescopy/samples/sample0001.mp3";
	//char* fileName2 = "samplefilescopy/samples/sample0002.mp3";
	//char* fileName = argv[1];
	//MP3Tag_t* var;
	//MP3Tag_t* var2;

	//var = tagRead(fileName, p);
	//var2 = tagRead(fileName2, p);

	//printf("FilenameMain:%s\n",var->fileName);

	TagSet_t* setOne;
	setOne = setCreate();

	int i= 0;
	while(i<12){
		printf("i=%d\n",i );
		var = tagRead(fileName, p);
		setAdd(setOne, var);
		var2 = tagRead(fileName2, p);
		setAdd(setOne, var2);
		printf("FilenameMain2:%s\n",setOne->data[0]->fileName);
		printf("FilenameMain2:%s\n",setOne->data[1]->fileName);

		i++;
	}

	printf("FilenameMain2:%s\n",setOne->data[0]->fileName);
	printf("FilenameMain2:%s\n",setOne->data[1]->fileName);

	return 0;
}