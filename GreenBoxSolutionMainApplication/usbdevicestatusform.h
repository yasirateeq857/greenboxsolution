#ifndef USBDEVICESTATUSFORM_H
#define USBDEVICESTATUSFORM_H

#include <QWidget>
#include <QTextStream>
#include <QDebug>

namespace Ui {
class USBDeviceStatusForm;
}

class USBDeviceStatusForm : public QWidget
{
    Q_OBJECT

public:
    explicit USBDeviceStatusForm(QWidget *parent = nullptr);
    ~USBDeviceStatusForm();
    void initialize();

private:
    Ui::USBDeviceStatusForm *ui;
};

#endif // USBDEVICESTATUSFORM_H
