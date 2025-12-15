QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    BoardLinkedList.cpp \
    BoardScreen.cpp \
    Cell.cpp \
    LoginScreen.cpp \
    MainWindow.cpp \
    MapSelectionDialog.cpp \
    SplashScreen.cpp \
    main.cpp

HEADERS += \
    BoardLinkedList.h \
    BoardScreen.h \
    Cell.h \
    CellNode.h \
    LoginScreen.h \
    MainWindow.h \
    MapSelectionDialog.h \
    SplashScreen.h

FORMS += \
    BoardScreen.ui \
    LoginScreen.ui \
    MainWindow.ui \
    MapSelectionDialog.ui \
    SplashScreen.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resources.qrc
