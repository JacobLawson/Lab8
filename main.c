//-----------------------------------------------------------------
// Name:	Coulston
// File:	lab7.c
// Date:	Fall 2014
// Purp:	Collect analog samples from P1.3 and P1.4
//-----------------------------------------------------------------
#include "msp430g2553.h"
#include "sensorLibr.h"

void initMSP430();

//----------------------------------------------------------------------
//----------------------------------------------------------------------
int main(void) {

	WDTCTL = WDTPW|WDTHOLD;                 // stop the watchdog timer

	    // Left
	    P2DIR |= BIT0;	// 1,2EN as OUT
	    P2DIR |= BIT1;  // Sets direction of left motor
	    P2DIR |= BIT2;							// P2.2 is associated with TA1CCR
	    P2SEL |= BIT2;							// P2.2 is associated with TA1CCTL1

		// Right
	   	P2DIR |= BIT5;  // 3,4EN as OUT
	   	P2DIR |= BIT3;  //direction of right motor
	   	P2DIR |= BIT4;							// P2.2 is associated with TA1CCR2
	   	P2SEL |= BIT4;							// P2.2 is associated with TA1CCTL2

	    TA1CTL = ID_3 | TASSEL_2 | MC_1;		// Use 1:8 presclar off MCLK
	    TA1CCR0 = 0x0100;						// set signal period

	    TA1CCR1 = 0x40;
	    TA1CCTL1 = OUTMOD_7;					// set TACCTL1 to Reset / Set mode

	    TA1CCR2 = 0x40;						// set TACCTL2 to Set / Reset mode
	    TA1CCTL2 = OUTMOD_3;


	int state=1;							// Just to analyze the values


	IFG1=0; 													// clear interrupt flag1
	WDTCTL = WDTPW + WDTHOLD;									// disable WDT

	BCSCTL1 = CALBC1_8MHZ;										// 8MHz clock
	DCOCTL = CALDCO_8MHZ;

//
	while(1) {

		if (senseLeft() > 0x0200)	{		//If the robot turns too close to the wall, it will turn away from it.
			stopMoving();
			__delay_cycles(delay);
			rotateRight();
			__delay_cycles(halfturn);
			moveForward();
			__delay_cycles(fullturn);
			P1DIR = BIT0;
			P1OUT |= BIT0;
		}	else  P1OUT &= ~BIT0;

		if (senseLeft() < 0x0BB){			//If the robot gets to far away from the wall, it will turn towards it
			stopMoving();
			__delay_cycles(delay);
			rotateLeft();
			__delay_cycles(halfturn);
			moveForward();
			__delay_cycles(fullturn);
			P1DIR = BIT6;
			P1OUT |= BIT6;
		} else P1OUT &= ~BIT6;
//
//
		if (senseCenter() > 0x01F0)	{  		//If the robot senses a wall from ahead, it will turn right
			stopMoving();
			__delay_cycles(delay);
		   	rotateRight();
		    __delay_cycles(halfturn);
			P1DIR = BIT6|BIT0;
			P1OUT |= BIT6|BIT0;
		}	else  P1OUT &= ~BIT6|~BIT0;


		moveForward();							Moves the robot forward at a slow pace if nothing else happens
		__delay_cycles(slow);
		stopMoving();
		__delay_cycles(slow);

	} // end infinite loop

} // end main
