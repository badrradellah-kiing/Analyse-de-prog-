/* Exercice 1 - correction par restructuration (intervalles propres).
 * Lancer :  frama-c -eva ex1_garde_fix.c */
#include "__fc_builtin.h"
int main(void){
  int d = Frama_C_interval(-5, 5);
  int z = 0;
  if (d > 0)      z = 100 / d;       /* d in [1,5]   : propre */
  else if (d < 0) z = 100 / d;       /* d in [-5,-1] : propre */
  Frama_C_show_each_z(z);
  return 0;
}
