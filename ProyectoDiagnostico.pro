TEMPLATE = app

QT += qml quick widgets

SOURCES += \
    gui.cpp \
    main.cpp \
    myLabel.cpp \
    loading.cpp

RESOURCES += \
    recursos.qrc


CONFIG += console


# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Default rules for deployment.
include(deployment.pri)

FORMS += \
    gui.ui \
    loading.ui

HEADERS += \
    gui.h \
    myLabel.h \
    loading.h

OTHER_FILES +=
