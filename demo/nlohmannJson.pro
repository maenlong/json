#-------------------------------------------------
#
# Project created by QtCreator 2018-09-25T10:03:26
#
#-------------------------------------------------

TEMPLATE = app
TARGET = nlohmannJsonTest

QT += core
greaterThan(QT_MAJOR_VERSION, 4) {
    QT += widgets
}

#-----------------------------------------------------

#CONFIG -= app_bundle
#CONFIG += debug_and_release warn_on
#CONFIG += thread exceptions rtti stl

# without c++11 & AppKit library compiler can't solve address for symbols
CONFIG += c++11
macx: LIBS += -framework AppKit

# 让Release版本生成调试信息
QMAKE_CXXFLAGS_RELEASE = $$QMAKE_CFLAGS_RELEASE_WITH_DEBUGINFO
QMAKE_LFLAGS_RELEASE = $$QMAKE_LFLAGS_RELEASE_WITH_DEBUGINFO


# 启用多线程、异常、RTTI、STL支持
CONFIG += thread exceptions rtti stl

# without c++11 & AppKit library compiler can't solve address for symbols
CONFIG += c++11
macx: LIBS += -framework AppKit

#-----------------------------------------------------


INCLUDEPATH += $$PWD/../single_include/nlohmann/

HEADERS  += \
    jsontestwgt.h \
    $$PWD/../single_include/nlohmann/json.hpp \
    $$PWD/../single_include/nlohmann/json_fwd.hpp

SOURCES += \
    main.cpp \
    jsontestwgt.cpp

FORMS += \
    jsontestwgt.ui
