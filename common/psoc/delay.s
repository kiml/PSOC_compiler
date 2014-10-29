/*******************************************************************************
* This file is closely based on CyBootAsmGnu.s v 3.20
* Therefore the original license is included
*
********************************************************************************
* Copyright 2010-2012, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

.syntax unified
.text
.thumb


/* void delay_cycles(uint32_t cycles) */
/* busy loop for the given number of cycles. The resolution is 4 cycles */

/*  Note: Delay func assumes instruction cache is enabled.
 *  If not actual delays are twice expected.
 */


.align 3                    /* Align to 8 byte boundary (2^n) */
.global delay_cycles
.func delay_cycles, delay_cycles
.type delay_cycles, %function
.thumb_func
delay_cycles:                   /* cycles bytes */
	ADDS r0, r0, #2         /*	1	2	Round to nearest multiple of 4 */
	LSRS r0, r0, #2         /*	1	2	Divide by 4 and set flags */
	BEQ delay_cycles_done   /*	2	2	Skip if 0 */
	NOP                     /*	1	2	Loop alignment padding */
delay_cycles_loop:
	SUBS r0, r0, #1         /*	1	2 */
	MOV r0, r0              /*	1	2	Pad loop to power of two cycles */
	BNE delay_cycles_loop   /*	2	2 */
delay_cycles_done:
	BX lr                   /*	3	2 */
.endfunc

.end
