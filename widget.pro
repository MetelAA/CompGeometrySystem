QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    customgraphicsview.cpp \
    interface/graphicalinterface.cpp \
    main.cpp \
    mainwindow.cpp \
    src/points/cpoint.cpp \
    src/polygons/convexpolygon.cpp \
    src/polygons/simplepolygon.cpp \
    src/polygons/starpolygon.cpp \
    src/shells/convexhull.cpp \
    src/shells/randompointsset.cpp

HEADERS += \
    GenerationType.h \
    customgraphicsview.h \
    custompolygon.h \
    interface/graphicalinterface.h \
    mainwindow.h \
    src/points/cpoint.h \
    src/polygons/convexpolygon.h \
    src/polygons/simplepolygon.h \
    src/polygons/custompolygon.h \
    src/polygons/starpolygon.h \
    src/shells/convexhull.h \
    src/shells/randompointsset.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
