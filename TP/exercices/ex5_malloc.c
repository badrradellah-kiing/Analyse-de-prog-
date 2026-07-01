/* Exercice 5 - base faible.
 * Lancer :  frama-c -eva ex5_malloc.c
 *           frama-c -eva -eva-auto-loop-unroll 20 ex5_malloc.c   (ne repare pas)
 *           frama-c -eva -eva-slevel 2000 ex5_malloc.c           (ne repare pas non plus) */
#include <__fc_builtin.h>
#include <stdlib.h>
typedef struct node { int v; struct node *next; } node;
void main(void){
    node *head=(void*)0; int n=Frama_C_interval(1,1000);
    for(int i=0;i<n;i++){ node *m=malloc(sizeof(node)); if(!m)break; m->v=i; m->next=head; head=m; }
    int s=0; for(node *c=head;c;c=c->next) s+=c->v;
    Frama_C_show_each_somme(s);
}
