#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tagtype.h"

#define WORDSIZE 30
#define	NAMESIZE 256

static void unifyName(char *name)
{
	//https://stackoverflow.com/questions/47809046/strtok-with-comma-spaces-and-tab

	char final_word[NAMESIZE] = ""; //Temos de dar espaco suficiente para os strcat senao da smashing stack
	char space[]= " ";

	char* token = strtok(name, " \t\n");//Para trabalhar com name em tokens, com delimitacao de espaco,tab e novalinha

    while(token != NULL)
    {
    	strcat(final_word,token);//Adiciona a palavra do token a palavra final limpa
        token = strtok(NULL, " \t\n");//Ver man strtok
        if(token)
        	strcat(final_word,space);//Adiciona espaco no fim da palavra
    }

    strcpy(name,final_word);//Colocar no ponteiro name o nome normalizado

	return;
}

MP3Tag_t* tagRead ( char *fileName, int *resPtr ){
	
	//ler o respetivo ficheiro mp3
	FILE * f = fopen(fileName, "r+b");
	
	//se der erro ao ler o ficheiro *resPtr = 1 e return NULL
	if(!f)
	{
		*resPtr = -1;
		return NULL;
	}

	char tag[4] = {0};
	char year[4];

	//coloca o ponteiro no inicio dos ultimos 128 bytes do ficheiro
	fseek(f, -128L, SEEK_END);

	//le os primeiros 3 bytes
	fread(&tag, sizeof(char),3,f);

	tag[4]='\0';

	//verificar se existe a palavra "TAG"
	if(strcmp(tag,"TAG")){//Se nao *resPtr = -2 e return NULL 
		printf("TAG nao encontrado\n");
		*resPtr = (-2);
		return NULL;
	}
	
	//Se sim alocar memoria para preencher dados e *resPtr = 0
	MP3Tag_t* mp3tag = (MP3Tag_t*)calloc(1,sizeof(MP3Tag_t));

	if(!mp3tag){
		return NULL;
	}

	fread(mp3tag->title,sizeof(char),30,f);
	fread(mp3tag->artist,sizeof(char),30,f);
	fread(mp3tag->album,sizeof(char),30,f);
	fread(&year,sizeof(char),4,f);

	//convert de char para shot
	short yearS = atoi(year);
	mp3tag->year = yearS;

	fread(mp3tag->comment,sizeof(char),30,f);
	fread(&mp3tag->genre,sizeof(char),1,f);

	mp3tag->fileName = fileName;

	//limpa as strings de espacos e tabs
	unifyName(mp3tag->title);
	unifyName(mp3tag->artist);
	unifyName(mp3tag->album);
	unifyName(mp3tag->comment);

	*resPtr = 0;
	return mp3tag;
}