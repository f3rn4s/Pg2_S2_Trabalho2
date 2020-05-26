#ifndef M_TAG
#define M_TAG

#include "tagtype.h"

typedef struct m_tagset_t
{
	int size; // Quantidade de elementos alojados em data.
	int count; // Quantidade de elementos preenchidos em data.
	MP3Tag_t **data; // Indica array, alojado dinamicamente, com ponteiros para as tags.
	MP3Tag_t **aux; // Indica array, alojado dinamicamente, com ponteiros para as tags;
} TagSet_t; // aux aponta as mesmas tags de data, com ordem diferente.

TagSet_t *setCreate( void );
/*Esta função cria o descritor de conjunto de tags no 
estado inicial, pronto para adicionar a informação
das tags. Retorna o endereço do descritor alojado dinamicamente.*/

void setAdd( TagSet_t *set, MP3Tag_t *tag );
/*Esta função adiciona ao descritor, indicado por set, uma tag,
 indicada por tag. Tendo em conta que o parâmetro tag indica um
  espaço alojado dinamicamente, a adição ao conjunto consiste em
referenciá-lo num array de ponteiros para MP3Tag_t. Este array 
também é alojado dinamicamente e deve ser redimensionado quando
 necessário.*/

void setReady( TagSet_t *set );
/*Esta função marca como concluída a fase de inserção das tags e 
prepara o descritor do conjunto para
dar as respostas pretendidas, na fase de comandos.*/

void setCommand( TagSet_t *set, char *cmdLine );
/*Esta função apresenta, em standard output, os resultados do comando 
inserido pelo utilizador. A linha de comando é passada à função 
através do parâmetro cmdLine.*/

void setDelete( TagSet_t *set );
/*Esta função, usada em consequência do comando “q”, elimina o
 descritor de conjunto de tags e as estruturas de dados dependentes 
 ele, libertando a respetiva memória de alojamento dinâmico.
*/
#endif