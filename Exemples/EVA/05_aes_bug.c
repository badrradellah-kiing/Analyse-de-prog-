/* Variante boguee : boucle i <= 16 -> hors-bornes. EVA le detecte.
 * Lancer : frama-c -eva 05_aes_bug.c   -> alarme "out of bounds index" */
typedef unsigned char uint8_t;
static uint8_t round_keys[11][16];
void main(void){ for (int i = 0; i <= 16; i++) round_keys[0][i] = (uint8_t)i; }
