/*
 * Copyright (C) 2014, KGblog.pl
 * License: http://www.gnu.org/licenses/gpl.html GPL version 2 or higher
 */

#include "pll.h"
#include <stdint.h>

#define LOOP_MAX 1000

void _pll_feed(void);

void pll_init(uint8_t cfg, uint8_t apb_divider)
{
	uint32_t loop_counter = 0;

    // Set configuration bits
	PLLCFG = cfg;
	// Enable PLL
	PLLCON = PLLE;
	// Set APB divider
	APBDIV |= apb_divider;
	// Feed PLL
	_pll_feed();
	// Wait until new frequency is locked
	while((PLLSTAT & PLLLOCK) == 0 && loop_counter <= LOOP_MAX)
		loop_counter++;
	// Connect PLL
	PLLCON |= PLLC;
	// PLL feed
	_pll_feed();
}

void _pll_feed(void)
{
	//Feed PLL
	PLLFEED = 0xAA;
	PLLFEED = 0x55;
}
