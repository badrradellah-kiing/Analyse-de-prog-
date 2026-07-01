/* Analyse de pointeurs : EVA calcule l'ENSEMBLE DE POINTAGE (points-to set),
 * puis fait une mise a jour FAIBLE quand la cible est imprecise.
 * Lancer : frama-c -eva 06_pointe_vers.c */
#include "__fc_builtin.h"
int x, y;
void main(void){
  x = 5; y = 7;
  int cond = Frama_C_interval(0,1);
  int *p = cond ? &x : &y;     /* p peut viser x OU y */
  Frama_C_show_each_p(p);      /* attendu : p dans {{ &x ; &y }} */
  *p = 0;                      /* cible imprecise -> mise a jour FAIBLE */
  Frama_C_show_each_x(x);      /* attendu : {0; 5}  (0 ajoute, 5 non retire) */
  Frama_C_show_each_y(y);      /* attendu : {0; 7} */
}
