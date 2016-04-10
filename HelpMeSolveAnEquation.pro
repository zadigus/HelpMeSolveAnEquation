TEMPLATE = app

QT += qml quick widgets

SOURCES += main.cpp \
    logic/EqnItems/PolynomialItem.cpp \
    logic/EqnItems/EqnSideItem.cpp \
    logic/Parser/PolynomialParser.cpp

RESOURCES += qml.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Default rules for deployment.
include(deployment.pri)

CONFIG += c++11

HEADERS += \
    logic/EqnItems/PolynomialItem.hpp \
    logic/EqnItems/EqnSideItem.hpp \
    logic/Parser/PolynomialParser.hpp

INCLUDEPATH += logic
