QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    about.cpp \
    generatesample.cpp \
    main.cpp \
    mainwindow.cpp \
    math.cpp \
    probdist.cpp \
    pvalues.cpp \
    random.cpp

HEADERS += \
    about.h \
    generatesample.h \
    mainwindow.h \
    math.h \
    probdist.h \
    pvalues.h \
    random.h

FORMS += \
    about.ui \
    generatesample.ui \
    mainwindow.ui \
    pvalues.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
