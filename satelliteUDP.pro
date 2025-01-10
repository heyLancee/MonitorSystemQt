QT       += core gui
QT       += charts
QT       += network
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

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
    src/core/base.cpp \
    src/core/communication.cpp \
    src/core/data_processor.cpp \
    src/core/diagnosis_win.cpp \
    src/core/main.cpp \
    src/core/monitor_system.cpp \
    src/core/visualization_window.cpp \
    src/utils/config_manager.cpp \
    src/utils/utils.cpp

HEADERS += \
    inc/core/base.h \
    inc/core/communication.h \
    inc/core/data_processor.h \
    inc/core/diagnosis_win.h \
    inc/core/monitor_system.h \
    inc/core/visualization_window.h \
    inc/utils/config_manager.h \
    inc/utils/utils.h

FORMS += \
    src/ui/diagnosis_win.ui \
    src/ui/visualization_window.ui

UI_DIR = ../qt/

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resources/Resources.qrc
