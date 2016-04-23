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

    Q_PROPERTY(QString  expression            READ expression            WRITE setExpression            NOTIFY expressionChanged)
    Q_PROPERTY(QPointF  expressionPosition    READ expressionPosition    WRITE setExpressionPosition    NOTIFY expressionPositionChanged)

    public:
      explicit EqnSideItem(QQuickItem* a_Parent = 0);
      ~EqnSideItem();

      QString expression() const;
      void setExpression(const QString& a_Expression);

      QPointF expressionPosition() const;
      void setExpressionPosition(const QPointF& a_Position);

    signals:
      void expressionChanged();
      void expressionPositionChanged();

    public slots:
      void buildTree();

    private:
      QString m_Expression;

      PolynomialItem* m_EqnItem;
  };

  //--------------------------------------------------------------
  // inline / template method(s) implementation
  //--------------------------------------------------------------

  inline QString EqnSideItem::expression() const
  {
    return m_Expression;
  }

  inline void EqnSideItem::setExpression(const QString& a_Expression)
  {
    m_Expression = a_Expression;
    emit expressionChanged();
  }
}

#endif // EQNITEMS_EQN_SIDE_ITEM_HPP
