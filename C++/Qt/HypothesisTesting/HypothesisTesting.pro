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
    nb_bernoulli.cpp \
    nb_distribution.cpp \
    nb_generator.cpp \
    nb_table.cpp \
    r32m.cpp

HEADERS += \
    dialog.h \
    document.h \
    mainwindow.h \
    nb_bernoulli.h \
    nb_distribution.h \
    nb_generator.h \
    nb_table.h \
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
