#ifndef GREENBOXSOLUTIONDEVICEGPIOLIBRARY_H
#define GREENBOXSOLUTIONDEVICEGPIOLIBRARY_H


#include <QString>
#include <QFile>
#include "greenboxsolutiondeviceGPIOlibrarydefines.h"

class GreenBoxSolutionDeviceGPIOLibrary
{

private:

    static GreenBoxSolutionDeviceGPIOLibrary* mInstance;

public:
    GreenBoxSolutionDeviceGPIOLibrary();
    int GPIOExport(int pin);
    int GPIOUnexport(int pin);
    int GPIODirection(int pin, int direction);
    int GPIORead(int pin);
    int GPIOWrite(int pin,int value);
    static GreenBoxSolutionDeviceGPIOLibrary* Instance();

};

#endif // GREENBOXSOLUTIONDEVICEGPIOLIBRARY_H
