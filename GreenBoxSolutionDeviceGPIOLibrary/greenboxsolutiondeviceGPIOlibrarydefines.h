#ifndef GREENBOXSOLUTIONDEVICEGPIOLIBRARYDEFINES_H
#define GREENBOXSOLUTIONDEVICEGPIOLIBRARYDEFINES_H


enum PORT_DIR
{
    INP=0,
    OUTP=1

};


#define VALUE_MAX 30
#define DIRECTION_MAX 35

#define LOW  0
#define HIGH 1

#define PIN  24 /* P1-18 */ //YA | note the physical pin number and pin number in the virtual GPIO file
#define POUT 4  /* P1-07 */


#endif // GREENBOXSOLUTIONDEVICEGPIOLIBRARYDEFINES_H
