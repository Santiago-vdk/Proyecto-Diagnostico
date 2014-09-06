TEMPLATE = app

QT += qml quick widgets

SOURCES += \
    main.cpp \
    myLabel.cpp \
    loading.cpp \
    guiPartida.cpp \
    gui.cpp \
    Thread.cpp \
    Jugador.cpp \
    Beneficio.cpp \
    Obstaculo.cpp \
    Ob_Estatico.cpp \
    Ob_Dinamico.cpp \
    Ob_Rastrero.cpp \
    Ob_Teledirigido.cpp \
    Ob_Volumen.cpp \
    Ob_Jefe.cpp \
    Be_Arma.cpp \
    Be_Vida.cpp \
    Be_Invencible.cpp \
    Be_Reliquia.cpp \
    Facade.cpp \
    miThread.cpp

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
    Thread.h \
    Jugador.h \
    Beneficio.h \
    Obstaculo.h \
    Ob_Estatico.h \
    Ob_Dinamico.h \
    Ob_Rastrero.h \
    Ob_Teledirigido.h \
    Ob_Volumen.h \
    Ob_Jefe.h \
    Be_Arma.h \
    Be_Vida.h \
    Be_Invecible.h \
    Be_Reliquia.h \
    Facade.h \
    miThread.h

OTHER_FILES +=
