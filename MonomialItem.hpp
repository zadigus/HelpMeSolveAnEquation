#ifndef MONOMIALITEM_HPP
#define MONOMIALITEM_HPP

#include <QObject>
#include <QtQuick/QQuickPaintedItem>
#include <functional>

class MonomialItem : public QQuickPaintedItem
{
    Q_OBJECT

    Q_PROPERTY(QString text READ text WRITE setText)
    Q_PROPERTY(QColor borderColor READ borderColor WRITE setBorderColor)

  public:
    MonomialItem(QQuickItem* a_Parent = 0);
    virtual ~MonomialItem();

    virtual void paint(QPainter* a_Painter);

    // TODO: the rectangle must be repainted with the text inside of it
    void setText(const QString& a_Text);
    QString text() const;

    void setOp(const QChar& a_Op);

    void setBorderColor(const QColor& a_Color);
    QColor borderColor() const;

  private:
    void setSize();

  public:
    static const qreal m_DEFAULT_WIDTH = 100;
    static const qreal m_DEFAULT_HEIGHT = 50;
    static const qreal m_VERTICAL_MARGIN = 10;
    static const qreal m_HORIZONTAL_MARGIN = 10;

  private:
    QString m_Text;
    QChar m_Op;
    QColor m_Color;
};

class AddItemWidth : public std::binary_function<qreal, QQuickItem*, qreal>
{
  public:
    qreal operator()(qreal a_TotalWidth, QQuickItem* a_Item) const;
};

class AddItemHeight : public std::binary_function<qreal, QQuickItem*, qreal>
{
  public:
    qreal operator()(qreal a_TotalHeight, QQuickItem* a_Item) const;
};

// inline methods

inline QString MonomialItem::text() const
{
  return m_Text;
}

// non-member functions

qreal childrenWidth(MonomialItem* a_Item);
qreal childrenHeight(MonomialItem* a_Item);

#endif // MONOMIALITEM_HPP
