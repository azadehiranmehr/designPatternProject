#include "directory.h"

Directory::Directory(QString addr)
{
    address=addr;
}
Directory::Directory()
{

}
void Directory::add(IFile *element)
{
    files.push_back(element);
}
void Directory::update()
{
    QStringList filters;
    filters << "*.log" << "*.txt"<<"*.xml"<< "*.xaml" << "*.html" << "*.json" << "*.dat";
    QDir dir(address);
    //Directory *diry = new Directory(address);
    QStringList filesName = dir.entryList(filters);
    foreach (const QString &addr , filesName) {
        if(!addr.isEmpty() && !exists(address+"/"+addr)){
            TextFile *file = new TextFile(address+"/"+addr);
            LogViewerForm *logView = new LogViewerForm(file);
            file->addView(logView);
            file->update();
            add(file);
        }
    }

    for(int i=0;i<files.size();i++)
    {
        files[i]->update();
    }
}
QString Directory::getText(){
    QString text = "";
    for(int i=0;i<files.size();i++)
    {
        text += files[i]->getText()+"\n";
    }
    return text;
}
void Directory::show(){
    for(int i=0;i<files.size();i++)
    {
        files[i]->show();
    }
}
QString Directory::name(){
    return address;
}

IFile* Directory::getFile(int index){
    return files[index];
}

bool Directory::exists(QString fileName)
{
    for(int i=0;i<files.size();i++)
    {
        if(getFile(i)->name().compare(fileName)==0)
            return true;
    }
    return false;
}
void Directory::remove(int index){
    files.removeAt(index);
}
Directory::~Directory()
{
    files.clear();
}
void Directory::addView(ILogViewer* view){
    //Do nothing, just overridden
}
