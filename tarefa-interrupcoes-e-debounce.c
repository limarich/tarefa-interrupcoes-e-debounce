#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/clocks.h"
#include "hardware/gpio.h"
#include "libs/leds.h"

#include "pio_matrix.pio.h"

#define button_a 5
#define button_b 6

void gpio_irq_handler(uint gpio, uint32_t events)
{
    printf("Interrupção no GPIO %d, evento: %d\n", gpio, events);
}

int main()
{
    bool ok;
    stdio_init_all();

    ok = set_sys_clock_khz(128000, false);

    printf("iniciando a transmissão PIO");
    if (ok)
        printf("clock set to %ld\n", clock_get_hz(clk_sys));

    // configurações da PIO
    PIO pio = pio0;
    uint offset = pio_add_program(pio, &pio_matrix_program);
    uint sm = pio_claim_unused_sm(pio, true);
    pio_matrix_program_init(pio, sm, offset, LED_PIN);

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
    // teste da matriz de leds
    test_matrix(pio, sm);
    while (true)
    {
    }
}
