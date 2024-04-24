// Let the compiler do the hard work

#if (F_CPU/1000000)<5  //  For SYS_CLK < 5 MHz
  #define COMPARE    F_CPU / 64  // Value to load into OutPut Compare A Register
  #define PRE_SCALE  3           // PreScaler option = / 64
#else                  //  For SYS_CLK >= 5 MHz  
  #define COMPARE    F_CPU / 256  // Value to load into OutPut Compare A Register
  #define PRE_SCALE  4            // PreScaler option = / 256
#endif
  
#define B1 2    //  LED is on GPIO B1

void setup () {
  DDRB = B1;    //  Set LED pin to OutPut
  
  TCCR0A = 1<<COM0B0 | 0<<WGM00;  // Toggle OC0B = GPIO B1 using CTC mode

  TCCR0B = 1<<WGM02 | PRE_SCALE<<CS00;  // CTC mode using OCR0A;

  OCR0A    = COMPARE;  //  ( F_CPU / 64 );  // = 15624 --  1 second  ie 0.5Hz

}

void loop () {}  //  just to keep the IDE happy.
