/*
 * uart.c
 *
 *  Created on: Jan 30, 2018
 *      Author: zhanlei
 */

#include "uart.h"
#include "sysclk.h"
static const uint16_t __div_slot[] = {
    0x0000u,
    0x0080u,
    0x0808u,
    0x0888u,
    0x2222u,
    0x4924u,
    0x4A52u,
    0x54AAu,
    0x5555u,
    0xD555u,
    0xD5D5u,
    0xDDD5u,
    0xDDDDu,
    0xDFDDu,
    0xDFDFu,
    0xFFDFu
};

int uart0_init(void)
{
    char ch;
    uint32_t epll = get_pll_clk(EPLL);
    float div_val = (epll / (115200.0f * 16)) - 1;
    uint32_t slot_num = (uint32_t)((div_val - (uint32_t)div_val) * 16 + 0.5f) & 0xf;

    /* select MOUT(EPLL) as UART clock  */
    r_system_control->CLK_SRC &= ~(1 << 13);
    /* Normal mode operation, No parity, One stop bit per frame, 8-bit of data */
    r_uart_0->ULCON0 = 0x3;
    /* EXT_UCLK1, Interrupt request or polling mode */
    r_uart_0->UCON0 = (3 << 10) | (1 << 2) | (1);
    /* 16-byte Tx FIFO, 1-byte Rx FIFO,  Enable FIFO */
    r_uart_0->UFCON0 = (1 << 6) | (1 << 2) | (1 << 1) | 1;
    /* When RX FIFO contains 48 bytes in-activate nRTS signal, Enable AFC  */
    r_uart_0->UMCON0 = (2 << 5) | (1 << 4);
    r_uart_0->UBRDIV0 = (uint32_t)div_val;      // 51
    r_uart_0->UDIVSLOT0 = __div_slot[slot_num]; // 0x0080;
    r_gpio_a->GPACON = 2 | (2 << 4) | (2 << 8) | (2 << 12);
    uart0_puts("UART0 is OK, press any key to continue ...");
    ch = uart0_getchar();
    uart0_putchar('[');
    uart0_putchar(ch);
    uart0_puts("]\r\n");
    return (int)slot_num;
}

int uart0_putchar(char ch)
{
    while (r_uart_0->UFSTAT0 & (1 << 14));
    r_uart_0->UTXH0 = ch;
    return 0;
}

int uart0_getchar(void)
{
    int ch = -1;
    while ((r_uart_0->UFSTAT0 & 0x3f) == 0);
    ch = (uint8_t)(r_uart_0->URXH0);
    return ch;
}

int uart0_puts(const char *str)
{
    while (*str) {
        uart0_putchar(*str);
        str++;
    }
    return 0;
}
