/* COMPARAISON EVA / WP sur le MEME code : le pointeur tague (les DEUX butent).
 * On cache un bit dans une adresse, on le retire, on dereference. Programme CORRECT.
 *
 *   EVA :  frama-c -eva pointeur.c
 *          -> garbled mix + FAUSSE alarme \valid_read(q) (pointeur reconstruit non garanti).
 *
 *   WP  :  frama-c -wp -wp-rte -wp-fct lire_tague pointeur.c
 *          -> 2 buts NON prouves (\valid_read(q) et \result == *p) : le cast entier -> pointeur
 *             sort du modele memoire standard (Typed).
 *
 * => AUCUN des deux ne gere : limite commune du modele memoire.
 *    (Le main ci-dessous ne sert qu'a exercer EVA.) */
#include "__fc_builtin.h"

/*@ requires \valid(p);
    assigns \nothing;
    ensures \result == *p; */
int lire_tague(int *p){
  unsigned long tagged = (unsigned long)p | 1uL;   /* on marque le bit 0 */
  int *q = (int*)(tagged & ~1uL);                  /* on retire le tag : q "vaut" p */
  return *q;                                       /* WP doit prouver \valid_read(q) -> echoue */
}

void main(void){ int x = 42; int r = lire_tague(&x); Frama_C_show_each_r(r); }
