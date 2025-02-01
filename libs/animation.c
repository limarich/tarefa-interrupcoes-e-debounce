#include "animation.h"
#include "hardware/pio.h"

const pixel red = {255, 0, 0}, black = {0, 0, 0};

void draw_number(PIO pio, uint sm)
{
    frame current_number;

    for (int16_t i = 0; i < PIXELS; i++)
    {
        current_number[i] = black;
    }
    draw_pio(current_number, pio, sm, 1);

    frame numbers[7] = {
        {
            red, black, black, black, black,
            red, black, black, black, black,
            red, black, black, black, black,
            red, black, black, black, black, 
            red, black, black, black, black
        },
        {
            red, red, red, red, red,
            red, black, black, black, red,
            red, red, red, red, red,
            black, black, black, black, red, 
            red, red, red, red, red
        },
        {
            black, red, red, red, black,
            black, black, black, red, black,
            black, red, red, red, black, 
            black, red, black, black, black, 
            black, red, red, red, black
        },
        {
            black, red, black, black, black,  
            black, black, black, red, black,
            black, red, red, red, black,  
            black, red, black, red, black, 
            black, red, black, red, black,
        },
        {
            black, red, red, red, black,
            black, black, black, red, black, 
            black, red, red, red, black, 
            black, black, black, red, black,
            black, red, red, red, black 
        },
        {
            black, red, red, red, black,
            black, red, black, black, black, 
            black, red, red, red, black,  
            black, black, black, red, black,  
            black, red, red, red, black 
        },
        {
            black, red, red, red, black,
            black, black, red, black, black,  
            black, black, red, black, black,  
            black, black, red, black, black,
            black, black, red, red, black
        }
    };
    
    for (uint i = 0; i < 8; i++)
    {
        draw_pio(numbers[i], pio, sm, 1);
        sleep_ms(1000);
    }
}