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

    Q_PROPERTY(QString polynom               READ polynom               WRITE setPolynom               NOTIFY polynomChanged)
    Q_PROPERTY(QPoint  polynomPosition       READ polynomPosition       WRITE setPolynomPosition       NOTIFY polynomPositionChanged)
    Q_PROPERTY(QSize   polynomSize           READ polynomSize           WRITE setPolynomSize           NOTIFY polynomSizeChanged)
    Q_PROPERTY(qreal   spaceBetweenItems     READ spaceBetweenItems     WRITE setSpaceBetweenItems     NOTIFY spaceBetweenItemsChanged)
    Q_PROPERTY(qreal   verticalMargin        READ verticalMargin        WRITE setVerticalMargin        NOTIFY verticalMarginChanged)
    Q_PROPERTY(qreal   horizontalMargin      READ horizontalMargin      WRITE setHorizontalMargin      NOTIFY horizontalMarginChanged)


    public:
      explicit EqnSideItem(QQuickItem* a_Parent = 0);
      ~EqnSideItem();

      QString polynom() const;
      void setPolynom(const QString& a_Polynom);

      QPoint polynomPosition() const;
      void setPolynomPosition(const QPoint& a_Position);

      QSize polynomSize() const;
      void setPolynomSize(const QSize& a_Size);

      qreal spaceBetweenItems() const;
      void setSpaceBetweenItems(qreal a_SpaceBetweenItems);

      qreal verticalMargin() const;
      void setVerticalMargin(qreal a_VerticalMargin);

      qreal horizontalMargin() const;
      void setHorizontalMargin(qreal a_HorizontalMargin);

    signals:
      void polynomChanged();
      void polynomPositionChanged();
      void polynomSizeChanged();
      void spaceBetweenItemsChanged();
      void verticalMarginChanged();
      void horizontalMarginChanged();

    public slots:
      void buildLayout();
      void buildTree();

    private:
      QString m_Polynom;
      QPoint  m_Position;
      QSize   m_Size;
      qreal   m_SpaceBetweenItems;
      qreal   m_VerticalMargin;
      qreal   m_HorizontalMargin;

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

  inline QPoint EqnSideItem::polynomPosition() const
  {
    return m_Position;
  }

  inline void EqnSideItem::setPolynomPosition(const QPoint& a_Position)
  {
    m_Position = a_Position;
    emit polynomPositionChanged();
  }

  inline QSize EqnSideItem::polynomSize() const
  {
    return m_Size;
  }

  inline void EqnSideItem::setPolynomSize(const QSize& a_Size)
  {
    m_Size = a_Size;
    emit polynomSizeChanged();
  }

  inline qreal EqnSideItem::spaceBetweenItems() const
  {
    return m_SpaceBetweenItems;
  }

  inline void EqnSideItem::setSpaceBetweenItems(qreal a_SpaceBetweenItems)
  {
    m_SpaceBetweenItems = a_SpaceBetweenItems;
    emit spaceBetweenItemsChanged();
  }

  inline qreal EqnSideItem::verticalMargin() const
  {
    return m_VerticalMargin;
  }

  inline void EqnSideItem::setVerticalMargin(qreal a_VerticalMargin)
  {
    m_VerticalMargin = a_VerticalMargin;
    emit verticalMarginChanged();
  }

  inline qreal EqnSideItem::horizontalMargin() const
  {
    return m_HorizontalMargin;
  }

  inline void EqnSideItem::setHorizontalMargin(qreal a_HorizontalMargin)
  {
    m_HorizontalMargin = a_HorizontalMargin;
    emit horizontalMarginChanged();
  }
}

#endif // EQNITEMS_EQN_SIDE_ITEM_HPP
