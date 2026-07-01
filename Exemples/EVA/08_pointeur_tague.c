/* "Pointeur tagué" : on cache un bit dans l'adresse, on le retire, puis on déréference.
 * Le programme est CORRECT (q vaut p, donc *q == 42), mais le passage adresse -> entier ->
 * adresse défait les deux outils. Lancer : frama-c -eva 08_pointeur_tague.c */
int x;
void main(void){
  x = 42;
  int *p = &x;
  unsigned long tagged = (unsigned long)p | 1uL;     /* on marque le bit 0 */
  Frama_C_show_each_tagged(tagged);                  /* garbled mix */
  int *q = (int*)(tagged & ~1uL);                    /* on retire le tag : q "vaut" p */
  Frama_C_show_each_q(q);                            /* pointeur reconstruit */
  int v = *q;                                        /* déréférencement */
  Frama_C_show_each_v(v);                            /* EVA peut-il retrouver 42 ? */
}
