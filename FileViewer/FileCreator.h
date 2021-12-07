#ifndef FILECREATOR_H
#define FILECREATOR_H
#include "DirectoryFactory.h"
#include "TextFileFactory.h"
class FileCreator{
public:
    static IFile* create(QString type, QString addr){
        if(type.compare("file")==0)
            return TextFileFactory().create(addr);
        if(type.compare("directory")==0)
            return DirectoryFactory().create(addr);
        else return nullptr;
    }
};
#endif // FILECREATOR_H
