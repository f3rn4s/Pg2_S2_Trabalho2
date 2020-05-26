#ifndef M_LISTFILES
#define M_LISTFILES

#include "tagtype.h"
#include "setdata.h"
#include "tag.h"

int listScan( char *listName, TagSet_t *data );
/*Esta função percorre o ficheiro de texto com nome indicado
 por listName, obtendo os nomes dos ficheiros MP3, armazenados 
 um em cada linha de texto. Por cada ficheiro MP3, obtém a
informação de tag, usando a função tagRead, e adiciona-a ao 
conjunto de tags, usando a função setAdd. Retorna 0, em caso 
de sucesso, ou -1, em caso de falha na leitura da lista.
Se ocorrer falha na obtenção da tag de alguma faixa, apresenta
 a ocorrência através de standard error, indicando o tipo de erro,
  e prossegue para a faixa seguinte; Não é armazenada nenhuma
informação relativa às faixas de áudio em que falha a leitura da tag.*/
#endif