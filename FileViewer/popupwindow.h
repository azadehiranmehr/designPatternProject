#ifndef POPUPWINDOW_H
#define POPUPWINDOW_H

#include <QWidget>
#include "ifile.h"

namespace Ui {
class PopupWindow;
}

class PopupWindow : public QWidget
{
    Q_OBJECT

public:
    explicit PopupWindow(QString text, ILogViewer *viewer, QWidget *parent = nullptr);
    ~PopupWindow();

private slots:
    void on_closeButton_clicked();

private:
    void closeEvent(QCloseEvent *bar);
    ILogViewer *viewer;
    Ui::PopupWindow *ui;
};

#endif // POPUPWINDOW_H
