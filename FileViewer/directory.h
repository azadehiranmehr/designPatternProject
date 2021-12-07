#ifndef DIRECTORY_H
#define DIRECTORY_H

#include "textfile.h"
#include "logviewerform.h"

class Directory : public IFile
{
private:
    QVector<IFile*> files;
public:
    Directory();
    Directory(QString addr);
    ~Directory();
    void update();
    void add(IFile* element);
    QString getText();
    void show();
    QString name();
    IFile *getFile(int index);
    void remove(int index);
    bool exists(QString fileName);
    void addView(ILogViewer* view);
};

#endif // DIRECTORY_H
