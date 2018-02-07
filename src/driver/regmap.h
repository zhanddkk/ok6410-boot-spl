/***********************************************************************************************************************
 * Original Author : Register Map File Generation Tool (v0.0.1)
 * File Path       : regmap.h
 * Item Number     : 30
 *
 * Please don't edit this file manually!!!
 *  [0x7E00F000 ~ 0x7E00F90C] System Control: 43 members
 *  [0x7E00FA00 ~ 0x7E00FA0C] User Information: 4 members
 *  [0x7F005000 ~ 0x7F005038] UART 0: 15 members
 *  [0x7F005400 ~ 0x7F005438] UART 1: 15 members
 *  [0x7F005800 ~ 0x7F005838] UART 2: 14 members
 *  [0x7F005C00 ~ 0x7F005C38] UART 3: 14 members
 *  [0x7F008000 ~ 0x7F008010] GPIO A: 5 members
 *  [0x7F008020 ~ 0x7F008030] GPIO B: 5 members
 *  [0x7F008040 ~ 0x7F008050] GPIO C: 5 members
 *  [0x7F008060 ~ 0x7F008070] GPIO D: 5 members
 *  [0x7F008080 ~ 0x7F008090] GPIO E: 5 members
 *  [0x7F0080A0 ~ 0x7F0080B0] GPIO F: 5 members
 *  [0x7F0080C0 ~ 0x7F0080D0] GPIO G: 5 members
 *  [0x7F0080E0 ~ 0x7F0080F4] GPIO H: 6 members
 *  [0x7F008100 ~ 0x7F008110] GPIO I: 5 members
 *  [0x7F008120 ~ 0x7F008130] GPIO J: 5 members
 *  [0x7F008140 ~ 0x7F008150] GPIO O: 5 members
 *  [0x7F008160 ~ 0x7F008170] GPIO P: 5 members
 *  [0x7F008180 ~ 0x7F008190] GPIO Q: 5 members
 *  [0x7F0081A0 ~ 0x7F0081A0] Special Port Configuration: 1 members
 *  [0x7F0081C0 ~ 0x7F0081D4] Memory Port: 6 members
 *  [0x7F008200 ~ 0x7F008270] External Interrupt 1 To 9: 21 members
 *  [0x7F008280 ~ 0x7F008288] External Interrupt common: 3 members
 *  [0x7F008800 ~ 0x7F00880C] GPIO K: 4 members
 *  [0x7F008810 ~ 0x7F00881C] GPIO L: 4 members
 *  [0x7F008820 ~ 0x7F008828] GPIO M: 3 members
 *  [0x7F008830 ~ 0x7F008838] GPIO N: 3 members
 *  [0x7F008880 ~ 0x7F008880] Special Port Sleep mode configure: 1 members
 *  [0x7F008900 ~ 0x7F008924] External Interrupt 0: 9 members
 *  [0x7F008930 ~ 0x7F008930] Sleep Mode Pad Configure: 1 members
***********************************************************************************************************************/
#ifndef _REGMAP_H_
#define _REGMAP_H_
#include <stdint.h>

#define __I     volatile const       /*!< Defines 'read only' permissions */
#define __O     volatile             /*!< Defines 'write only' permissions */
#define __IO    volatile             /*!< Defines 'read / write' permissions */

/*====================================================================================================================*/
/* [0x7E00F000 ~ 0x7E00F90C] System Control: 43 members */
/*--------------------------------------------------------------------------------------------------------------------*/
struct system_control_reg_map {
    __IO uint32_t APLL_LOCK; /* 0x7E00F000: Control PLL locking period for APLL 0x0000_FFFF */
    __IO uint32_t MPLL_LOCK; /* 0x7E00F004: Control PLL locking period for MPLL 0x0000_FFFF */
    __IO uint32_t EPLL_LOCK; /* 0x7E00F008: Control PLL locking period for EPLL 0x0000_FFFF */
    __IO uint32_t APLL_CON; /* 0x7E00F00C: Control PLL output frequency for APLL 0x0190_0302 */
    __IO uint32_t MPLL_CON; /* 0x7E00F010: Control PLL output frequency for MPLL 0x0214_0603 */
    __IO uint32_t EPLL_CON0; /* 0x7E00F014: Control PLL output frequency for EPLL 0x0020_0102 */
    __IO uint32_t EPLL_CON1; /* 0x7E00F018: Control PLL output frequency for EPLL 0x0000_9111 */
    __IO uint32_t CLK_SRC; /* 0x7E00F01C: Select clock source 0x0000_0000 */
    __IO uint32_t CLK_DIV0; /* 0x7E00F020: Set clock divider ratio 0x0105_1000 */
    __IO uint32_t CLK_DIV1; /* 0x7E00F024: Set clock divider ratio 0x0000_0000 */
    __IO uint32_t CLK_DIV2; /* 0x7E00F028: Set clock divider ratio 0x0000_0000 */
    __IO uint32_t CLK_OUT; /* 0x7E00F02C: Select clock output 0x0000_0000 */
    __IO uint32_t HCLK_GATE; /* 0x7E00F030: Control HCLK clock gating 0xFFFF_FFFF */
    __IO uint32_t PCLK_GATE; /* 0x7E00F034: Control PCLK clock gating 0xFFFF_FFFF */
    __IO uint32_t SCLK_GATE; /* 0x7E00F038: Control SCLK clock gating 0xFFFF_FFFF */
    __IO uint32_t MEM0_CLK_GATE; /* 0x7E00F03C: Control MEM0 clock gating 0xFFFF_FFFF */
    __I uint32_t RESERVED_0[48]; /* 0x7E00F040 ~ 0x7E00F0FC: RESERVED - */
    __IO uint32_t AHB_CON0; /* 0x7E00F100: Configure AHB I/P/X/F bus 0x0400_0000 */
    __IO uint32_t AHB_CON1; /* 0x7E00F104: Configure AHB M1/M0/T1/T0 bus 0x0000_0000 */
    __IO uint32_t AHB_CON2; /* 0x7E00F108: Configure AHB R/S1/S0 bus 0x0000_0000 */
    __IO uint32_t CLK_SRC2; /* 0x7E00F10C: Select Audio2 clock source 0x0000_0000 */
    __IO uint32_t SDMA_SEL; /* 0x7E00F110: Select secure DMA input 0x0000_0000 */
    __IO uint32_t RESERVED_1; /* 0x7E00F114: RESERVED 0x0000_0000 */
    __I uint32_t SYS_ID; /* 0x7E00F118: System ID for revision and pass 0x3641_0101 */
    __IO uint32_t SYS_OTHERS; /* 0x7E00F11C: SYSCON others control register 0x0000_0000 */
    __IO uint32_t MEM_SYS_CFG; /* 0x7E00F120: Configure memory subsystem 0x0000_0080 */
    __IO uint32_t RESERVED_2; /* 0x7E00F124: RESERVED 0x0000_0000 */
    __IO uint32_t QOS_OVERRIDE1; /* 0x7E00F128: Override DMC1 QOS 0x0000_0000 */
    __I uint32_t MEM_CFG_STAT; /* 0x7E00F12C: Memory subsystem setup status 0x0000_0000 */
    __IO uint32_t RESERVED_3; /* 0x7E00F130: Should be 0x0 0x0000_0000 */
    __I uint32_t RESERVED_4[51]; /* 0x7E00F134 ~ 0x7E00F1FC: RESERVED - */
    __IO uint32_t RESERVED_5[16]; /* 0x7E00F200 ~ 0x7E00F23C: Should be 0x0 0x0000_0000~0x0000_0000 */
    __I uint32_t RESERVED_6[369]; /* 0x7E00F240 ~ 0x7E00F800: RESERVED - */
    __IO uint32_t PWR_CFG; /* 0x7E00F804: Configure power manager 0x0000_0001 */
    __IO uint32_t EINT_MASK; /* 0x7E00F808: Configure EINT(external interrupt) mask 0x0000_0000 */
    __I uint32_t RESERVED_7; /* 0x7E00F80C: RESERVED - */
    __IO uint32_t NORMAL_CFG; /* 0x7E00F810: Configure power manager at NORMAL mode 0xFFFF_FF00 */
    __IO uint32_t STOP_CFG; /* 0x7E00F814: Configure power manager at STOP mode 0x2012_0100 */
    __IO uint32_t SLEEP_CFG; /* 0x7E00F818: Configure power manager at SLEEP mode 0x0000_0000 */
    __IO uint32_t STOP_MEM_CFG; /* 0x7E00F81C: Configure memory power at STOP mode 0x0000_007f */
    __IO uint32_t OSC_FREQ; /* 0x7E00F820: Oscillator frequency scale counter 0x0000_000F */
    __IO uint32_t OSC_STABLE; /* 0x7E00F824: Oscillator pad stable counter 0x0000_0001 */
    __IO uint32_t PWR_STABLE; /* 0x7E00F828: Power stable counter 0x0000_0001 */
    __I uint32_t RESERVED_8; /* 0x7E00F82C: RESERVED - */
    __IO uint32_t MTC_STABLE; /* 0x7E00F830: MTC stable counter 0xFFFF_FFFF */
    __IO uint32_t BUS_CACHEABLE_CON; /* 0x7E00F834: Decision whether packing is used or not - */
    __IO uint32_t MISC_CON; /* 0x7E00F838: Bus control 0x0000_0000 */
    __I uint32_t RESERVED_9[49]; /* 0x7E00F83C ~ 0x7E00F8FC: RESERVED - */
    __IO uint32_t OTHERS; /* 0x7E00F900: Others control register 0x0000_801E */
    __I uint32_t RST_STAT; /* 0x7E00F904: Reset status register 0x0000_0001 */
    __IO uint32_t WAKEUP_STAT; /* 0x7E00F908: Wakeup status register 0x0000_0000 */
    __I uint32_t BLK_PWR_STAT; /* 0x7E00F90C: Block power status register 0x0000_00FF */
};
#define r_system_control ((volatile struct system_control_reg_map *)0x7E00F000)
/*====================================================================================================================*/
/* [0x7E00FA00 ~ 0x7E00FA0C] User Information: 4 members */
/*--------------------------------------------------------------------------------------------------------------------*/
struct user_information_reg_map {
    __IO uint32_t INFORM0; /* 0x7E00FA00: Information register0 0x0000_0000 */
    __IO uint32_t INFORM1; /* 0x7E00FA04: Information register1 0x0000_0000 */
    __IO uint32_t INFORM2; /* 0x7E00FA08: Information register2 0x0000_0000 */
    __IO uint32_t INFORM3; /* 0x7E00FA0C: Information register3 0x0000_0000 */
};
#define r_user_information ((volatile struct user_information_reg_map *)0x7E00FA00)
/*====================================================================================================================*/
/* [0x7F005000 ~ 0x7F005038] UART 0: 15 members */
/*--------------------------------------------------------------------------------------------------------------------*/
struct uart_0_reg_map {
    __IO uint32_t ULCON0; /* 0x7F005000: UART channel 0 line control register 0x00 */
    __IO uint32_t UCON0; /* 0x7F005004: UART channel 0 control register 0x00 */
    __IO uint32_t UFCON0; /* 0x7F005008: UART channel 0 FIFO control register 0x0 */
    __IO uint32_t UMCON0; /* 0x7F00500C: UART channel 0 Modem control register 0x0 */
    __I uint32_t UTRSTAT0; /* 0x7F005010: UART channel 0 Tx/Rx status register 0x6 */
    __I uint32_t UERSTAT0; /* 0x7F005014: UART channel 0 Rx error status register 0x0 */
    __I uint32_t UFSTAT0; /* 0x7F005018: UART channel 0 FIFO status register 0x00 */
    __I uint32_t UMSTAT0; /* 0x7F00501C: UART channel 0 Modem status register 0x0 */
    __O uint32_t UTXH0; /* 0x7F005020: UART channel 0 transmit buffer register - */
    __I uint32_t URXH0; /* 0x7F005024: UART channel 0 receive buffer register 0x00 */
    __IO uint32_t UBRDIV0; /* 0x7F005028: UART channel 0 Baud rate divisior register 0x0000 */
    __IO uint32_t UDIVSLOT0; /* 0x7F00502C: UART channel 0 Dividing slot register 0x0000 */
    __IO uint32_t UINTP0; /* 0x7F005030: UART channel 0 Interrupt Pending Register 0x0 */
    __IO uint32_t UINTSP0; /* 0x7F005034: UART channel 0 Interrupt Source Pending Register 0x0 */
    __IO uint32_t UINTM0; /* 0x7F005038: UART channel 0 Interrupt Mask Register 0x0 */
};
#define r_uart_0 ((volatile struct uart_0_reg_map *)0x7F005000)
/*====================================================================================================================*/
/* [0x7F005400 ~ 0x7F005438] UART 1: 15 members */
/*--------------------------------------------------------------------------------------------------------------------*/
struct uart_1_reg_map {
    __IO uint32_t ULCON1; /* 0x7F005400: UART channel 1 line control register 0x00 */
    __IO uint32_t UCON1; /* 0x7F005404: UART channel 1 control register 0x00 */
    __IO uint32_t UFCON1; /* 0x7F005408: UART channel 1 FIFO control register 0x0 */
    __IO uint32_t UMCON1; /* 0x7F00540C: UART channel 1 Modem control register 0x0 */
    __I uint32_t UTRSTAT1; /* 0x7F005410: UART channel 1 Tx/Rx status register 0x6 */
    __I uint32_t UERSTAT1; /* 0x7F005414: UART channel 1 Rx error status register 0x0 */
    __I uint32_t UFSTAT1; /* 0x7F005418: UART channel 1 FIFO status register 0x00 */
    __I uint32_t UMSTAT1; /* 0x7F00541C: UART channel 1 Modem status register 0x0 */
    __O uint32_t UTXH1; /* 0x7F005420: UART channel 1 transmit buffer register - */
    __I uint32_t URXH1; /* 0x7F005424: UART channel 1 receive buffer register 0x00 */
    __IO uint32_t UBRDIV1; /* 0x7F005428: UART channel 1 Baud rate divisior register 0x0000 */
    __IO uint32_t UDIVSLOT1; /* 0x7F00542C: UART channel 1 Dividing slot register 0x0000 */
    __IO uint32_t UINTP1; /* 0x7F005430: UART channel 1 Interrupt Pending Register 0x0 */
    __IO uint32_t UINTSP1; /* 0x7F005434: UART channel 1 Interrupt Source Pending Register 0x0 */
    __IO uint32_t UINTM1; /* 0x7F005438: UART channel 1 Interrupt Mask Register 0x0 */
};
#define r_uart_1 ((volatile struct uart_1_reg_map *)0x7F005400)
/*====================================================================================================================*/
/* [0x7F005800 ~ 0x7F005838] UART 2: 14 members */
/*--------------------------------------------------------------------------------------------------------------------*/
struct uart_2_reg_map {
    __IO uint32_t ULCON2; /* 0x7F005800: UART channel 2 line control register 0x00 */
    __IO uint32_t UCON2; /* 0x7F005804: UART channel 2 control register 0x00 */
    __IO uint32_t UFCON2; /* 0x7F005808: UART channel 2 FIFO control register 0x0 */
    __I uint32_t RESERVED_0; /* 0x7F00580C: RESERVED - */
    __I uint32_t UTRSTAT2; /* 0x7F005810: UART channel 2 Tx/Rx status register 0x6 */
    __I uint32_t UERSTAT2; /* 0x7F005814: UART channel 2 Rx error status register 0x0 */
    __I uint32_t UFSTAT2; /* 0x7F005818: UART channel 2 FIFO status register 0x00 */
    __I uint32_t RESERVED_1; /* 0x7F00581C: RESERVED - */
    __O uint32_t UTXH2; /* 0x7F005820: UART channel 2 transmit buffer register - */
    __I uint32_t URXH2; /* 0x7F005824: UART channel 2 receive buffer register 0x00 */
    __IO uint32_t UBRDIV2; /* 0x7F005828: UART channel 2 Baud rate divisior register 0x0000 */
    __IO uint32_t UDIVSLOT2; /* 0x7F00582C: UART channel 2 Dividing slot register 0x0000 */
    __IO uint32_t INTP2; /* 0x7F005830: UART channel 2 Interrupt Pending Register 0x0 */
    __IO uint32_t UINTSP2; /* 0x7F005834: UART channel 2 Interrupt Source Pending Register 0x0 */
    __IO uint32_t UINTM2; /* 0x7F005838: UART channel 2 Interrupt Mask Register 0x0 */
};
#define r_uart_2 ((volatile struct uart_2_reg_map *)0x7F005800)
/*====================================================================================================================*/
/* [0x7F005C00 ~ 0x7F005C38] UART 3: 14 members */
/*--------------------------------------------------------------------------------------------------------------------*/
struct uart_3_reg_map {
    __IO uint32_t ULCON3; /* 0x7F005C00: UART channel 3 line control register 0x00 */
    __IO uint32_t UCON3; /* 0x7F005C04: UART channel 3 control register 0x00 */
    __IO uint32_t UFCON3; /* 0x7F005C08: UART channel 3 FIFO control register 0x0 */
    __I uint32_t RESERVED_0; /* 0x7F005C0C: RESERVED - */
    __I uint32_t UTRSTAT3; /* 0x7F005C10: UART channel 3 Tx/Rx status register 0x6 */
    __I uint32_t UERSTAT3; /* 0x7F005C14: UART channel 3 Rx error status register 0x0 */
    __I uint32_t UFSTAT3; /* 0x7F005C18: UART channel 3 FIFO status register 0x00 */
    __I uint32_t RESERVED_1; /* 0x7F005C1C: RESERVED - */
    __O uint32_t UTXH3; /* 0x7F005C20: UART channel 3 transmit buffer register - */
    __I uint32_t URXH3; /* 0x7F005C24: UART channel 3 receive buffer register 0x00 */
    __IO uint32_t UBRDIV3; /* 0x7F005C28: UART channel 3 Baud rate divisior register 0x0000 */
    __IO uint32_t UDIVSLOT3; /* 0x7F005C2C: UART channel 3 Dividing slot register 0x0000 */
    __IO uint32_t INTP3; /* 0x7F005C30: UART channel 3 Interrupt Pending Register 0x0 */
    __IO uint32_t UINTSP3; /* 0x7F005C34: UART channel 3 Interrupt Source Pending Register 0x0 */
    __IO uint32_t UINTM3; /* 0x7F005C38: UART channel 3 Interrupt Mask Register 0x0 */
};
#define r_uart_3 ((volatile struct uart_3_reg_map *)0x7F005C00)
/*====================================================================================================================*/
/* [0x7F008000 ~ 0x7F008010] GPIO A: 5 members */
/*--------------------------------------------------------------------------------------------------------------------*/
struct gpio_a_reg_map {
    __IO uint32_t GPACON; /* 0x7F008000: Port A Configuration Register 0x0 */
    __IO uint32_t GPADAT; /* 0x7F008004: Port A Data Register Undefined */
    __IO uint32_t GPAPUD; /* 0x7F008008: Port A Pull-up/down Register 0x00005555 */
    __IO uint32_t GPACONSLP; /* 0x7F00800C: Port A Sleep mode Configuration Register 0x0 */
    __IO uint32_t GPAPUDSLP; /* 0x7F008010: Port A Sleep mode Pull-up/down Register 0x0 */
};
#define r_gpio_a ((volatile struct gpio_a_reg_map *)0x7F008000)
/*====================================================================================================================*/
/* [0x7F008020 ~ 0x7F008030] GPIO B: 5 members */
/*--------------------------------------------------------------------------------------------------------------------*/
struct gpio_b_reg_map {
    __IO uint32_t GPBCON; /* 0x7F008020: Port B Configuration Register 0x40000 */
    __IO uint32_t GPBDAT; /* 0x7F008024: Port B Data Register Undefined */
    __IO uint32_t GPBPUD; /* 0x7F008028: Port B Pull-up/down Register 0x00001555 */
    __IO uint32_t GPBCONSLP; /* 0x7F00802C: Port B Sleep mode Configuration Register 0x0 */
    __IO uint32_t GPBPUDSLP; /* 0x7F008030: Port B Sleep mode Pull-up/down Register 0x0 */
};
#define r_gpio_b ((volatile struct gpio_b_reg_map *)0x7F008020)
/*====================================================================================================================*/
/* [0x7F008040 ~ 0x7F008050] GPIO C: 5 members */
/*--------------------------------------------------------------------------------------------------------------------*/
struct gpio_c_reg_map {
    __IO uint32_t GPCCON; /* 0x7F008040: Port C Configuration Register 0x0 */
    __IO uint32_t GPCDAT; /* 0x7F008044: Port C Data Register Undefined */
    __IO uint32_t GPCPUD; /* 0x7F008048: Port C Pull-up/down Register 0x00005555 */
    __IO uint32_t GPCCONSLP; /* 0x7F00804C: Port C Sleep mode Configuration Register 0x0 */
    __IO uint32_t GPCPUDSLP; /* 0x7F008050: Port C Sleep mode Pull-up/down Register 0x0 */
};
#define r_gpio_c ((volatile struct gpio_c_reg_map *)0x7F008040)
/*====================================================================================================================*/
/* [0x7F008060 ~ 0x7F008070] GPIO D: 5 members */
/*--------------------------------------------------------------------------------------------------------------------*/
struct gpio_d_reg_map {
    __IO uint32_t GPDCON; /* 0x7F008060: Port D Configuration Register 0x0 */
    __IO uint32_t GPDDAT; /* 0x7F008064: Port D Data Register Undefined */
    __IO uint32_t GPDPUD; /* 0x7F008068: Port D Pull-up/down Register 0x00000155 */
    __IO uint32_t GPDCONSLP; /* 0x7F00806C: Port D Sleep mode Configuration Register 0x0 */
    __IO uint32_t GPDPUDSLP; /* 0x7F008070: Port D Sleep mode Pull-up/down Register 0x0 */
};
#define r_gpio_d ((volatile struct gpio_d_reg_map *)0x7F008060)
/*====================================================================================================================*/
/* [0x7F008080 ~ 0x7F008090] GPIO E: 5 members */
/*--------------------------------------------------------------------------------------------------------------------*/
struct gpio_e_reg_map {
    __IO uint32_t GPECON; /* 0x7F008080: Port E Configuration Register 0x0 */
    __IO uint32_t GPEDAT; /* 0x7F008084: Port E Data Register Undefined */
    __IO uint32_t GPEPUD; /* 0x7F008088: Port E Pull-up/down Register 0x00000155 */
    __IO uint32_t GPECONSLP; /* 0x7F00808C: Port E Sleep mode Configuration Register 0x0 */
    __IO uint32_t GPEPUDSLP; /* 0x7F008090: Port E Sleep mode Pull-up/down Register 0x0 */
};
#define r_gpio_e ((volatile struct gpio_e_reg_map *)0x7F008080)
/*====================================================================================================================*/
/* [0x7F0080A0 ~ 0x7F0080B0] GPIO F: 5 members */
/*--------------------------------------------------------------------------------------------------------------------*/
struct gpio_f_reg_map {
    __IO uint32_t GPFCON; /* 0x7F0080A0: Port F Configuration Register 0x0 */
    __IO uint32_t GPFDAT; /* 0x7F0080A4: Port F Data Register Undefined */
    __IO uint32_t GPFPUD; /* 0x7F0080A8: Port F Pull-up/down Register 0x55555555 */
    __IO uint32_t GPFCONSLP; /* 0x7F0080AC: Port F Sleep mode Configuration Register 0x0 */
    __IO uint32_t GPFPUDSLP; /* 0x7F0080B0: Port F Sleep mode Pull-up/down Register 0x0 */
};
#define r_gpio_f ((volatile struct gpio_f_reg_map *)0x7F0080A0)
/*====================================================================================================================*/
/* [0x7F0080C0 ~ 0x7F0080D0] GPIO G: 5 members */
/*--------------------------------------------------------------------------------------------------------------------*/
struct gpio_g_reg_map {
    __IO uint32_t GPGCON; /* 0x7F0080C0: Port G Configuration Register 0x0 */
    __IO uint32_t GPGDAT; /* 0x7F0080C4: Port G Data Register Undefined */
    __IO uint32_t GPGPUD; /* 0x7F0080C8: Port G Pull-up/down Register 0x00001555 */
    __IO uint32_t GPGCONSLP; /* 0x7F0080CC: Port G Sleep mode Configuration Register 0x0 */
    __IO uint32_t GPGPUDSLP; /* 0x7F0080D0: Port G Sleep mode Pull-up/down Register 0x0 */
};
#define r_gpio_g ((volatile struct gpio_g_reg_map *)0x7F0080C0)
/*====================================================================================================================*/
/* [0x7F0080E0 ~ 0x7F0080F4] GPIO H: 6 members */
/*--------------------------------------------------------------------------------------------------------------------*/
struct gpio_h_reg_map {
    __IO uint32_t GPHCON0; /* 0x7F0080E0: Port H Configuration Register 0x0 */
    __IO uint32_t GPHCON1; /* 0x7F0080E4: Port H Configuration Register 0x0 */
    __IO uint32_t GPHDAT; /* 0x7F0080E8: Port H Data Register Undefined */
    __IO uint32_t GPHPUD; /* 0x7F0080EC: Port H Pull-up/down Register 0x00055555 */
    __IO uint32_t GPHCONSLP; /* 0x7F0080F0: Port H Sleep mode Configuration Register 0x0 */
    __IO uint32_t GPHPUDSLP; /* 0x7F0080F4: Port H Sleep mode Pull-up/down Register 0x0 */
};
#define r_gpio_h ((volatile struct gpio_h_reg_map *)0x7F0080E0)
/*====================================================================================================================*/
/* [0x7F008100 ~ 0x7F008110] GPIO I: 5 members */
/*--------------------------------------------------------------------------------------------------------------------*/
struct gpio_i_reg_map {
    __IO uint32_t GPICON; /* 0x7F008100: Port I Configuration Register 0x0 */
    __IO uint32_t GPIDAT; /* 0x7F008104: Port I Data Register Undefined */
    __IO uint32_t GPIPUD; /* 0x7F008108: Port I Pull-up/down Register 0x55555555 */
    __IO uint32_t GPICONSLP; /* 0x7F00810C: Port I Sleep mode Configuration Register 0x0 */
    __IO uint32_t GPIPUDSLP; /* 0x7F008110: Port I Sleep mode Pull-up/down Register 0x0 */
};
#define r_gpio_i ((volatile struct gpio_i_reg_map *)0x7F008100)
/*====================================================================================================================*/
/* [0x7F008120 ~ 0x7F008130] GPIO J: 5 members */
/*--------------------------------------------------------------------------------------------------------------------*/
struct gpio_j_reg_map {
    __IO uint32_t GPJCON; /* 0x7F008120: Port J Configuration Register 0x0 */
    __IO uint32_t GPJDAT; /* 0x7F008124: Port J Data Register Undefined */
    __IO uint32_t GPJPUD; /* 0x7F008128: Port J Pull-up/down Register 0x00555555 */
    __IO uint32_t GPJCONSLP; /* 0x7F00812C: Port J Sleep mode Configuration Register 0x0 */
    __IO uint32_t GPJPUDSLP; /* 0x7F008130: Port J Sleep mode Pull-up/down Register 0x0 */
};
#define r_gpio_j ((volatile struct gpio_j_reg_map *)0x7F008120)
/*====================================================================================================================*/
/* [0x7F008140 ~ 0x7F008150] GPIO O: 5 members */
/*--------------------------------------------------------------------------------------------------------------------*/
struct gpio_o_reg_map {
    __IO uint32_t GPOCON; /* 0x7F008140: Port O Configuration Register 0xAAAAAAAA */
    __IO uint32_t GPODAT; /* 0x7F008144: Port O Data Register Undefined */
    __IO uint32_t GPOPUD; /* 0x7F008148: Port O Pull-up/down Register 0x0 */
    __IO uint32_t GPOCONSLP; /* 0x7F00814C: Port O Sleep mode Configuration Register 0x0 */
    __IO uint32_t GPOPUDSLP; /* 0x7F008150: Port O Sleep mode Pull-up/down Register 0x0 */
};
#define r_gpio_o ((volatile struct gpio_o_reg_map *)0x7F008140)
/*====================================================================================================================*/
/* [0x7F008160 ~ 0x7F008170] GPIO P: 5 members */
/*--------------------------------------------------------------------------------------------------------------------*/
struct gpio_p_reg_map {
    __IO uint32_t GPPCON; /* 0x7F008160: Port P Configuration Register 0x2AAAAAAA */
    __IO uint32_t GPPDAT; /* 0x7F008164: Port P Data Register Undefined */
    __IO uint32_t GPPPUD; /* 0x7F008168: Port P Pull-up/down Register 0x1011AAA0 */
    __IO uint32_t GPPCONSLP; /* 0x7F00816C: Port P Sleep mode Configuration Register 0x0 */
    __IO uint32_t GPPPUDSLP; /* 0x7F008170: Port P Sleep mode Pull-up/down Register 0x0 */
};
#define r_gpio_p ((volatile struct gpio_p_reg_map *)0x7F008160)
/*====================================================================================================================*/
/* [0x7F008180 ~ 0x7F008190] GPIO Q: 5 members */
/*--------------------------------------------------------------------------------------------------------------------*/
struct gpio_q_reg_map {
    __IO uint32_t GPQCON; /* 0x7F008180: Port Q Configuration Register 0x0002AAAA */
    __IO uint32_t GPQDAT; /* 0x7F008184: Port Q Data Register Undefined */
    __IO uint32_t GPQPUD; /* 0x7F008188: Port Q Pull-up/down Register 0x0 */
    __IO uint32_t GPQCONSLP; /* 0x7F00818C: Port Q Sleep mode Configuration Register 0x0 */
    __IO uint32_t GPQPUDSLP; /* 0x7F008190: Port Q Sleep mode Pull-up/down Register 0x0 */
};
#define r_gpio_q ((volatile struct gpio_q_reg_map *)0x7F008180)
/*====================================================================================================================*/
/* [0x7F0081A0 ~ 0x7F0081A0] Special Port Configuration: 1 members */
/*--------------------------------------------------------------------------------------------------------------------*/
struct special_port_configuration_reg_map {
    __IO uint32_t SPCON; /* 0x7F0081A0: Special Port Configuration Register 0xBFC11500 */
};
#define r_special_port_configuration ((volatile struct special_port_configuration_reg_map *)0x7F0081A0)
/*====================================================================================================================*/
/* [0x7F0081C0 ~ 0x7F0081D4] Memory Port: 6 members */
/*--------------------------------------------------------------------------------------------------------------------*/
struct memory_port_reg_map {
    __IO uint32_t MEM0CONSLP0; /* 0x7F0081C0: Memory Port 0 Sleep mode configure 0 0x0 */
    __IO uint32_t MEM0CONSLP1; /* 0x7F0081C4: Memory Port 0 Sleep mode configure 1 0x0 */
    __IO uint32_t MEM1CONSLP; /* 0x7F0081C8: Memory Port 1 Sleep mode configure 0x0 */
    __I uint32_t RESERVED; /* 0x7F0081CC: RESERVED - */
    __IO uint32_t MEM0DRVCON; /* 0x7F0081D0: Memory Port 0 Drive strength Control Register 0x10555551 */
    __IO uint32_t MEM1DRVCON; /* 0x7F0081D4: Memory Port 0 Drive strength Control Register 0x555555 */
};
#define r_memory_port ((volatile struct memory_port_reg_map *)0x7F0081C0)
/*====================================================================================================================*/
/* [0x7F008200 ~ 0x7F008270] External Interrupt 1 To 9: 21 members */
/*--------------------------------------------------------------------------------------------------------------------*/
struct external_interrupt_1_to_9_reg_map {
    __IO uint32_t EINT12CON; /* 0x7F008200: External Interrupt 1,2 Configuration Register 0x0 */
    __IO uint32_t EINT34CON; /* 0x7F008204: External Interrupt 3,4 Configuration Register 0x0 */
    __IO uint32_t EINT56CON; /* 0x7F008208: External Interrupt 5,6 Configuration Register 0x0 */
    __IO uint32_t EINT78CON; /* 0x7F00820C: External Interrupt 7,8 Configuration Register 0x0 */
    __IO uint32_t EINT9CON; /* 0x7F008210: External Interrupt 9 Configuration Register 0x0 */
    __I uint32_t RESERVED_0[3]; /* 0x7F008214 ~ 0x7F00821C: RESERVED - */
    __IO uint32_t EINT12FLTCON; /* 0x7F008220: External Interrupt 1,2 Filter Control Register 0x0 */
    __IO uint32_t EINT34FLTCON; /* 0x7F008224: External Interrupt 3,4 Filter Control Register 0x0 */
    __IO uint32_t EINT56FLTCON; /* 0x7F008228: External Interrupt 5,6 Filter Control Register 0x0 */
    __IO uint32_t EINT78FLTCON; /* 0x7F00822C: External Interrupt 7,8 Filter Control Register 0x0 */
    __IO uint32_t EINT9FLTCON; /* 0x7F008230: External Interrupt 9 Filter Control Register 0x0 */
    __I uint32_t RESERVED_1[3]; /* 0x7F008234 ~ 0x7F00823C: RESERVED - */
    __IO uint32_t EINT12MASK; /* 0x7F008240: External Interrupt 1,2 Mask Register 0x00FF7FFF */
    __IO uint32_t EINT34MASK; /* 0x7F008244: External Interrupt 3,4 Mask Register 0x3FFF03FF */
    __IO uint32_t EINT56MASK; /* 0x7F008248: External Interrupt 5,6 Mask Register 0x03FF007F */
    __IO uint32_t EINT78MASK; /* 0x7F00824C: External Interrupt 7,8 Mask Register 0x7FFFFFFF */
    __IO uint32_t EINT9MASK; /* 0x7F008250: External Interrupt 9 Mask Register 0x000001FF */
    __I uint32_t RESERVED_2[3]; /* 0x7F008254 ~ 0x7F00825C: RESERVED - */
    __IO uint32_t EINT12PEND; /* 0x7F008260: External Interrupt 1,2 Pending Register 0x0 */
    __IO uint32_t EINT34PEND; /* 0x7F008264: External Interrupt 3,4 Pending Register 0x0 */
    __IO uint32_t EINT56PEND; /* 0x7F008268: External Interrupt 5,6 Pending Register 0x0 */
    __IO uint32_t EINT78PEND; /* 0x7F00826C: External Interrupt 7,8 Pending Register 0x0 */
    __IO uint32_t EINT9PEND; /* 0x7F008270: External Interrupt 9 Pending Register 0x0 */
};
#define r_external_interrupt_1_to_9 ((volatile struct external_interrupt_1_to_9_reg_map *)0x7F008200)
/*====================================================================================================================*/
/* [0x7F008280 ~ 0x7F008288] External Interrupt common: 3 members */
/*--------------------------------------------------------------------------------------------------------------------*/
struct external_interrupt_common_reg_map {
    __IO uint32_t PRIORITY; /* 0x7F008280: Priority Control Register 0x000003FF */
    __I uint32_t SERVICE; /* 0x7F008284: Current Service Register 0x0 */
    __I uint32_t SERVICEPEND; /* 0x7F008288: Current Service Pending Register 0x0 */
};
#define r_external_interrupt_common ((volatile struct external_interrupt_common_reg_map *)0x7F008280)
/*====================================================================================================================*/
/* [0x7F008800 ~ 0x7F00880C] GPIO K: 4 members */
/*--------------------------------------------------------------------------------------------------------------------*/
struct gpio_k_reg_map {
    __IO uint32_t GPKCON0; /* 0x7F008800: Port K Configuration Register 0 0x22222222 */
    __IO uint32_t GPKCON1; /* 0x7F008804: Port K Configuration Register 1 0x22222222 */
    __IO uint32_t GPKDAT; /* 0x7F008808: Port K Data Register Undefined */
    __IO uint32_t GPKPUD; /* 0x7F00880C: Port K Pull-up/down Register 0x55555555 */
};
#define r_gpio_k ((volatile struct gpio_k_reg_map *)0x7F008800)
/*====================================================================================================================*/
/* [0x7F008810 ~ 0x7F00881C] GPIO L: 4 members */
/*--------------------------------------------------------------------------------------------------------------------*/
struct gpio_l_reg_map {
    __IO uint32_t GPLCON0; /* 0x7F008810: Port L Configuration Register 0x22222222 */
    __IO uint32_t GPLCON1; /* 0x7F008814: Port L Configuration Register 0x02222222 */
    __IO uint32_t GPLDAT; /* 0x7F008818: Port L Data Register Undefined */
    __IO uint32_t GPLPUD; /* 0x7F00881C: Port L Pull-up/down Register 0x15555555 */
};
#define r_gpio_l ((volatile struct gpio_l_reg_map *)0x7F008810)
/*====================================================================================================================*/
/* [0x7F008820 ~ 0x7F008828] GPIO M: 3 members */
/*--------------------------------------------------------------------------------------------------------------------*/
struct gpio_m_reg_map {
    __IO uint32_t GPMCON; /* 0x7F008820: Port M Configuration Register 0x00222222 */
    __IO uint32_t GPMDAT; /* 0x7F008824: Port M Data Register Undefined */
    __IO uint32_t GPMPUD; /* 0x7F008828: Port M Pull-up/down Register 0x000002AA */
};
#define r_gpio_m ((volatile struct gpio_m_reg_map *)0x7F008820)
/*====================================================================================================================*/
/* [0x7F008830 ~ 0x7F008838] GPIO N: 3 members */
/*--------------------------------------------------------------------------------------------------------------------*/
struct gpio_n_reg_map {
    __IO uint32_t GPNCON; /* 0x7F008830: Port N Configuration Register 0x0 */
    __IO uint32_t GPNDAT; /* 0x7F008834: Port N Data Register Undefined */
    __IO uint32_t GPNPUD; /* 0x7F008838: Port N Pull-up/down Register 0x55555555 */
};
#define r_gpio_n ((volatile struct gpio_n_reg_map *)0x7F008830)
/*====================================================================================================================*/
/* [0x7F008880 ~ 0x7F008880] Special Port Sleep mode configure: 1 members */
/*--------------------------------------------------------------------------------------------------------------------*/
struct special_port_sleep_mode_configure_reg_map {
    __IO uint32_t SPCONSLP; /* 0x7F008880: Special Port Sleep mode configure Register 0x00000010 */
};
#define r_special_port_sleep_mode_configure ((volatile struct special_port_sleep_mode_configure_reg_map *)0x7F008880)
/*====================================================================================================================*/
/* [0x7F008900 ~ 0x7F008924] External Interrupt 0: 9 members */
/*--------------------------------------------------------------------------------------------------------------------*/
struct external_interrupt_0_reg_map {
    __IO uint32_t EINT0CON0; /* 0x7F008900: External Interrupt configuration Register 0 0x0 */
    __IO uint32_t EINT0CON1; /* 0x7F008904: External Interrupt configuration Register 1 0x0 */
    __I uint32_t RESERVED[2]; /* 0x7F008908 ~ 0x7F00890C: RESERVED - */
    __IO uint32_t EINT0FLTCON0; /* 0x7F008910: External Interrupt Filter Control Register 0 0x0 */
    __IO uint32_t EINT0FLTCON1; /* 0x7F008914: External Interrupt Filter Control Register 1 0x0 */
    __IO uint32_t EINT0FLTCON2; /* 0x7F008918: External Interrupt Filter Control Register 2 0x0 */
    __IO uint32_t EINTF0LTCON3; /* 0x7F00891C: External Interrupt Filter Control Register 3 0x0 */
    __IO uint32_t EINT0MASK; /* 0x7F008920: External Interrupt Mask Register 0x0FFFFFFF */
    __IO uint32_t EINT0PEND; /* 0x7F008924: External Interrupt Pending Register 0x0 */
};
#define r_external_interrupt_0 ((volatile struct external_interrupt_0_reg_map *)0x7F008900)
/*====================================================================================================================*/
/* [0x7F008930 ~ 0x7F008930] Sleep Mode Pad Configure: 1 members */
/*--------------------------------------------------------------------------------------------------------------------*/
struct sleep_mode_pad_configure_reg_map {
    __IO uint32_t SLPEN; /* 0x7F008930: Sleep Mode Pad Configure Register 0x0 */
};
#define r_sleep_mode_pad_configure ((volatile struct sleep_mode_pad_configure_reg_map *)0x7F008930)
#endif /* _REGMAP_H_ */