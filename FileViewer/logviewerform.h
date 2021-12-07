#ifndef LOGVIEWERFORM_H
#define LOGVIEWERFORM_H

#include <QWidget>
#include "ifile.h"
#include "popupwindow.h"
#include <QTextDocument>

namespace Ui {
class LogViewerForm;
}

class LogViewerForm : public QWidget, public ILogViewer
{
    Q_OBJECT

public:
    explicit LogViewerForm(IFile *model ,QWidget *parent = nullptr);
    ~LogViewerForm();
    void updateModel();
    bool isShown();
    void show_it();
    void dropWindow(QWidget* Popup);

private slots:
    void on_exitButton_clicked();

    void on_copyButton_clicked();

    void on_findButton_clicked();

    void on_findLineEdit_returnPressed();

private:
    QTextDocument *documentHistory;
    QVector<QWidget*> Popups;
    IFile *file;
    Ui::LogViewerForm *ui;
};

#endif // LOGVIEWERFORM_H
