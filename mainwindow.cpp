#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->comboBox->addItem("Raspberry Pi 3");
    QString dstPath = "/media/roopkumar/Downloads/2.txt";

    if(QFile::exists(config_path))
    QFile::remove(config_path);
    qDebug()<<QDir::currentPath();
    QFile::copy(QDir::currentPath()+"/buildroot-2019.05.1/minimal_raspberrypi_config/minimal_defconfig",config_path);


    //read_script();

    if(check_status()==0){
        sh_read();
    }

     if(pw==true){
        Initialization ini;
        ini.adjustSize();
        ini.move(QApplication::desktop()->screen()->rect().center() - ini.rect().center());
        ini.setModal(true);
        ini.exec();
     }

    /*if(check_status()==100)
    {
        foreach (const QStorageInfo &storage, QStorageInfo::mountedVolumes())
        {
           if((QString)storage.device() != "tmpfs")
             ui->comboBox->addItem((QString)storage.rootPath());
        }
    }*/
}

MainWindow::~MainWindow()
{
    delete ui;
}


/*
 * -------------------------------------------------------
 * Run the shell script with the requirements installation
 * -------------------------------------------------------
*/

void MainWindow::sh_read(){
    /*
     * ---------------------------------------------
     * Ask for the correct password
     * ---------------------------------------------
    */

        //sh_param2 = QInputDialog::getText(this, tr("This action requires password"),tr("Root psw:"), QLineEdit::Password,"", &ok);
        QInputDialog *ask_pw = new QInputDialog(this);
        ask_pw->setLabelText("User password:");
        ask_pw->setWindowTitle("This action requires password");
        ask_pw->setTextEchoMode(QLineEdit::Password);
        ask_pw->adjustSize();
        ask_pw->move(QApplication::desktop()->screen()->rect().center() - ask_pw->rect().center());
        if(ask_pw->exec() == QDialog::Accepted){
                sh_param2 = ask_pw->textValue();
                qDebug()<<"caralhitos";
                check_for_requirements();
        }
        else
            sh_read();

}

/*
 * ---------------------------------------------
 * Slot that receives SIGNAL from password check
 * ---------------------------------------------
*/
void MainWindow::check_for_requirements()
{
    sh_params<<param1<<sh_param2;
    qDebug()<<sh_params;
    check_pw->setWorkingDirectory(QDir::currentPath());
    check_pw->start(QCoreApplication::applicationDirPath()+"/hello.sh", sh_params);
    qDebug()<<"Your password is: "<<sh_param2;

    if(!check_pw->waitForStarted()){
        QMessageBox::information(this, "error","Error openning script");
        qDebug()<<"error openning script";
    }
    check_pw->waitForFinished(-1);

   // usr_pw=check_pw->readAllStandardOutput();

    usr_pw=check_pw->readAllStandardError();
    //ui->textBrowser->append(check_pw->readAllStandardError());
    if(usr_pw.contains("Sorry, try again"))
        {
           //check password again
            qDebug()<<"INCORRECT PASSWORD WELELE";
            check_pw->kill();
            ui->textBrowser->append("INCORRECT PASSWORD\n");
            sh_param1="0";
            sh_param2.clear();
            sh_params.clear();
            sh_read();

        }
    else
        pw=true;


}


int MainWindow::check_status(){

    QString initfile = QCoreApplication::applicationDirPath()+"/init.txt";
    QFile init(initfile);
    if(init.open(QIODevice::ReadOnly)){
        QString tmp;
        QTextStream s1(&init);
        tmp.append(s1.readAll());
        if(tmp.isNull())
            status=0;
        else
            status=tmp.mid(7,3).toInt();

        return status;
    }

}

void MainWindow::on_pushButton_clicked()
{
    QString img_dir = QFileDialog::getExistingDirectory();
    QMessageBox::information(this, tr("Your img directory"),img_dir);
}

void MainWindow::on_pushButton_2_clicked()
{

    QProcess process;

        process.start("ls");
        process.waitForFinished();

        QString output(process.readAllStandardOutput());
        ui->textEdit->setText(output);
        qDebug()<<output;


}
void MainWindow::config(QString config_line)
{

/*    QFile fs("/buildroot-2019.05.1/minimal_raspberrypi_config/configs/minimal_defconfig");
    fs.open(QIODevice::ReadOnly);
    QFile fd("/buildroot-2019.05.1/minimal_raspberrypi_config/configs/tailorOS_defconfig");
    fd.open(QIODevice::WriteOnly);
    fd.write((char*) fs.map(0, fs.size()), fs.size()); //Copies all data

    fd.close();
    fs.close();

*/
    QFile file(config_path);
    if(!file.exists()){
        qDebug() << "Can't open "<<config_path;
    }else{
        qDebug() << config_path<<" is open";
    }
    QString configs;
    ui->textEdit->clear();
    if (file.open(QIODevice::ReadWrite | QIODevice::Text)){
        QTextStream stream(&file);
        while (!stream.atEnd()){
            configs = stream.readLine();
            ui->textEdit->setText(ui->textEdit->toPlainText()+configs+"\n");

            if(stream.atEnd())
            {
                if(!configs.contains(config_line, Qt::CaseSensitivity()))
                    stream << config_line <<endl;

                else    ui->textEdit->setText(config_line);

            }
        }

       //QTextStream stream(&file);

    }
    file.close();
}

/*
 * -------------------------
 * WRITE CONFIGS
 * -------------------------
*/

void MainWindow::on_pushButton_3_clicked()
{

    if(!bit_pw & bit_ssh){
        QMessageBox::warning(this, tr("My Application"),
                             tr("The password is not set. SSH won't be available.\n"),
                             QMessageBox::Discard);
    }

   if(bit_ssh){
       config(activate_ssh);
       bit_ssh=false;
   }

   if(bit_pw){
       config(activate_pw);
       bit_pw=false;
   }
   if(bit_py) {
       config(deactivate_py);
       config(activate_wchar);
       config(activate_mmu);
       config(activate_threads);
       config(activate_dinamic_libs);
       bit_py=false;
   }
   if(bit_py3) {
       config(activate_py3);
       bit_py3=false;
   }

   br_make();

   /*QProcess make;

       QString tmp_dir=config_path;
       QString make_external="make BR2_EXTERNAL=";
       QString total_make = make_external + external_dir;
       make.setWorkingDirectory(QDir::currentPath()+"/minimal_raspberrypi_buildroot-master/buildroot-2019.05.1");
       qDebug()<<"buildroot dir"<<QDir::currentPath()+"/minimal_raspberrypi_buildroot-master/buildroot-2019.05.1";
       make.start(make_external+QDir::currentPath()+"/minimal_raspberrypi_buildroot-master");
       qDebug()<<"executing this"<<QDir::currentPath()+"/minimal_raspberrypi_buildroot-master";
       make.waitForFinished();

       QString output(make.readAllStandardOutput());
       QString error(make.readAllStandardError());
       ui->textEdit->setText(output);
       qDebug()<<output << error;*/
}
/*
 * ---------------------------------------------
 * SSH
 * ---------------------------------------------
 */
void MainWindow::on_checkBox_clicked()
{
    bit_ssh=1;
}


/*
 * ---------------------------------------------
 * ROOT PASSWORD
 * ---------------------------------------------
*/
void MainWindow::on_checkBox_5_stateChanged(int arg1)
{
    //BR2_TARGET_GENERIC_ROOT_PASSWD=""
        bool ok = true;
        if (!bit_pw && usr_pw.isNull()){
            bit_pw = true;
            usr_pw = QInputDialog::getText(this, tr("Enter password"),tr("Root psw:"), QLineEdit::Password,"", &ok);
            qDebug()<<"Your password is: "<<usr_pw;
           // activate_pw=activate_pw+usr_pw;
            QString q_mark = "\"";
            activate_pw=activate_pw+q_mark+usr_pw+q_mark;
            ui->textEdit->setText(activate_pw);
        }

        else {
            usr_pw = QString();
            activate_pw="BR2_TARGET_GENERIC_ROOT_PASSWD=";
            bit_pw= false;
        }


}

/*
 * ---------------------------------------------
 * PYTHON UTILITIES
 * ---------------------------------------------
*/

void MainWindow::on_checkBox_6_clicked()
{
    bit_py=1;
}

/*
 * ____________________________________________
 * PYTHON3
 * --------------------------------------------
*/
void MainWindow::on_checkBox_3_stateChanged(int arg1)
{
    bit_py3=1;
}

void MainWindow::br_make()
{
    make->setWorkingDirectory(QDir::currentPath() + "/buildroot-2019.05.1");
    make->start(QCoreApplication::applicationDirPath() + "/make.sh");

    if(!make->waitForStarted()){
        QMessageBox::information(this, "error","Error openning script");
    }

    connect(make,
            SIGNAL(readyReadStandardOutput()),
            this,
            SLOT(make_output()));

    connect(make,
            SIGNAL(readyReadStandardError()),
            this,
            SLOT(make_output()));
}



void MainWindow::make_output(){
    QString tmp;
    ui->textEdit->setText("Making...");

    ui->textEdit->clear();
    // ui->textEdit->append(make->readAllStandardOutput());
     tmp=make->readAllStandardOutput();
   //  ui->textEdit->append(make->readAllStandardError());
     tmp=tmp.append(make->readAllStandardError());
     qDebug()<<tmp;
     ui->textEdit->setText(tmp);

}


void MainWindow::on_checkBox_4_stateChanged(int arg1)
{
   // bit_ssh=1;
}
