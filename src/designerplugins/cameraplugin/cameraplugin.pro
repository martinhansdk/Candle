CONFIG += plugin designer
TEMPLATE = lib
QT += widgets multimedia multimediawidgets

TARGET = cameraplugin

HEADERS +=  overlay.h \
            camerawidget.h \
            cameraplugin.h

SOURCES +=  overlay.cpp \
            camerawidget.cpp \
            cameraplugin.cpp
