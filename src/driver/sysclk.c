/*
 * sysclk.c
 *
 *  Created on: Feb 5, 2018
 *      Author: zhanlei
 */

#include "sysclk.h"
#include "regmap.h"


uint32_t get_pll_clk(uint32_t pll_reg)
{
    uint32_t r, m, p, s;

    switch (pll_reg) {
        case APLL:
            r = r_system_control->APLL_CON;
            break;
        case MPLL:
            r = r_system_control->MPLL_CON;
            break;
        case EPLL:
            r = r_system_control->EPLL_CON0;
            break;
        default:
            return 0;
    }

    m = (r >> 16) & 0x3ff;
    p = (r >> 8) & 0x3f;
    s = r & 0x7;

    return (m * (CONFIG_SYS_CLK_FREQ / (p * (1 << s))));
}

/* return ARMCORE frequency */
uint32_t get_arm_clk(void)
{
    uint32_t div;

    div = r_system_control->CLK_DIV0;

    return (get_pll_clk(APLL) / ((div & 0x7) + 1));
}

/* return HCLK frequency */
uint32_t get_h_clk(void)
{
    uint32_t fclk;
    uint32_t hclkx2_div = ((r_system_control->CLK_DIV0 >> 9) & 0x7) + 1;
    uint32_t hclk_div = ((r_system_control->CLK_DIV0 >> 8) & 0x1) + 1;

    if(r_system_control->OTHERS & 0x80)
        fclk = get_arm_clk();       // SYNC Mode
    else
        fclk = get_pll_clk(MPLL);   // ASYNC Mode

    return fclk / (hclk_div * hclkx2_div);
}

/* return PCLK frequency */
uint32_t get_p_clk(void)
{
    uint32_t fclk;
    uint32_t hclkx2_div = ((r_system_control->CLK_DIV0 >> 9) & 0x7) + 1;
    uint32_t pre_div = ((r_system_control->CLK_DIV0 >> 12) & 0xf) + 1;

    if(r_system_control->OTHERS & 0x80)
        fclk = get_arm_clk();       // SYNC Mode
    else
        fclk = get_pll_clk(MPLL);   // ASYNC Mode

    return fclk / (hclkx2_div * pre_div);
}

