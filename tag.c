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
	printf("%s\n",fileName );
	FILE * f = fopen(fileName, "r+b");
	
	//se der erro ao ler o ficheiro *resPtr = 1 e return NULL
	if(!f)
	{
		*resPtr = 1;
		return NULL;
	}

	//fazer rewind ou fset ou fseek 128 bytes para tras
	char tag[4] = {0};
	char year[4];
	/*char title[31];
	char artist[31];
	char album[31];
	char comment[31];
	char year[4];
	char genre;*/

	//coloca o ponteiro no inicio dos ultimos 128 bytes do ficheiro
	fseek(f, -128L, SEEK_END);

	//le os primeiros 3 bytes
	fread(&tag, sizeof(char),3,f);
	/*fread(&title, sizeof(char),30,f);
	fread(&artist, sizeof(char),30,f);
	fread(&album, sizeof(char),30,f);
	fread(&year, sizeof(char),4,f);
	fread(&comment, sizeof(char),30,f);
	fread(&genre, sizeof(char),1,f);

	printf("Title:%s\n",title );
	printf("Artist:%s\n",artist );
	printf("Album:%s\n",album );
	printf("Year:%s\n",year );

	//convert o valor da string para short
	short yearS = atoi(year);

	printf("year shorted:%d\n", yearS );
	printf("Comment:%s\n",comment);
	printf("tag:%s\n", tag);
	tag[4]='\0';
	printf("tag:%s\n", tag);*/

	printf("tag:%s\n", tag);
	tag[4]='\0';
	printf("tag:%s\n", tag);
	//verificar se existe a palavra "TAG"
	if(strcmp(tag,"TAG")){//Se nao *resPtr = -2 e return NULL 
		printf("TAG nao encontrado\n");
		*resPtr = (-2);
		return NULL;
	}
	
	//Se sim alocar memoria para preencher dados e *resPtr = 0
	MP3Tag_t* mp3tag = (MP3Tag_t*)calloc(1,sizeof(MP3Tag_t));

	if(!mp3tag){
		*resPtr = 1;
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

	//Falta verificar se existe track -> fazer funcao

	fread(&mp3tag->genre,sizeof(char),1,f);
	mp3tag->fileName = fileName;

	printf("\n---------BEFORE-------------\n\n");

	printf("Title:%s\n",mp3tag->title );
	printf("artist:%s\n",mp3tag->artist );
	printf("album:%s\n",mp3tag->album );
	printf("year:%d\n",mp3tag->year );
	printf("comment:%s\n",mp3tag->comment);
	printf("genre%c\n",mp3tag->genre);
	printf("fileName:%s\n",mp3tag->fileName);


	//limpa as strings de espacos e tabs
	unifyName(mp3tag->title);
	unifyName(mp3tag->artist);
	unifyName(mp3tag->album);
	unifyName(mp3tag->comment);

	printf("\n---------AFTER-------------\n\n");
	printf("Title:%s\n",mp3tag->title );
	printf("artist:%s\n",mp3tag->artist );
	printf("album:%s\n",mp3tag->album );
	printf("year:%d\n",mp3tag->year );
	printf("comment:%s\n",mp3tag->comment);
	printf("genre%c\n",mp3tag->genre);
	printf("fileName:%s\n",mp3tag->fileName);

	return NULL;
}