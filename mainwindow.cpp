#include "mainwindow.h"
#include "./ui_mainwindow.h"

#include <QFileDialog>

#include "romdialog.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionLoad_ROM_triggered()
{
    auto filename = QFileDialog::getOpenFileName(this);

    // TODO: add GbCore class
    // TODO: GbCore::loadRom, if GbRom::isLoaded() => open dialog
    RomDialog romDialog(this);
    romDialog.exec();
}

