#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "memory_manager.h"

QT_BEGIN_NAMESPACE
namespace Ui
{
class MainWindow;
}
QT_END_NAMESPACE

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
    std::shared_ptr<memory_manager> memory_manager_instance;

    void readAndDisplayCPUIDData();
};
#endif // MAINWINDOW_H
