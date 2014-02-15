/*
 * Copyright (C) 2014, KGblog.pl
 * License: http://www.gnu.org/licenses/gpl.html GPL version 2 or higher
 */

#ifndef PLL_H_
#define PLL_H_

#include <stdint.h>
#include "LPC214x.h"

#define PLLE 0x01
#define PLLC 0x04
#define PLLLOCK (1<<10)
#define APBDIV1 0x01
#define APBDIV2 0x02
#define APBDIV4 0x00

void pll_init(uint8_t cfg, uint8_t apb_divider);

#endif
