#ifndef EQNITEMS_EQN_SIDE_ITEM_HPP
#define EQNITEMS_EQN_SIDE_ITEM_HPP

#include <QtQuick/QQuickItem>

namespace N_EqnItems {
  class PolynomialItem;
}

namespace N_EqnItems
{

  class EqnSideItem : public QQuickItem
  {
    Q_OBJECT

    Q_PROPERTY(QString  polynom               READ polynom               WRITE setPolynom               NOTIFY polynomChanged)
    Q_PROPERTY(QPointF  polynomPosition       READ polynomPosition       WRITE setPolynomPosition       NOTIFY polynomPositionChanged)

    public:
      explicit EqnSideItem(QQuickItem* a_Parent = 0);
      ~EqnSideItem();

      QString polynom() const;
      void setPolynom(const QString& a_Polynom);

      QPointF polynomPosition() const;
      void setPolynomPosition(const QPointF& a_Position);

    signals:
      void polynomChanged();
      void polynomPositionChanged();

    public slots:
      void buildTree();

    private:
      QString m_Polynom;

      PolynomialItem* m_EqnItem;
  };

  //--------------------------------------------------------------
  // inline / template method(s) implementation
  //--------------------------------------------------------------

  inline QString EqnSideItem::polynom() const
  {
    return m_Polynom;
  }

  inline void EqnSideItem::setPolynom(const QString& a_Polynom)
  {
    m_Polynom = a_Polynom;
    emit polynomChanged();
  }
}

#endif // EQNITEMS_EQN_SIDE_ITEM_HPP
