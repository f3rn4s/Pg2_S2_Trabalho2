#ifndef M_TAG
#define M_TAG

#include "tagtype.h"

MP3Tag_t* tagRead ( char* fileName, int* resPtr );
/*Esta função lê a tag existente no ficheiro com o nome 
indicado por fileName, e armazena-a em memória alojada 
dinamicamente e retorna o seu endereço. O parâmetro resPtr,
 se for NULL deve ser ignorado; se não, indica uma variável
 que deve ser afetada com um código de resultado. Em caso de 
 sucesso, a função retorna o endereço da tag preenchida e o
 código de resultado é 0; caso contrário, retorna NULL, não 
 devendo alojar memória dinamicamente, e o código de resultado é -
1, se falhar o acesso ao ficheiro, ou -2, se a faixa de áudio 
não tiver informação de tag.*/
#endif

/*typedef struct{
char title[MAX_TIT + 1];
char artist[MAX_ART + 1];
char album[MAX_ALB + 1];
short year;
char comment[MAX_COM + 1];
char track;
char genre;
char *fileName; // Aponta string com o nome do ficheiro, em alojamento dinâmico.
} MP3Tag_t;*/