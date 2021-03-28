#ifndef RASPBERRYPIDEVICEFORM_H
#define RASPBERRYPIDEVICEFORM_H

#include <QWidget>

namespace Ui {
class RaspberryPIDeviceForm;
}

class RaspberryPIDeviceForm : public QWidget
{
    Q_OBJECT

public:
    explicit RaspberryPIDeviceForm(QWidget *parent = nullptr);
    ~RaspberryPIDeviceForm();
    void initialize();

private:
    Ui::RaspberryPIDeviceForm *ui;
};

#endif // RASPBERRYPIDEVICEFORM_H
