/********************************************************************************
** Form generated from reading UI file 'downloads.ui'
**
** Created by: Qt User Interface Compiler version 5.12.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DOWNLOADS_H
#define UI_DOWNLOADS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QTextBrowser>

QT_BEGIN_NAMESPACE

class Ui_Downloads
{
public:
    QLabel *label;
    QTextBrowser *textBrowser;
    QProgressBar *progressBar;
    QLabel *label_2;

    void setupUi(QDialog *Downloads)
    {
        if (Downloads->objectName().isEmpty())
            Downloads->setObjectName(QString::fromUtf8("Downloads"));
        Downloads->resize(400, 300);
        label = new QLabel(Downloads);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(110, 50, 171, 121));
        label->setPixmap(QPixmap(QString::fromUtf8("../build-Custom_OS_BR-Desktop_Qt_5_12_3_GCC_64bit-Debug/logo.png")));
        label->setScaledContents(true);
        textBrowser = new QTextBrowser(Downloads);
        textBrowser->setObjectName(QString::fromUtf8("textBrowser"));
        textBrowser->setGeometry(QRect(110, 180, 171, 31));
        progressBar = new QProgressBar(Downloads);
        progressBar->setObjectName(QString::fromUtf8("progressBar"));
        progressBar->setGeometry(QRect(110, 230, 171, 23));
        progressBar->setValue(24);
        label_2 = new QLabel(Downloads);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(100, 70, 67, 17));

        retranslateUi(Downloads);

        QMetaObject::connectSlotsByName(Downloads);
    } // setupUi

    void retranslateUi(QDialog *Downloads)
    {
        Downloads->setWindowTitle(QApplication::translate("Downloads", "Dialog", nullptr));
        label->setText(QString());
        textBrowser->setHtml(QApplication::translate("Downloads", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Ubuntu'; font-size:11pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Downloading Buildroot</p></body></html>", nullptr));
        label_2->setText(QApplication::translate("Downloads", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Downloads: public Ui_Downloads {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DOWNLOADS_H
