#include "greenboxsolutionusbdevicelibrary.h"

#include <pthread.h>
#include <QCoreApplication>
#include <QDebug>

#include <QThread>
#include <QTextStream>
#include "greenboxsolutionlogginglibrary.h"


GreenBoxSolutionUSBDeviceLibrary::GreenBoxSolutionUSBDeviceLibrary()
{

}

GreenBoxSolutionUSBDeviceLibrary::~GreenBoxSolutionUSBDeviceLibrary()
{

}


// Uses control transfers to write a Feature report to the HID
// and receive a Feature report from the HID.
// Returns - zero on success, libusb error code on failure.
int GreenBoxSolutionUSBDeviceLibrary::exchange_feature_reports_via_control_transfers(libusb_device_handle *devh)
{

    int bytes_received;
    int bytes_sent;
    unsigned char data_in[MAX_CONTROL_IN_TRANSFER_SIZE];
    unsigned char data_out[MAX_CONTROL_OUT_TRANSFER_SIZE];	int i = 0;
    int result = 0;

    // Store example data in the output buffer for sending.
    // This example uses binary data.

    for (i=0;i < MAX_CONTROL_OUT_TRANSFER_SIZE; i++)
    {
        data_out[i]=0x30+i;
    }

    // Send data to the device.

    bytes_sent = libusb_control_transfer(
            devh,
            CONTROL_REQUEST_TYPE_OUT ,
            HID_SET_REPORT,
            (HID_REPORT_TYPE_FEATURE<<8)|0x00,
            INTERFACE_NUMBER,
            data_out,
            sizeof(data_out),
            TIMEOUT_MS); //TIMEOUT_MS

    //libusb_control_transfer
    //    (mDevHandle, CMD_REQUEST_TYPE, CMD_REQUEST, 0x200, 0, cmdData, length, 0);



    if (bytes_sent >= 0)
    {
        qDebug("Feature report data sent:\n");
        for(i = 0; i < bytes_sent; i++)
        {
            qDebug("%02x ",data_out[i]);
        }
        qDebug("\n");

        // Request data from the device.

        bytes_received = libusb_control_transfer(
                devh,
                CONTROL_REQUEST_TYPE_IN ,
                HID_GET_REPORT,
                (HID_REPORT_TYPE_FEATURE<<8)|0x00,
                INTERFACE_NUMBER,
                data_in,
                MAX_CONTROL_IN_TRANSFER_SIZE,
                TIMEOUT_MS);

        if (bytes_received >= 0)
        {
            qDebug("Feature report data received:\n");
            for(i = 0; i < bytes_received; i++)
            {
                qDebug("%02x ",data_in[i]);
            }
            qDebug("\n");
        }
        else
        {
            //qDebug()->stderr;
            qDebug()<<stderr<<"Error receiving Feature report %d\n"<<result;
            return result;
        }
    }
    else
    {
        //stderror
        qDebug()<<stderr<<"Error sending Feature report %d\n"<<result;
        return result;
    }
    return 0;


}

// Uses control transfers to write an Output report to the HID
// and receive an Input report from the HID.
// Returns - zero on success, libusb error code on failure.
int GreenBoxSolutionUSBDeviceLibrary::exchange_input_and_output_reports_via_control_transfers(libusb_device_handle *devh)
{

        unsigned int bytes_received;
        unsigned int bytes_sent;
        unsigned char data_in[MAX_CONTROL_IN_TRANSFER_SIZE];
        unsigned char data_out[MAX_CONTROL_OUT_TRANSFER_SIZE];
        unsigned int i = 0;
        int result = 0;

        // Store example data in the output buffer for sending.
        // This example uses binary data.

        for (i=0;i < MAX_CONTROL_OUT_TRANSFER_SIZE-10; i++)
        {
            data_out[i]=i;
        }

        // Send data to the device.

        bytes_sent = libusb_control_transfer(
                devh,
                CONTROL_REQUEST_TYPE_OUT ,
                HID_SET_REPORT,
                (HID_REPORT_TYPE_OUTPUT<<8)|0x00,
                INTERFACE_NUMBER,
                data_out,
                sizeof(data_out),
                TIMEOUT_MS);

        qDebug("Bytes sent =%d",bytes_sent);

        if (bytes_sent >= 0)
        {
            qDebug("Output report data sent:\n");
            for(i = 0; i < bytes_sent; i++)
            {
                qDebug("%d ",data_out[i]);
            }
            qDebug("\n");

            // Request data from the device.

            bytes_received = libusb_control_transfer(
                    devh,
                    CONTROL_REQUEST_TYPE_IN ,
                    HID_GET_REPORT,
                    (HID_REPORT_TYPE_INPUT<<8)|0x00,
                    INTERFACE_NUMBER,
                    data_in,
                    MAX_CONTROL_IN_TRANSFER_SIZE,
                    TIMEOUT_MS);
            qDebug("Bytes received =%d",bytes_received);

            if (bytes_received >= 0)
            {
                qDebug("Input report data received:\n");
                for(i = 0; i < bytes_received; i++)
                {
                    qDebug("%d ",data_in[i]);
                }
                qDebug("\n");
            }
            else
            {
                //stderr
                qDebug()<<stderr<<"Error receiving Input report %d\n"<<result;
                return result;
            }
        }
        else
        {

            qDebug()<<stderr<<"Error sending Input report %d\n"<<result;
            return result;
        }
        return 0;




}


// Use interrupt transfers to to write data to the device and receive data from the device.
// Returns - zero on success, libusb error code on failure.
int GreenBoxSolutionUSBDeviceLibrary::exchange_input_and_output_reports_via_interrupt_transfers(libusb_device_handle *devh)
{
    // Assumes interrupt endpoint 2 IN and OUT:

        static const int INTERRUPT_IN_ENDPOINT = 0x81;
        static const int INTERRUPT_OUT_ENDPOINT = 0x01;

        // With firmware support, transfers can be > the endpoint's max packet size.

        static const int MAX_INTERRUPT_IN_TRANSFER_SIZE = 2;
        static const int MAX_INTERRUPT_OUT_TRANSFER_SIZE = 2;

        int bytes_transferred;
        int i = 0;
        int result = 0;;

        unsigned char data_in[MAX_INTERRUPT_IN_TRANSFER_SIZE];
        unsigned char data_out[MAX_INTERRUPT_OUT_TRANSFER_SIZE];

        // Store data in a buffer for sending.

        for (i=0;i < MAX_INTERRUPT_OUT_TRANSFER_SIZE; i++)
        {
            data_out[i]=0x40+i;
        }
        // Write data to the device.

        result = libusb_interrupt_transfer(
                devh,
                INTERRUPT_OUT_ENDPOINT,
                data_out,
                MAX_INTERRUPT_OUT_TRANSFER_SIZE,
                &bytes_transferred,
                TIMEOUT_MS);

        if (result >= 0)
        {
            qDebug("Data sent via interrupt transfer:\n");
            for(i = 0; i < bytes_transferred; i++)
            {
                qDebug("%02x ",data_out[i]);
            }
            qDebug("\n");

            // Read data from the device.

            result = libusb_interrupt_transfer(
                    devh,
                    INTERRUPT_IN_ENDPOINT,
                    data_in,
                    MAX_INTERRUPT_OUT_TRANSFER_SIZE,
                    &bytes_transferred,
                    TIMEOUT_MS);

            if (result >= 0)
            {
                if (bytes_transferred > 0)
                {
                    qDebug("Data received via interrupt transfer:\n");
                    for(i = 0; i < bytes_transferred; i++)
                    {
                        qDebug("%02x ",data_in[i]);
                    }
                    qDebug("\n");
                }
                else
                {
                    //sterr
                    qDebug()<<stderr<<"No data received in interrupt transfer (%d)\n"<<result;
                    return -1;
                }
            }
            else
            {
                //stderr
                qDebug()<<stderr<<"Error receiving data via interrupt transfer %d\n"<< result;
                return result;
            }
        }
        else
        {
            //stderr
            qDebug()<<stderr<<"Error sending data via interrupt transfer %d\n"<<result;
            return result;
        }
        return 0;

}




QString GreenBoxSolutionUSBDeviceLibrary::RawDataToString(unsigned char *rawData, int offset, int length)
{

    QString resultData = "";
    char aChar;

    for(int i = 0; i < length; i++)
    {
        aChar = (char)rawData[i + offset];

        if (((int)aChar) > 47 &&  ((int)aChar) < 123 ) // only ascii from 48 to 122
        {
           resultData = resultData + aChar;
        }

    }

   return resultData;
}



