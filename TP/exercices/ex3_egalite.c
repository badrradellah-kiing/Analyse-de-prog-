/* Exercice 3 (bonus) - egalite.
 * Lancer : frama-c -eva ex3_egalite.c   puis   frama-c -eva -eva-domains cvalue,octagon ex3_egalite.c */
#include <__fc_builtin.h>
void main(void){
    int x=Frama_C_interval(0,100);
    int y=x;     int eq=(x==y);   Frama_C_show_each_egaux(eq);
    int z=x+1;   int neq=(x==z);  Frama_C_show_each_differents(neq);
}
