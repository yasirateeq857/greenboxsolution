#include "raspberrypideviceform.h"
#include "ui_raspberrypideviceform.h"
#include "greenboxsolutiondevicegpiolibrary.h"
#include "greenboxsolutionappformnavigator.h"
#include <QThread>


RaspberryPIDeviceForm::RaspberryPIDeviceForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::RaspberryPIDeviceForm)
{
    ui->setupUi(this);
}

RaspberryPIDeviceForm::~RaspberryPIDeviceForm()
{
    delete ui;
}
void RaspberryPIDeviceForm::initialize()
{
    int repeat = 10;

        /*
         * Enable GPIO pins
         */
        if (-1 == GreenBoxSolutionDeviceGPIOLibrary::Instance()->GPIOExport(POUT) || -1 ==GreenBoxSolutionDeviceGPIOLibrary::Instance()->GPIOExport(PIN))
            qDebug()<<"GPIO pins issue\n";

        /*
         * Set GPIO directions
         */
        if (-1 == GreenBoxSolutionDeviceGPIOLibrary::Instance()->GPIODirection(POUT, OUT) || -1 == GreenBoxSolutionDeviceGPIOLibrary::Instance()->GPIODirection(PIN, IN))
            qDebug()<<"GPIO pins direction issue\n";

        do {
            /*
             * Write GPIO value
             */
            if (-1 == GreenBoxSolutionDeviceGPIOLibrary::Instance()->GPIOWrite(POUT, repeat % 2))
                qDebug()<<"Write to GPIO issue\n";

            /*
             * Read GPIO value
             */
            qDebug()<<"I'm reading %d in GPIO %d\n"<<GreenBoxSolutionDeviceGPIOLibrary::Instance()->GPIORead(PIN)<<PIN;

            QThread::sleep(500 * 1000);
        }
        while (repeat--);

        /*
         * Disable GPIO pins
         */
        if (-1 == GreenBoxSolutionDeviceGPIOLibrary::Instance()->GPIOUnexport(POUT) || -1 == GreenBoxSolutionDeviceGPIOLibrary::Instance()->GPIOUnexport(PIN))
            qDebug()<<"Disabling GPIO pins issue\n";
}
