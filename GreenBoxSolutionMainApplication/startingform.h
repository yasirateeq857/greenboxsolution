#ifndef STARTINGFORM_H
#define STARTINGFORM_H
#include <QWidget>

namespace Ui {
class StartingForm;
}

class StartingForm : public QWidget
{
    Q_OBJECT

public:
    explicit StartingForm(QWidget *parent = nullptr);
    ~StartingForm();
    void initialize();

private:
    Ui::StartingForm *ui;
};

#endif // STARTINGFORM_H
