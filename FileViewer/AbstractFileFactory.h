#ifndef ABSTRACTFILEFACTORY_H
#define ABSTRACTFILEFACTORY_H
#include "ifile.h"
class AbstractFileFactory{
public:
    virtual IFile* create(QString addr) = 0;
};

#endif // ABSTRACTFILEFACTORY_H
