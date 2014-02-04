/*
 * Copyright (C) 2014, KGblog.pl
 * License: http://www.gnu.org/licenses/gpl.html GPL version 2 or higher
 */

#include "LPC214x.h"

#define LED_MASK 0x00ff0000
#define SEQUENCES_NUM 14

/* LED sequences */
int sequences[SEQUENCES_NUM] = {
		0x00010000,
		0x00020000,
		0x00040000,
		0x00080000,
		0x00100000,
		0x00200000,
		0x00400000,
		0x00800000,
		0x00400000,
		0x00200000,
		0x00100000,
		0x00080000,
		0x00040000,
		0x00020000
};

void delay(unsigned long delay)
{
	unsigned long i;
	for (i = 0; i < delay; i++);
}

/* Initializes LED' pins */
void init_leds(void)
{
	IODIR1 |= LED_MASK;
}

/* Clears LED' pins */
void clear_leds(void)
{
	IOSET1 |= LED_MASK;
}

/* Sets LEDs */
void set_sequence(int sequence)
{
	IOCLR1 |= sequence;
}

/* Sets LED' sequences */
void set_sequences(void)
{
	unsigned int i;

	for (i = 0; i < SEQUENCES_NUM; i++)
	{
		clear_leds();
		set_sequence(sequences[i]);
		delay(45000);
	}
}

int main(void)
{
	MAMCR = 2;
	init_leds();

	while(1)
	{
		set_sequences();
	}
	return 0;
}
