QT = core
QT += dbus
QT += multimedia multimediawidgets
QT += dbus widgets

CONFIG += qdbus
CONFIG += c++17 cmdline

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        audiocontroller.cpp \
        main.cpp
DBUS_ADAPTORS += application.xml



# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

HEADERS += \
    application_adaptor.h \
    audiocontroller.h

#DISTFILES += \
#    application.xml
