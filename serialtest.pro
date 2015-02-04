#-------------------------------------------------
#
# Project created by QtCreator 2015-02-04T15:40:06
#
#-------------------------------------------------

QT       += core

QT       -= gui

TARGET = serialtest
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += main.cpp \
    serialport.c \
    windows.c

HEADERS += \
    libserialport.h \
    libserialport_internal.h

LIBS += -lsetupapi

DEFINES += SP_PRIV= SP_API= STDC_HEADERS=1 HAVE_SYS_TYPES_H=1 HAVE_SYS_STAT_H=1 HAVE_STDLIB_H=1 HAVE_STRING_H=1 HAVE_MEMORY_H=1 HAVE_STRINGS_H=1 HAVE_INTTYPES_H=1 HAVE_STDINT_H=1 HAVE_UNISTD_H=1
