#include <QApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QQmlComponent>
#include <QDebug>

#include "PolynomialItem.hpp"

int main(int argc, char *argv[])
{
  QApplication app(argc, argv);

  qmlRegisterType<PolynomialItem>("EquationSolver", 1, 0, "Polynomial");

  QQmlApplicationEngine engine;
  engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

  return app.exec();
}
