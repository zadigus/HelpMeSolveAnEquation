#include <QApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QQmlComponent>
#include <QDebug>

#include "EquationParser.hpp"
#include "MonomialItem.hpp"
#include "PolynomialItem.hpp"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    qmlRegisterType<PolynomialItem>("EquationSolver", 1, 0, "Polynomial");
//    qmlRegisterType<MonomialItem>("EquationSolver", 1, 0, "Monomial");

    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    return app.exec();
}
