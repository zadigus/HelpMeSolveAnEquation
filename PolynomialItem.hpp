#ifndef POLYNOM_H
#define POLYNOM_H

#include <QObject>
#include <QtQuick/QQuickItem>

class MonomialItem;

class PolynomialItem : public QQuickItem
{
    Q_OBJECT

  public:
    explicit PolynomialItem(QQuickItem* a_Parent = 0);
    ~PolynomialItem();

  signals:

  public slots:

  private:
    MonomialItem* m_EqnItem;
};

#endif // POLYNOM_H
