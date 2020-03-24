QT += testlib
QT -= gui

CONFIG += qt console warn_on depend_includepath testcase
CONFIG -= app_bundle

TEMPLATE = app

SOURCES +=  tst_strategymodifyinvertedtest.cpp \
    ../Form1/StrategyModify.cpp \
    ../Form1/StrategyModifyInverted.cpp

HEADERS += ../Form1/StrategyModify.h \
    ../Form1/StrategyModifyInverted.h


OPENCV_PATH = ../../opencv
INCLUDEPATH += $$OPENCV_PATH/build/include
Release:LIBS += -L$$OPENCV_PATH/build/x64/vc15/lib -lopencv_world401
Debug:LIBS += -L$$OPENCV_PATH/build/x64/vc15/lib -lopencv_world401d
