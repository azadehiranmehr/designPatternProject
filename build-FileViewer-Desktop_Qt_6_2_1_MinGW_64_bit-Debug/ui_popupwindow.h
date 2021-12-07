/********************************************************************************
** Form generated from reading UI file 'popupwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_POPUPWINDOW_H
#define UI_POPUPWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_PopupWindow
{
public:
    QTextBrowser *textBrowser;
    QPushButton *closeButton;

    void setupUi(QWidget *PopupWindow)
    {
        if (PopupWindow->objectName().isEmpty())
            PopupWindow->setObjectName(QString::fromUtf8("PopupWindow"));
        PopupWindow->resize(400, 300);
        textBrowser = new QTextBrowser(PopupWindow);
        textBrowser->setObjectName(QString::fromUtf8("textBrowser"));
        textBrowser->setGeometry(QRect(10, 10, 381, 231));
        closeButton = new QPushButton(PopupWindow);
        closeButton->setObjectName(QString::fromUtf8("closeButton"));
        closeButton->setGeometry(QRect(20, 260, 75, 23));

        retranslateUi(PopupWindow);

        QMetaObject::connectSlotsByName(PopupWindow);
    } // setupUi

    void retranslateUi(QWidget *PopupWindow)
    {
        PopupWindow->setWindowTitle(QCoreApplication::translate("PopupWindow", "Popup", nullptr));
        closeButton->setText(QCoreApplication::translate("PopupWindow", "Close", nullptr));
    } // retranslateUi

};

namespace Ui {
    class PopupWindow: public Ui_PopupWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_POPUPWINDOW_H
