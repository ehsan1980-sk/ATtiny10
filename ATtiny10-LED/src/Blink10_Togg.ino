#include <util/delay.h>

#define B1 2  //  GPIO B1 is controlled by Bit #2 in the Registers

void setup() {
        DDRB |= B1;  //  Set bit #2 to 1 to enable GPIO1 as OutPut
}

void loop() {
        PINB |= B1;        //  Toggle GPIO1
       _delay_ms( 1000 );  //  wait for 1000 mSec
}
