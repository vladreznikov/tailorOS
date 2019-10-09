#include "information.h"
#include "ui_information.h"

Information::Information(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Information)
{
    ui->setupUi(this);
    ui->textBrowser->append("BOMDIA");
}

Information::~Information()
{
    delete ui;
}
