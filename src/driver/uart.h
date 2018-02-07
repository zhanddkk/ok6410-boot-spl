/*
 * uart.h
 *
 *  Created on: Jan 30, 2018
 *      Author: zhanlei
 */

#ifndef SRC_DRIVER_UART_H_
#define SRC_DRIVER_UART_H_

#include "regmap.h"

extern int uart0_init(void);
extern int uart0_putchar(char ch);
extern int uart0_getchar(void);
extern int uart0_puts(const char *str);
#endif /* SRC_DRIVER_UART_H_ */
