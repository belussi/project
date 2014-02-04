/*
 * Copyright (C) 2014, KGblog.pl
 * License: http://www.gnu.org/licenses/gpl.html GPL version 2 or higher
 */

#include "LPC214x.h"

#define LED0 (1 << 16)
#define LED1 (1 << 17)
#define PIN0 (1 << 1)
#define PIN1 (1 << 2)

void init(void)
{
	// Set P1.16 and P1.17 as outputs.
	IODIR1 |= (LED0 | LED1);
	// Set P0.1 and P0.2 as inputs.
	IODIR0 &= ~(PIN0 | PIN1);

	IOSET1 |= LED0 | LED1;
}

void led_on(int led)
{
	IOCLR1 |= led;
}

void led_off(int led)
{
	IOSET1 |= led;
}

/* Function is used to change state of a LED using suitable button. */
void switch_led(int led, int button, int *marker)
{
	int counter = 0;

	if ((IOPIN0 & button) == 0)
	{
		while((IOPIN0 & button) == 0) counter++;
		if (counter >= 1000)
		{
			if (*marker == 0)
			{
				led_on(led);
				(*marker) = 1;
			}
			else
			{
				led_off(led);
				(*marker) = 0;
			}
			counter = 0;
		}
	}
}

int main(void)
{
	MAMCR = 2;
	int led0_marker = 0;
	int led1_marker = 0;

	init();
	while(1)
	{
		switch_led(LED0, PIN0, &led0_marker);
		switch_led(LED1, PIN1, &led1_marker);
	}

	return 0;
}
