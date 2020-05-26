#ifndef M_NAMEFORMAT
#define M_NAMEFORMAT

int verify(char *nameWord, char *lowerWords[], int numWords );
/*funcao que, recebendo em nameWord uma palavra pertencente a
 um nome, verifica se ela é idêntica a alguma
das strings indicadas pelos ponteiros do array lowerWords. 
O parâmetro numWords é o número de strings indicadas por lowerWords. 
Em caso afirmativo retorna 1; se não, 0.*/

void upper_first(char *nameWord, char *lowerWords[], int numWords );
/*funcao que, recebendo em nameWord uma palavra pertencente a um nome,
converte-a para a forma padrão: a primeira letra em maiúscula e as
 restantes para  minúscula; exceção – se a palavra existir nas strings 
 indicadas por lowerWords, deve ficar toda em minúsculas. Deve utilizar
a função  anterior.*/

void unifyName(char *name, char *lowerWords[], int numWords );/*
que, recebendo em name um nome formado por várias palavras, separadas,
 antecedidas ou sucedidas por um ou vários espaços ou Tabs, reproduz
 a string com as palavras convertidas para a forma padrão e separadas
  por um espaço, sem espaços no início nem no fim. Para isso, a função 
  dentifica as palavras, usando a função strtok, converte-as para a 
  forma padrão, usando a função upper_first, e reconstrói a sequência. 
  O parâmetro lowerWords aponta para strings com as palavras que, se
  existirem na string name, devem ficar totalmente em minúsculas.*/

void test_program();

/*Escreva um programa de teste que apresente, em standard output, o 
resultado do processamento de cada linha recebida de standard input.
Propõe-se que leia de standard input com fgets, admitindo que cada linha
 não tem mais do que 255 caracteres. Pode utilizar as funções de
 biblioteca que considerar convenientes, tanto nas funções como no
programa de teste.*/

#endif