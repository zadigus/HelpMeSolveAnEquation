#include <QApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QQmlComponent>
#include <QDebug>

#include "EqnItems/EqnSideItem.hpp"
#include "EqnItems/LayoutProperties.hpp"
#include "EqnItems/PolynomialItem.hpp"

using namespace N_EqnItems;

int main(int argc, char *argv[])
{
  QApplication app(argc, argv);

  qmlRegisterType<EqnSideItem>("EquationSolver", 1, 0, "EqnSideItem");
  qmlRegisterType<LayoutProperties>("EquationSolver", 1, 0, "LayoutProperties");
  qmlRegisterType<PolynomialItem>("EquationSolver", 1, 0, "PolynomialItem");

  QQmlApplicationEngine engine;
  engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

  return app.exec();
}
