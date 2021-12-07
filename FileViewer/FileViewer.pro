QT       += core gui


greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    directory.cpp \
    ifile.cpp \
    logviewerform.cpp \
    main.cpp \
    mainwindow.cpp \
    popupwindow.cpp \
    textfile.cpp

HEADERS += \
    AbstractFileFactory.h \
    DirectoryFactory.h \
    FileCreator.h \
    TextFileFactory.h \
    ilogviewer.h \
    directory.h \
    ifile.h \
    logviewerform.h \
    mainwindow.h \
    popupwindow.h \
    textfile.h

FORMS += \
    logviewerform.ui \
    mainwindow.ui \
    popupwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

