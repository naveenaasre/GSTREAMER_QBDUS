QT = core
QT += dbus
QT += multimedia widgets

CONFIG += qdbus
CONFIG += c++17 cmdline
CONFIG += link_pkgconfig


LIBS += -lgstreamer-1.0
LIBS += -lgobject-2.0
LIBS += -lglib-2.0

LIBS += -lgstbase-1.0 -lgstapp-1.0 -lgstvideo-1.0

INCLUDEPATH += /usr/include/gstreamer-1.0
INCLUDEPATH += /usr/include/glib-2.0
INCLUDEPATH += /usr/lib/x86_64-linux-gnu/glib-2.0/include

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
