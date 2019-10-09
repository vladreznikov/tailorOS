#include "initialization.h"
#include "ui_initialization.h"
#include <QString>
#include <QDate>
#include <QTextStream>


Initialization::Initialization(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Initialization)
{
    qDebug()<<"afterinfo";
    ui->setupUi(this);
    QPixmap br_logo(lwd);
    qDebug()<<"hello"<<lwd;
    ui->label_pic->setPixmap(br_logo.scaled(300,300,Qt::KeepAspectRatio));
    ui->label_pic->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
    ui->progressBar->setValue(0);
    load_buildroot();



}

Initialization::~Initialization()
{
    delete ui;
}

/*
 * ---------------------------------------------
 * Run the script that downloads and sets the BR
 * ---------------------------------------------
*/

void Initialization::load_buildroot(){

    QStringList params;
    param1="download";
    params<<param1<<param2<<"2";
    shell_script->setWorkingDirectory(QDir::currentPath());
    qDebug()<<params;
    shell_script->start(QCoreApplication::applicationDirPath() + "/hello.sh", params);

    qDebug()<<QCoreApplication::applicationDirPath() + "/hello.sh";

    if(!shell_script->waitForStarted()){
        QMessageBox::information(this, "error","Error openning script");
    }

    connect(shell_script,
            SIGNAL(readyReadStandardOutput()),
            this,
            SLOT(sh_output()));

    connect(shell_script,
            SIGNAL(readyReadStandardError()),
            this,
            SLOT(sh_output()));

}




void Initialization::sh_output(){
    QString tmp;
    //qDebug()<<"shoutput";
    // ui->textBrowser->append(shell_script->readAllStandardOutput());
     tmp=shell_script->readAllStandardOutput();
     //ui->textBrowser->append(shell_script->readAllStandardError());
     tmp=tmp.append(shell_script->readAllStandardError());
     qDebug()<<tmp;
     ui->textBrowser->setText(tmp);
     if(tmp.contains("status=001")){
         ui->progressBar->setValue(5);
     }

     if(tmp.contains("status=002") && !finish)
        {
            //status=3;
            //on_progressBar_valueChanged(50);
            ui->progressBar->setValue(15);

            //ui->textBrowser->append("coise 2 aqui");
        }

     if(tmp.contains("status=003") && !finish){
        // ui->textBrowser->setText(tmp);
         //ui->label->setText("Downloading Buildroot");
         ui->progressBar->setValue(35);

     }

     if(tmp.contains("status=004") && !finish){
         ui->progressBar->setValue(50);
         //ui->textBrowser->setText("STATUS 4");
         ui->label->clear();
         ui->label->setText("Installing Packages");
         //status=100;
     }

     if(tmp.contains("status=010") && !finish){
         ui->progressBar->setValue(65);
         //ui->textBrowser->setText("STATUS 10");
         ui->label->clear();
         ui->label->setText("Configuring Buildroot");
     }

     if(tmp.contains("status=020") && !finish){
         ui->progressBar->setValue(90);
         //ui->textBrowser->setText("STATUS 20");
         ui->label->clear();
         ui->label->setText("Configuring Buildroot");
     }
     if((tmp.contains("status=100") || status==100) && !finish){
         ui->progressBar->setValue(100);
            //status=100;
            finish=true;
            shell_script->kill();
            this->close();
        }

     //else qDebug()<<"what else?";

     tmp.clear();

}

void Initialization::write_log()
{
    QString filename = QCoreApplication::applicationDirPath()+"/minimal_raspberrypi_buildroot-master/init.txt";
    QFile file(filename);
    if (file.open(QIODevice::ReadWrite| QIODevice::Truncate | QIODevice::Text)) {
        QTextStream stream(&file);
        stream << QDate::currentDate().toString();
        stream << "\n";
       // stream << shell_script->readAllStandardOutput() << shell_script->readAllStandardError();

    }
    //shell_script->kill();
    //param1="0";

}

/*
 * ---------------------------------------------
 * Check the status of the requirements download
 * ---------------------------------------------
*/

u_int Initialization::check_status(){

    this->exec();

    QString initfile = QCoreApplication::applicationDirPath()+"/minimal_raspberrypi_buildroot-master/init.txt";
    QFile init(initfile);
    if(init.open(QIODevice::ReadOnly)){
        QString tmp;
        QTextStream s1(&init);
        tmp.append(s1.readAll());
        status=tmp.right(2).toInt();

        return status;
    }
}

