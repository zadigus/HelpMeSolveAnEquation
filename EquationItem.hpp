#ifndef EQUATIONITEM_HPP
#define EQUATIONITEM_HPP

#include <QObject>
#include <QtQuick/QQuickPaintedItem>

class EquationItem : public QQuickPaintedItem
{
    Q_OBJECT

    Q_PROPERTY(QString text READ text WRITE setText)
    Q_PROPERTY(QColor color READ color WRITE setColor)

  public:
    EquationItem(QQuickItem* a_Parent = 0);
    virtual ~EquationItem();

    virtual void paint(QPainter* a_Painter);

    // TODO: the rectangle must be repainted with the text inside of it
    void setText(const QString& a_Text);
    QString text() const;

    void setOp(const QChar& a_Op);

    void setColor(const QColor& a_Color);
    QColor color() const;

  private:
    QString m_Text;
    QChar m_Op;
    QColor m_Color;
};

inline QString EquationItem::text() const
{
  return m_Text;
}

#endif // EQUATIONITEM_HPP
