QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    adddialog.cpp \
    detailcard.cpp \
    listitemwidget.cpp \
    listitemwidget_2.cpp \
    main.cpp \
    messagebutton.cpp \
    morethingmenu.cpp \
    notfoundwidget.cpp \
    previewcards.cpp \
    starbutton.cpp \
    tujianwindow.cpp \
    widget.cpp

HEADERS += \
    adddialog.h \
    detailcard.h \
    listitemwidget.h \
    listitemwidget_2.h \
    messagebutton.h \
    morethingmenu.h \
    notfoundwidget.h \
    previewcards.h \
    starbutton.h \
    tujianwindow.h \
    widget.h

FORMS += \
    adddialog.ui \
    detailcard.ui \
    morethingmenu.ui \
    notfoundwidget.ui \
    previewcards.ui \
    tujianwindow.ui \
    widget.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    Dishes.qrc
