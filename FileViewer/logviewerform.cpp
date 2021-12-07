#include "logviewerform.h"
#include "ui_logviewerform.h"

LogViewerForm::LogViewerForm(IFile *model, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::LogViewerForm)
{
    ui->setupUi(this);
    file = model;
    setWindowTitle(file->name());
    documentHistory = new QTextDocument;
    ui->findLineEdit->setFocus();

}

LogViewerForm::~LogViewerForm()
{
    delete ui;
}

bool LogViewerForm::isShown(){return isVisible();}
void LogViewerForm::show_it() { show();}

void LogViewerForm::on_exitButton_clicked()
{
    hide();
}


void LogViewerForm::on_copyButton_clicked()
{

    ui->textBrowser->copy();
    QClipboard *clipboard = QGuiApplication::clipboard();
    QString originalText = clipboard->text();
    Popups.push_back(new PopupWindow(originalText, this));
    Popups.last()->show();

}

void LogViewerForm::updateModel(){
    ui->textBrowser->setText(file->getText());
    ui->textBrowser->document()->allFormats().clear();
    documentHistory->setPlainText(ui->textBrowser->toPlainText());
}
void LogViewerForm::dropWindow(QWidget *Popup){
    Popups.removeAll(Popup);
    delete Popup;
}


void LogViewerForm::on_findButton_clicked()
{
    QString searchLine = ui->findLineEdit->text();
    QTextDocument *document = ui->textBrowser->document();

    bool found = false;

    // undo previous change (if any)
    document->setPlainText(documentHistory->toPlainText());
    if (searchLine.isEmpty()) {
            QMessageBox::information(this, tr("Empty Search Field"), tr("The search field is empty. "
                                        "Please enter at least a word or several words by <,> and click Find."));
        }
    else{
        QStringList searchList = searchLine.split(",");

        foreach(QString searchString, searchList)
        {
            if(searchString.isEmpty())
                continue;
            QTextCursor highlightCursor(document);
            QTextCursor cursor(document);
            cursor.beginEditBlock();
            QTextCharFormat plainFormat(highlightCursor.charFormat());
            QTextCharFormat colorFormat = plainFormat;
            colorFormat.setForeground(Qt::red);
            while (!highlightCursor.isNull() && !highlightCursor.atEnd())
            {
                highlightCursor = document->find(searchString.trimmed(), highlightCursor, QTextDocument::FindWholeWords);
                if (!highlightCursor.isNull())
                {
                    found = true;
                    highlightCursor.movePosition(QTextCursor::WordRight, QTextCursor::KeepAnchor);
                    highlightCursor.mergeCharFormat(colorFormat);
                }
            }
            cursor.endEditBlock();

        }
        if (found == false)
        {
            QMessageBox::information(this, tr("Word Not Found"), tr("Sorry, the word cannot be found."));
        }
    }
}


void LogViewerForm::on_findLineEdit_returnPressed()
{
    ui->findButton->click();
}

