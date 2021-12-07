#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "logviewerform.h"
#include <QFileDialog>
#include <QMainWindow>
#include "FileCreator.h"
#include <QStringListModel>
#include <QTimer>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


private slots:
    void openTextFile();
    void selectDirectory();
    void updateAllModels();
    void on_selectedFileView_doubleClicked(const QModelIndex &index);

    void on_pushButton_clicked();

private:
    QTimer *timer;
    Directory localDirectory;
    QStringListModel *dataModel;
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
