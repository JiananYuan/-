#include "youwin.h"
#include "ui_youwin.h"

youwin::youwin(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::youwin)
{
    ui->setupUi(this);
    setWindowTitle("Congratulations!");
    setWindowIcon(QIcon(":/img/icon.jpg"));
    connect(ui->confirm,SIGNAL(clicked(bool)),this,SLOT(accept()));
}

youwin::~youwin()
{
    delete ui;
}
