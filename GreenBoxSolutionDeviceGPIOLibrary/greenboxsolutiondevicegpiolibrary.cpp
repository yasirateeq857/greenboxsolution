#include "greenboxsolutiondevicegpiolibrary.h"


GreenBoxSolutionDeviceGPIOLibrary* GreenBoxSolutionDeviceGPIOLibrary::mInstance=0;

GreenBoxSolutionDeviceGPIOLibrary::GreenBoxSolutionDeviceGPIOLibrary()
{

}

GreenBoxSolutionDeviceGPIOLibrary* GreenBoxSolutionDeviceGPIOLibrary::Instance()
{
    if(mInstance==0)
    {

        mInstance = new GreenBoxSolutionDeviceGPIOLibrary();
    }

    return mInstance;

}
int GreenBoxSolutionDeviceGPIOLibrary:: GPIOExport(int pin)
{

    char str_pin[2];

    FILE *sysfs_handle = NULL;
    sysfs_handle = fopen("/sys/class/gpio/export", "w");
    if (sysfs_handle != NULL){


        snprintf(str_pin,(2*sizeof(char)), "%d" , pin);
        fwrite(str_pin, sizeof(char), 2, sysfs_handle);
        qDebug("\nGPIO %d opened for EXPORT\n",pin);
        fclose(sysfs_handle);
        return 0;

    }
    else
    {
        qDebug("\nCan't open gpio/export.  Something went wrong. Are you root?\n");
        return -1;

    }


}

int GreenBoxSolutionDeviceGPIOLibrary::GPIOUnexport(int pin)
{

    char str_pin[2];
    FILE *sysfs_handle = NULL;
    sysfs_handle = fopen("/sys/class/gpio/unexport", "w");
    if (sysfs_handle != NULL){

        snprintf(str_pin,(2*sizeof(char)) , "%d" ,pin);
        fwrite(str_pin, sizeof(char), 2, sysfs_handle);
        qDebug("\nGPIO %d opened for UNEXPORT\n",pin);
        fclose(sysfs_handle);
        return 0;
    }
    else
    {
        qDebug("\nCan't open gpio/unexport.  Something went wrong. Are you root?\n");
        return -1;
    }

}

int GreenBoxSolutionDeviceGPIOLibrary::GPIODirection(int pin, int direction)
{

    char str_dir[4];

    char path[DIRECTION_MAX];

    snprintf(path, DIRECTION_MAX, "/sys/class/gpio/gpio%d/direction", pin);

    FILE *sysfs_handle = NULL;
    sysfs_handle = fopen(path, "w");
    if (sysfs_handle != NULL){

        snprintf(str_dir,(4*sizeof(char)) , "%s" ,(PORT_DIR)(direction) ? "out" : "input");
        fwrite(str_dir, sizeof(char), 2, sysfs_handle);
        qDebug("\nGPIO %d opened for DIRECTION\n",pin);
        fclose(sysfs_handle);
        return 0;
    }
    else
    {
        qDebug("\nCan't set gpio direction.  Something went wrong. Are you root?\n");
        return -1;

    }

}

int GreenBoxSolutionDeviceGPIOLibrary::GPIORead(int pin)
{


    char path[VALUE_MAX];


    snprintf(path, VALUE_MAX, "/sys/class/gpio/gpio%d/value", pin);

    char str_read;
    FILE *sysfs_handle = NULL;
    sysfs_handle = fopen(path, "r");
    if (sysfs_handle != NULL){
        fread(&str_read, sizeof(char), 1, sysfs_handle);
        qDebug("\nGPIO %d opened for READ\n",pin);
        fclose(sysfs_handle);
        return 0;
    }
    else
    {
        qDebug("\nCan't read gpio, Something went wrong. Are you root?\n");
        return -1;

    }



}


int GreenBoxSolutionDeviceGPIOLibrary::GPIOWrite(int pin, int value)
{

    char str_wr[2];

    char path[VALUE_MAX];
    snprintf(path, VALUE_MAX, "/sys/class/gpio/gpio%d/value", pin);

    FILE *sysfs_handle = NULL;
    sysfs_handle = fopen(path, "w");
    if (sysfs_handle != NULL){
        snprintf(str_wr,(2*sizeof(char)) , "%d" ,value);
        fwrite(str_wr, sizeof(char), 2, sysfs_handle);
        qDebug("\nGPIO %d opened for Write\n",pin);
        fclose(sysfs_handle);
        return 0;
    }
    else
    {
        qDebug("\nCan't open write GPIO ,Smething went wrong. Are you root?\n");
        return -1;

    }

}
