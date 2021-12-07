#include "textfile.h"

TextFile::TextFile(QString addr)
{
    address = addr;
}
TextFile::TextFile()
{

}
void TextFile::addView(ILogViewer* view){
    views.push_back(view);
}
bool TextFile::isValid() {return !address.isEmpty();}
bool TextFile::isAccessible() {return file->open(QIODevice::ReadOnly);}
void TextFile::update(){

    if(isValid())
    {
        file = new QFile(address);
        if(isAccessible())
        {
            QTextStream tempStream(file);
            QString current = tempStream.readAll();
            //QMessageBox::information(nullptr,"info",tempStream.readAll());
            if(history.compare(current)!=0)
            {
                history = current;
                for(int i=0;i<views.size();i++)
                {
                    //if(views[i]->isShown())
                        views[i]->updateModel();
                }
            }
            file->close();
        }
        else{
            try{
                file->close();
            }
            catch(std::exception exp)
            {}
        }
    }
}
QString TextFile::getText(){
    return history;
}
void TextFile::show(){
    for(int i=0;i<views.size();i++)
    {
        views[i]->show_it();
    }
}
QString TextFile::name(){return address;}

TextFile::~TextFile(){
    delete file;
    views.clear();
}
