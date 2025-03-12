#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    this->setWindowState(Qt::WindowFullScreen);
    ui->setupUi(this);

    QObject::connect(ui->exitButton, &QPushButton::clicked, this, &MainWindow::exitApplication);
    QObject::connect(ui->powerOffButton, &QPushButton::clicked, this, &MainWindow::poweroff);
    QObject::connect(ui->setRegAddrButton, &QPushButton::clicked, this, &MainWindow::setRegAddr);
    QObject::connect(ui->readRegAddrButton, &QPushButton::clicked, this, &MainWindow::readRegAddr);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::readAndDisplayCPUIDData()
{
    this->ui->ID_PFR0_le->setText(QString("%1").arg(this->register_data.pfr0, 0, 16));
    this->ui->ID_PFR1_le->setText(QString("%1").arg(this->register_data.pfr1, 0, 16));
    this->ui->ID_DFR0_le->setText(QString("%1").arg(this->register_data.dfr0, 0, 16));
    this->ui->ID_AFR0_le->setText(QString("%1").arg(this->register_data.afr0, 0, 16));
    this->ui->ID_MMFR0_le->setText(QString("%1").arg(this->register_data.mmfr0, 0, 16));
    this->ui->ID_MMFR1_le->setText(QString("%1").arg(this->register_data.mmfr1, 0, 16));
    this->ui->ID_MMFR2_le->setText(QString("%1").arg(this->register_data.mmfr2, 0, 16));
    this->ui->ID_MMFR3_le->setText(QString("%1").arg(this->register_data.mmfr3, 0, 16));
    this->ui->ID_ISAR0_le->setText(QString("%1").arg(this->register_data.isar0, 0, 16));
    this->ui->ID_ISAR1_le->setText(QString("%1").arg(this->register_data.isar1, 0, 16));
    this->ui->ID_ISAR2_le->setText(QString("%1").arg(this->register_data.isar2, 0, 16));
    this->ui->ID_ISAR3_le->setText(QString("%1").arg(this->register_data.isar3, 0, 16));
    this->ui->ID_ISAR4_le->setText(QString("%1").arg(this->register_data.isar4, 0, 16));
    this->ui->ID_ISAR5_le->setText(QString("%1").arg(this->register_data.isar5, 0, 16));
}

void MainWindow::poweroff()
{
}

void MainWindow::exitApplication()
{
    exit(0);
}

void MainWindow::setRegAddr()
{
}

void MainWindow::readRegAddr()
{
    readAndDisplayCPUIDData();
}
