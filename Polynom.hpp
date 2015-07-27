#ifndef POLYNOM_H
#define POLYNOM_H

#include <QObject>
#include <QtQuick/QQuickItem>

class EquationItem;

//class Polynom : public QObject
class Polynom : public QQuickItem
{
    Q_OBJECT

  public:
    explicit Polynom(QQuickItem* a_Parent = 0);
    ~Polynom();

  signals:

  public slots:

  private:
    EquationItem* m_EqnItem;
};

#endif // POLYNOM_H
