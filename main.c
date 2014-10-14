#include <msp430.h>
#include "pong.h"

/*
 * main.c
 */
int main(void)
{
    WDTCTL = WDTPW | WDTHOLD;	// Stop watchdog timer
	
    // Create ball with radius 2 at pixel (60, 90) with velocity (2, 2)
    ball_st volly = makeBall(2, 90, 60, 2, 2);

    while(1)
    {
    	volly = moveBall(volly);
    }

	return 0;
}
