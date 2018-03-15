/*
 * irom.s
 *
 *  Created on: Mar 2, 2018
 *      Author: zhanlei
 */


#if 0
	int32_t nand_read_page_adv(uint32_t block, uint32_t page, uint8_t *buf)
	{
		uint8_t *tmp_buf;
		uint32_t addr;
		uint32_t r9 = 0;
		uint32_t *gpio_n_cfg_reg = (uint32_t *)0x7f008830u; // Port N Configuration Register
		uint32_t *gpio_n_dat_reg = (uint32_t *)0x7f008834u;
		uint32_t tmp_val;
		page &= 0xff;
		tmp_buf = buf;
		addr = (block << 6) + page;
		tmp_val = *gpio_n_cfg_reg;
		/* set GPN13 GPN14 GPN15 as input mode */
		tmp_val = tmp_val & (~0xfc000000);
		*gpio_n_cfg_reg = tmp_val;
		/* tmp_val = GPN15 GPN14 GPN13 */
		tmp_val = ((*gpio_n_dat_reg) << 16) >> 29;
		switch (tmp_val)
		{
		case 4:
			break;
		case 5:
			break;
		case 6:
			break;
		}
	}
#endif
#if 0
	.global nand_read_page_adv
nand_read_page_adv:
    push    {r4, r5, r6, r7, r8, r9, sl, fp, lr}                       @  f88:  e92d4ff0
    and r1, r1, #255    @ 0xff                                         @  f8c:  e20110ff
    mov r5, r2                                                         @  f90:  e1a05002
    add r6, r1, r0, lsl #6                                             @  f94:  e0816300
    sub sp, sp, #32                                                    @  f98:  e24dd020
    ldr r2, [pc, #564]  @ 0x11d8                                       @  f9c:  e59f2234
    mov r9, #0                                                         @  fa0:  e3a09000
    ldr r3, [r2, #2096] @ 0x830                                        @  fa4:  e5923830
    bic r3, r3, #-67108864  @ 0xfc000000                               @  fa8:  e3c3333f
    str r3, [r2, #2096] @ 0x830                                        @  fac:  e5823830
    ldr r2, [r2, #2100] @ 0x834                                        @  fb0:  e5922834
    lsl r2, r2, #16                                                    @  fb4:  e1a02802
    lsr r2, r2, #29                                                    @  fb8:  e1a02ea2
    cmp r2, #4                                                         @  fbc:  e3520004
    moveq   r8, #4                                                     @  fc0:  03a08004
    beq 1f @ 0xfe8                                                     @  fc4:  0a000007
    cmp r2, #5                                                         @  fc8:  e3520005
    beq 2f @ 0xfe4                                                     @  fcc:  0a000004
    cmp r2, #6                                                         @  fd0:  e3520006
    moveq   r8, #5                                                     @  fd4:  03a08005
    moveq   r7, #4096   @ 0x1000                                       @  fd8:  03a07a01
    addeq   r6, r1, r0, lsl #7                                         @  fdc:  00816380
    beq 3f @ 0xfec                                                          @  fe0:  0a000001
1:
    mov r8, #5                                                         @  fe4:  e3a08005
2:
    mov r7, #2048   @ 0x800                                            @  fe8:  e3a07b02
3:
    ldr r1, [pc, #472]  @ 0x11cc                                       @  fec:  e59f11d8
    ldr r0, [r1]                                                       @  ff0:  e5910000
    ldr r2, [pc, #480]  @ 0x11dc                                       @  ff4:  e59f21e0
    bic r0, r0, #25165824   @ 0x1800000                                @  ff8:  e3c00506
    orr r0, r0, r2                                                     @  ffc:  e1800002
    str r0, [r1]                                                       @ 1000:  e5810000
    ldr r0, [r1, #4]                                                   @ 1004:  e5910004
    bic r0, r0, #262144 @ 0x40000                                      @ 1008:  e3c00701
    orr r0, r0, #65 @ 0x41                                             @ 100c:  e3800041
    str r0, [r1, #4]                                                   @ 1010:  e5810004
    ldr r0, [r1, #40]   @ 0x28                                         @ 1014:  e5910028
    orr r0, r0, #240    @ 0xf0                                         @ 1018:  e38000f0
    str r0, [r1, #40]   @ 0x28                                         @ 101c:  e5810028
    ldr r0, [r1, #4]                                                   @ 1020:  e5910004
    lsr sl, r7, #9                                                     @ 1024:  e1a0a4a7
    orr r0, r0, #128    @ 0x80                                         @ 1028:  e3800080
    str r0, [r1, #4]                                                   @ 102c:  e5810004
    ldr r0, [r1, #4]                                                   @ 1030:  e5910004
    bic r0, r0, #2                                                     @ 1034:  e3c00002
    str r0, [r1, #4]                                                   @ 1038:  e5810004
    ldr r0, [r1, #40]   @ 0x28                                         @ 103c:  e5910028
    orr r0, r0, #16                                                    @ 1040:  e3800010
    str r0, [r1, #40]   @ 0x28                                         @ 1044:  e5810028
    mov r4, #0                                                         @ 1048:  e3a04000
    mov fp, #5                                                         @ 104c:  e3a0b005
    b   _lab_0 @ 0x11a8                                                         @ 1050:  ea000054
_lab_3:
    ldr r1, [pc, #368]  @ 0x11cc                                       @ 1054:  e59f1170
    ldr r0, [r1, #4]                                                   @ 1058:  e5910004
    orr r0, r0, #128    @ 0x80                                         @ 105c:  e3800080
    str r0, [r1, #4]                                                   @ 1060:  e5810004
    ldr r0, [r1, #40]   @ 0x28                                         @ 1064:  e5910028
    orr r0, r0, #16                                                    @ 1068:  e3800010
    str r0, [r1, #40]   @ 0x28                                         @ 106c:  e5810028
    cmp r4, #0                                                         @ 1070:  e3540000
    bne _lab_1 @ 0x10d0                                                         @ 1074:  1a000015
    mov r0, #0                                                         @ 1078:  e3a00000
    str r0, [r1, #8]                                                   @ 107c:  e5810008
    str r0, [r1, #12]                                                  @ 1080:  e581000c
    str r0, [r1, #12]                                                  @ 1084:  e581000c
    and r0, r6, #255    @ 0xff                                         @ 1088:  e20600ff
    str r0, [r1, #12]                                                  @ 108c:  e581000c
    lsl r0, r6, #16                                                    @ 1090:  e1a00806
    lsr r0, r0, #24                                                    @ 1094:  e1a00c20
    str r0, [r1, #12]                                                  @ 1098:  e581000c
    cmp r8, #5                                                         @ 109c:  e3580005
    lsleq   r0, r6, #8                                                 @ 10a0:  01a00406
    lsreq   r0, r0, #24                                                @ 10a4:  01a00c20
    streq   r0, [r1, #12]                                              @ 10a8:  0581000c
    mov r0, #48 @ 0x30                                                 @ 10ac:  e3a00030
    str r0, [r1, #8]                                                   @ 10b0:  e5810008
1:
    ldr r0, [r1, #40]   @ 0x28                                         @ 10b4:  e5910028
    tst r0, #16                                                        @ 10b8:  e3100010
    beq 1b @ 0x10b4                                                         @ 10bc:  0afffffc
    ldr r0, [r1, #40]   @ 0x28                                         @ 10c0:  e5910028
    orr r0, r0, #16                                                    @ 10c4:  e3800010
    str r0, [r1, #40]   @ 0x28                                         @ 10c8:  e5810028
    b   _lab_2 @ 0x10f4                                                         @ 10cc:  ea000008
_lab_1:
    str fp, [r1, #8]                                                   @ 10d0:  e581b008
    mov r2, #0                                                         @ 10d4:  e3a02000
    lsl r0, r4, #9                                                     @ 10d8:  e1a00484
    str r2, [r1, #12]                                                  @ 10dc:  e581200c
    lsl r0, r0, #16                                                    @ 10e0:  e1a00800
    lsr r0, r0, #24                                                    @ 10e4:  e1a00c20
    str r0, [r1, #12]                                                  @ 10e8:  e581000c
    mov r0, #224    @ 0xe0                                             @ 10ec:  e3a000e0
    str r0, [r1, #8]                                                   @ 10f0:  e5810008
_lab_2:
    ldr r0, [r1, #4]                                                   @ 10f4:  e5910004
    bic r0, r0, #128    @ 0x80                                         @ 10f8:  e3c00080
    str r0, [r1, #4]                                                   @ 10fc:  e5810004
    ldr r0, [r1, #4]                                                   @ 1100:  e5910004
    orr r0, r0, #48 @ 0x30                                             @ 1104:  e3800030
    str r0, [r1, #4]                                                   @ 1108:  e5810004
    mov r0, #0                                                         @ 110c:  e3a00000
    mov r2, r1                                                         @ 1110:  e1a02001
1:
    ldrb    r1, [r2, #16]                                              @ 1114:  e5d21010
    add r0, r0, #1                                                     @ 1118:  e2800001
    cmp r0, #512    @ 0x200                                            @ 111c:  e3500c02
    strb    r1, [r5], #1                                               @ 1120:  e4c51001
    blt 1b @ 0x1114                                                         @ 1124:  bafffffa
    str fp, [r2, #8]                                                   @ 1128:  e582b008
    mov r0, #13                                                        @ 112c:  e3a0000d
    mla r0, r4, r0, r7                                                 @ 1130:  e0207094
    and r1, r0, #255    @ 0xff                                         @ 1134:  e20010ff
    str r1, [r2, #12]                                                  @ 1138:  e582100c
    lsl r0, r0, #16                                                    @ 113c:  e1a00800
    lsr r0, r0, #24                                                    @ 1140:  e1a00c20
    str r0, [r2, #12]                                                  @ 1144:  e582000c
    mov r0, #224    @ 0xe0                                             @ 1148:  e3a000e0
    str r0, [r2, #8]                                                   @ 114c:  e5820008
    mov r0, #0                                                         @ 1150:  e3a00000
1:
    ldrb    r1, [r2, #16]                                              @ 1154:  e5d21010
    add r0, r0, #1                                                     @ 1158:  e2800001
    cmp r0, #13                                                        @ 115c:  e350000d
    blt 1b @ 0x1154                                                         @ 1160:  bafffffb
    ldr r0, [r2, #4]                                                   @ 1164:  e5920004
    orr r0, r0, #128    @ 0x80                                         @ 1168:  e3800080
    str r0, [r2, #4]                                                   @ 116c:  e5820004
1:
    ldr r0, [r2, #40]   @ 0x28                                         @ 1170:  e5920028
    tst r0, #64 @ 0x40                                                 @ 1174:  e3100040
    beq 1b @ 0x1170                                                         @ 1178:  0afffffc
    ldr r0, [r2, #40]   @ 0x28                                         @ 117c:  e5920028
    orr r0, r0, #64 @ 0x40                                             @ 1180:  e3800040
    str r0, [r2, #40]   @ 0x28                                         @ 1184:  e5820028
1:
    ldr r0, [r2, #68]   @ 0x44                                         @ 1188:  e5920044
    tst r0, #-2147483648    @ 0x80000000                               @ 118c:  e3100102
    bne 1b @ 0x1188                                                         @ 1190:  1afffffc
    sub r0, r5, #512    @ 0x200                                        @ 1194:  e2450c02
    bl 0xcd8
    @ bl  test_2 @ 0xcd8                                                          @ 1198:  ebfffece
    str r0, [sp, r4, lsl #2]                                           @ 119c:  e78d0104
    add r4, r4, #1                                                     @ 11a0:  e2844001
    add r9, r0, r9                                                     @ 11a4:  e0809009
_lab_0:
    cmp r4, sl                                                         @ 11a8:  e154000a
    bcc _lab_3 @ 0x1054                                                         @ 11ac:  3affffa8
    ldr r0, [pc, #20]   @ 0x11cc                                       @ 11b0:  e59f0014
    ldr r1, [r0, #4]                                                   @ 11b4:  e5901004
    orr r1, r1, #2                                                     @ 11b8:  e3811002
    str r1, [r0, #4]                                                   @ 11bc:  e5801004
    add sp, sp, #32                                                    @ 11c0:  e28dd020
    mov r0, r9                                                         @ 11c4:  e1a00009
    pop {r4, r5, r6, r7, r8, r9, sl, fp, pc}                           @ 11c8:  e8bd8ff0

    .word 0x70200000                                                 @ 11cc:  70200000
    .word 0x0100777c                                             @ 11d0:  0100777c
    .word 0x00007776                                         @ 11d4:  00007776
    .word 0x7f008000                                                 @ 11d8:  7f008000
    .word 0x00807770                                         @ 11dc:  00807770

test_2:
    ldr r1, [pc, #1260] @ 0x11cc                                       @  cd8:  e59f14ec
    push    {r4, r5, lr}                                               @  cdc:  e92d4030
    sub sp, sp, #48 @ 0x30                                             @  ce0:  e24dd030
    ldr r2, [r1, #68]   @ 0x44                                         @  ce4:  e5912044
    lsl r2, r2, #3                                                     @  ce8:  e1a02182
    lsr r3, r2, #28                                                    @  cec:  e1a03e22
    ldr r2, [r1, #68]   @ 0x44                                         @  cf0:  e5912044
    lsl r2, r2, #22                                                    @  cf4:  e1a02b02
    lsr r2, r2, #22                                                    @  cf8:  e1a02b22
    str r2, [sp, #16]                                                  @  cfc:  e58d2010
    ldr r2, [r1, #68]   @ 0x44                                         @  d00:  e5912044
    mvn ip, #130048 @ 0x1fc00                                          @  d04:  e3e0cb7f
    and r2, ip, r2, lsr #15                                            @  d08:  e00c27a2
    str r2, [sp, #20]                                                  @  d0c:  e58d2014
    ldr r2, [r1, #72]   @ 0x48                                         @  d10:  e5912048
    and r2, r2, ip, lsr #22                                            @  d14:  e0022b2c
    str r2, [sp, #24]                                                  @  d18:  e58d2018
    ldr r2, [r1, #72]   @ 0x48                                         @  d1c:  e5912048
    lsl r2, r2, #11                                                    @  d20:  e1a02582
    lsr r2, r2, #22                                                    @  d24:  e1a02b22
    str r2, [sp, #28]                                                  @  d28:  e58d201c
    ldr r2, [r1, #72]   @ 0x48                                         @  d2c:  e5912048
    lsr r2, r2, #22                                                    @  d30:  e1a02b22
    str r2, [sp, #32]                                                  @  d34:  e58d2020
    ldr r2, [r1, #76]   @ 0x4c                                         @  d38:  e591204c
    and r2, r2, ip, lsr #22                                            @  d3c:  e0022b2c
    str r2, [sp, #36]   @ 0x24                                         @  d40:  e58d2024
    ldr r2, [r1, #76]   @ 0x4c                                         @  d44:  e591204c
    lsl r2, r2, #11                                                    @  d48:  e1a02582
    lsr r2, r2, #22                                                    @  d4c:  e1a02b22
    str r2, [sp, #40]   @ 0x28                                         @  d50:  e58d2028
    ldr r2, [r1, #76]   @ 0x4c                                         @  d54:  e591204c
    lsr r2, r2, #22                                                    @  d58:  e1a02b22
    str r2, [sp, #44]   @ 0x2c                                         @  d5c:  e58d202c
    ldr r2, [r1, #96]   @ 0x60                                         @  d60:  e5912060
    strb    r2, [sp, #1]                                               @  d64:  e5cd2001
    ldr r2, [r1, #96]   @ 0x60                                         @  d68:  e5912060
    lsr r2, r2, #8                                                     @  d6c:  e1a02422
    strb    r2, [sp, #2]                                               @  d70:  e5cd2002
    ldr r2, [r1, #96]   @ 0x60                                         @  d74:  e5912060
    lsr r2, r2, #16                                                    @  d78:  e1a02822
    strb    r2, [sp, #3]                                               @  d7c:  e5cd2003
    ldr r2, [r1, #96]   @ 0x60                                         @  d80:  e5912060
    lsr r2, r2, #24                                                    @  d84:  e1a02c22
    strb    r2, [sp, #4]                                               @  d88:  e5cd2004
    ldr r2, [r1, #100]  @ 0x64                                         @  d8c:  e5912064
    strb    r2, [sp, #5]                                               @  d90:  e5cd2005
    ldr r2, [r1, #100]  @ 0x64                                         @  d94:  e5912064
    lsr r2, r2, #8                                                     @  d98:  e1a02422
    strb    r2, [sp, #6]                                               @  d9c:  e5cd2006
    ldr r2, [r1, #100]  @ 0x64                                         @  da0:  e5912064
    lsr r2, r2, #16                                                    @  da4:  e1a02822
    strb    r2, [sp, #7]                                               @  da8:  e5cd2007
    ldr r1, [r1, #100]  @ 0x64                                         @  dac:  e5911064
    lsr r1, r1, #24                                                    @  db0:  e1a01c21
    cmp r3, #0                                                         @  db4:  e3530000
    strb    r1, [sp, #8]                                               @  db8:  e5cd1008
    beq 0xe00                                                          @  dbc:  0a00000f
    cmp r3, #9                                                         @  dc0:  e3530009
    moveq   r0, #1                                                     @  dc4:  03a00001
    beq 0xe04                                                          @  dc8:  0a00000d
    mov r1, #1                                                         @  dcc:  e3a01001
    add r4, sp, #12                                                    @  dd0:  e28d400c
    mov ip, sp                                                         @  dd4:  e1a0c00d
    b   0xdf8                                                          @  dd8:  ea000006
    ldr r2, [r4, r1, lsl #2]                                           @  ddc:  e7942101
    cmp r2, #512    @ 0x200                                            @  de0:  e3520c02
    ldrccb  lr, [r0, r2]                                               @  de4:  37d0e002
    ldrccb  r5, [ip, r1]                                               @  de8:  37dc5001
    add r1, r1, #1                                                     @  dec:  e2811001
    eorcc   lr, lr, r5                                                 @  df0:  302ee005
    strccb  lr, [r0, r2]                                               @  df4:  37c0e002
    cmp r1, r3                                                         @  df8:  e1510003
    bls 0xddc                                                          @  dfc:  9afffff6
    mov r0, #0                                                         @  e00:  e3a00000
    add sp, sp, #48 @ 0x30                                             @  e04:  e28dd030
    pop {r4, r5, pc}                                                   @  e08:  e8bd8030
#endif
