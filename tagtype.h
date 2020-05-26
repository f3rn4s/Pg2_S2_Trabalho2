#ifndef M_APP
#define M_APP

#define MAX_TIT (30)
#define MAX_ART (30)
#define MAX_ALB (30)
#define MAX_COM (30)

typedef struct m_mp3tag_t
{
	
	char title[MAX_TIT + 1];
	char artist[MAX_ART + 1];
	char album[MAX_ALB + 1];
	short year;
	char comment[MAX_COM + 1];
	char track;
	char genre;
	char *fileName; // Aponta string com o nome do ficheiro, em alojamento dinâmico.
} MP3Tag_t;

#endif