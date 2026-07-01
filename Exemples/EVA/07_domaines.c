/* (a) Congruences : EVA les suit nativement dans cvalue (notation ,0%4).
 * (b) Domaine bitwise : -eva-domains bitwise ne recupere PAS le garbled mix sur adresse
 *     (c'est une limite du modele memoire, pas de l'interpretation des operateurs bit a bit).
 * Lancer : frama-c -eva 07_domaines.c
 *          frama-c -eva -eva-domains bitwise 07_domaines.c */
#include "__fc_builtin.h"
int x;
void main(void){
  int k = Frama_C_interval(0,1000);
  int mult4 = 4 * k;                       /* (a) multiple de 4 */
  Frama_C_show_each_mult4(mult4);          /* attendu : [0..4000],0%4 */
  unsigned long a = (unsigned long)&x;
  Frama_C_show_each_adr_bitand(a & 0xF);   /* (b) garbled mix, meme avec -eva-domains bitwise */
}
