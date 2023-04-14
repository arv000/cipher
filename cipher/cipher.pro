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

INCLUDEPATH += $$PWD/3rdparty/openssl/include/

SOURCES += \
        main.cpp \
        view/mainwindow.cpp \
        view/main_widget.cpp \
        view/encryption_hash_view.cpp \
        view/encryption_asymmetric_view.cpp \
        view/encryption_symmetric_view.cpp \
        view/encrytion_data_view.cpp \
        view/encrytion_file_view.cpp \
        tools/hash/abstract_encytion.cpp \
        tools/hash/encytion_md5.cpp \
        tools/hash/encytion_sha256.cpp \
        tools/hash/encytion_sm3.cpp \
        view/encryption_hash_base_view.cpp \
        tools/hash/encytion_data_job.cpp \
        tools/hash/encytion_file_job.cpp \
    tools/tools.cpp \
    tools/asymmetry/abstract_symmetry_encytion.cpp \
    tools/asymmetry/encytion_aes.cpp

HEADERS += \
        view/mainwindow.h \
        view/main_widget.h \
        view/encryption_hash_view.h \
        view/encryption_asymmetric_view.h \
        view/encryption_symmetric_view.h \
        view/encrytion_data_view.h \
        view/encrytion_file_view.h \
        tools/hash/abstract_encytion.h \
        tools/hash/encytion_md5.h \
        tools/hash/encytion_sha256.h \
        tools/hash/encytion_sm3.h \
        tools/hash/encytion_data_job.h \
        tools/hash/encytion_file_job.h \
        view/encryption_hash_base_view.h \
        tools/tools.h \
    tools/asymmetry/abstract_symmetry_encytion.h \
    tools/asymmetry/encytion_aes.h



LIBS += $$PWD/3rdparty/openssl/lib64/libcrypto.a
LIBS += $$PWD/3rdparty/openssl/lib64/libssl.a
LIBS += -ldl
# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
