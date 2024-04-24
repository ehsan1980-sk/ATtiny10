#include <util/delay.h>

#define B1 2

void setup() {
        DDRB |= B1;  //  Set bit #1 to 1 to enable GPIO1 as OutPut
}

void loop() {
       PORTB |= B1;        //  Set GPIO1 to HIGH
       _delay_ms( 1000 );  //  wait for 1000 mSec
       PORTB &= ~B1;       //  Set GPIO1 to LOW
       _delay_ms( 1000 );  //  wait for 1000 mSec
}
