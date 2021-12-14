#ifndef ROMDIALOG_H
#define ROMDIALOG_H

#include <QDialog>

#include "rom.h"

namespace Ui {
class RomDialog;
}

class RomDialog : public QDialog
{
    Q_OBJECT

public:
    explicit RomDialog(const Gb::Rom& rom, QWidget *parent = nullptr);
    ~RomDialog();

private:
    Gb::Rom::AttributeValuePairs attributeValuePairs;
    Ui::RomDialog *ui;
};

#endif // ROMDIALOG_H
