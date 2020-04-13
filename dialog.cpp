#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    setWindowTitle("About");
    setWindowIcon(QIcon(":/img/ac.png"));
    connect(ui->pushButton,SIGNAL(clicked()),this,SLOT(accept()));
}

Dialog::~Dialog()
{
    delete ui;
}
