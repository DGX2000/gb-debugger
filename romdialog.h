#ifndef ROMDIALOG_H
#define ROMDIALOG_H

#include <QDialog>

namespace Ui {
class RomDialog;
}

class RomDialog : public QDialog
{
    Q_OBJECT

public:
    explicit RomDialog(QWidget *parent = nullptr);
    ~RomDialog();

private:
    Ui::RomDialog *ui;
};

#endif // ROMDIALOG_H
