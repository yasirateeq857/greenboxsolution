#ifndef GREENBOXSOLUTIONAPPFORMNAVIGATOR_H
#define GREENBOXSOLUTIONAPPFORMNAVIGATOR_H

#include "globals.h"
#include "mainwindow.h"
#include "raspberrypideviceform.h"
#include "startingform.h"
#include "usbdevicestatusform.h"
#include "zinttestform.h"
#include <QMainWindow>
#include "greenboxsolutionlogginglibrary.h"
#include "greenboxsolutiondevicegpiolibrary.h"
#include "greenboxsolutionusbdevicelibrary.h"

class GreenBoxSolutionAppFormNavigator : public QObject
    {
        Q_OBJECT

    public:
        enum GBAPP_FORMS
        {
            STARTUP,
            USBDEVICEINTERFACE,
            RASPBERRYIO,
            ZINTBARCODE
        };

    private:
        static GreenBoxSolutionAppFormNavigator *mInstance;
        QObject *mParent;

        GBAPP_FORMS mCurrentForm;
        GBAPP_FORMS mLastForm;

        // Designer Forms
        StartingForm* mStartingForm;
        USBDeviceStatusForm* mUSBDeviceStatusForm;
        RaspberryPIDeviceForm* mRaspberryPIDeviceForm;
        ZintTestForm* mZintTestForm;

        //library objs
        GreenBoxSolutionDeviceGPIOLibrary*  mDeviceGPIOLibrary;
        GreenBoxSolutionUSBDeviceLibrary*   mUSBDeviceLibrary;


        // Hide Default Constructor
        GreenBoxSolutionAppFormNavigator();

        ~GreenBoxSolutionAppFormNavigator();

        // Hide Copy Constructor
        GreenBoxSolutionAppFormNavigator(const GreenBoxSolutionAppFormNavigator&);

        // Hide Assign Up
        GreenBoxSolutionAppFormNavigator& operator = (const GreenBoxSolutionAppFormNavigator&);

        QMainWindow* mainWindow;

    //    ScannerController scannerController;

    public:
        void setMainWindow(QMainWindow* mainwindow);
        static GreenBoxSolutionAppFormNavigator* Instance();
        bool Initialize(QObject* parent);
        void ShowForm(GBAPP_FORMS formId);
        bool SetProperty(const char *propertyName, const QVariant &value);
        QVariant GetProperty(const char* name);


};

#endif // GREENBOXSOLUTIONAPPFORMNAVIGATOR_H
