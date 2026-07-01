/* Exercice 6 - annoncer une precondition avec requires.
 * diviser(a,b) n'est sure que si b > 0. Au lieu de tester partout, on l'ANNONCE.
 * Lancer :  frama-c -eva ex6_requires.c -main diviser    (la fonction seule)
 * Puis :    frama-c -eva ex6_requires.c                   (avec les appels de main) */
#include "__fc_builtin.h"

/*@ requires b > 0; */
int diviser(int a, int b){ return a / b; }

int main(void){
  int ok     = diviser(100, 5);       /* 5 > 0 : precondition respectee */
  int d      = Frama_C_interval(-3, 3);/* d peut valoir 0 ou negatif */
  int risque = diviser(100, d);        /* precondition garantie ici ? */
  return 0;
}
