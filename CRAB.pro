#-------------------------------------------------
#
# Project created by QtCreator 2014-12-02T18:57:20
#
#-------------------------------------------------

QT       += core gui sql multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = CRAB
TEMPLATE = app


SOURCES +=  main.cpp\
            GUI/FormMain.cpp \
			GUI/FormOrder.cpp \
            Reader/CReaderThread.cpp \
            Sound/CSoundPlayer.cpp \
            Database/CCRABDB.cpp \
            Database/CCustomer.cpp \
            Database/CProduct.cpp \
            Database/COrder.cpp
            

HEADERS  += GUI/FormMain.h \
			GUI/FormOrder.h \
            Reader/CReaderThread.h \
            Sound/CSoundPlayer.h \
            Database/CCRABDB.h \
            Database/CCustomer.h \
            Database/CProduct.h \
            Database/COrder.h

FORMS    += GUI/FormMain.ui \
			GUI/FormOrder.ui

RESOURCES += \
    crab_resources.qrc
