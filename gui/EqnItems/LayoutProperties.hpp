#ifndef EQNITEMS_LAYOUTPROPERTIES_HPP
#define EQNITEMS_LAYOUTPROPERTIES_HPP

#include <QObject>

#include <QSize>

namespace N_EqnItems
{

  class LayoutProperties : public QObject
  {
      Q_OBJECT

      Q_PROPERTY(QSize   polynomSize           READ polynomSize           WRITE setPolynomSize           NOTIFY layoutChanged)
      Q_PROPERTY(qreal   spaceBetweenItems     READ spaceBetweenItems     WRITE setSpaceBetweenItems     NOTIFY layoutChanged)
      Q_PROPERTY(qreal   verticalMargin        READ verticalMargin        WRITE setVerticalMargin        NOTIFY layoutChanged)
      Q_PROPERTY(qreal   horizontalMargin      READ horizontalMargin      WRITE setHorizontalMargin      NOTIFY layoutChanged)

    public:
      explicit LayoutProperties(QObject *parent = 0);

      QSize polynomSize() const;
      void setPolynomSize(const QSize& a_Size);

      qreal spaceBetweenItems() const;
      void setSpaceBetweenItems(qreal a_SpaceBetweenItems);

      qreal verticalMargin() const;
      void setVerticalMargin(qreal a_VerticalMargin);

      qreal horizontalMargin() const;
      void setHorizontalMargin(qreal a_HorizontalMargin);

    signals:
      void layoutChanged();

    public slots:

    private:
      QSize   m_Size;
      qreal   m_SpaceBetweenItems;
      qreal   m_VerticalMargin;
      qreal   m_HorizontalMargin;

  };

  //--------------------------------------------------------------
  // inline / template method(s) implementation
  //--------------------------------------------------------------

  inline QSize LayoutProperties::polynomSize() const
  {
    return m_Size;
  }

  inline void LayoutProperties::setPolynomSize(const QSize& a_Size)
  {
    m_Size = a_Size;
    emit layoutChanged();
  }

  inline qreal LayoutProperties::spaceBetweenItems() const
  {
    return m_SpaceBetweenItems;
  }

  inline void LayoutProperties::setSpaceBetweenItems(qreal a_SpaceBetweenItems)
  {
    m_SpaceBetweenItems = a_SpaceBetweenItems;
    emit layoutChanged();
  }

  inline qreal LayoutProperties::verticalMargin() const
  {
    return m_VerticalMargin;
  }

  inline void LayoutProperties::setVerticalMargin(qreal a_VerticalMargin)
  {
    m_VerticalMargin = a_VerticalMargin;
    emit layoutChanged();
  }

  inline qreal LayoutProperties::horizontalMargin() const
  {
    return m_HorizontalMargin;
  }

  inline void LayoutProperties::setHorizontalMargin(qreal a_HorizontalMargin)
  {
    m_HorizontalMargin = a_HorizontalMargin;
    emit layoutChanged();
  }

}

#endif // EQNITEMS_LAYOUTPROPERTIES_HPP
