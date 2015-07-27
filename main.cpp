#include <QApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QQmlComponent>
#include <QDebug>

#include "EquationParser.hpp"
#include "EquationItem.hpp"
#include "Polynom.hpp"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    qmlRegisterType<Polynom>("EquationSolver", 1, 0, "Polynom");
    qmlRegisterType<EquationItem>("EquationSolver", 1, 0, "EquationItem");

    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    return app.exec();
}
