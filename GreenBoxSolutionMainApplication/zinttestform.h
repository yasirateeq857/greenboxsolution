#ifndef ZINTTESTFORM_H
#define ZINTTESTFORM_H

#include <QWidget>

namespace Ui {
class ZintTestForm;
}

class ZintTestForm : public QWidget
{
    Q_OBJECT

public:
    explicit ZintTestForm(QWidget *parent = nullptr);
    ~ZintTestForm();
    void initialize();

private:
    Ui::ZintTestForm *ui;
};

#endif // ZINTTESTFORM_H
