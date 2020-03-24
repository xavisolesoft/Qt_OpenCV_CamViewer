#-------------------------------------------------
#
# Project created by QtCreator 2019-03-25T17:20:32
#
#-------------------------------------------------

QT       += core gui widgets concurrent

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = CamViewer
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

OPENCV_PATH = ../../opencv
INCLUDEPATH += $$OPENCV_PATH/build/include
Release:LIBS += -L$$OPENCV_PATH/build/x64/vc15/lib -lopencv_world401
Debug:LIBS += -L$$OPENCV_PATH/build/x64/vc15/lib -lopencv_world401d

SOURCES += \
    MainWindow.cpp \
    VideoController.cpp \
        main.cpp \
    FrameGrabber.cpp \
    StrategyModify.cpp \
    StrategyModifyWB.cpp \
    StrategyModifyInverted.cpp

HEADERS += \
    FrameGrabber.h \
    MainWindow.h \
    StrategyModify.h \
    StrategyModifyWB.h \
    StrategyModifyInverted.h \
    VideoController.h

FORMS += \
    MainWindow.ui
