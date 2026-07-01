/* Racine carree entiere - PROUVEE par WP pour tout N <= 10^9, sans deroulage.
 * A comparer avec eva_experiences/04_racine_carree.c (ou EVA a besoin d'un slevel
 * qui grandit avec N). Source : Blanchard, Kosmatov, Loulergue, HPCS 2018, Fig. 8.
 * Lancer :  frama-c -wp -wp-rte root.c
 * Attendu :  tous les buts prouves (Qed / Alt-Ergo / CVC4). */
/*@
  requires 0 <= N <= 1000000000;
  assigns \nothing;
  ensures \result * \result <= N;
  ensures N < (\result + 1) * (\result + 1);
*/
int root(int N){
  int R = 0;
  /*@
    loop invariant 0 <= R*R <= N;
    loop assigns R;
    loop variant N - R;
  */
  while (((R+1)*(R+1)) <= N) {
    R = R + 1;
  }
  return R;
}
