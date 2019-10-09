#include "mainwindow.h"
#include "initialization.h"
#include <QApplication>
#include <QFile>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    //w.adjustSize();
    w.move(QApplication::desktop()->screen()->rect().center() - w.rect().center());

    qDebug()<<"trying to";
    qDebug()<<w.check_status();
    if(w.check_status()==100)
        w.show();

    qDebug()<<"CURRENT WORKING DIRECTORY:"<<QCoreApplication::applicationDirPath();

    QDir br_dir(QCoreApplication::applicationDirPath());

    return a.exec();
}
