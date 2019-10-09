#ifndef INITIALIZATION_H
#define INITIALIZATION_H

#include <QDialog>
#include <QPixmap>
#include <QCoreApplication>
#include <QDebug>
#include <QProcess>
#include <QInputDialog>
#include <QDir>
#include <QMessageBox>
#include <QMainWindow>
#include <QtGlobal>
#include <information.h>


namespace Ui {
class Initialization;
}

class Initialization : public QDialog
{
    Q_OBJECT

public:
    explicit Initialization(QWidget *parent = nullptr);
    ~Initialization();
     //u_int status = 0;
    QString logfile = QCoreApplication::applicationDirPath() + "/minimal_raspberrypi_buildroot-master/init.txt";
    QString lol;
    u_int get_value_status(void) {return check_status();}
    u_int get_value_complete(void) {return complete;}


private slots:
    void write_log();

    u_int check_status();

    void sh_output();


private:
    Ui::Initialization *ui;
    QProcess *shell_script = new QProcess;


    QString lwd= QCoreApplication::applicationDirPath() + "/logo.png";
    u_int status = 0;
    u_int complete = 0;
    QString root_pw;
    bool ok = true;
    QString param1 = "0";
    QString param2;
    QString tmp;
    QStringList script_params;
    bool init = false;
    volatile bool finish = false;



    void load_buildroot();


};

#endif // INITIALIZATION_H
