TEMPLATE = app

QT += qml quick widgets multimedia serialport
SOURCES += \
    main.cpp \
    myLabel.cpp \
    loading.cpp \
    guiPartida.cpp \
    gui.cpp \
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
    threadObstaculos.cpp \
    threadCrearObstaculos.cpp \
    threadRefrescaGui.cpp \
    json.cpp \
    threadCrearDisparos.cpp \
    threadDisparos.cpp \
    Disparo.cpp \
    threadCrearBeneficios.cpp \
    threadBeneficio.cpp \
    threadJugador.cpp \
    com.cpp \
    threadArduino.cpp \
    threadTiempo.cpp \
    infomapa.cpp

RESOURCES += \
    recursos.qrc


CONFIG += console
CONFIG += C++11



# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Default rules for deployment.
include(deployment.pri)

FORMS += \
    gui.ui \
    loading.ui \
    guiPartida.ui




HEADERS += \
    gui.h \
    myLabel.h \
    loading.h \
    guiPartida.h \
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
    threadObstaculos.h \
    threadCrearObstaculo.h \
    threadRefrescaGui.h \
    json.h \
    threadCrearDisparos.h \
    threadDisparos.h \
    Disparo.h \
    threadCrearBeneficios.h \
    threadBeneficio.h \
    threadJugador.h \
    com.h \
    threadArduino.h \
    threadTiempo.h \
    infomapa.h

OTHER_FILES +=
