CONFIG += plugin 
TEMPLATE = lib
QT += widgets multimedia multimediawidgets designer

TARGET = cameraplugin

HEADERS +=  overlay.h \
            camerawidget.h \
            cameraplugin.h

SOURCES +=  overlay.cpp \
            camerawidget.cpp \
            cameraplugin.cpp
