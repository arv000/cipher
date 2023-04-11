#-------------------------------------------------
#
# Project created by QtCreator 2023-04-10T17:27:33
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = cipher
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

SOURCES += \
        main.cpp \
        view/mainwindow.cpp \
        view/main_widget.cpp \
        view/encryption_hash_view.cpp \
        view/encryption_asymmetric_view.cpp \
        view/encryption_symmetric_view.cpp \
        view/encrytion_data_view.cpp \
        view/encrytion_file_view.cpp \
        tools/abstract_encytion.cpp \
        tools/encytion_md5.cpp \
        tools/encytion_sha256.cpp \
        tools/encytion_sm3.cpp \
        view/encryption_hash_base_view.cpp

HEADERS += \
        view/mainwindow.h \
        view/main_widget.h \
        view/encryption_hash_view.h \
        view/encryption_asymmetric_view.h \
        view/encryption_symmetric_view.h \
        view/encrytion_data_view.h \
        view/encrytion_file_view.h \
        tools/abstract_encytion.h \
        tools/encytion_md5.h \
        tools/encytion_sha256.h \
        tools/encytion_sm3.h \
        view/encryption_hash_base_view.h

INCLUDEPATH += ./3rdparty/openssl/include/

LIBS += -L./3rdparty/openssl/lib64/libcrypto.a
LIBS += -L./3rdparty/openssl/lib64/libssl.a
# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
