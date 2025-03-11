#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui
{
class MainWindow;
}
QT_END_NAMESPACE

typedef struct cpuid_reg_contents
{
    uint32_t pfr0;
    uint32_t pfr1;
    uint32_t dfr0;
    uint32_t afr0;
    uint32_t mmfr0;
    uint32_t mmfr1;
    uint32_t mmfr2;
    uint32_t mmfr3;
    uint32_t isar0;
    uint32_t isar1;
    uint32_t isar2;
    uint32_t isar3;
    uint32_t isar4;
    uint32_t isar5;
} cpuid_reg_contents;

class MainWindow : public QMainWindow
{
    Q_OBJECT

  public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void poweroff();
    void exitApplication();
    void setRegAddr();
    void readRegAddr();

  private:
    Ui::MainWindow *ui;

    void readAndDisplayCPUIDData();
    cpuid_reg_contents register_data;
};
#endif // MAINWINDOW_H
