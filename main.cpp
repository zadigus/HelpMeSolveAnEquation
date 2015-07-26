#include <QApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QQmlComponent>
#include <QDebug>

#include "EquationParser.hpp"
#include "EquationItem.hpp"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    qmlRegisterType<EquationItem>("EquationSolver", 1, 0, "EquationItem");

    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    return app.exec();
}
