/* Octogones : EVA capture-t-il la relation x - y ?
 * Intervalles : frama-c -eva 01_octogones.c
 * Octogones   : frama-c -eva -eva-domains octagon 01_octogones.c
 * Regarder la valeur de (x - y) et de (x == y). */
#include "__fc_builtin.h"
void main(void){
  int x = Frama_C_interval(0,100);
  int y = x;                         /* relation : x == y */
  int eq  = (x == y);
  int dif = x - y;
  Frama_C_show_each_eq(eq);          /* intervalles -> {0;1} ; octogones -> {1} */
  Frama_C_show_each_x_moins_y(dif);  /* intervalles -> [-100..100] ; octogones -> {0} */
}
