#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "name_format.h"

#define WORDSIZE 30
#define	NAMESIZE 256
#define LOWERWORDSIZE 7

char * lowerWords[]= {"da","de","do","das","dos","a","e"};

void lowerString(char * word){

	while(*word)
	{
		*word = tolower(*word);
		word++;
	}
	return ;
}

int verify(char *nameWord, char *lowerWords[], int numWords ){


	char auxWord[WORDSIZE];
	
	if(nameWord == NULL){
		printf("Palavra nao existe!\n");
		return 0;
	}

	strcpy(auxWord,nameWord);//Para nao mexer na word original
	int i = 0;

	while(i < numWords)
	{
		lowerString(auxWord);//Razao pela qual usamos o strcpy
		if(!strcmp(auxWord,*(lowerWords+i)))
		{
			return 1;
		}
		i++;
	}
	return 0;
}

void upper_first(char *nameWord, char *lowerWords[], int numWords )
{
	if(nameWord == NULL){
		printf("Palavra nao existe!\n");
		return ;
	}

	//Para colocar em minusculas
	if(verify(nameWord, lowerWords, numWords)){
		lowerString(nameWord);
		return;
	}
	else//Para colocar em maiusculas
	{
		lowerString(nameWord);
		*nameWord = toupper(*nameWord);//coloca primeiro caracter em maiuscula
	}
	return;
}

void unifyName(char *name, char *lowerWords[], int numWords )
{
	//https://stackoverflow.com/questions/47809046/strtok-with-comma-spaces-and-tab

	char final_word[NAMESIZE] = ""; //Temos de dar espaco suficiente para os strcat senao da smashing stack
	char space[]= " ";

	char* token = strtok(name, " \t\n");//Para trabalhar com name em tokens, com delimitacao de espaco,tab e novalinha

	upper_first(token,lowerWords,numWords);

    while(token != NULL)
    {
    	strcat(final_word,token);//Adiciona a palavra do token a palavra final limpa
        token = strtok(NULL, " \t\n");//Ver man strtok
        if(token)
        	upper_first(token,lowerWords,numWords);
        	strcat(final_word,space);//Adiciona espaco no fim da palavra
    }

    strcpy(name,final_word);//Colocar no ponteiro name o nome normalizado

	return;
}

void test_program()
{

	char name[NAMESIZE]={""};
	int maxNumber = NAMESIZE-1;

	while(1)
	{
		printf("Insira nome:\n");
		fgets(name,maxNumber,stdin);
		unifyName(name,lowerWords,LOWERWORDSIZE);
		printf("%s\n",name);
	}
	return;

}
