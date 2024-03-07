QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    GeneralFunctions.cpp \
    equation.cpp \
    filewindow.cpp \
    main.cpp \
    mainwindow.cpp \
    newtonmethod.cpp \
    rootfindingmethod.cpp \
    secantmethod.cpp

HEADERS += \
    GeneralFunctions.h \
    equation.h \
    filewindow.h \
    mainwindow.h \
    newtonmethod.h \
    rootfindingmethod.h \
    secantmethod.h

FORMS += \
    filewindow.ui \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resources.qrc

INCLUDEPATH += D:\armadillo-12.2.0\armadillo-12.2.0\include

LIBS += \
    -LD:\armadillo-12.2.0\armadillo-12.2.0\examples\lib_win64 \
    -lliblapack \
    -llibblas
