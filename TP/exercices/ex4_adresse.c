/* Exercice 4 - garbled mix.  Lancer : frama-c -eva ex4_adresse.c */
#include <__fc_builtin.h>
int x; int t[16];
void main(void){
    int *p = &x;
    unsigned long a = (unsigned long)p;
    Frama_C_show_each_adresse(a);
    unsigned long g = a % 16;
    Frama_C_show_each_hash_adresse(g);
    int idx = (int)g;
    t[idx] = 1;
    int b = Frama_C_interval(0,3000);
    int c = b % 16;
    Frama_C_show_each_hash_nombre(c);
}
