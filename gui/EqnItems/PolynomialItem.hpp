#ifndef EQNITEMS_POLYNOMIALITEM_HPP
#define EQNITEMS_POLYNOMIALITEM_HPP

#include <QObject>
#include <QtQuick/QQuickPaintedItem>

#include <functional>

namespace N_EqnItems
{

  class PolynomialItem : public QQuickPaintedItem
  {
      Q_OBJECT

      Q_PROPERTY(QString  text        READ text         WRITE setText         NOTIFY textChanged)
      Q_PROPERTY(QColor   borderColor READ borderColor  WRITE setBorderColor  NOTIFY borderColorChanged)
      Q_PROPERTY(QString  exprType    READ exprType     WRITE setExprType     NOTIFY exprTypeChanged)
      Q_PROPERTY(QFont    font        READ font         WRITE setFont         NOTIFY fontChanged)
      Q_PROPERTY(QChar    op          READ op           WRITE setOp           NOTIFY opChanged)

    public:
      PolynomialItem(QQuickItem* a_Parent = 0);
      virtual ~PolynomialItem();

      virtual void paint(QPainter* a_Painter);

      void setText(const QString& a_Text);
      QString text() const;

      QChar op() const;
      void setOp(const QChar& a_Op);

      void setBorderColor(const QColor& a_Color);
      QColor borderColor() const;

      void setExprType(const QString& a_ExprType);
      QString exprType() const;

      void setFont(const QFont& a_Font);
      QFont font() const;

    private:
      void drawText(QPainter* a_Painter);

    signals:
      void textChanged();
      void borderColorChanged();
      void exprTypeChanged();
      void fontChanged();
      void opChanged();

    private:
      const qreal m_VERTICAL_MARGIN;// = 10;
      const qreal m_HORIZONTAL_MARGIN;// = 10;
      const qreal m_HORIZONTAL_OFFSET;// = 5;

      QString m_Text;
      QString m_ExprType;
      QChar m_Op;
      QColor m_Color;
      QFont m_Font;
  };

  // inline methods

  inline QString PolynomialItem::text() const
  {
    return m_Text;
  }

  inline void PolynomialItem::setText(const QString& a_Text)
  {
    m_Text      = a_Text;
    emit textChanged();
  }

  inline QColor PolynomialItem::borderColor() const
  {
    return m_Color;
  }

  inline void PolynomialItem::setBorderColor(const QColor& a_Color)
  {
    m_Color = a_Color;
    emit borderColorChanged();
  }

  inline void PolynomialItem::setExprType(const QString& a_ExprType)
  {
    m_ExprType = a_ExprType;
    emit exprTypeChanged();
  }

  inline QString PolynomialItem::exprType() const
  {
    return m_ExprType;
  }

  inline void PolynomialItem::setFont(const QFont& a_Font)
  {
    m_Font = a_Font;
    emit fontChanged();
  }

  inline QFont PolynomialItem::font() const
  {
    return m_Font;
  }

  inline QChar PolynomialItem::op() const
  {
    return m_Op;
  }

  inline void PolynomialItem::setOp(const QChar& a_Op)
  {
    m_Op = a_Op;
    emit opChanged();
  }
}

#endif // EQNITEMS_POLYNOMIALITEM_HPP
