#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    dataModel = new QStringListModel(this);
    ui->selectedFileView->setModel(dataModel);
    timer = new QTimer(this); // create it
    connect(timer, &QTimer::timeout, this, &MainWindow::updateAllModels ); // connect it


    connect(ui->actionOpen_a_text_file, SIGNAL(triggered()), this, SLOT(openTextFile()));
    connect(ui->actionSelect_a_directory, SIGNAL(triggered()), this, SLOT(selectDirectory()));
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::updateAllModels(){
    localDirectory.update();
}
void MainWindow::selectDirectory(){

    QFileDialog dialog;
    QString address = dialog.getExistingDirectory(this,"Select a directory");
    if(!address.isEmpty())
    {
        IFile *diry = FileCreator::create("directory",address);
        diry->update();
        localDirectory.add(diry);

        dataModel->insertRows(dataModel->rowCount(), 1);
        dataModel->setData(dataModel->index(dataModel->rowCount()-1), diry->name());
    }
    else{
        QMessageBox::information(this,"info","No directory selected!");
    }
}
void MainWindow::openTextFile(){

    const QString filters= tr("Log files (*.log *.txt *.xml *.xaml *.html *.json *.dat);;Any files (*)");
    QFileDialog dialog;
    //dialog.setNameFilters(filters);
    //dialog.setMimeTypeFilters(filters);
    QString address = dialog.getOpenFileName(this,"Select a log file",QString(),filters);
    if(!address.isEmpty())
    {
        IFile *file = FileCreator::create("file",address);

        LogViewerForm *logView = new LogViewerForm(file);
        file->addView(logView);
        file->update();
        //QMessageBox::information(this,"info",file->name());
        localDirectory.add(file);

        dataModel->insertRows(dataModel->rowCount(), 1);
        dataModel->setData(dataModel->index(dataModel->rowCount()-1), file->name());

    }
    else{
        QMessageBox::information(this,"info","No file selected!");
    }

}

void MainWindow::on_selectedFileView_doubleClicked(const QModelIndex &index)
{

    localDirectory.getFile(index.row())->show();
    localDirectory.update();
    timer->start(300);
}


void MainWindow::on_pushButton_clicked()
{
    int index = ui->selectedFileView->currentIndex().row();


    dataModel->removeRow(index);
    localDirectory.remove(index);
}

