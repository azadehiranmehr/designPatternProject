#ifndef DIRECTORYFACTORY_H
#define DIRECTORYFACTORY_H
#include "AbstractFileFactory.h"
#include "directory.h"

class DirectoryFactory : AbstractFileFactory
{
public:
    IFile* create(QString addr) {return new Directory(addr); }
};
#endif // DIRECTORYFACTORY_H
