/* swap - illustre comment WP gere l'ALIAS : via \separated (l'utilisateur DECLARE
 * que les deux pointeurs ne se chevauchent pas). Source : HPCS 2018, Fig. 4.
 * Lancer :  frama-c -wp -wp-rte swap.c
 * Attendu :  contrat de swap prouve, et precondition de l'appel swap(&x,&y) prouvee.
 * Experience : appeler swap(&x,&x) -> la precondition \separated DOIT echouer. */
/*@
  requires \valid(a) && \valid(b);
  requires \separated(a, b);
  assigns *a, *b;
  ensures *a == \old(*b) && *b == \old(*a);
*/
void swap(int *a, int *b){
  int tmp = *a; *a = *b; *b = tmp;
}

int main(void){
  int x = 2, y = 4;
  swap(&x, &y);
  /*@ assert x == 4 && y == 2; */
  return 0;
}
