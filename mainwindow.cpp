#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "hps_0.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    this->setWindowState(Qt::WindowFullScreen);
    ui->setupUi(this);

    QObject::connect(ui->exitButton, &QPushButton::clicked, this, &MainWindow::exitApplication);
    QObject::connect(ui->powerOffButton, &QPushButton::clicked, this, &MainWindow::poweroff);
    QObject::connect(ui->setRegAddrButton, &QPushButton::clicked, this, &MainWindow::setRegAddr);
    QObject::connect(ui->readRegAddrButton, &QPushButton::clicked, this, &MainWindow::readRegAddr);

    this->memory_manager_instance = std::make_shared<memory_manager>();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::readAndDisplayCPUIDData()
{
    std::array<QLineEdit*, 24> line_edits = { ui->midr_le, ui->ctr_le, ui->tcmtr_le, ui->tlbtr_le, ui->mpidr_le,
                                              ui->revidr_le, ui->id_pfr0_le, ui->id_pfr1_le, ui->id_dfr0_le,
                                              ui->id_afr0_le, ui->id_mmfr0_le, ui->id_mmfr1_le, ui->id_mmfr2_le,
                                              ui->id_mmfr3_le, ui->id_isar0_le, ui->id_isar1_le, ui->id_isar2_le,
                                              ui->id_isar3_le, ui->id_isar4_le, ui->id_isar5_le, ui->ccsidr_le,
                                              ui->clidr_le, ui->aidr_le, ui->csselr_le

    };

    uint32_t index = 0;
    std::optional<uint32_t> value = 0;
    for (auto le : line_edits) {
        value = this->memory_manager_instance->read_from_register(LW_FPGA_SLAVES_MEM_REGION, MIDR_BASE + 0x10 * index);
        if (value.has_value()) {
            le->setText(QString("%1").arg(value.value(), 0, 16));
        }
        else {
            le->setText(QString("ERR: Could not get val from reg"));
        }
    }
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
