//-----------------------------------------------------------------
// Name:	Coulston
// File:	lab7.c
// Date:	Fall 2014
// Purp:	Collect analog samples from P1.3 and P1.4
//-----------------------------------------------------------------
#include "msp430g2553.h"
#include "SensorLibr.h"

void initMSP430();

//----------------------------------------------------------------------
//----------------------------------------------------------------------


void moveForward(){

	//For the Left
	P2OUT |= BIT0;
	P2OUT &= ~BIT1;
	TA1CCTL1 = OUTMOD_3;

	//For the Right
	P2OUT |= BIT5;
	P2OUT |= BIT3;
	TA1CCTL2 = OUTMOD_7;
}

void moveBackward(){

	//For the Left
	P2OUT |= BIT0;
	P2OUT |= BIT1;
	TA1CCTL1 = OUTMOD_7;

	//For the Right
	P2OUT |= BIT5;
	P2OUT &= ~BIT3;
	TA1CCTL2 = OUTMOD_3;
}

void stopMoving(){

	P2OUT &= ~BIT1;
	P2OUT &= BIT3;
}

void rotateRight(){

	//For the Left
	P2OUT |= BIT0;
	P2OUT &= ~BIT1;
	TA1CCTL1 = OUTMOD_3;

	// For the Right
	P2OUT |= BIT5;
	P2OUT &= ~BIT3;
	TA1CCTL2 = OUTMOD_3;
}

void rotateLeft(){

	//For the Left
	P2OUT |= BIT0;
	P2OUT |= BIT1;
	TA1CCTL1 = OUTMOD_7;

	//For the Right
	P2OUT |= BIT5;
	P2OUT |= BIT3;
	TA1CCTL2 = OUTMOD_7;
}

short senseLeft(){

	// Configure P1.4 to be the ADC input for the Left

		ADC10CTL0 = 0;											// Turn off ADC subsystem
		ADC10CTL1 = INCH_4 | ADC10DIV_3 ;						// Channel 4, ADC10CLK/4
		ADC10AE0 = BIT4;		 								// Make P1.4 analog input
		ADC10CTL0 = SREF_0 | ADC10SHT_3 | ADC10ON | ENC;		// Vcc & Vss as reference

		ADC10CTL0 |= ADC10SC;									// Start a conversion
		while(ADC10CTL1 & ADC10BUSY);							// Wait for conversion to complete
		return ADC10MEM;										// collect that 10-bit value
}


short senseRight(){

	// Configure P1.5 to be the ADC input for Right

		ADC10CTL0 = 0;											// Turn off ADC subsystem
		ADC10CTL1 = INCH_5 | ADC10DIV_3 ;						// Channel 3, ADC10CLK/4
		ADC10AE0 = BIT5;		 								// Make P1.3 analog input
		ADC10CTL0 = SREF_0 | ADC10SHT_3 | ADC10ON | ENC;		// Vcc & Vss as reference

		ADC10CTL0 |= ADC10SC;									// Start a conversion
		while(ADC10CTL1 & ADC10BUSY);							// Wait for conversion to complete
		return ADC10MEM;									// collect that 10-bit value
}

short senseCenter(){

		// Configure P1.3 to be the ADC input for Center

		ADC10CTL0 = 0;											// Turn off ADC subsystem
		ADC10CTL1 = INCH_3 | ADC10DIV_3 ;						// Channel 3, ADC10CLK/4
		ADC10AE0 = BIT3;		 								// Make P1.3 analog input
		ADC10CTL0 = SREF_0 | ADC10SHT_3 | ADC10ON | ENC;		// Vcc & Vss as reference

		ADC10CTL0 |= ADC10SC;									// Start a conversion
		while(ADC10CTL1 & ADC10BUSY);							// Wait for conversion to complete
		return ADC10MEM;									// collect that 10-bit value
}
