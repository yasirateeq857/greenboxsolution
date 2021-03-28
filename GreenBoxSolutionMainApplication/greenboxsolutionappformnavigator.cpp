#include "greenboxsolutionappformnavigator.h"
#include "QDebug"

GreenBoxSolutionAppFormNavigator* GreenBoxSolutionAppFormNavigator::mInstance = 0;

GreenBoxSolutionAppFormNavigator::GreenBoxSolutionAppFormNavigator()
{

    mDeviceGPIOLibrary = new GreenBoxSolutionDeviceGPIOLibrary;
    mUSBDeviceLibrary = new GreenBoxSolutionUSBDeviceLibrary;
    mCurrentForm = STARTUP;
    mLastForm = STARTUP;

}

GreenBoxSolutionAppFormNavigator::~GreenBoxSolutionAppFormNavigator()
{
}

GreenBoxSolutionAppFormNavigator* GreenBoxSolutionAppFormNavigator::Instance()
{
    if(mInstance == 0)
    {
        mInstance = new GreenBoxSolutionAppFormNavigator;
    }

    return mInstance;
}

bool GreenBoxSolutionAppFormNavigator::Initialize(QObject* parent)
{
   // GreenBoxSolutionLoggingLibrary::Instance()->AddToLog(OUT, APPLICATION, INFO, Q_FUNC_INFO, "Initializing application");

    if(parent == NULL)
    {
        return false;
    }

    mParent = parent;

    mStartingForm = new StartingForm((QWidget *) mParent);
    mUSBDeviceStatusForm = new USBDeviceStatusForm((QWidget *) mParent);
    mRaspberryPIDeviceForm = new RaspberryPIDeviceForm((QWidget *) mParent);
    mZintTestForm = new ZintTestForm((QWidget *) mParent);

    return true;
}


void GreenBoxSolutionAppFormNavigator::ShowForm(GBAPP_FORMS formId)
{
   GreenBoxSolutionLoggingLibrary::Instance()->AddToLogFile(APPLICATION,"New Form: " + QString::number(formId));

    for (int i = 0; i < mParent->children().count(); i++ )
    {
        if(QWidget *widget = qobject_cast<QWidget *>( mParent->children().at(i)))
        {
            if(widget->isVisibleTo(qobject_cast<QWidget *>(mParent)))
            {
                widget->hide();
            }
        }
    }


    switch(formId)
    {
    case STARTUP:
        mLastForm = STARTUP;
        mStartingForm->initialize();
        mStartingForm->show();
        break;

    case USBDEVICEINTERFACE:
        mUSBDeviceStatusForm->initialize();
        mUSBDeviceStatusForm->show();
        break;

    case RASPBERRYIO:
        mRaspberryPIDeviceForm->show();
        break;

    case ZINTBARCODE:
        mZintTestForm->initialize();
        GreenBoxSolutionLoggingLibrary::Instance()->AddToLogFile(APPLICATION,"Now Show zintform\n");
        mZintTestForm->show();
        break;

    }



}

bool GreenBoxSolutionAppFormNavigator::SetProperty(const char *propertyName, const QVariant &value)
{
    if(mParent == NULL)
    {
        return false;
    }

    GreenBoxSolutionLoggingLibrary::Instance()->AddToLogFile(APPLICATION, QString(propertyName) + "=" + value.toString());

    return mParent->setProperty(propertyName, value);
}

QVariant GreenBoxSolutionAppFormNavigator::GetProperty(const char *name)
{
    if(mParent == NULL)
    {
        return QVariant();
    }

    GreenBoxSolutionLoggingLibrary::Instance()->AddToLogFile(APPLICATION,name);

    return mParent->property(name);
}



void GreenBoxSolutionAppFormNavigator::setMainWindow(QMainWindow* mainwindow)
{
    mainWindow = mainwindow;
}



