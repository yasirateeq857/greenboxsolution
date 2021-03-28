#include "usbdevicestatusform.h"
#include "ui_usbdevicestatusform.h"
#include "greenboxsolutionusbdevicelibrary.h"

USBDeviceStatusForm::USBDeviceStatusForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::USBDeviceStatusForm)
{
    ui->setupUi(this);
}

USBDeviceStatusForm::~USBDeviceStatusForm()
{
    delete ui;
}

void USBDeviceStatusForm::initialize()

{

        GreenBoxSolutionUSBDeviceLibrary *libusbobj= new GreenBoxSolutionUSBDeviceLibrary();
        struct libusb_device_handle *devh = NULL;
        int device_ready = 0;
        int result;

        result = libusb_init(NULL);
        if (result >= 0)
        {
            devh = libusb_open_device_with_vid_pid(NULL, VENDOR_ID, PRODUCT_ID);

            if (devh != NULL)
            {
                libusb_set_option(NULL,LIBUSB_OPTION_LOG_LEVEL,LIBUSB_LOG_LEVEL_WARNING);
                // The HID has been detected.
                // Detach the hidusb driver from the HID to enable using libusb.

                libusb_set_auto_detach_kernel_driver(devh, 1);
                {
                    result = libusb_claim_interface(devh, libusbobj->INTERFACE_NUMBER);
                    if (result >= 0)
                    {
                        device_ready = 1;
                    }
                    else
                    {
                        qDebug()<<stderr<<"libusb_claim_interface error %d\n"<<result;
                    }
                }
            }
            else
            {
                qDebug()<<stderr<<"Unable to find the device.\n";
            }
        }
        else
        {
            qDebug()<<stderr<<"Unable to initialize libusb.\n";
        }

        if (device_ready)
        {
            // Send and receive data.

            //libusbobj->exchange_input_and_output_reports_via_interrupt_transfers(devh);
            //In our STM32F446 only 2 bytes control transfer is found by me @ 07-03-2021
            libusbobj->exchange_input_and_output_reports_via_control_transfers(devh);

            //libusbobj->exchange_feature_reports_via_control_transfers(devh);

            // Finished using the device.

            libusb_release_interface(devh, 0);
        }
        libusb_close(devh);
        libusb_exit(NULL);





}
