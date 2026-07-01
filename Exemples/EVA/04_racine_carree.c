/* Racine carree entiere (Fig 2 du papier) : boucle NON-LINEAIRE.
 * Defaut       : frama-c -eva 04_racine_carree.c              -> overflow non prouve
 * slevel borne : frama-c -eva -eva-slevel 8 04_racine_carree.c -> 0 alarme (pour N<=64)
 * Mais le slevel necessaire GRANDIT avec N (8 pour 64, ~2000 pour 10^6, impraticable
 * pour 10^9) -> c'est la que WP prend le relais (voir wp_a_prouver/root.c). */
#include "__fc_builtin.h"
int root(int N){ int R = 0; while (((R+1)*(R+1)) <= N) R = R + 1; return R; }
void main(void){ int A = Frama_C_interval(0,64); int B = root(A); Frama_C_show_each_R(B); }
