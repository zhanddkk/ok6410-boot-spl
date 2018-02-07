/*
 * main.c
 *
 *  Created on: Nov 10, 2017
 *      Author: zhanlei
 */
#include <stdio.h>
#include "../driver/uart.h"
uint32_t count = 0;

void printf_hex(uint32_t num)
{
    int i;
    uart0_puts("0x");
    for (i = 0; i < 8; i++) {
        char ch = (char)((num & 0xf0000000) >> 28);
        if (ch > 9) {
            ch += 'A' - 10;
        } else {
            ch += '0';
        }
        num <<= 4;
        uart0_putchar(ch);
    }
}

int main(void)
{
    uint32_t i = 0;
    uart0_init();
    while (1) {
        i++;
        if (i == 0x5fffff) {
            count++;
            printf_hex(count);
            uart0_puts("\r");
            i = 0;
        }
    }
}
