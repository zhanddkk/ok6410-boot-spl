/*
 * sysclk.h
 *
 *  Created on: Feb 5, 2018
 *      Author: zhanlei
 */

#ifndef SRC_DRIVER_SYSCLK_H_
#define SRC_DRIVER_SYSCLK_H_
#include <stdint.h>
#define APLL    0
#define MPLL    1
#define EPLL    2
#define CONFIG_SYS_CLK_FREQ 12000000u

extern uint32_t get_pll_clk(uint32_t pll_reg);
extern uint32_t get_arm_clk(void);
extern uint32_t get_h_clk(void);
extern uint32_t get_p_clk(void);
#endif /* SRC_DRIVER_SYSCLK_H_ */
