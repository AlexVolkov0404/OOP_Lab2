QT       += core gui multimedia testlib

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    alarm.cpp \
    editconstructor.cpp \
    icon.cpp \
    main.cpp \
    mainwindow.cpp \
    settings.cpp \
    sorting.cpp \
    testalarm.cpp \
    testdel.cpp \
    testsorts.cpp \
    testtimer.cpp \
    timeoutwindow.cpp \
    timer.cpp \
    timerconstructor.cpp \
    timerdelete.cpp

HEADERS += \
    alarm.h \
    editconstructor.h \
    icon.h \
    mainwindow.h \
    settings.h \
    sorting.h \
    testalarm.h \
    testdel.h \
    testsorts.h \
    testtimer.h \
    timeoutwindow.h \
    timer.h \
    timerconstructor.h \
    timerdelete.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    Resources/AlarmClock.wav \
    Resources/add.png \
    Resources/delete.png \
    Resources/deleteAll.png \
    Resources/edit.png \
    Resources/info.png \
    Resources/stop.jpg

RESOURCES += \
    resourses.qrc

STATECHARTS +=

