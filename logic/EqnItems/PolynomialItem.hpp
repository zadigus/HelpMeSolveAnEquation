#ifndef POLYNOMIALITEM_HPP
#define POLYNOMIALITEM_HPP

#include <QObject>
#include <QtQuick/QQuickPaintedItem>

#include <functional>

class PolynomialItem : public QQuickPaintedItem
{
    Q_OBJECT

    Q_PROPERTY(QString text READ text WRITE setText NOTIFY textChanged)
    Q_PROPERTY(QColor borderColor READ borderColor WRITE setBorderColor)

  public:
    PolynomialItem(QQuickItem* a_Parent = 0);
    virtual ~PolynomialItem();

    virtual void paint(QPainter* a_Painter);

    void setText(const QString& a_Text);
    QString text() const;

    void setOp(const QChar& a_Op);

    void setBorderColor(const QColor& a_Color);
    QColor borderColor() const;

  private:
    void drawText(QPainter* a_Painter);

  signals:
    void textChanged();

  private:
    const qreal m_VERTICAL_MARGIN = 10;
    const qreal m_HORIZONTAL_MARGIN = 10;
    const qreal m_HORIZONTAL_OFFSET = 5;

    QString m_Text;
    QChar m_Op;
    QColor m_Color;
    QFont m_Font;
};

// inline methods

inline QString PolynomialItem::text() const
{
  return m_Text;
}

#endif // POLYNOMIALITEM_HPP
