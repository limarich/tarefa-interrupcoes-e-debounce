#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/clocks.h"
#include "hardware/gpio.h"
#include "hardware/pio.h"
// bibliotecas personalizadas
#include "libs/leds.h"
#include "libs/animation.h"
#include "pio_matrix.pio.h"

#define button_a 5
#define button_b 6

void gpio_irq_handler(uint gpio, uint32_t events)
{
    printf("Interrupção no GPIO %d, evento: %d\n", gpio, events);
}

void PIO_setup(PIO *pio, uint *sm);
void button_setup(uint gpio);
void clock_setup();
void enable_interrupt();

int main()
{
    stdio_init_all();
    PIO pio;
    uint sm;

    // configura o clock
    clock_setup();
    // configurações da PIO
    PIO_setup(&pio, &sm);
    // configuração dos botões esquerdo e direito
    button_setup(button_a);
    button_setup(button_b);
    // configuração da interrupção nos dois botões
    enable_interrupt();

    // teste da matriz de leds
    test_matrix(pio, sm);
    draw_number(pio, sm);
    while (true)
    {
    }
}

void clock_setup()
{
    bool ok;
    ok = set_sys_clock_khz(128000, false);

    if (ok)
        printf("clock set to %ld\n", clock_get_hz(clk_sys));
}

void button_setup(uint gpio)
{
    // configuração do botão esquerdo
    gpio_init(gpio);
    gpio_set_dir(gpio, GPIO_IN);
    gpio_pull_up(gpio); // habilitando pull_up
}

void PIO_setup(PIO *pio, uint *sm)
{
    // configurações da PIO
    *pio = pio0;
    uint offset = pio_add_program(*pio, &pio_matrix_program);
    *sm = pio_claim_unused_sm(*pio, true);
    pio_matrix_program_init(*pio, *sm, offset, LED_PIN);
}

void enable_interrupt()
{
    gpio_set_irq_enabled_with_callback(button_a, GPIO_IRQ_EDGE_FALL, true, &gpio_irq_handler);
    gpio_set_irq_enabled_with_callback(button_b, GPIO_IRQ_EDGE_FALL, true, &gpio_irq_handler);
}