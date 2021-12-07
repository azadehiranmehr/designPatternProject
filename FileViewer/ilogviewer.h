#ifndef ILOGVIEWER_H
#define ILOGVIEWER_H
#include <QClipboard>

class ILogViewer{
public:
    virtual void updateModel() = 0;
    virtual bool isShown() = 0;
    virtual void show_it() = 0;
    virtual void dropWindow(QWidget* Popup) = 0;
};

#endif // ILOGVIEWER_H
