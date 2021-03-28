QT       += core gui
QT  +=svg

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

include(configration.pri)

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
    greenboxsolutionappformnavigator.cpp \
    main.cpp \
    mainwindow.cpp \
    raspberrypideviceform.cpp \
    startingform.cpp \
    usbdevicestatusform.cpp \
    zinttestform.cpp

HEADERS += \
    globals.h \
    greenboxsolutionappformnavigator.h \
    mainwindow.h \
    raspberrypideviceform.h \
    startingform.h \
    styles/Styles.h \
    usbdevicestatusform.h \
    zinttestform.h

FORMS += \
    mainwindow.ui \
    raspberrypideviceform.ui \
    startingform.ui \
    usbdevicestatusform.ui \
    zinttestform.ui



# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /home/pi/Desktop/GreenBox_test/folder_2/folder_1
!isEmpty(target.path): INSTALLS += target

unix:!macx: LIBS += -L$$PWD/../../CCompiled_Libraries/libusb/ -lusb-1.0

INCLUDEPATH += $$PWD/../../CCompiled_Libraries/libusb
DEPENDPATH += $$PWD/../../CCompiled_Libraries/libusb



unix:!macx: LIBS += -L$$OUT_PWD/../GreenBoxSolutionLoggingLibrary/ -lGreenBoxSolutionLoggingLibrary

INCLUDEPATH += $$PWD/../GreenBoxSolutionLoggingLibrary
DEPENDPATH += $$PWD/../GreenBoxSolutionLoggingLibrary

unix:!macx: PRE_TARGETDEPS += $$OUT_PWD/../GreenBoxSolutionLoggingLibrary/libGreenBoxSolutionLoggingLibrary.a

unix:!macx: LIBS += -L$$OUT_PWD/../GreenBoxSolutionUSBDeviceLibrary/ -lGreenBoxSolutionUSBDeviceLibrary

INCLUDEPATH += $$PWD/../GreenBoxSolutionUSBDeviceLibrary
DEPENDPATH += $$PWD/../GreenBoxSolutionUSBDeviceLibrary

unix:!macx: PRE_TARGETDEPS += $$OUT_PWD/../GreenBoxSolutionUSBDeviceLibrary/libGreenBoxSolutionUSBDeviceLibrary.a

unix:!macx: LIBS += -L$$OUT_PWD/../GreenBoxSolutionQtZintSharedLibrary/ -lGreenBoxSolutionQtZintSharedLibrary

INCLUDEPATH += $$PWD/../GreenBoxSolutionQtZintSharedLibrary
DEPENDPATH += $$PWD/../GreenBoxSolutionQtZintSharedLibrary

unix:!macx: LIBS += -L$$OUT_PWD/../GreenBoxSolutionDeviceGPIOLibrary/ -lGreenBoxSolutionDeviceGPIOLibrary

INCLUDEPATH += $$PWD/../GreenBoxSolutionDeviceGPIOLibrary
DEPENDPATH += $$PWD/../GreenBoxSolutionDeviceGPIOLibrary

unix:!macx: PRE_TARGETDEPS += $$OUT_PWD/../GreenBoxSolutionDeviceGPIOLibrary/libGreenBoxSolutionDeviceGPIOLibrary.a

unix:!macx: LIBS += -L$$OUT_PWD/../GreenBoxSolutionQtZintSharedLibrary/ -lGreenBoxSolutionQtZintSharedLibrary

INCLUDEPATH += $$PWD/../GreenBoxSolutionQtZintSharedLibrary
DEPENDPATH += $$PWD/../GreenBoxSolutionQtZintSharedLibrary

unix:!macx: LIBS += -L$$PWD/../../CCompiled_Libraries/libzint/ -lzint

INCLUDEPATH += $$PWD/../../CCompiled_Libraries/libzint
DEPENDPATH += $$PWD/../../CCompiled_Libraries/libzint

DISTFILES += \
    Images/AnimatedProgressBar.gif \
    Images/green_box.jpg
