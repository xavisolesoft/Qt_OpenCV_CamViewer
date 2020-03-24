QT += testlib
QT -= gui

CONFIG += qt console warn_on depend_includepath testcase
CONFIG -= app_bundle

TEMPLATE = app

SOURCES +=  tst_strategymodifyinvertedtest.cpp \
    ../Application/StrategyModify.cpp \
   ../Application/StrategyModifyInverted.cpp

HEADERS += StrategyModify.h \
   StrategyModifyInverted.h


OPENCV_PATH = ../../opencv
INCLUDEPATH += $$OPENCV_PATH/build/include ../Application
Release:LIBS += -L$$OPENCV_PATH/build/x64/vc15/lib -lopencv_world401
Debug:LIBS += -L$$OPENCV_PATH/build/x64/vc15/lib -lopencv_world401d
