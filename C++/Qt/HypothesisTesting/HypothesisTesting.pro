QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    dialog.cpp \
    document.cpp \
    main.cpp \
    mainwindow.cpp \
    negativebinomialbernoulli.cpp \
    negativebinomialtable.cpp \
    r32m.cpp

HEADERS += \
    dialog.h \
    distribution.h \
    document.h \
    mainwindow.h \
    negativebinomialbernoulli.h \
    negativebinomialtable.h \
    r32m.h

FORMS += \
    dialog.ui \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    Resource.qrc
