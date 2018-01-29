/*
 * start.S
 *
 *  Created on: Nov 10, 2017
 *      Author: zhanlei
 */

	.global reset

reset:
	/* set the cpu to SVC32 mode */
	mrs	r0, cpsr
	bic	r0, r0, #0x3f
	orr	r0, r0, #0xd3
	msr	cpsr, r0
	/* init sequence */
	bl __disable_watch_dog
	bl __disable_all_soft_interrupt
	bl __init_system_clock
	bl __init_ddr2_sdram
	bl __enable_vfp
	bl __clear_bss
	bl __init_stack
	/* step into C code */
	bl main

#define WTCON	0x7E004000
__disable_watch_dog:
	ldr r0, =WTCON
	mov r1, #0
	/* disable wdt timer, disable interrupt generation, disable reset */
	str r1, [r0]
	mov pc, lr

#define VIC0_BASE	0x71200000
#define VIC1_BASE	0x71300000

#define VIC_SELECT_OFFSET	0x10
#define VIC_CLEAR_OFFSET	0x14
#define VIC_ADDR_OFFSET		0xF00
__disable_all_soft_interrupt:
	ldr r0, =VIC0_BASE
	ldr r1, =VIC1_BASE

	mov r2, #0xFFFFFFFF
	/* disable soft interrupt */
	str r2, [r0, #VIC_CLEAR_OFFSET]
	str r2, [r1, #VIC_CLEAR_OFFSET]

	mov r2, #0x0
	/* set all interrupts as IRQ */
	str r2, [r0, #VIC_SELECT_OFFSET]
	str r2, [r1, #VIC_SELECT_OFFSET]

	/* clear interrupt vector address */
	str r2, [r0, #VIC_ADDR_OFFSET]
	str r2, [r1, #VIC_ADDR_OFFSET]
	mov pc, lr

#define SYS_CLK_BASE				0x7E00F000
#define SYS_CLK_APLL_LOCK_OFFSET	0x0
#define SYS_CLK_MPLL_LOCK_OFFSET	0x4
#define SYS_CLK_EPLL_LOCK_OFFSET	0x8
#define SYS_CLK_APLL_CON_OFFSET		0xC
#define SYS_CLK_MPLL_CON_OFFSET		0x10
#define SYS_CLK_EPLL_CON0_OFFSET	0x14
#define SYS_CLK_EPLL_CON1_OFFSET	0x18
#define SYS_CLK_CLK_SRC_OFFSET		0x1C
#define SYS_CLK_DIV0_OFFSET			0x20
#define SYS_CLK_HCLK_GATE_OFFSER	0x30
#define SYS_CLK_OTHERS_OFFSET		0x900

#define SYS_CLK_OSC_FREQ			12000000
/* APLL == 533 MHz */
#define SYS_CLK_APLL_MDIV			266
#define SYS_CLK_APLL_PDIV			3
#define SYS_CLK_APLL_SDIV			1
#define SYS_CLK_APLL_FREQ			(SYS_CLK_OSC_FREQ / (SYS_CLK_APLL_PDIV << SYS_CLK_APLL_SDIV) * SYS_CLK_APLL_MDIV)
/* MPLL == 533 MHZ */
#define SYS_CLK_MPLL_MDIV			266
#define SYS_CLK_MPLL_PDIV			3
#define SYS_CLK_MPLL_SDIV			1
#define SYS_CLK_MPLL_FREQ			(SYS_CLK_OSC_FREQ / (SYS_CLK_MPLL_PDIV << SYS_CLK_MPLL_SDIV) * SYS_CLK_MPLL_MDIV)
/* EPLL == 96 MHz */
#define SYS_CLK_EPLL_MDIV			32
#define SYS_CLK_EPLL_PDIV			1
#define SYS_CLK_EPLL_SDIV			2
#define SYS_CLK_EPLL_KDIV			0
#define SYS_CLK_EPLL_FREQ			(SYS_CLK_OSC_FREQ / (SYS_CLK_EPLL_PDIV << SYS_CLK_EPLL_SDIV) * (SYS_CLK_EPLL_MDIV + (SYS_CLK_EPLL_KDIV << 16)))
/* ARMCLK = 533 MHz */
#define SYS_CLK_ARM_DIV				0
#define SYS_CLK_ARMCLK_FREQ			(SYS_CLK_APLL_FREQ / (1 + SYS_CLK_ARM_DIV))
/* HCLKX2 = 533 MHz / (1 + 1) = 266 MHz*/
#define SYS_CLK_HCLKX2_DIV			1
#define SYS_CLK_HCLKX2_FREQ			(SYS_CLK_APLL_FREQ / (1 + SYS_CLK_HCLKX2_DIV))
/* HCLK = 266 MHz / (1 + 1) = 133 MHz */
#define SYS_CLK_HCLK_DIV			1
#define SYS_CLK_HCLK_FREQ			(SYS_CLK_HCLKX2_FREQ / (1 + SYS_CLK_HCLK_DIV))
/* PCLK = 266 MHz / (3 + 1) = 66 MHz */
#define	SYS_CLK_PCLK_DIV			3
#define SYS_CLK_PCLK_FREQ			(SYS_CLK_HCLKX2_FREQ / (1 + SYS_CLK_PCLK_DIV))
/* DOUT MPLL = 533 MHz / (1 + 1) = 266 MHz */
#define SYS_CLK_MPLL_DIV			1

#define SYS_CLK_DIV0_INIT_VAL		(SYS_CLK_ARM_DIV | (SYS_CLK_MPLL_DIV << 4) | (SYS_CLK_HCLK_DIV << 8) | (SYS_CLK_HCLKX2_DIV << 9) | (SYS_CLK_PCLK_DIV << 12) | (1 << 31))
#define SYS_CLK_APLL_CON_VAL		(SYS_CLK_APLL_SDIV | (SYS_CLK_APLL_PDIV << 8) | (SYS_CLK_APLL_MDIV << 16) | (1 << 31))
#define SYS_CLK_MPLL_CON_VAL		(SYS_CLK_MPLL_SDIV | (SYS_CLK_MPLL_PDIV << 8) | (SYS_CLK_MPLL_MDIV << 16) | (1 << 31))
#define SYS_CLK_EPLL_CON0_VAL		(SYS_CLK_EPLL_SDIV | (SYS_CLK_EPLL_PDIV << 8) | (SYS_CLK_EPLL_MDIV << 16) | (1 << 31))
#define SYS_CLK_EPLL_CON1_VAL		(SYS_CLK_EPLL_KDIV)


__init_system_clock:
	ldr r0, =SYS_CLK_BASE
	/* select all clock to FIN */
	ldr r1, [r0, #SYS_CLK_CLK_SRC_OFFSET]
	bic r1, r1, #0x3
	str r1, [r0, #SYS_CLK_CLK_SRC_OFFSET]
	/*
	reset lock value for all PLLs, APLL_LOCK, MPLL_LOCK, and EPLL_LOCK fields denote the number of external clock
	User can adjust this fields, which must be larger than maximum lock time (A/MPLL is 300us, EPLL is 300us)
	=============================================
	PLL | Max. LockTime(us) | PLL_LOCK(FIN:12MHz)
	----+-------------------+--------------------
	APLL| 300               | 0xE11
	MPLL| 300               | 0xE11
	EPLL| 300               | 0xE11
	=============================================
	*/
	ldr r1, =0xFFFF
	str	r1, [r0, #SYS_CLK_APLL_LOCK_OFFSET]
	str	r1, [r0, #SYS_CLK_MPLL_LOCK_OFFSET]
	str	r1, [r0, #SYS_CLK_EPLL_LOCK_OFFSET]

	/* set clock divider [0] */
	ldr r1, [r0, #SYS_CLK_DIV0_OFFSET]
	ldr r2, =0x3ffff
	bic r1, r1, r2
	str r1, [r0, #SYS_CLK_DIV0_OFFSET]
	ldr r2, =SYS_CLK_DIV0_INIT_VAL
	orr r1, r1, r2
	str r1, [r0, #SYS_CLK_DIV0_OFFSET]
	/*
	APLL / MPLL
	===================================================
	FIN (MHz) | Target FOUT (MHz) | MDIV | PDIV | SDIV
	----------+-------------------+------+------+------
	12        | 100               | 400  | 3    | 4
	12        | 200               | 400  | 3    | 3
	12        | 266               | 266  | 3    | 2
	12        | 400               | 400  | 3    | 2
	12        | 533               | 266  | 3    | 1
	12        | 667               | 333  | 3    | 1
	===================================================

	EPLL
	====================================================
	FIN (MHz) |  FOUT (MHz) | MDIV | PDIV | SDIV | KDIV
	----------+-------------+------+------+------+------
	12        |  36         | 48   | 1    | 4    | 0
	12        |  48         | 32   | 1    | 3    | 0
	12        |  60         | 40   | 1    | 3    | 0
	12        |  72         | 48   | 1    | 3    | 0
	12        |  84         | 28   | 1    | 2    | 0
	12        |  96         | 32   | 1    | 2    | 0
	12        |  32.768     | 43   | 1    | 4    | 45264
	12        |  45.158     | 30   | 1    | 3    | 6903
	12        |  49.152     | 32   | 1    | 3    | 50332
	12        |  67.738     | 45   | 1    | 3    | 10398
	12        |  73.728     | 49   | 1    | 3    | 9961
	====================================================
	*/
	/* set APLL */
	ldr r1, =SYS_CLK_APLL_CON_VAL
	str r1, [r0, #SYS_CLK_APLL_CON_OFFSET]
	/* set MPLL */
	ldr r1, =SYS_CLK_MPLL_CON_VAL
	str r1, [r0, #SYS_CLK_MPLL_CON_OFFSET]
	/* set EPLL */
	ldr r1, =SYS_CLK_EPLL_CON0_VAL
	str r1, [r0, #SYS_CLK_EPLL_CON0_OFFSET]
	ldr r1, =SYS_CLK_EPLL_CON1_VAL
	str r1, [r0, #SYS_CLK_EPLL_CON1_VAL]

	/* wait PLL output stable clock, it needs 0xffff numbers of external clock */
	mov r1, #0x10000
1:
	subs r1, r1, #1
	bne 1b

	/* select all clock to FOUT */
	ldr r1, [r0, #SYS_CLK_CLK_SRC_OFFSET]
	orr r1, r1, #0x3
	str r1, [r0, #SYS_CLK_CLK_SRC_OFFSET]

	/* synchronous mode init */
	ldr r0, =SYS_CLK_BASE
	ldr r1, [r0, #SYS_CLK_OTHERS_OFFSET]
	mov r2, #0x40
	orr r1, r1, r2
	/*  SYS CLOCK SELECT IN CMU: DOUT APLL */
	str r1, [r0, #SYS_CLK_OTHERS_OFFSET]
	nop
	nop
	nop
	nop
	nop
	mov r2, #0x80
	orr r1, r1, r2
	/* set synchronous mode */
	str r1, [r0, #SYS_CLK_OTHERS_OFFSET]

	/* while ((SYS_CLK_OTHERS & 0xf00) != 0xf00) */
__loop_check_sync_ack:
	ldr r1, [r0, #SYS_CLK_OTHERS_OFFSET]
	mov r2, #0xF00
	and r1, r1, r2
	cmp r1, #0xF00
	bne __loop_check_sync_ack
	mov pc, lr

#define SYS_MEM_CLK					SYS_CLK_HCLK_FREQ
#define SYS_MEM_CFG					0x7E00F120
#define SYS_MEM_DRAM_BASE			0x7E001000
#define SYS_MEM_P1MEMSTAT_OFFSET	0x0
#define SYS_MEM_P1MEMCCMD_OFFSET	0x4
#define SYS_MEM_P1DIRECTCMD_OFFSET	0x8
#define SYS_MEM_P1MEMCFG_OFFSET		0xC
#define SYS_MEM_P1REFRESH_OFFSET	0x10
#define SYS_MEM_P1CASLAT_OFFSET		0x14
#define SYS_MEM_P1T_DQSS_OFFSET		0x18
#define SYS_MEM_P1T_MRD_OFFSET		0x1C
#define SYS_MEM_P1T_RAS_OFFSET		0x20
#define SYS_MEM_P1T_RC_OFFSET		0x24
#define SYS_MEM_P1T_RCD_OFFSET		0x28
#define SYS_MEM_P1T_RFC_OFFSET		0x2C
#define SYS_MEM_P1T_RP_OFFSET		0x30
#define SYS_MEM_P1T_RRD_OFFSET		0x34
#define SYS_MEM_P1T_WR_OFFSET		0x38
#define SYS_MEM_P1T_WTR_OFFSET		0x3C
#define SYS_MEM_P1T_XP_OFFSET		0x40
#define SYS_MEM_P1T_XSR_OFFSET		0x44
#define SYS_MEM_P1T_ESR_OFFSET		0x48
#define SYS_MEM_P1MEMCFG2_OFFSET 	0x4C
#define SYS_MEM_P1_CHIP0_CFG_OFFSET	0x200
#define SYS_MEM_P1_USER_CFG_OFFSET	0x304
#define SYS_MEM_GET_TIME_COUNT(time)		((SYS_MEM_CLK / 1000 * (time) - 1) / 1000000 + 1)

/* DDR Parameters for K4X1G163PC - L(F)E/G 64Mx16 Mobile DDR SDRAM */
#define DDR_tREFRESH		7800		/* ns (max: 64ms)*/
#define DDR_tRAS			45			/* ns (min: 45ns) */
#define DDR_tRC 			68			/* ns (min: 67.5ns) */
#define DDR_tRCD			23			/* ns (min: 22.5ns) */
#define DDR_tRFC			80			/* ns (min: 80ns) */
#define DDR_tRP 			23			/* ns (min: 22.5ns) */
#define DDR_tRRD			15			/* ns (min: 15ns) */
#define DDR_tWR 			15			/* ns (min: 15ns) */
#define DDR_tXSR			120			/* ns (min: 120ns) */
#define DDR_CASL			3			/* CAS Latency 3 */
#define DDR_tDQSS			1			/* 0.75 ~ 1.25 tCK */
#define DDR_tMRD			2			/* min: 2 tCK */
#define DDR_tWTR			2			/* 2 tCK, this parameter is not defined in datasheet */
#define DDR_tPDEX			2			/* min: 1 tCK */
#define DDR_tESR			DDR_tXSR	/* this parameter is not defined in datasheet */
/*
• Set ‘Memc_cmd' field in P1MEMCCMD to ‘3’b100’, which makes DRAM Controller enter ‘Config’ state.
• Write memory timing parameter, chip configuration, and id configuration registers.
• Wait 200us to allow SDRAM power and clock to stabilize. However, when CPU starts working, power and clock would already be stabilized.
• Execute memory initialization sequence.(refer to 5.4.2)
• Set ‘Memc_cmd' field in P1MEMCCMD to ‘3’b000’, which makes DRAM Controller enter ‘Ready’ state.
• Check ‘Controller status’ field in P1MEMSTAT until memory status becomes ‘2’b01’, which means ‘Ready’.

• Set ‘Memory command’ field in P1DIRECTCMD to ‘2’b11’, which makes DRAM Controller issue ‘NOP’ memory command.
• Set ‘Memory command’ field in P1DIRECTCMD to ‘2’b00’, which makes DRAM Controller issue ‘PrechargeAll’ memory command.
• Set ‘Memory command’ field in P1DIRECTCMD to ‘2’b01’, which makes DRAM Controller issue ‘Autorefresh’ memory command.
• Set ‘Memory command’ field in P1DIRECTCMD to ‘2’b01’, which makes DRAM Controller issue ‘Autorefresh’ memory command.
• Set ‘Memory command’ field in P1DIRECTCMD to ‘2’b10’, which makes DRAM Controller issue ‘MRS’ memory command.
      - Initialize the Mode Register
• Set ‘Memory command’ field in P1DIRECTCMD to ‘2’b10’, which makes DRAM Controller issue ‘EMRS’ memory command.
      - Define PASR or DS operating type of the device
*/
__init_ddr2_sdram:
	ldr r0, =SYS_CLK_BASE
	/* Gating HCLK for SDMA0 (0: mask, 1: pass) */
	ldr r1, [r0, #SYS_CLK_HCLK_GATE_OFFSER]
	orr r1, r1, #(1 << 26)
	str r1, [r0, #SYS_CLK_HCLK_GATE_OFFSER]
	/* clear SYS_MEM_CFG[7] to make Xm1DATA[26:16] pins are used for DMC1 upper halfword data field, data[26:16]. */
	ldr r0, =SYS_MEM_CFG
	mov r1, #0x0
	str r1, [r0]

	/* enter configuration mode */
	ldr r0, =SYS_MEM_DRAM_BASE
	mov r1, #0x4
	str r1, [r0, #SYS_MEM_P1MEMCCMD_OFFSET]

	ldr r1, =SYS_MEM_GET_TIME_COUNT(DDR_tREFRESH)
	str r1, [r0, #SYS_MEM_P1REFRESH_OFFSET]

	ldr r1, =(DDR_CASL << 1)
	str r1, [r0, #SYS_MEM_P1CASLAT_OFFSET]

	ldr r1, =DDR_tDQSS
	str r1, [r0, #SYS_MEM_P1T_DQSS_OFFSET]

	ldr r1, =DDR_tMRD
	str r1, [r0, #SYS_MEM_P1T_MRD_OFFSET]

	ldr r1, =SYS_MEM_GET_TIME_COUNT(DDR_tRAS)
	str r1, [r0, #SYS_MEM_P1T_RAS_OFFSET]

	ldr r1, =SYS_MEM_GET_TIME_COUNT(DDR_tRC)
	str r1, [r0, #SYS_MEM_P1T_RC_OFFSET]

	ldr r1, =SYS_MEM_GET_TIME_COUNT(DDR_tRCD) | ((SYS_MEM_GET_TIME_COUNT(DDR_tRCD) - 3) << 3)
	str r1, [r0, #SYS_MEM_P1T_RCD_OFFSET]

	ldr r1, =SYS_MEM_GET_TIME_COUNT(DDR_tRFC) | ((SYS_MEM_GET_TIME_COUNT(DDR_tRFC) - 3) << 5)
	str r1, [r0, #SYS_MEM_P1T_RFC_OFFSET]

	ldr r1, =SYS_MEM_GET_TIME_COUNT(DDR_tRP) | ((SYS_MEM_GET_TIME_COUNT(DDR_tRP) - 3) << 3)
	str r1, [r0, #SYS_MEM_P1T_RP_OFFSET]

	ldr r1, =SYS_MEM_GET_TIME_COUNT(DDR_tRRD)
	str r1, [r0, #SYS_MEM_P1T_RRD_OFFSET]

	ldr r1, =SYS_MEM_GET_TIME_COUNT(DDR_tWR)
	str r1, [r0, #SYS_MEM_P1T_WR_OFFSET]

	ldr r1, =DDR_tWTR
	str r1, [r0, #SYS_MEM_P1T_WTR_OFFSET]

	ldr r1, =DDR_tPDEX
	str r1, [r0, #SYS_MEM_P1T_XP_OFFSET]

	ldr r1, =SYS_MEM_GET_TIME_COUNT(DDR_tXSR)
	str r1, [r0, #SYS_MEM_P1T_XSR_OFFSET]

	ldr r1, =SYS_MEM_GET_TIME_COUNT(DDR_tESR)
	str r1, [r0, #SYS_MEM_P1T_ESR_OFFSET]

	/* Supports one CKE control, Chip1, Burst4, Row(14bit), Column(10bit)*/
	ldr r1, =0x0001001A
	str r1, [r0, #SYS_MEM_P1MEMCFG_OFFSET]

	/* Read delay 1 cycle, Mobile DDR SDRAM, 32-bit, set dqm to outputs high after reset, aclk and mclk are synchronous */
	ldr r1, =((1 << 11) | (3 << 8) | (1 << 6) | (1 << 2) | 1)
	str r1, [r0, #SYS_MEM_P1MEMCFG2_OFFSET]

	/*
	Bank-Row-Column organization, why set Address match = 0x50 and Address mask = 0xF0 for 256M DDRAM?
	Address match | [15:8] | Comparison value for AXI address bits [31:24] to determine which chip is selected. | 0xFF
	Address mask  | [7:0]  | The mask for AXI address bits [31:24] to determine which chip is selected:         | 0x00
	              |        | 1 = corresponding address bit is to be used for comparison
	*/
	ldr r1, =0x150F0
	str r1, [r0, #SYS_MEM_P1_CHIP0_CFG_OFFSET]

	mov r1, #0
	str r1, [r0, #SYS_MEM_P1_USER_CFG_OFFSET]

	ldr r1, =(3 << 18)
	str r1, [r0, #SYS_MEM_P1DIRECTCMD_OFFSET]

	mov r1, #0
	str r1, [r0, #SYS_MEM_P1DIRECTCMD_OFFSET]

	ldr r1, =(1 << 18)
	str r1, [r0, #SYS_MEM_P1DIRECTCMD_OFFSET]
	str r1, [r0, #SYS_MEM_P1DIRECTCMD_OFFSET]

	ldr r1, =(2 << 18) | (3 << 4) | 2
	str r1, [r0, #SYS_MEM_P1DIRECTCMD_OFFSET]

	ldr r1, =(2 << 18) | (2 << 16)
	str r1, [r0, #SYS_MEM_P1DIRECTCMD_OFFSET]

	/* start DMC1 */
	mov r1, #0
	str r1, [r0, #SYS_MEM_P1MEMCCMD_OFFSET]

__loop_check_dmc1_ready:
	ldr	r1, [r0, #SYS_MEM_P1MEMSTAT_OFFSET]
	mov	r2, #0x3
	and	r1, r1, r2
	cmp	r1, #0x1
	bne	__loop_check_dmc1_ready
	nop

	mov r0, #0x50000000
	ldr r1, =0x12345678
	str r1, [r0]
	mov r1, #0
	ldr r1, [r0]

	mov pc, lr


__clear_bss:
	ldr r0, _bss_start
	ldr r1, _bss_end
	mov r2, #0
1:
	str r2, [r0], #4
	cmp r0, r1
	bne 1b
	mov pc, lr

__init_stack:
	ldr sp, =0x5fffffff
	mov pc, lr

#define VFP_ENABLE	0x40000000
__enable_vfp:
	mrc p15, 0, r0, c1, c0, 2
	orr r0, r0, #0x00F00000
	mcr p15, 0, r0, c1, c0, 2

	mov r1, #0
	mcr p15, 0, r1, c7, c5, 4
	mov r0, #VFP_ENABLE
	fmxr fpexc, r0
	nop
	nop
	bx lr

.globl _bss_start
_bss_start:
	.word __bss_start

.globl _bss_end
_bss_end:
	.word __bss_end
