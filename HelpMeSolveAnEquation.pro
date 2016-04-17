TEMPLATE = app

QT += qml quick widgets

EQNITEMS_FOLDER = logic/EqnItems
PARSER_FOLDER   = logic/Builders

SOURCES += main.cpp \
    $${EQNITEMS_FOLDER}/PolynomialItem.cpp \
    $${EQNITEMS_FOLDER}/EqnSideItem.cpp \
    $${PARSER_FOLDER}/EqnItemTreeBuilder.cpp \
    logic/Builders/EqnGraphicalLayoutBuilder.cpp

RESOURCES += gui/qml.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Default rules for deployment.
include(deployment.pri)

CONFIG += c++11

HEADERS += \
    $${EQNITEMS_FOLDER}/PolynomialItem.hpp \
    $${EQNITEMS_FOLDER}/EqnSideItem.hpp \
    $${PARSER_FOLDER}/EqnItemTreeBuilder.hpp \
    logic/Builders/EqnGraphicalLayoutBuilder.hpp

INCLUDEPATH += logic
