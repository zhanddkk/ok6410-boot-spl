/*
 * nand.h
 *
 *  Created on: Feb 8, 2018
 *      Author: zhanlei
 */

#ifndef SRC_DRIVER_NAND_H_
#define SRC_DRIVER_NAND_H_

#include "regmap.h"
extern int nand0_init(void);
extern int nand0_write_page(uint32_t block, uint32_t page, const uint8_t *page_data, uint8_t *oob_data);
extern int nand0_erase_block(uint32_t block, uint32_t number_of);
#endif /* SRC_DRIVER_NAND_H_ */
