/* Exercice 1 - le piege de la garde (trou d'intervalle).
 * Lancer :  frama-c -eva ex1_garde.c
 * Puis :    frama-c -eva -eva-slevel 20 ex1_garde.c   (ca n'aide pas !) */
#include "__fc_builtin.h"
int main(void){
  int d = Frama_C_interval(-5, 5);     /* d peut valoir 0 */
  int z = 0;
  if (d != 0) {
    Frama_C_show_each_d_dans_le_if(d); /* que croit EVA pour d ICI ? */
    z = 100 / d;
  }
  return 0;
}
