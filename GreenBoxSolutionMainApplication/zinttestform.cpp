#include "zinttestform.h"
#include "ui_zinttestform.h"
#include "styles/Styles.h"
#include "greenboxsolutionlogginglibrary.h"
#include "greenboxsolutionqtzintsharedlibrary.h"
#include "QtSvg/qsvgrenderer.h"

ZintTestForm::ZintTestForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ZintTestForm)
{
    ui->setupUi(this);
}

ZintTestForm::~ZintTestForm()
{
    delete ui;
}
void ZintTestForm::initialize()
{

    const  QString filename="./GreenBoxBarcode.svg";
    QString barcode =  "AAWWYA12345678121";
    Zint::GreenBoxSolutionQtZintSharedLibrary *zintobj = new Zint::GreenBoxSolutionQtZintSharedLibrary();
    zintobj->setMode(9);
    zintobj->setText(barcode);
    zintobj->setScale(1.6);
    zintobj->setHeight(100);
    zintobj->setWidth(400);
    zintobj->save_to_file(filename);
    delete zintobj;

    QSvgRenderer svgRenderer(filename);
    QPixmap pix( svgRenderer.defaultSize() );
    QPainter pixPainter( &pix );
    svgRenderer.render( &pixPainter );
    ui->lbl_barcode->setPixmap(pix);
    ui->lbl_barhead->setStyleSheet(Ui::LBL_CODE_STYLE_20);
    ui->lbl_barhead->setText(barcode);
    ui->lbl_header->setPixmap(QPixmap(":/Images/green_box.jpg"));


    GreenBoxSolutionLoggingLibrary::Instance()->AddToLogFile(APPLICATION,"123456");
}
