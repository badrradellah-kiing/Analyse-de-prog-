/* Exercice 2 - alias / weak update.
 * Lancer : frama-c -eva ex2_alias.c   puis   frama-c -eva -eva-slevel 10 ex2_alias.c */
#include <__fc_builtin.h>
int x=1, y=1;
void main(void){
    int *p = Frama_C_interval(0,1) ? &x : &y;
    *p = 0;
    Frama_C_show_each_apres(x,y);
    int z = 100 / (x + y);
    Frama_C_show_each_resultat(z);
}
