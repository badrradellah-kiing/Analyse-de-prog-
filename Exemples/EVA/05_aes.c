/* AES (Contiki, simplifie) : EVA prouve l'absence d'erreur runtime, sans annotation.
 * galois_mul2 fait <<, >>, ^ sur des VALEURS (uint8_t) -> EVA precis.
 * Lancer : frama-c -eva 05_aes.c */
typedef unsigned char uint8_t;
static uint8_t round_keys[11][16];
static uint8_t galois_mul2(uint8_t v){ uint8_t x = (v >> 7) * 0x1b; return ((v << 1) ^ x); }
void main(void){
  uint8_t r = galois_mul2(0x53);            /* = 166, precis */
  Frama_C_show_each_r(r);
  for (int i = 0; i < 16; i++) round_keys[0][i] = (uint8_t)i;  /* indices valides */
  Frama_C_show_each_cell(round_keys[0][15]);
}
