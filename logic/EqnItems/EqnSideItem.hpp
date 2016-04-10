#ifndef EQN_SIDE_ITEM_H
#define EQN_SIDE_ITEM_H

#include <QObject>
#include <QtQuick/QQuickItem>

class PolynomialItem;

class EqnSideItem : public QQuickItem
{
    Q_OBJECT

  public:
    explicit EqnSideItem(QQuickItem* a_Parent = 0);
    ~EqnSideItem();

  signals:

  public slots:

  private:
    PolynomialItem* m_EqnItem;
};

#endif // EQN_SIDE_ITEM_H
