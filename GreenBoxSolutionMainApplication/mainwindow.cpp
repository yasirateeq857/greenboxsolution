#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "styles/Styles.h"
#include "greenboxsolutionappformnavigator.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{


    this->setWindowFlags(Qt::CustomizeWindowHint);
    this->setWindowFlags(Qt::FramelessWindowHint);

   this->setFixedSize(601,530);

    ui->setupUi(this);

    this->setStyleSheet(Ui::MAIN_WINDOW_STYLE);




    if(GreenBoxSolutionAppFormNavigator::Instance()->Initialize(ui->centralwidget) == true)
    {

        GreenBoxSolutionAppFormNavigator::Instance()->setMainWindow(this);

      //  GreenBoxSolutionAppFormNavigator::Instance()->ShowForm(GreenBoxSolutionAppFormNavigator::STARTUP);
      // GreenBoxSolutionAppFormNavigator::Instance()->ShowForm(GreenBoxSolutionAppFormNavigator::ZINTBARCODE);
       GreenBoxSolutionAppFormNavigator::Instance()->ShowForm(GreenBoxSolutionAppFormNavigator::USBDEVICEINTERFACE);

    }


   }



MainWindow::~MainWindow()
{
    /*if(GreenBoxSolutionAppFormNavigator::Instance() != NULL)
    {
        GreenBoxSolutionAppFormNavigator::Instance()->dimScreen(false);
    }*/

    delete ui;
}

