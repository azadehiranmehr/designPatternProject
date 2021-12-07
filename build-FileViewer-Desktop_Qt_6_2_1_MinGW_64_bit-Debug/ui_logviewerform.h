/********************************************************************************
** Form generated from reading UI file 'logviewerform.ui'
**
** Created by: Qt User Interface Compiler version 6.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGVIEWERFORM_H
#define UI_LOGVIEWERFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LogViewerForm
{
public:
    QTextBrowser *textBrowser;
    QPushButton *exitButton;
    QPushButton *copyButton;
    QLineEdit *findLineEdit;
    QPushButton *findButton;
    QLabel *label;

    void setupUi(QWidget *LogViewerForm)
    {
        if (LogViewerForm->objectName().isEmpty())
            LogViewerForm->setObjectName(QString::fromUtf8("LogViewerForm"));
        LogViewerForm->resize(400, 600);
        textBrowser = new QTextBrowser(LogViewerForm);
        textBrowser->setObjectName(QString::fromUtf8("textBrowser"));
        textBrowser->setGeometry(QRect(15, 41, 371, 501));
        exitButton = new QPushButton(LogViewerForm);
        exitButton->setObjectName(QString::fromUtf8("exitButton"));
        exitButton->setGeometry(QRect(10, 570, 75, 23));
        copyButton = new QPushButton(LogViewerForm);
        copyButton->setObjectName(QString::fromUtf8("copyButton"));
        copyButton->setGeometry(QRect(310, 570, 75, 23));
        findLineEdit = new QLineEdit(LogViewerForm);
        findLineEdit->setObjectName(QString::fromUtf8("findLineEdit"));
        findLineEdit->setGeometry(QRect(70, 10, 231, 20));
        findButton = new QPushButton(LogViewerForm);
        findButton->setObjectName(QString::fromUtf8("findButton"));
        findButton->setGeometry(QRect(310, 10, 75, 23));
        findButton->setAutoDefault(false);
        label = new QLabel(LogViewerForm);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(20, 10, 47, 13));

        retranslateUi(LogViewerForm);

        findButton->setDefault(false);


        QMetaObject::connectSlotsByName(LogViewerForm);
    } // setupUi

    void retranslateUi(QWidget *LogViewerForm)
    {
        LogViewerForm->setWindowTitle(QCoreApplication::translate("LogViewerForm", "Form", nullptr));
        exitButton->setText(QCoreApplication::translate("LogViewerForm", "Exit", nullptr));
        copyButton->setText(QCoreApplication::translate("LogViewerForm", "Copy", nullptr));
        findButton->setText(QCoreApplication::translate("LogViewerForm", "Find", nullptr));
        label->setText(QCoreApplication::translate("LogViewerForm", "Search:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class LogViewerForm: public Ui_LogViewerForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGVIEWERFORM_H
