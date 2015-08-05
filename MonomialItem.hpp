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

    /*!
     * \brief Once all the monomial items of the polynomial have been set (i.e. the deepest children have got a text),
     * \brief the root item should call this method to adapt each item's size nicely
     */
    void updateGeometry();

  private:
    const qreal m_DEFAULT_WIDTH = 100;
    const qreal m_DEFAULT_HEIGHT = 50;
    const qreal m_VERTICAL_MARGIN = 10;
    const qreal m_HORIZONTAL_MARGIN = 10;
    const qreal m_HORIZONTAL_OFFSET = 5;

    QString m_Text;
    QChar m_Op;
    QColor m_Color;
};

// inline methods

inline QString MonomialItem::text() const
{
  return m_Text;
}

// non-member functions

/*!
 * \brief Computes the sum of the widths of the a_Item's children
 * \param a_Item: monomial item whose children are considered
 * \return the total width of all children
 */
qreal childrenWidth(MonomialItem* a_Item);

/*!
 * \brief Computes the maximum of the heights of the a_Item's children
 * \param a_Item: monomial item whose children are considered
 * \return the maximal height of all children
 */
qreal childrenHeight(MonomialItem* a_Item);

#endif // MONOMIALITEM_HPP
