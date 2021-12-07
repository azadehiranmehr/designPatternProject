#ifndef TEXTFILE_H
#define TEXTFILE_H

#include "ifile.h"

class TextFile : public IFile
{
private:
    QVector<ILogViewer*> views;

    QFile *file;
    QString history;
public:
    TextFile();
    TextFile(QString addr);
    ~TextFile();
    void addView(ILogViewer* view);
    bool isValid();
    bool isAccessible();
    void update();
    QString getText();
    void show();
    QString name();
};

#endif // TEXTFILE_H
