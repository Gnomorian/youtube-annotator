QT += testlib
QT += gui
CONFIG += qt warn_on depend_includepath testcase c++17

TEMPLATE = app

SOURCES +=  \
    annotatortester.cpp \
    tests-main.cpp

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../yt-annotator-core/release/ -lyt-annotator-core
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../yt-annotator-core/debug/ -lyt-annotator-core
else:unix: LIBS += -L$$OUT_PWD/../yt-annotator-core/ -lyt-annotator-core

INCLUDEPATH += $$PWD/../yt-annotator-core
DEPENDPATH += $$PWD/../yt-annotator-core

HEADERS += \
    annotatortester.h
