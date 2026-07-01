/* Fausse division par zero par jointure de branches (Fig 1b, Blanchard et al. 2018).
 * sum vaut TOUJOURS 5, mais EVA joint {0,5}x{0,5} -> sum in {0,5,10} -> fausse alarme.
 * Defaut  : frama-c -eva 03_alias_division.c            -> 1 alarme (fausse)
 * Corrige : frama-c -eva -eva-slevel 2 03_alias_division.c -> 0 alarme */
#include "__fc_builtin.h"
int f(int a){
  int x, y;
  if (a == 0) { x = 0; y = 5; } else { x = 5; y = 0; }
  int sum = x + y;            /* toujours 5 */
  return 10 / sum;           /* EVA : risque de division par zero ? */
}
void main(void){ int a = Frama_C_interval(-10,10); int r = f(a); Frama_C_show_each_r(r); }
