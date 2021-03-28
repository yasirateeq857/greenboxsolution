#ifndef GREENBOXSOLUTIONUSBDEVICELIBRARY_H
#define GREENBOXSOLUTIONUSBDEVICELIBRARY_H

/*
 * generic_hid.c
 *
 *  Created on: Apr 22, 2011
 *      Author: Jan Axelson
 *
 * Demonstrates communicating with a device designed for use with a generic HID-class USB device.
 * Sends and receives 2-byte reports.
 * Requires: an attached HID-class device that supports 2-byte
 * Input, Output, and Feature reports.
 * The device firmware should respond to a received report by sending a report.
 * Change VENDOR_ID and PRODUCT_ID to match your device's Vendor ID and Product ID.
 * See Lvr.com/winusb.htm for example device firmware.
 * This firmware is adapted from code provided by Xiaofan.
 * Note: libusb error codes are negative numbers.*/


#include "../../CCompiled_Libraries/libusb/libusb.h"
#include <QTextStream>
#include <QFile>
#include <QString>
#include "errno.h"

#define VENDOR_ID 1155  //vendor ID of mine STM32F446RE
#define  PRODUCT_ID 22352  //product ID of //

class GreenBoxSolutionUSBDeviceLibrary: public QObject
{
     Q_OBJECT

private:





public:

    GreenBoxSolutionUSBDeviceLibrary();
    ~GreenBoxSolutionUSBDeviceLibrary();

    // Change these as needed to match idVendor and idProduct in your device's device descriptor.


    QString RawDataToString(unsigned char *rawData, int offset, int length);
    // Values for bmRequestType in the Setup transaction's Data packet.

    static const int CONTROL_REQUEST_TYPE_IN = LIBUSB_ENDPOINT_IN | LIBUSB_REQUEST_TYPE_CLASS | LIBUSB_RECIPIENT_INTERFACE;
    static const int CONTROL_REQUEST_TYPE_OUT = LIBUSB_ENDPOINT_OUT | LIBUSB_REQUEST_TYPE_CLASS | LIBUSB_RECIPIENT_INTERFACE;

    // From the HID spec:

    static const int HID_GET_REPORT = 0x01;
    static const int HID_SET_REPORT = 0x09;
    static const int HID_REPORT_TYPE_INPUT = 0x01;
    static const int HID_REPORT_TYPE_OUTPUT = 0x02;
    static const int HID_REPORT_TYPE_FEATURE = 0x03;

    // With firmware support, transfers can be > the endpoint's max packet size.

    unsigned int MAX_CONTROL_IN_TRANSFER_SIZE = 32;
    unsigned int MAX_CONTROL_OUT_TRANSFER_SIZE = 32;

    unsigned int INTERFACE_NUMBER = 0;
    unsigned int TIMEOUT_MS = 5000;

    int exchange_feature_reports_via_control_transfers(libusb_device_handle *devh);
    int exchange_input_and_output_reports_via_control_transfers(libusb_device_handle *devh);
    int exchange_input_and_output_reports_via_interrupt_transfers(libusb_device_handle *devh);

     //QString data =  RawDataToString(recvData, 4, recvData[0] - 5);



};

#endif // GREENBOXSOLUTIONUSBDEVICELIBRARY_H
