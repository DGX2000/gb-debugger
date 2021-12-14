#include "romdialog.h"
#include "ui_romdialog.h"

RomDialog::RomDialog(const Gb::Rom& rom, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::RomDialog)
{
    ui->setupUi(this);

    attributeValuePairs = rom.getAttributeValuePairs();

    ui->tableWidget->setRowCount(attributeValuePairs.size());

    int row = 0;
    for(const auto& [attribute, value] : attributeValuePairs)
    {
        QTableWidgetItem* attributeItem = new QTableWidgetItem(QString::fromStdString(attribute));
        QTableWidgetItem* valueItem = new QTableWidgetItem(QString::fromStdString(value));

        ui->tableWidget->setItem(row, 0, attributeItem);
        ui->tableWidget->setItem(row, 1, valueItem);

        ++row;
    }
}

RomDialog::~RomDialog()
{
    delete ui;
}
