/* Exercice 5 - tableau borne fixe (pas de malloc).
 * Lancer : frama-c -eva ex5_tableau.c   puis   frama-c -eva -eva-auto-loop-unroll 20 ex5_tableau.c */
void main(void){
    int t[10]; for(int i=0;i<10;i++) t[i]=i;
    int s=0; for(int i=0;i<10;i++) s+=t[i];
    Frama_C_show_each_somme(s);
}
