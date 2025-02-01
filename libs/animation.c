#include "animation.h"
#include "hardware/pio.h"

const pixel red = {255, 0, 0}, black = {0, 0, 0};

void draw_number(PIO pio, uint sm, uint index)
{
    frame numbers[10] = {
        // 0
        {black, red, red, red, black,
         black, red, black, red, black,
         black, red, black, red, black,
         black, red, black, red, black,
         black, red, red, red, black},
        //  1
        {black, red, red, black, black,
         black, black, black, red, black,
         black, red, black, black, black,
         black, black, red, red, black,
         black, red, black, black, black},
        // 2
        { black, red, red, red, black,
          black,red, black, black, black,
         black, red, red, red, black,
         black, black, black, red, black,
         black, red, red, red, black},
        //  3
        {black, red, red, red, black,
          black, black, black,red, black,
         black, red, red, red, black,
         black, black, black, red, black,
         black, red, red, red, black},
        //  4
        {
            black, red, black, black, black,
            black, black, black, red, black,
            black, red, red, red, black,
            black, red, black, red, black,
            black, red, black, red,black,
        },
        //  5
        {black, red, red, red, black,
         black, black, black, red, black,
         black, red, red, red, black,
         black, red, black, black, black,
         black, red, red, red, black},
        
        // 6
        {black, red, red, red, black,
         black, red, black, red, black,
         black, red, red, red, black,
         black,red, black, black, black,
         black, red, red, red, black},
        //  7
        {black, red, black, black, black,
         black, black, black,red, black,
         black, red, black, black, black,
         black, black, black, red, black,
         black, red, red, red, black},
        //  8
        {black, red, red, red, black,
         black, red, black, red, black,
         black, red, red, red, black,
         black,red, black, red, black,
         black, red, red, red, black},
        //  9
        {black, red, red, red, black,
         black, black, black, red, black,
         black, red, red, red, black,
         black,red, black, red, black,
         black, red, red, red, black},

    };

    // for (int i = 0; i <= 10; i++)
    // {
    //     draw_pio(numbers[i], pio, sm, 1);
    //     sleep_ms(500);
    // }
    draw_pio(numbers[index], pio, sm, .2);
}