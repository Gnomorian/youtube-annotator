QT       += core gui webenginewidgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    annotationlist.cpp \
    annotationlistitem.cpp \
    javascriptparambuilder.cpp \
    main.cpp \
    mainwindow.cpp \
    webpagefactory.cpp \
    youtubeannotationstore.cpp \
    youtubeplayer.cpp \
    youtubevideostate.cpp

HEADERS += \
    annotationlist.h \
    annotationlistitem.h \
    javascriptparambuilder.h \
    mainwindow.h \
    webpagefactory.h \
    youtubeannotationstore.h \
    youtubeplayer.h \
    youtubevideostate.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    webpagetemplates.qrc

DISTFILES += \
    concrete-youtube-player.html \
    template-youtube-player.html
