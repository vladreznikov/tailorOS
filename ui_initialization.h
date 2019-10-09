/********************************************************************************
** Form generated from reading UI file 'initialization.ui'
**
** Created by: Qt User Interface Compiler version 5.12.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INITIALIZATION_H
#define UI_INITIALIZATION_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QTextBrowser>

QT_BEGIN_NAMESPACE

class Ui_Initialization
{
public:
    QLabel *label_pic;
    QProgressBar *progressBar;
    QLabel *label;
    QTextBrowser *textBrowser;

    void setupUi(QDialog *Initialization)
    {
        if (Initialization->objectName().isEmpty())
            Initialization->setObjectName(QString::fromUtf8("Initialization"));
        Initialization->resize(597, 575);
        label_pic = new QLabel(Initialization);
        label_pic->setObjectName(QString::fromUtf8("label_pic"));
        label_pic->setGeometry(QRect(50, 50, 491, 321));
        progressBar = new QProgressBar(Initialization);
        progressBar->setObjectName(QString::fromUtf8("progressBar"));
        progressBar->setGeometry(QRect(40, 460, 521, 25));
        progressBar->setValue(24);
        label = new QLabel(Initialization);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(240, 440, 161, 17));
        textBrowser = new QTextBrowser(Initialization);
        textBrowser->setObjectName(QString::fromUtf8("textBrowser"));
        textBrowser->setGeometry(QRect(45, 381, 511, 71));

        retranslateUi(Initialization);

        QMetaObject::connectSlotsByName(Initialization);
    } // setupUi

    void retranslateUi(QDialog *Initialization)
    {
        Initialization->setWindowTitle(QApplication::translate("Initialization", "Dialog", nullptr));
        label_pic->setText(QString());
        label->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Initialization: public Ui_Initialization {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INITIALIZATION_H
