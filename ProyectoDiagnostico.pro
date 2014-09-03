TEMPLATE = app

QT += qml quick widgets

QMAKE_LFAGS += -Wl,--repath=\\\$\$ORIGIN
QMAKE_LFAGS += -Wl,--repath=\\\$\$ORIGIN/lib
QMAKE_LFAGS += -Wl,--repath=\\\$\$ORIGIN/libs
QMAKE_RPATH=

SOURCES += \
    gui.cpp \
    main.cpp \
    customlabel.cpp

RESOURCES += \
    recursos.qrc


CONFIG += console


# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Default rules for deployment.
include(deployment.pri)

FORMS += \
    gui.ui

HEADERS += \
    gui.h \
    customlabel.h

OTHER_FILES +=
