/* Exercice 5 - malloc seul.  Lancer : frama-c -eva ex5_malloc_seul.c */
#include <stdlib.h>
typedef struct node { int v; struct node *next; } node;
void main(void){
    node *m=malloc(sizeof(node)); if(!m) return;
    m->v=42; Frama_C_show_each_v(m->v);
}
