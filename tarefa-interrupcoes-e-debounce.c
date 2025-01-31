#include <stdio.h>
#include "pico/stdlib.h"

#define button_a 5
#define button_b 6

void gpio_irq_handler(uint gpio, uint32_t events)
{
    printf("Interrupção no GPIO %d, evento: %d\n", gpio, events);
}

int main()
{
    stdio_init_all();

    // configuração do botão esquerdo
    gpio_init(button_a);
    gpio_set_dir(button_a, GPIO_IN);
    gpio_pull_up(button_a); // habilitando pull_up
    // configuração do botão direito
    gpio_init(button_b);
    gpio_set_dir(button_b, GPIO_IN);
    gpio_pull_up(button_b); // habilitando pull_up

    gpio_set_irq_enabled_with_callback(button_a, GPIO_IRQ_EDGE_FALL, true, &gpio_irq_handler);
    gpio_set_irq_enabled_with_callback(button_b, GPIO_IRQ_EDGE_FALL, true, &gpio_irq_handler);
    while (true)
    {
    }
}
