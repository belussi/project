/*
 * Copyright (C) 2014, KGblog.pl
 * License: http://www.gnu.org/licenses/gpl.html GPL version 2 or higher
 */

#include <stdint.h>
#include "LPC214x.h"
#include "pll.h"

#define LED16 (1 << 16)

void delay(void)
{
	unsigned long i;
	for (i = 0; i < 60000; i++);
}

int main(void)
{
	MAMCR = 2;
	uint8_t pll_cfg = 0x23;

	pll_init(pll_cfg, APBDIV4);
	IODIR1 |= LED16;

	while(1)
	{
		IOSET1 |= LED16;
		delay();
		IOCLR1 |= LED16;
		delay();
	}
	return 0;
}
