#include "mainwindow.h"
#include "./ui_mainwindow.h"

#include <QFileDialog>

#include "romdialog.h"
#include "rom.h"

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
    Gb::Rom rom(filename.toStdString());

    RomDialog romDialog(rom, this);
    romDialog.exec();
}

