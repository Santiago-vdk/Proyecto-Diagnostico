TEMPLATE = app

QT += qml quick widgets

SOURCES += \
    main.cpp \
    myLabel.cpp \
    loading.cpp \
    guiPartida.cpp \
    gui.cpp \
    Thread.cpp

RESOURCES += \
    recursos.qrc


CONFIG += console


# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Default rules for deployment.
include(deployment.pri)

FORMS += \
    gui.ui \
    loading.ui \
    guiPartida.ui


QT += multimedia

HEADERS += \
    gui.h \
    myLabel.h \
    loading.h \
    guiPartida.h \
    Thread.h

OTHER_FILES +=
