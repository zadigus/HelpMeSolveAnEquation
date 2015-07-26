#include "EquationItem.hpp"

#include <QPen>
#include <QPainter>

EquationItem::EquationItem(QQuickItem *a_Parent)
  : QQuickPaintedItem(a_Parent)
{

}

EquationItem::~EquationItem()
{

}

void EquationItem::paint(QPainter* a_Painter)
{
  QPen pen(m_Color, 2);
  a_Painter->setPen(pen);
  a_Painter->setRenderHints(QPainter::Antialiasing, true);
//  a_Painter->drawPie(boundingRect().adjusted(1, 1, -1, -1), 90 * 16, 290 * 16);

  a_Painter->drawRect(0, 0, width(), height());
}

void EquationItem::setText(const QString& a_Text)
{
  m_Text = a_Text;
  // TODO: this method must update the rectangle's width / height
}

QColor EquationItem::color() const
{
  return m_Color;
}

void EquationItem::setColor(const QColor& a_Color)
{
  m_Color = a_Color;
}

void EquationItem::setOp(const QChar& a_Op)
{
  m_Op = a_Op;
}
