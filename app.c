#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "listfiles.h"
#include "tag.c"


int main(int argc, char* argv[])
{
	int* p = (int*)calloc(1,sizeof(int));

	//char* fileName = "samplefilescopy/samples/sample0001.mp3";
	char* fileName = argv[1];

	tagRead(fileName, p);

	return 0;
}