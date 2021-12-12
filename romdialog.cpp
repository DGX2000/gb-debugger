#include "romdialog.h"
#include "ui_romdialog.h"

RomDialog::RomDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::RomDialog)
{
    ui->setupUi(this);
}

RomDialog::~RomDialog()
{
    delete ui;
}
