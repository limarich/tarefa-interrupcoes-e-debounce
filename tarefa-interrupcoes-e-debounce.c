#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/clocks.h"
#include "hardware/gpio.h"
#include "hardware/pio.h"
// bibliotecas personalizadas
#include "libs/leds.h"
#include "libs/animation.h"
#include "pio_matrix.pio.h"

#define DEBOUNCE_TIME_MS 200

#define button_a 5
#define button_b 6
#define led_red 13

uint last_interrupt_time_a = 0;
uint last_interrupt_time_b = 0;
uint counter = 0;
PIO pio;
uint sm;
bool random_colors_mode = false;

void gpio_irq_handler(uint gpio, uint32_t events)
{
    uint32_t current_time = to_ms_since_boot(get_absolute_time());

    if (gpio == button_a)
    {
        if (current_time - last_interrupt_time_a > DEBOUNCE_TIME_MS)
        {
            last_interrupt_time_a = current_time;
            printf("interrupção do botão A detectada\n");
            counter = counter < 9 ? counter + 1 : counter;
            if(counter == 9 && !random_colors_mode) random_colors_mode = true;
        }
    }
    if (gpio == button_b)
    {
        if (current_time - last_interrupt_time_b > DEBOUNCE_TIME_MS)
        {
            last_interrupt_time_b = current_time;
            printf("interrupção do botão B detectada\n");
            counter = counter > 0 ? counter - 1 : 0;
            if(counter == 0 && random_colors_mode) random_colors_mode = false;
        }
    }
    printf("valor do contador: %d\n", counter);
    draw_number(pio, sm, counter, random_colors_mode);
}

void PIO_setup(PIO *pio, uint *sm);
void button_setup(uint gpio);
void led_setup(uint gpio);
void clock_setup();
void enable_interrupt();

int main()
{
    stdio_init_all();

    // configura o clock
    clock_setup();
    // configurações da PIO
    PIO_setup(&pio, &sm);
    // configuração dos botões esquerdo e direito
    button_setup(button_a);
    button_setup(button_b);
    // configuração do led vermelho
    led_setup(led_red);
    // configuração da interrupção nos dois botões
    enable_interrupt();

    // teste da matriz de leds
    test_matrix(pio, sm);
    draw_number(pio, sm, counter, random_colors_mode);
    while (true)
    {
        // para o led piscar 5 vezes por segundo 1000ms / 5 = 200ms
        for (uint i = 0; i < 5; i++) 
        {
            gpio_put(led_red, true);
            sleep_ms(100);
            gpio_put(led_red, false);
            sleep_ms(100);
        }
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
void led_setup(uint gpio)
{
    gpio_init(gpio);
    gpio_set_dir(gpio, GPIO_OUT);
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