/*
 * start.S
 *
 *  Created on: Nov 10, 2017
 *      Author: zhanlei
 */

	.global reset

reset:
	mov r0, #0
	bl main
