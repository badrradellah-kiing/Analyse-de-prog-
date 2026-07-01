/* COMPARAISON EVA / WP sur le MEME code : la racine carree entiere.
 * On analyse le MEME fichier avec les deux outils :
 *
 *   EVA :  frama-c -eva racine.c
 *          -> CALE : 2 overflows non prouves, R dans [0..2^31]. Il faut un -eva-slevel
 *             qui grandit avec N (8 pour N<=64, 2000 pour N<=10^6, impraticable au-dela).
 *             L'invariant ACSL ci-dessous est juste marque "unknown" par EVA (il ne s'en sert pas).
 *
 *   WP  :  frama-c -wp -wp-rte -wp-fct root racine.c
 *          -> PROUVE : 15/15 (Alt-Ergo), pour TOUT N, grace a l'invariant 0 <= R*R <= N
 *             et au variant N - R.
 *
 * => WP reussit la ou EVA cale. (Le main ci-dessous ne sert qu'a exercer EVA.) */
#include "__fc_builtin.h"

/*@ requires 0 <= N <= 1000000000;
    assigns \nothing;
    ensures \result * \result <= N;
    ensures N < (\result + 1) * (\result + 1); */
int root(int N){
  int R = 0;
  /*@ loop invariant 0 <= R*R <= N;
      loop assigns R;
      loop variant N - R; */
  while (((R+1)*(R+1)) <= N) R = R + 1;
  return R;
}

void main(void){ int A = Frama_C_interval(0,64); int B = root(A); Frama_C_show_each_R(B); }
