QT -= gui

CONFIG += c++11 console
CONFIG -= app_bundle

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        main.cpp \
    polynom.cpp \
    tapplication.cpp \
    tcomplex.cpp

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

HEADERS += \
    number.h \
    tapplication.h \
    polynom.h \
    tcomplex.h



unix|win32: LIBS += -L$$PWD/../../../Qt/5.11.2/msvc2015/lib/ -lQt5Network

INCLUDEPATH += $$PWD/../../../Qt/5.11.2/msvc2015/include
DEPENDPATH += $$PWD/../../../Qt/5.11.2/msvc2015/include

win32:!win32-g++: PRE_TARGETDEPS += $$PWD/../../../Qt/5.11.2/msvc2015/lib/Qt5Network.lib
else:unix|win32-g++: PRE_TARGETDEPS += $$PWD/../../../Qt/5.11.2/msvc2015/lib/libQt5Network.a

unix|win32: LIBS += -L$$PWD/../../../Qt/5.11.2/msvc2015/lib/ -lQt5Widgets

INCLUDEPATH += $$PWD/../../../Qt/5.11.2/msvc2015/include
DEPENDPATH += $$PWD/../../../Qt/5.11.2/msvc2015/include

win32:!win32-g++: PRE_TARGETDEPS += $$PWD/../../../Qt/5.11.2/msvc2015/lib/Qt5Widgets.lib
else:unix|win32-g++: PRE_TARGETDEPS += $$PWD/../../../Qt/5.11.2/msvc2015/lib/libQt5Widgets.a
