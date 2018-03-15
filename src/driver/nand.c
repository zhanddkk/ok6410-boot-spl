/*
 * nand.c
 *
 *  Created on: Feb 8, 2018
 *      Author: zhanlei
 */
#include "nand.h"
#include "uart.h"
extern void printf_hex(uint32_t num, uint32_t display_num);

#define NAND_ECC_WRITE  0
#define NAND_ECC_READ   1

#define NAND_DATA_SZIE_PER_ECC_CAL   512
#define NAND_DATA_ECC_SIZE_PER_ECC_CAL  13
#define NAND_PAGE_SIZE  4096
#define NAND_OOB_SIZE   218
#define NAND_NUM_OF_PAGE_PER_BLOCK  128
#define NAND_NUM_OF_BLOCK_PER_CHIP  4096

static void set_hwecc_8bit_mode(uint32_t mode)
{
    uint32_t nfcont;
    nfcont = r_nand_flash_controller->NFCONT;
    /* Initialize main area ECC decoder/encoder and Initialize spare area ECC decoder/encoder */
    nfcont |= 3 << 4;
    /* Unlock Main area ECC */
    nfcont &= ~(1 << 7);

    if (mode == NAND_ECC_WRITE) {
        nfcont |= 1 << 18;
    } else {
        nfcont &= ~(1 << 18);
    }
    r_nand_flash_controller->NFCONT = nfcont;
}

static void get_8bit_hwecc_code(uint8_t *ecc_code)
{
    uint32_t nfcont, nfm8ecc0, nfm8ecc1, nfm8ecc2, nfm8ecc3;

    /* Lock */
    nfcont = r_nand_flash_controller->NFCONT;
    nfcont |= 1 << 7;
    r_nand_flash_controller->NFCONT = nfcont;
    while ((r_nand_flash_controller->NFSTAT & (1 << 7)) == 0);

    nfm8ecc0 = r_nand_flash_controller->NFM8ECC0;
    nfm8ecc1 = r_nand_flash_controller->NFM8ECC1;
    nfm8ecc2 = r_nand_flash_controller->NFM8ECC2;
    nfm8ecc3 = r_nand_flash_controller->NFM8ECC3;

    ecc_code[0] = nfm8ecc0 & 0xff;
    ecc_code[1] = (nfm8ecc0 >> 8) & 0xff;
    ecc_code[2] = (nfm8ecc0 >> 16) & 0xff;
    ecc_code[3] = (nfm8ecc0 >> 24) & 0xff;
    ecc_code[4] = nfm8ecc1 & 0xff;
    ecc_code[5] = (nfm8ecc1 >> 8) & 0xff;
    ecc_code[6] = (nfm8ecc1 >> 16) & 0xff;
    ecc_code[7] = (nfm8ecc1 >> 24) & 0xff;
    ecc_code[8] = nfm8ecc2 & 0xff;
    ecc_code[9] = (nfm8ecc2 >> 8) & 0xff;
    ecc_code[10] = (nfm8ecc2 >> 16) & 0xff;
    ecc_code[11] = (nfm8ecc2 >> 24) & 0xff;
    ecc_code[12] = nfm8ecc3 & 0xff;
}

int nand0_init(void)
{
    uint8_t id[6];
    uint32_t i;
    /* 8bit ECC with 512-byte data, TACLS = 2, TWRPH0 = TWRPH1 = 2 */
    /* CLE & ALE duration = 2 HCLK cycle, TWRPH0 duration = 3 HCLK cycle, TWRPH1 duration = 3 HCLK cycle */
    r_nand_flash_controller->NFCONF = (1 << 30) | (1 << 23) | (2 << 12) | (2 << 8) | (2 << 4) | (1 << 2);
    r_nand_flash_controller->NFCONT &= ~(1 << 1);
    r_nand_flash_controller->NFCMMD = 0x90;
    r_nand_flash_controller->NFADDR = 0x00;
    while ((r_nand_flash_controller->NFSTAT & 0x1) == 0);
    uart0_puts("Nand Flash: ");
    for (i = 0; i < 6; i++) {
        id[i] = *(uint8_t *)&(r_nand_flash_controller->NFDATA);
        printf_hex(id[i], 2);
        if (i < 5) {
            uart0_putchar(' ');
        } else {
            uart0_puts("\r\n");
        }
    }
    r_nand_flash_controller->NFCONT |= 1 << 1;
    return 0;
}

int nand0_read_page(uint32_t block, uint32_t page, uint8_t *page_buf, uint8_t *oob_buf)
{
    return 0;
}

int nand0_write_page(uint32_t block, uint32_t page, const uint8_t *page_data, uint8_t *oob_data)
{
    uint32_t i;
    uint32_t index;
    const uint8_t *main_data = page_data;
    uint8_t *ecc_data = oob_data;
    uint8_t status;
    int ret_val = -1;
    r_nand_flash_controller->NFCONT &= ~(1 << 1);
    r_nand_flash_controller->NFCMMD = 0x80;
    r_nand_flash_controller->NFADDR = 0;
    r_nand_flash_controller->NFADDR = 0;
    r_nand_flash_controller->NFADDR = (page & 0x7f) | ((block & 1) << 7);
    r_nand_flash_controller->NFADDR = (block >> 1) & 0xff;
    r_nand_flash_controller->NFADDR = (block >> 8) & 0x07;
    for (i = 0; i < (NAND_PAGE_SIZE / NAND_DATA_SZIE_PER_ECC_CAL); i++) {
        set_hwecc_8bit_mode(NAND_ECC_WRITE);
        for (index = 0; index < NAND_DATA_SZIE_PER_ECC_CAL; index++) {
            *(uint8_t *)&(r_nand_flash_controller->NFDATA) = main_data[index];
        }
        main_data = &page_data[index];
        get_8bit_hwecc_code(ecc_data);
        ecc_data = &oob_data[(i + 1) * NAND_DATA_ECC_SIZE_PER_ECC_CAL];
    }
    for (index = 0; index < NAND_OOB_SIZE; index++) {
        *(uint8_t *)&(r_nand_flash_controller->NFDATA) = oob_data[index];
    }
    r_nand_flash_controller->NFCMMD = 0x10;
    while ((r_nand_flash_controller->NFSTAT & 0x1) == 0);
    r_nand_flash_controller->NFCMMD = 0x70;
    status = *(uint8_t *)&(r_nand_flash_controller->NFDATA);

    uart0_puts("write @");
    printf_hex(block * NAND_PAGE_SIZE * NAND_NUM_OF_PAGE_PER_BLOCK + page * NAND_PAGE_SIZE, 8);
    if (status & 0x01) {
        uart0_puts(" failed\r\n");
    } else {
        uart0_puts(" succeed\r\n");
        ret_val = 0;
    }
    r_nand_flash_controller->NFCONT |= 1 << 1;
    return ret_val;
}

int nand0_erase_block(uint32_t block, uint32_t number_of)
{
    uint8_t status;
    int ret_val = -1;
    uint32_t i;
    r_nand_flash_controller->NFCONT &= ~(1 << 1);
    for (i = 0; (i < number_of) && (block < NAND_NUM_OF_BLOCK_PER_CHIP); i++) {
        r_nand_flash_controller->NFCMMD = 0x60;
        r_nand_flash_controller->NFADDR = (block & 1) << 7;
        r_nand_flash_controller->NFADDR = (block >> 1) & 0xff;
        r_nand_flash_controller->NFADDR = (block >> 8) & 0x07;
        r_nand_flash_controller->NFCMMD = 0xd0;
        while ((r_nand_flash_controller->NFSTAT & 0x1) == 0);
        r_nand_flash_controller->NFCMMD = 0x70;
        status = *(uint8_t *)&(r_nand_flash_controller->NFDATA);
        uart0_puts("erase @");
        printf_hex(block * NAND_PAGE_SIZE * NAND_NUM_OF_PAGE_PER_BLOCK, 8);
        if (status & 0x01) {
            uart0_puts(" failed\r\n");
            ret_val += -1;
        } else {
            uart0_puts(" succeed\r");
            ret_val = 0;
        }
        block++;
    }
    if ((status & 0x01) == 0) {
        uart0_puts("\n");
    }
    r_nand_flash_controller->NFCONT |= 1 << 1;
    return ret_val;
}
