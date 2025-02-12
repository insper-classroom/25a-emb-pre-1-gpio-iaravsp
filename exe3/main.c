#include "hardware/gpio.h"
#include "pico/stdlib.h"
#include <stdio.h>

const int BTN_VERDE = 26;
const int BTN_VERM = 28;
const int LED_PIN_VERDE = 6;
const int LED_PIN_VERM = 4;

int main()
{
  stdio_init_all();

  gpio_init(BTN_VERDE);
  gpio_init(BTN_VERM);
  gpio_init(LED_PIN_VERDE);
  gpio_init(LED_PIN_VERM);

  gpio_set_dir(BTN_VERDE, GPIO_IN);
  gpio_set_dir(BTN_VERM, GPIO_IN);
  gpio_set_dir(LED_PIN_VERDE, GPIO_OUT);
  gpio_set_dir(LED_PIN_VERM, GPIO_OUT);

  gpio_pull_up(BTN_VERDE);
  gpio_pull_up(BTN_VERM);

  int led_verd_on = 0;
  int led_verm_on = 0;

  while (true)
  {
    if (!gpio_get(BTN_VERDE))
    {
      led_verd_on = !led_verd_on;
      gpio_put(LED_PIN_VERDE, led_verd_on);
      while (!gpio_get(BTN_VERDE))
      {
        sleep_ms(100);
      }

    }
    if (!gpio_get(BTN_VERM))
    {
      led_verm_on = !led_verm_on;
      gpio_put(LED_PIN_VERM, led_verm_on);
      while (!gpio_get(BTN_VERM))
      {
        sleep_ms(100);
      }

    }
  }
}
