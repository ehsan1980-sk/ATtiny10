
#include <util/delay.h>

// #include "Seg7.h"

// Let the compiler do the hard work

#if (F_CPU/1000000)<5  //  For SYS_CLK < 5 MHz
  #define COMPARE    F_CPU / 64  // Value to load into OutPut Compare A Register
  #define PRE_SCALE  1           // PreScaler option = / 64
#else                  //  For SYS_CLK >= 5 MHz  
  #define COMPARE    F_CPU / 256  // Value to load into OutPut Compare A Register
  #define PRE_SCALE  2            // PreScaler option = / 256
#endif

#define B1 2

#define INVERT_mode    2
#define nonINVERT_mode 3

#define OVF_irq   1 // Enable OverFlow IRQ
#define COMPA_irq 2 // Enable CMPA IRQ
#define COMPB_irq 4 // Enable CMPB IRQ

ISR( TIM0_COMPB_vect ) {  //  We will change the OCR0B value in increments of 128 (80HEX)
  if( OCR0B > 0x82 ) { OCR0B -= 0x80; } else { OCR0B = 0x3F80; } 
}

void setup() {

  DIDR0 = 0x08;  //  Disable GPIO on B3 - RST/ADC3
  DDRB  = B1;    //  Set LED pin to OutPut

  TCCR0A = INVERT_mode<<COM0B0 | 0<<WGM00;  // Toggle OC0B = GPIO B1 using PWM mode

  TCCR0B = 2<<WGM02 | PRE_SCALE<<CS00;  // PWM mode 8 using ICR0 as TOP

  ICR0  = 0x4000;  // This is TOP
  OCR0B = 0x2000;  // This value set the PW - here set to 50%

  TIMSK0 |= COMPB_irq;
  sei();    

/**
  Seg7_init();   //  this will set B0, B1, B2 to OUTPUT for both the Seg7 and the 74HC595
  Seg7_clear( 0 );	   //		Cleat the Seg7 display starting at position 0
   _delay_ms( 125 );
   Seg7_hex( 0x29, 0 );
   _delay_ms( 382 );
**/   
//  Seg7_hex( OCR0A, 0 );
//  Seg7_hex( TCCR0B, 4 );  // write the value 0xA3 to the display - we will be displaying the value of ADC3
//  Seg7_dec( OCR0A,  4 );
//  Seg7_dec( 54321,  5 );

// Seg7_hex( 0x6B, 1 );
}

void loop() {

//   Seg7_hex( icnt,  0 );  // This is for my 7Segment LED Debug Display
//   Seg7_hex( TCNT0, 4 );
//   _delay_ms( 1000 );

}
