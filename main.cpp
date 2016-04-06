#include <QApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QQmlComponent>
#include <QDebug>

#include "EqnSideItem.hpp"

int main(int argc, char *argv[])
{
  QApplication app(argc, argv);

  qmlRegisterType<EqnSideItem>("EquationSolver", 1, 0, "EqnSideItem");

  QQmlApplicationEngine engine;
  engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

  return app.exec();
}
