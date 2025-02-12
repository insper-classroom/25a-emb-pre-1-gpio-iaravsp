#include "hardware/gpio.h"
#include "pico/stdlib.h"
#include <stdio.h>
const int BTN_PIN = 28;
const int LED_PIN_VERM = 5;
const int LED_PIN_ROXO = 8;
const int LED_PIN_AZUL = 11;
const int LED_PIN_AMAR = 15;

int main() {
  stdio_init_all();
  gpio_init(BTN_PIN);
  gpio_init(LED_PIN_VERM);
  gpio_init(LED_PIN_ROXO);
  gpio_init(LED_PIN_AZUL);
  gpio_init(LED_PIN_AMAR);
  gpio_set_dir(BTN_PIN, GPIO_IN);
  gpio_set_dir(LED_PIN_VERM, GPIO_OUT);
  gpio_set_dir(LED_PIN_ROXO, GPIO_OUT);
  gpio_set_dir(LED_PIN_AZUL, GPIO_OUT);
  gpio_set_dir(LED_PIN_AMAR, GPIO_OUT);
  gpio_pull_up(BTN_PIN);

  while (true) {
    if (!gpio_get(BTN_PIN)){
      gpio_put(LED_PIN_VERM, 1);
      sleep_ms(300);
      gpio_put(LED_PIN_VERM, 0);
      gpio_put(LED_PIN_ROXO, 1);
      sleep_ms(300);
      gpio_put(LED_PIN_ROXO, 0);
      gpio_put(LED_PIN_AZUL, 1);
      sleep_ms(300);
      gpio_put(LED_PIN_AZUL, 0);
      gpio_put(LED_PIN_AMAR, 1);
      sleep_ms(300);
      gpio_put(LED_PIN_AMAR, 0);
      sleep_ms(300); 
      while (!gpio_get(BTN_PIN)){
        sleep_ms(100);
      }
    }
    // Use delay de 300 ms entre os estados!
  }
}
