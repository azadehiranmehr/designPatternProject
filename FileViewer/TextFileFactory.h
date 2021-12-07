#ifndef TEXTFILEFACTORY_H
#define TEXTFILEFACTORY_H
#include "AbstractFileFactory.h"
#include "textfile.h"

class TextFileFactory : AbstractFileFactory
{
public:
    IFile* create(QString addr) {return new TextFile(addr);}
};

#endif // TEXTFILEFACTORY_H
