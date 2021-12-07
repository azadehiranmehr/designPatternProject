#include "popupwindow.h"
#include "ui_popupwindow.h"

PopupWindow::PopupWindow(QString text , ILogViewer *viewer, QWidget  *parent) :
    QWidget(parent),
    ui(new Ui::PopupWindow)
{
    ui->setupUi(this);
    ui->textBrowser->setText(text);
    this->viewer = viewer;
}

PopupWindow::~PopupWindow()
{
    delete ui;
}

void PopupWindow::on_closeButton_clicked()
{
    close();

}

void PopupWindow::closeEvent(QCloseEvent *event){
    viewer->dropWindow(this);
}
