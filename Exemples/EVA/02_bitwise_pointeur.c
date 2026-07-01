/* Bitwise sur une ADRESSE -> garbled mix (vs bitwise sur un NOMBRE -> precis).
 * Lancer : frama-c -eva 02_bitwise_pointeur.c */
#include "__fc_builtin.h"
int x;
void main(void){
  unsigned long a = (unsigned long)&x;   /* l'adresse de x vue comme un entier */
  Frama_C_show_each_AND_adresse(a & 0xF); /* garbled mix (origin: Arithmetic) */
  Frama_C_show_each_OR_adresse (a | 1);   /* garbled mix */
  Frama_C_show_each_SHIFT_adr  (a >> 4);  /* garbled mix */
  unsigned long n = Frama_C_interval(0,255);
  Frama_C_show_each_AND_nombre (n & 0xF); /* [0..15] : precis */
}
