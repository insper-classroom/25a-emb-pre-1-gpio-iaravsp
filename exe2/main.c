#include "hardware/gpio.h"
#include "pico/stdlib.h"
#include <stdio.h>

const int BTN_PIN_1V = 26; //botao 1 verde
const int BTN_PIN_2A = 7;  //botao 2 amarelo
//acho q tudo ok, reenviando commit p/ testes
int main() {
  stdio_init_all();

  gpio_init(BTN_PIN_1V);
  gpio_init(BTN_PIN_2A);
  gpio_set_dir(BTN_PIN_1V, GPIO_IN);
  gpio_set_dir(BTN_PIN_2A, GPIO_IN);
  gpio_pull_up(BTN_PIN_1V);
  gpio_pull_up(BTN_PIN_2A);

  while (true) {
    if (!gpio_get(BTN_PIN_1V)) {
      printf("Botao 1\n");
      while (!gpio_get(BTN_PIN_1V)) {
        sleep_ms(100);
      }
    }
    else if (!gpio_get(BTN_PIN_2A)) {
      printf("Botao 2\n");
      while (!gpio_get(BTN_PIN_2A)) {
        sleep_ms(100);
      }
    }
  }
}
