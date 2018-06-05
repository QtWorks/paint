#-------------------------------------------------
#
# Project created by QtCreator 2018-03-15T12:55:43
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = paint
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    newcanvas.cpp \
    canvas.cpp \
    eraserproperties.cpp \
    penproperties.cpp \
    lineproperties.cpp

HEADERS  += mainwindow.h \
    newcanvas.h \
    canvas.h \
    eraserproperties.h \
    penproperties.h \
    lineproperties.h

FORMS    += mainwindow.ui \
    newcanvas.ui \
    eraserproperties.ui \
    penproperties.ui \
    lineproperties.ui

DISTFILES += \
    Icons/bcolor_icon.bmp \
    Icons/bitmap.bmp \
    Icons/clearall_icon.bmp \
    Icons/eraser_icon.bmp \
    Icons/fcolor_icon.bmp \
    Icons/line_icon.bmp \
    Icons/new_icon.bmp \
    Icons/open_icon.bmp \
    Icons/pen_icon.bmp \
    Icons/rect_icon.bmp \
    Icons/redo_icon.bmp \
    Icons/resize_icon.bmp \
    Icons/save_icon.bmp \
    Icons/undo_icon.bmp \
    Icons/bcolor_icon.png \
    Icons/clearall_icon.png \
    Icons/eraser_icon.png \
    Icons/fcolor_icon.png \
    Icons/line_icon.png \
    Icons/new_icon.png \
    Icons/open_icon.png \
    Icons/pen_icon.png \
    Icons/rect_icon.png \
    Icons/redo_icon.png \
    Icons/resize_icon.png \
    Icons/save_icon.png \
    Icons/undo_icon.png

RESOURCES += \
    resources.qrc
