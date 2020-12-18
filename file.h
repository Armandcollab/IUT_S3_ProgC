#ifndef FILE_H
#define FILE_H

typedef void ( *ptr_fonction_liberation )( gpointer data );
typedef void ( *ptr_fonction_affichage )( gpointer data );

struct Element_s
{
    gpointer valeur;
    struct Element_s *succ;
    struct Element_s *pred;
};

struct File_s
{
    struct Element_s *tete;
    struct Element_s *queue;
    unsigned int taille;
    ptr_fonction_liberation myfree;
    ptr_fonction_affichage myprint;
};

typedef struct Element_s Element_t;
typedef struct File_s File_t;
typedef int gpointer;

File_t *File_creer(ptr_fonction_liberation myfree, ptr_fonction_affichage myprint);
void File_enfiler(File_t *f, gpointer v);
gpointer File_defiler(File_t *f);
void File_afficher(const File_t *f);
gpointer File_taille(const File_t *f);
bool File_vide(const File_t *f);
gpointer File_premier(const File_t *f);
gpointer File_dernier(const File_t *f);
void File_liberer(File_t *f);

#endif