#ifndef _PSOC_REGISTERS_H
#define _PSOC_REGISTERS_H

/*
    Copyright (C) 2014 Kim Lester
    http://www.dfusion.com.au/

    This Program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This Program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this Program.  If not, see <http://www.gnu.org/licenses/>.
*/

// FORMAT:
//  REG_xxx register address
// in xxx below the register name may be abbreviated
//  xxx__bitfield_name
//  xxx__bitfield_name_SBIT     where values are specified (shift/start bit)
//  xxx__bitfield_name_MASK     generally only for multi-bit fields
//  xxx__bitfield_name__value   specific field values (pre-shifted by SBIT)


// TRM 1.3.10 Clock Configuration
#define REG_CLKDIST_CR 0x40004000

#define CLKDIST__PLL_SRC_SBIT     0
#define CLKDIST__PLL_SRC_MASK     (3 << CLKDIST__PLL_SRC_SBIT)
#define CLKDIST__PLL_SRC__IMO     (0 << CLKDIST__PLL_SRC_SBIT)
#define CLKDIST__PLL_SRC__XTAL    (1 << CLKDIST__PLL_SRC_SBIT)
#define CLKDIST__PLL_SRC__DIGK    (2 << CLKDIST__PLL_SRC_SBIT)
#define CLKDIST__PLL_SRC__RSVD    (3 << CLKDIST__PLL_SRC_SBIT)

#define CLKDIST__ILO_OUT_SBIT     2
#define CLKDIST__ILO_OUT_MASK     (3 << CLKDIST__ILO_OUT_SBIT)
#define CLKDIST__ILO_OUT__100K    (0 << CLKDIST__ILO_OUT_SBIT)
#define CLKDIST__ILO_OUT__33K     (1 << CLKDIST__ILO_OUT_SBIT)
#define CLKDIST__ILO_OUT__1K      (2 << CLKDIST__ILO_OUT_SBIT)
#define CLKDIST__ILO_OUT__RSVD    (3 << CLKDIST__ILO_OUT_SBIT)

#define CLKDIST__IMO_OUT_SBIT     4
#define CLKDIST__IMO_OUT_MASK     (3 << CLKDIST__IMO_OUT_SBIT)
#define CLKDIST__IMO_OUT__IMO     (0 << CLKDIST__IMO_OUT_SBIT)
#define CLKDIST__IMO_OUT__IMO2X   (1 << CLKDIST__IMO_OUT_SBIT)
#define CLKDIST__IMO_OUT__IMO36   (2 << CLKDIST__IMO_OUT_SBIT)
#define CLKDIST__IMO_OUT__RSVD    (3 << CLKDIST__IMO_OUT_SBIT)

#define CLKDIST__IMO2X_SRC_SBIT   6
#define CLKDIST__IMO2X_SRC_MASK   (1 << CLKDIST__IMO2X_SRC_SBIT)
#define CLKDIST__IMO2X_SRC__DSI   (0 << CLKDIST__IMO2X_SRC_SBIT)
#define CLKDIST__IMO2X_SRC__XTAL  (1 << CLKDIST__IMO2X_SRC_SBIT)

// TRM 1.3.11 Clock Load
#define REG_CLKDIST_LD 0x40004001
#define CLKDIST_LD__SYNC_EN 0x02
#define CLKDIST_LD__LOAD    0x01

// TRM 1.3.12 Clock LSB Shadow Divider Value
#define REG_CLKDIST_WRK0 0x40004002

// TRM 1.3.13 Clock MSB Shadow Divider Value
#define REG_CLKDIST_WRK1 0x40004003

// TRM 1.3.14 Master Clock Divider Value
#define REG_CLKDIST_MSTR0 0x40004004

// TRM 1.3.15 Master Clock Config / CPU Divider Value
#define REG_CLKDIST_MSTR1 0x40004005

// TRM 1.3.16 CLK_BUS LSB Divider Value
#define REG_CLKDIST_BCFG0 0x40004006

// TRM 1.3.17 CLK_BUS MSB Divider Value
#define REG_CLKDIST_BCFG1 0x40004007

// TRM 1.3.18 CLK_BUS Configuration
#define REG_CLKDIST_BCFG2 0x40004008
// Note: field is called mask.
#define CLKDIST__MASK  0x80
#define CLKDIST__SSS   0x40
#define CLKDIST__EARLY 0x20
#define CLKDIST__DUTY  0x10
#define CLKDIST__SYNC  0x80

// TRM 1.3.31 Internal Main Oscillator Control
#define REG_FASTCLK_IMO_CR 0x40004200

#define FASTCLK_IMO__F_RANGE_SBIT       0 
#define FASTCLK_IMO__F_RANGE_MASK       0x07 
#define FASTCLK_IMO__F_RANGE(range)     (((range) & FASTCLK_IMO__F_RANGE_MASK) << FASTCLK_IMO__F_RANGE_SBIT)

// Convenience: (non-fast start speeds)
#define FASTCLK_IMO__F_RANGE__3MHz       3
#define FASTCLK_IMO__F_RANGE__6MHz       1
#define FASTCLK_IMO__F_RANGE__12MHz      0
#define FASTCLK_IMO__F_RANGE__24MHz      2
#define FASTCLK_IMO__F_RANGE__48MHz      4
#define FASTCLK_IMO__F_RANGE__67MHz      5
#define FASTCLK_IMO__F_RANGE__80MHz      6
#define FASTCLK_IMO__F_RANGE__96MHz      7


#define FASTCLK_IMO__FIMO_EN_SBIT       3
#define FASTCLK_IMO__FIMO_EN__NORMAL   (0 << FASTCLK_IMO__FIMO_EN_SBIT)
#define FASTCLK_IMO__FIMO_EN__FAST     (1 << FASTCLK_IMO__FIMO_EN_SBIT)

#define FASTCLK_IMO__F2XON              0x10
#define FASTCLK_IMO__XCLKEN             0x20
#define FASTCLK_IMO__USBCLK_ON          0x40


// TRM 1.3.36 PLL Configuration Reg 0
#define REG_FASTCLK_PLL_CFG0 0x40004220
#define FASTCLK_PLL__EN       0x01

#define FASTCLK_PLL__DELAY_SBIT       4
#define FASTCLK_PLL__DELAY_MASK       (3 << FASTCLK_PLL__DELAY_SBIT)
#define FASTCLK_PLL__DELAY__3NS       (0 << FASTCLK_PLL__DELAY_SBIT)
#define FASTCLK_PLL__DELAY__5NS       (1 << FASTCLK_PLL__DELAY_SBIT)
#define FASTCLK_PLL__DELAY__7NS       (2 << FASTCLK_PLL__DELAY_SBIT)
#define FASTCLK_PLL__DELAY__8NS       (3 << FASTCLK_PLL__DELAY_SBIT)

#define FASTCLK_PLL__WAIT_SBIT        6
#define FASTCLK_PLL__WAIT_MASK        (3 << FASTCLK_PLL__WAIT_SBIT)
#define FASTCLK_PLL__WAIT__0          (0 << FASTCLK_PLL__WAIT_SBIT)
#define FASTCLK_PLL__WAIT__1          (1 << FASTCLK_PLL__WAIT_SBIT)
#define FASTCLK_PLL__WAIT__2          (2 << FASTCLK_PLL__WAIT_SBIT)
#define FASTCLK_PLL__WAIT__3          (3 << FASTCLK_PLL__WAIT_SBIT)

// TRM 1.3.37 PLL Configuration Reg 1
#define REG_FASTCLK_PLL_CFG1 0x40004221

// TRM 1.3.38 PLL P-Counter Configuration
#define REG_FASTCLK_PLL_P 0x40004222
//#define FASTCLK__PLL_P_DIV(divider)     (((divider) & 0xFF))

// TRM 1.3.39 PLL Q-Counter Configuration
#define REG_FASTCLK_PLL_Q 0x40004223

// TRM 1.3.40 PLL Test
#define REG_FASTCLK_PLL_TST 0x40004224

// TRM 1.3.41 PLL Status
#define REG_FASTCLK_PLL_SR 0x40004225
#define FASTCLK_PLL_SR__LOCKDET 0x01
#define FASTCLK_PLL_SR__ILOCK   0x02

// TRM 1.3.42 Internal Low-speed Oscillator Control Reg 0
#define REG_SLOWCLK_ILO_CR0 0x40004300
#define SLOWCLK_ILO__EN_1K      0x02
#define SLOWCLK_ILO__EN_100K    0x04

#define SLOWCLK_ILO__PD_MODE_MASK  0x10
#define SLOWCLK_ILO__PD_MODE_SBIT  4
#define SLOWCLK_ILO__PD_MODE__FAST  (0 << SLOWCLK_ILO__PD_MODE_SBIT)
#define SLOWCLK_ILO__PD_MODE__SLOW  (1 << SLOWCLK_ILO__PD_MODE_SBIT)

#define SLOWCLK_ILO__DIV3_EN    0x20

// TRM 1.3.43 Internal Low-speed Oscillator Control Reg 1
#define REG_SLOWCLK_ILO_CR1 0x40004301

// TRM 1.3.44 External 32kHz Crystal Oscillator Control
#define REG_SLOWCLK_X32_CR 0x40004308

// TRM 1.3.45 External 32kHz Crystal Oscillator Configuration
#define REG_SLOWCLK_X32_CFG 0x40004309

// TRM 1.3.46 External 32kHz Crystal Oscillator Test
#define REG_SLOWCLK_X32_TST 0x4000430A

// TRM 1.3.47 Boost Control 0
#define REG_BOOST_CR0 0x40004320

// TRM 1.3.48 Boost Control 1
#define REG_BOOST_CR1 0x40004321

// TRM 1.3.49 Boost Control 2
#define REG_BOOST_CR2 0x40004322

// TRM 1.3.50 Boost Control 3
#define REG_BOOST_CR3 0x40004323

// TRM 1.3.51 Boost Status
#define REG_BOOST_STATUS 0x40004324

// TRM 1.3.52 Power System Control Reg 0
#define REG_PWRSYS_CR0 0x40004330

// TRM 1.3.53 Power System Control Reg 1
#define REG_PWRSYS_CR1 0x40004331

// TRM 1.3.54-56 Timewheel Configuration
#define REG_PM_TW_CFG0 0x40004380
#define REG_PM_TW_CFG1 0x40004381
#define REG_PM_TW_CFG2 0x40004382

#define PM_TW_CFG2_FTW_EN       (1 << 0)
#define PM_TW_CFG2_FTW_IE       (1 << 1)
#define PM_TW_CFG2_CTW_EN       (1 << 2)
#define PM_TW_CFG2_CTW_IE       (1 << 3)
#define PM_TW_CFG2_ONEPPS_EN    (1 << 4)
#define PM_TW_CFG2_ONEPPS_IE    (1 << 5)

// TRM 1.3.57 Watchdog Timer Configuration
#define REG_PM_WDT_CFG 0x40004383

// TRM 1.3.58 Watchdog Timer Control
#define REG_PM_WDT_CR 0x40004384

// TRM 1.3.59 Power Manager Interrupt Status
#define REG_PM_INT_SR 0x40004390

// TRM 1.3.60 Power Mode Configuration Reg 0
#define REG_PM_MODE_CFG0 0x40004391

// TRM 1.3.61 Power Mode Configuration Reg 1
#define REG_PM_MODE_CFG1 0x40004392

// TRM 1.3.62 Power Mode Control/Status
#define REG_PM_MODE_CSR 0x40004393

// TRM 1.3.63-74 Active Power Mode Configuration
#define PM_CFG_NREGS 12

#define REG_PM_ACT_CFG0 0x400043A0
// ... CFG11
#define REG_PM_ACT_BASE REG_PM_ACT_CFG0

// TRM 1.3.75-86 Standby Power Mode Configuration
#define REG_PM_STBY_CFG0 0x400043B0
// ... CFG11
#define REG_PM_STBY_BASE REG_PM_STBY_CFG0


// TRM 1.3.124 Internal Main Oscillator Trim Reg 1
#define REG_IMO_TR1 0x400046A1

// TRM 1.3.138 - 141 Reset Controls
#define REG_RESET_CR0 0x400046F4
#define REG_RESET_CR1 0x400046F5
#define REG_RESET_CR2 0x400046F6
#define REG_RESET_CR3 0x400046F7


// TRM 1.3.155 Cache Control (what does CC stand for or it is redundant ?)
#define REG_CACHE_CC_CTL 0x40004800
#define CACHE_CC_CTL__DISABLE       0x01
#define CACHE_CC_CTL__FLASH_LOWPWR  0x02
#define CACHE_CC_CTL__FLUSH         0x04

#define CACHE_CC_CTL__FLASH_CYCLES_SBIT  6
#define CACHE_CC_CTL__FLASH_CYCLES_MASK  (3 << CACHE_CC_CTL__FLASH_CYCLES_SBIT)
#define CACHE_CC_CTL__FLASH_CYCLES__4C   (0 << CACHE_CC_CTL__FLASH_CYCLES_SBIT)
#define CACHE_CC_CTL__FLASH_CYCLES__1C   (1 << CACHE_CC_CTL__FLASH_CYCLES_SBIT)
#define CACHE_CC_CTL__FLASH_CYCLES__2C   (2 << CACHE_CC_CTL__FLASH_CYCLES_SBIT)
#define CACHE_CC_CTL__FLASH_CYCLES__3C   (3 << CACHE_CC_CTL__FLASH_CYCLES_SBIT)

#define CACHE_CC_CTL__LPMODE_SBIT  8
#define CACHE_CC_CTL__LPMODE_MASK  (0xFF << CACHE_CC_CTL__FLASH_CYCLES_SBIT)
#define CACHE_CC_CTL__LPMODE(value)  (((value) & 0xFF) << CACHE_CC_CTL__FLASH_CYCLES_SBIT)

// TRM 1.3.196 Port Pin Configuration
#define REG_PRT0_PC0 0x40005000
#define REG_PRT0_PC1 0x40005001
#define REG_PRT0_PC2 0x40005002
#define REG_PRT0_PC3 0x40005003
#define REG_PRT0_PC4 0x40005004
#define REG_PRT0_PC5 0x40005005
#define REG_PRT0_PC6 0x40005006
#define REG_PRT0_PC7 0x40005007
#define REG_PRT1_PC0 0x40005008
#define REG_PRT1_PC1 0x40005009
#define REG_PRT1_PC2 0x4000500A
#define REG_PRT1_PC3 0x4000500B
#define REG_PRT1_PC4 0x4000500C
#define REG_PRT1_PC5 0x4000500D
#define REG_PRT1_PC6 0x4000500E
#define REG_PRT1_PC7 0x4000500F
#define REG_PRT2_PC0 0x40005010
#define REG_PRT2_PC1 0x40005011
#define REG_PRT2_PC2 0x40005012
#define REG_PRT2_PC3 0x40005013
#define REG_PRT2_PC4 0x40005014
#define REG_PRT2_PC5 0x40005015
#define REG_PRT2_PC6 0x40005016
#define REG_PRT2_PC7 0x40005017
#define REG_PRT3_PC0 0x40005018
#define REG_PRT3_PC1 0x40005019
#define REG_PRT3_PC2 0x4000501A
#define REG_PRT3_PC3 0x4000501B
#define REG_PRT3_PC4 0x4000501C
#define REG_PRT3_PC5 0x4000501D
#define REG_PRT3_PC6 0x4000501E
#define REG_PRT3_PC7 0x4000501F
#define REG_PRT4_PC0 0x40005020
#define REG_PRT4_PC1 0x40005021
#define REG_PRT4_PC2 0x40005022
#define REG_PRT4_PC3 0x40005023
#define REG_PRT4_PC4 0x40005024
#define REG_PRT4_PC5 0x40005025
#define REG_PRT4_PC6 0x40005026
#define REG_PRT4_PC7 0x40005027
#define REG_PRT5_PC0 0x40005028
#define REG_PRT5_PC1 0x40005029
#define REG_PRT5_PC2 0x4000502A
#define REG_PRT5_PC3 0x4000502B
#define REG_PRT5_PC4 0x4000502C
#define REG_PRT5_PC5 0x4000502D
#define REG_PRT5_PC6 0x4000502E
#define REG_PRT5_PC7 0x4000502F
#define REG_PRT6_PC0 0x40005030
#define REG_PRT6_PC1 0x40005031
#define REG_PRT6_PC2 0x40005032
#define REG_PRT6_PC3 0x40005033
#define REG_PRT6_PC4 0x40005034
#define REG_PRT6_PC5 0x40005035
#define REG_PRT6_PC6 0x40005036
#define REG_PRT6_PC7 0x40005037
#define REG_PRT12_PC0 0x40005060
#define REG_PRT12_PC1 0x40005061
#define REG_PRT12_PC2 0x40005062
#define REG_PRT12_PC3 0x40005063
#define REG_PRT12_PC4 0x40005064
#define REG_PRT12_PC5 0x40005065
#define REG_PRT12_PC6 0x40005066
#define REG_PRT12_PC7 0x40005067
#define REG_PRT15_PC0 0x40005078
#define REG_PRT15_PC1 0x40005079
#define REG_PRT15_PC2 0x4000507A
#define REG_PRT15_PC3 0x4000507B
#define REG_PRT15_PC4 0x4000507C
#define REG_PRT15_PC5 0x4000507D
#define REG_PRT15_PC6 0x4000507E
#define REG_PRT15_PC7 0x4000507F

#define PRT_PC__DATA_OUT        0x01

#define PRT_PC__DRIVE_MODE_SBIT             1
#define PRT_PC__DRIVE_MODE_MASK            (0x07 << PRT_PC__DRIVE_MODE_SBIT)
#define PRT_PC__DRIVE_MODE__HI_Z_ANALOGUE  (0 << PRT_PC__DRIVE_MODE_SBIT)
#define PRT_PC__DRIVE_MODE__HI_Z_DIGITAL   (1 << PRT_PC__DRIVE_MODE_SBIT)
#define PRT_PC__DRIVE_MODE__RES_PULLUP     (2 << PRT_PC__DRIVE_MODE_SBIT)
#define PRT_PC__DRIVE_MODE__RES_PULLDOWN   (3 << PRT_PC__DRIVE_MODE_SBIT)
#define PRT_PC__DRIVE_MODE__OD_DRIVE_LO    (4 << PRT_PC__DRIVE_MODE_SBIT)
#define PRT_PC__DRIVE_MODE__OD_DRIVE_HI    (5 << PRT_PC__DRIVE_MODE_SBIT)
#define PRT_PC__DRIVE_MODE__STRONG         (6 << PRT_PC__DRIVE_MODE_SBIT)
#define PRT_PC__DRIVE_MODE__RES_PULLUPDOWN (7 << PRT_PC__DRIVE_MODE_SBIT)

#define PRT_PC__PIN_STATE       0x10
#define PRT_PC__PIN_STATE_SBIT  4
#define PRT_PC__BIDIR_EN        0x20
#define PRT_PC__SLEW            0x40
#define PRT_PC__BYPASS_EN       0x80

// TRM 1.3.199 Port Data Output
#define REG_PRT0_DR 0x40005100
#define REG_PRT1_DR 0x40005110
#define REG_PRT2_DR 0x40005120
#define REG_PRT3_DR 0x40005130
#define REG_PRT4_DR 0x40005140
#define REG_PRT5_DR 0x40005150
#define REG_PRT6_DR 0x40005160

#define REG_PRT12_DR 0x400051C0
#define REG_PRT15_DR 0x400051F0

// TRM 1.3.200 Port Pin State
#define REG_PRT0_PS 0x40005101
#define REG_PRT1_PS 0x40005111
#define REG_PRT2_PS 0x40005121
#define REG_PRT3_PS 0x40005131
#define REG_PRT4_PS 0x40005141
#define REG_PRT5_PS 0x40005151
#define REG_PRT6_PS 0x40005161

#define REG_PRT12_PS 0x400051C1
#define REG_PRT15_PS 0x400051F1

// TRM 1.3.201 Port Drive Mode
#define REG_PRT0_DM0 0x40005102
#define REG_PRT0_DM1 0x40005103
#define REG_PRT0_DM2 0x40005104
#define REG_PRT1_DM0 0x40005112
#define REG_PRT1_DM1 0x40005113
#define REG_PRT1_DM2 0x40005114
#define REG_PRT2_DM0 0x40005122
#define REG_PRT2_DM1 0x40005123
#define REG_PRT2_DM2 0x40005124
#define REG_PRT3_DM0 0x40005132
#define REG_PRT3_DM1 0x40005133
#define REG_PRT3_DM2 0x40005134
#define REG_PRT4_DM0 0x40005142
#define REG_PRT4_DM1 0x40005143
#define REG_PRT4_DM2 0x40005144
#define REG_PRT5_DM0 0x40005152
#define REG_PRT5_DM1 0x40005153
#define REG_PRT5_DM2 0x40005154
#define REG_PRT6_DM0 0x40005162
#define REG_PRT6_DM1 0x40005163
#define REG_PRT6_DM2 0x40005164

#define REG_PRT12_DM0 0x400051C2
#define REG_PRT12_DM1 0x400051C3
#define REG_PRT12_DM2 0x400051C4

#define REG_PRT15_DM0 0x400051F2
#define REG_PRT15_DM1 0x400051F3
#define REG_PRT15_DM2 0x400051F4

// TRM 1.3.202 Port slew rate control
#define REG_PRT0_SLW 0x40005105
#define REG_PRT1_SLW 0x40005115
#define REG_PRT2_SLW 0x40005125
#define REG_PRT3_SLW 0x40005135
#define REG_PRT4_SLW 0x40005145
#define REG_PRT5_SLW 0x40005155
#define REG_PRT6_SLW 0x40005165

#define REG_PRT12_SLW 0x400051C5
#define REG_PRT15_SLW 0x400051F5

// General PORT info. All the above REG_PRT variables can be condensed into
// x:0-6,12,15  y:0-7  r:0-15 Note y,r addr change fastest (by 1) then x
// Note: x,y,r are not bounded/masked.
#define PRTx_PC_SIZE          0x08
#define REG_PRTx_PCy(x,y)     (0x40005000 + (PRTx_PC_SIZE * (x)) + (y))

// step between PRTx
#define PRT_REG_BASE          0x40005100   // == REG_PRT0_DR
#define PRTx_REG_SIZE         0x10
//#define PRTx_REG_NREGS         16
#define REG_PRTx_REGr(x,r)    (PRT_REG_BASE + (PRTx_REG_SIZE * (x)) + (r))

//#define PRTx_REG_BASE(x)      REG_PRTx_REGr(x,0)
#define REG_PRTx_BASE(x)      REG_PRTx_REGr(x,0)

// See TRM 21.5 for details
#define PRTx_REG__DR              0x0
#define PRTx_REG__PS              0x1
#define PRTx_REG__DM0             0x2
#define PRTx_REG__DM1             0x3
#define PRTx_REG__DM2             0x4
#define PRTx_REG__SLW             0x5
#define PRTx_REG__BYP             0x6
#define PRTx_REG__BIE             0x7
#define PRTx_REG__INP_DIS         0x8
#define PRTx_REG__CTL             0x9
#define PRTx_REG__PRT             0xA
#define PRTx_REG__BIT_MASK        0xB
#define PRTx_REG__AMUX            0xC
#define PRTx_REG__AG              0xD
#define PRTx_REG__LCD_COM_SEG     0xE
#define PRTx_REG__LCD_EN          0xF
// Port12 exceptions:
#define PRTx_REG__SIO_HYST_EN     0x9
#define PRTx_REG__SIO_REG_HIFREQ  0xC
#define PRTx_REG__SIO_CFG         0xE
#define PRTx_REG__SIO_DIFF        0xF

#define REG_PRTx_DR_ALIAS(x)  (0x40005080 + (x))
#define REG_PRTx_PS_ALIAS(x)  (0x40005090 + (x))


// TRM 1.3.213 Port 12 Data Output - refer  1.2.199
// TRM 1.3.214 Port 12 Pin State - refer 1.3.200
// TRM 1.3.215 Port 12 Port Drive Mode - refer 1.3.201
// TRM 1.3.216 Port 12 Port slew rate control - refer 1.3.202

// TRM 1.3.227 Port 15 Data Output
// TRM 1.3.228 Port 15 Pin State - refer 1.3.200
// TRM 1.3.229 Port 15 Port Drive Mode - refer 1.3.201
// TRM 1.3.230 Port 15 Port slew rate control - refer 1.3.202

// TRM 1.3.241-247 Port 0 Digital System Interconnect Port Pin Output Select
#define REG_PRT0_OUT_SEL0       0x40005200
#define REG_PRT0_OUT_SEL1       0x40005201
#define REG_PRT0_OE_SEL0        0x40005202
#define REG_PRT0_OE_SEL1        0x40005203
#define REG_PRT0_DBL_SYNC_IN    0x40005204
#define REG_PRT0_SYNC_OUT       0x40005205
#define REG_PRT0_CAPS_SEL       0x40005206

// TRM 1.3.248++ Port 1 Digital System Interconnect Port Pin Output Select
// #define REG_PRT1_OUT_SEL0 0x40005208

// REPLACEMENT FOR THE PRTx DSI defines...
#define REG_PRTx_DSI_REGr(x,r)  (0x40005200 + (0x08 * (x)) + (r))
#define PRTx_DSI_REG__OUT_SEL0      0
#define PRTx_DSI_REG__OUT_SEL1      1
#define PRTx_DSI_REG__OE_SEL0       2
#define PRTx_DSI_REG__OE_SEL1       3
#define PRTx_DSI_REG__DBL_SYNC_IN   4
#define PRTx_DSI_REG__SYNC_OUT      5
#define PRTx_DSI_REG__CAPS_SEL      6


// TRM 1.3.1128++ (UDB DSI Interconnect)
// Note: UDB_CFG_B0_BASE == B0_P0_U0_PLD_IT0: 
#define REG_UDB_CFG_B_BASE          0x40010000
#define REG_UDB_CFG_Bi_SIZE         0x1000
#define REG_UDB_CFG_B_SIZE          0x4000
#define REG_UDB_CFG_Pi_SIZE         0x200

// Convenience:
#define REG_UDB_CFG_B0_BASE         REG_UDB_CFG_B_BASE
#define REG_UDB_CFG_B1_BASE         (REG_UDB_CFG_B_BASE + 1 * REG_UDB_CFG_Bi_SIZE)
#define REG_UDB_CFG_B2_BASE         (REG_UDB_CFG_B_BASE + 2 * REG_UDB_CFG_Bi_SIZE)
#define REG_UDB_CFG_B3_BASE         (REG_UDB_CFG_B_BASE + 3 * REG_UDB_CFG_Bi_SIZE)
// B1: No P0,P1 !? only P2 - P5
#define REG_UDB_CFG_B1_P2_BASE      (REG_UDB_CFG_B1_BASE + 2 * REG_UDB_CFG_Pi_SIZE)
#define REG_UDB_CFG_B1_P2_P5_SIZE   (4 * REG_UDB_CFG_Pi_SIZE)
#define REG_UDB_CFG_B1_IMPLEMENTED_BASE      REG_UDB_CFG_B1_P2_BASE
#define REG_UDB_CFG_B1_IMPLEMENTED_SIZE      REG_UDB_CFG_B1_P2_P5_SIZE

// 
#define REG_UDB_CFG_DSI_BASE        0x40014000
#define REG_UDB_CFG_DSI_SIZE        0x1000
#define REG_UDB_CFG_DSIi_SIZE       0x100

// Convenience:
#define REG_UDB_CFG_DSI0_BASE       REG_UDB_CFG_DSI_BASE
#define REG_UDB_CFG_DSI12_BASE      (REG_UDB_CFG_DSI_BASE + 12 * REG_UDB_CFG_DSIi_SIZE)
#define REG_UDB_CFG_DSI_0_9_SIZE    (10 * REG_UDB_CFG_DSIi_SIZE)
// No DSI 10,11
#define REG_UDB_CFG_DSI_12_13_SIZE  (2 * REG_UDB_CFG_DSIi_SIZE)
// No DSI 14,15


// TRM 1.3.1215 DCLK_EN
#define REG_BCTL0_MDCLK_EN 0x40015000
#define REG_BCTL1_MDCLK_EN 0x40015010
//#define REG_BCTL2_MDCLK_EN 0x40015020 ??
//#define REG_BCTL3_MDCLK_EN 0x40015030 ??

#define REG_BCTL_BASE           0x40015000
#define REG_BCTLi_SIZE          16
#define REG_BCTLi_BASE(i)       (REG_BCTL_BASE + ((i) * REG_BCTLi_SIZE))
#define REG_BCTLi_REGr(i,r)     (REG_BCTL_BASE + ((i) * REG_BCTLi_SIZE) + (r))
#define BCTLi_REG__MDCLK_EN         0x0
#define BCTLi_REG__MBCLK_EN         0x1
#define BCTLi_REG__WAIT_CFG         0x2
#define BCTLi_REG__BANK_CTL         0x3
// gap
#define BCTLi_REG__DCLK_EN0         0x8
#define BCTLi_REG__BCLK_EN0         0x9
#define BCTLi_REG__DCLK_EN1         0xA
#define BCTLi_REG__BCLK_EN1         0xB
#define BCTLi_REG__DCLK_EN2         0xC
#define BCTLi_REG__BCLK_EN2         0xD
#define BCTLi_REG__DCLK_EN3         0xE
#define BCTLi_REG__BCLK_EN3         0xF

// TRM 1.3.1216 BCLK_EN
#define REG_BCTL0_MBCLK_EN 0x40015001
#define REG_BCTL1_MBCLK_EN 0x40015011



// ------------------------------
// ARM Cortex M3 Common Registers
// ------------------------------
// Note: These are supported via CMSIS too


// TRM 1.3.1381 CPU ID Base Register (32 bits)
#define REG_NVIC_CPUID_BASE 0xE000ED00

// TRM 1.3.1382 CPU ID Base Register (32 bits)
#define REG_NVIC_INTR_CTRL_STATE 0xE000ED04

// TRM 1.3.1383 Interrupt Control State Register (32 bits)
#define REG_NVIC_VECT_OFFSET 0xE000ED08

// TRM 1.3.1384 Application Interrupt and Reset Control (32 bits)
#define REG_NVIC_APPLN_INTR 0xE000ED0C

#define NVIC_APPLN_INTR__VECTKEY_SBIT  16
#define NVIC_APPLN_INTR__VECTKEY_MASK  (0xFFFF << NVIC_APPLN_INTR__VECTKEY_SBIT)
#define NVIC_APPLN_INTR__VECTKEY__KEY  (0x05FA << NVIC_APPLN_INTR__VECTKEY_SBIT)

#define NVIC_APPLN_INTR__PRIGROUP_SBIT  8
#define NVIC_APPLN_INTR__PRIGROUP_MASK  (7<< NVIC_APPLN_INTR__PRIGROUP_SBIT)
#define NVIC_APPLN_INTR__PRIGROUP__7_1  (0<< NVIC_APPLN_INTR__PRIGROUP_SBIT)
#define NVIC_APPLN_INTR__PRIGROUP__6_2  (1<< NVIC_APPLN_INTR__PRIGROUP_SBIT)
#define NVIC_APPLN_INTR__PRIGROUP__5_3  (2<< NVIC_APPLN_INTR__PRIGROUP_SBIT)
#define NVIC_APPLN_INTR__PRIGROUP__4_4  (3<< NVIC_APPLN_INTR__PRIGROUP_SBIT)
#define NVIC_APPLN_INTR__PRIGROUP__3_5  (4<< NVIC_APPLN_INTR__PRIGROUP_SBIT)
#define NVIC_APPLN_INTR__PRIGROUP__2_6  (5<< NVIC_APPLN_INTR__PRIGROUP_SBIT)
#define NVIC_APPLN_INTR__PRIGROUP__1_7  (6<< NVIC_APPLN_INTR__PRIGROUP_SBIT)
#define NVIC_APPLN_INTR__PRIGROUP__0_8  (7<< NVIC_APPLN_INTR__PRIGROUP_SBIT)

// ...

// TRM 1.3.1385 System Control
#define REG_NVIC_SYSTEM_CONTROL 0xE000ED10

// TRM 1.3.1386 Configuration Control
#define REG_NVIC_CFG_CONTROL 0xE000ED14
#define NVIC_CFG_CONTROL__NONEBASETHRDENA  0x0001
#define NVIC_CFG_CONTROL__USERSETMPEND     0x0002
#define NVIC_CFG_CONTROL__UNALIGN_TRP      0x0008
#define NVIC_CFG_CONTROL__DIV_0_TRP        0x0010
#define NVIC_CFG_CONTROL__BFHFNMIGN        0x0100
#define NVIC_CFG_CONTROL__STKALIGN         0x0200


#endif
