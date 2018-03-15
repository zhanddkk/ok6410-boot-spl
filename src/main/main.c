/*
 * main.c
 *
 *  Created on: Nov 10, 2017
 *      Author: zhanlei
 */
#include <stdio.h>
#include <stdbool.h>
#include "../driver/uart.h"
#include "../driver/nand.h"
/**
* This Function copies a block of page to destination memory( 8-bit ECC only )
* @param uint32 blcok : Source block address number to copy.
* @param uint32 page : Source page address number to copy.
* @param uint8 *buffer : Target Buffer pointer.
* @return int32 - Success or failure.
*/
typedef int32_t (*nand_read_page_t)(uint32_t block, uint32_t page, uint8_t *buf);
nand_read_page_t nand_read_page = NULL;
#define NAND_READ_PAGE_FUN_ADDR (*((volatile uint32_t *)0x0C004004u))
uint8_t page_buf[4096 + 218];
//#define NF8_ReadPage_Adv(a,b,c) (((int(*)(uint32, uint32, uint8*))(*((uint32 *)0x0C004004)))(a,b,c))
/**
* This Function copies SD/MMC Card Data to memory.
* Always use EPLL source clock.
* @param channel : HSMMC Controller channel number ( Not support. Depend on GPN15, GPN14 and GPN13 )
* @param StartBlkAddress : Source card(SD/MMC) Address.(It must block address.)
* @param blockSize : Number of blocks to copy.
* @param memoryPtr : Buffer to copy from.
* @param with_init : reinitialize or not
* @return bool(unsigend char) - Success or failure.
*/

//#define CopyMMCtoMem(z,a,b,c,e) (((bool(*)(int, unsigned int, unsigned short, unsigned int*, bool)) (*((unsigned int *)0x0C004008)))(z,a,b,c,e))
uint32_t count = 0;
//extern int32_t nand_read_page_adv(uint32_t block, uint32_t page, uint8_t *buf);

void printf_hex(uint32_t num, uint32_t display_num)
{
    int i;
    uart0_puts("0x");
    for (i = 0; i < 8; i++) {
        char ch = (char)((num & 0xf0000000) >> 28);
        if (ch > 9) {
            ch += 'A' - 10;
        } else {
            if ((ch ==0) && (i < 8 - display_num) && (i != 7))
            {
                num <<= 4;
                continue;
            }
            ch += '0';
        }
        num <<= 4;
        uart0_putchar(ch);
    }
}

int main(void)
{
    uint32_t i = 0;
    int32_t ret;
    uart0_init();
    nand0_init();
    nand0_erase_block(0, 1);
    for (i = 0 ; i < 4096; i++)
    {
        page_buf[i] = i & 0xff;
    }
    nand0_write_page(0, 0, page_buf, &page_buf[4096]);
    nand_read_page = (nand_read_page_t)NAND_READ_PAGE_FUN_ADDR;
    ret = nand_read_page(0, 0, page_buf);
//    ret = nand_read_page_adv(0, 0, page_buf);
    uart0_puts("retval = ");
    printf_hex(ret, 2);
    uart0_puts("\r\n");
    for (i = 0; i < sizeof(page_buf); i++) {
        printf_hex(page_buf[i], 2);
        if ((i % 16) == 15) {
            uart0_puts("\r\n");
        } else {
            uart0_putchar(' ');
        }
    }
    if ((i % 16) != 15) {
        uart0_puts("\r\n");
    }
    i = 0;
    while (1) {
        i++;
        if (i == 0x5fffff) {
            count++;
            printf_hex(count, 8);
            uart0_puts("\r");
            i = 0;
        }
    }
}
