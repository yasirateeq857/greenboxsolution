#include "startingform.h"
#include "ui_startingform.h"
#include "greenboxsolutionlogginglibrary.h"

StartingForm::StartingForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::StartingForm)
{
    ui->setupUi(this);

}

StartingForm::~StartingForm()
{
    delete ui;
}

void StartingForm::initialize()
{

GreenBoxSolutionLoggingLibrary::Instance()->AddToLogFile(APPLICATION,"Starting first form\n");

}
