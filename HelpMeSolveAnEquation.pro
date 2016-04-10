TEMPLATE = app

QT += qml quick widgets

EQNITEMS_FOLDER = logic/EqnItems
PARSER_FOLDER   = logic/Parser

SOURCES += main.cpp \
    $${EQNITEMS_FOLDER}/PolynomialItem.cpp \
    $${EQNITEMS_FOLDER}/EqnSideItem.cpp \
    $${PARSER_FOLDER}/PolynomialParser.cpp

RESOURCES += gui/qml.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Default rules for deployment.
include(deployment.pri)

CONFIG += c++11

HEADERS += \
    $${EQNITEMS_FOLDER}/PolynomialItem.hpp \
    $${EQNITEMS_FOLDER}/EqnSideItem.hpp \
    $${PARSER_FOLDER}/PolynomialParser.hpp

INCLUDEPATH += logic
