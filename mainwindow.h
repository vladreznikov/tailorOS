#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileDialog>
#include <QMessageBox>
#include <QDebug>
#include <QStorageInfo>
#include <QDir>
#include <QProcess>
#include <QCoreApplication>
#include <QInputDialog>
#include <QDebug>
#include <QDesktopWidget>
#include <QDialog>
#include <QThread>
#include "initialization.h"


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    int check_status(void);

    int get_value_status(void) {return status;}




private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_checkBox_clicked();

    void check_for_requirements();

    void on_checkBox_5_stateChanged(int arg1);

    void on_checkBox_6_clicked();

    void on_checkBox_3_stateChanged(int arg1);

    void br_make(void);

    void on_checkBox_4_stateChanged(int arg1);

    void make_output();
private:
    Ui::MainWindow *ui;
    void config(QString config_line);
    void sh_read();



    QString cwd= QCoreApplication::applicationDirPath();
    QString current_path=QDir::currentPath();
    QString config_path=current_path.append("/buildroot-2019.05.1/minimal_raspberrypi_config/configs/tailorOS_defconfig");
    QString minimal_path=current_path.append("/buildroot-2019.05.1/minimal_raspberrypi_config/minimal_defconfig");
   // QString external_dir=current_path.append("/buildroot-2019.05.1/minimal_raspberrypi_buildroot-master");
    QString br_dir=current_path.append("/buildroot-2019.05.1");

    //Features activation
    QString activate_ssh="BR2_PACKAGE_DROPBEAR=y";
    QString activate_pw="BR2_TARGET_GENERIC_ROOT_PASSWD=";
    QString deactivate_py="BR2_PACKAGE_PYTHON=n";
    QString activate_wchar="BR2_USE_WCHAR=y";
    QString activate_mmu="BR2_USE_MMU=y";
    QString activate_threads="BR2_TOOLCHAIN_HAS_THREADS=y";
    QString activate_dinamic_libs="BR2_STATIC_LIBS=n";
    QString activate_py3="BR2_PACKAGE_PYTHON3=y";

    //Bits
    bool bit_ssh = false;
    bool bit_pw = false;
    bool bit_py = false;
    bool bit_py3 = true;

    int status;

    QProcess *shell_script = new QProcess;
    QProcess *check_pw = new QProcess;
    QProcess *make = new QProcess;

    QString lwd= QCoreApplication::applicationDirPath() + "/logo.png";
    bool ok = true;
    QString param1 = "password";
    QString param2;

    QString sh_param1;
    QString sh_param2;

    QString usr_pw;
    QStringList check_pw_params;
    QStringList sh_params;
    bool init = false;

    volatile bool pw = false;

};

#endif // MAINWINDOW_H
