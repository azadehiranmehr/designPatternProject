#ifndef IFILE_H
#define IFILE_H
#include <QMessageBox>
#include <QFile>
#include <QDir>
#include <QTextStream>
#include "ilogviewer.h"

class IFile
{

protected:
    QString address;
public:
    IFile();
    virtual ~IFile() {};
    //virtual bool isValid() = 0;
    //virtual bool isAccessible() = 0;
    virtual QString name() = 0;
    virtual void update() = 0;
    virtual QString getText() = 0;
    virtual void show() = 0;
    virtual void addView(ILogViewer*) = 0;
};

#endif // IFILE_H
