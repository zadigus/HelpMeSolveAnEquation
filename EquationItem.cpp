#include "EquationItem.hpp"

#include <QPen>
#include <QPainter>

#include <numeric>

EquationItem::EquationItem(QQuickItem *a_Parent)
  : QQuickPaintedItem(a_Parent)
//  , m_DEFAULT_WIDTH(100)
//  , m_DEFAULT_HEIGHT(50)
  , m_Color(QColor("black"))
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
  a_Painter->drawRect(0, 0, width(), height());
}

void EquationItem::setSize()
{
  qreal w(childrenWidth(this));
  qreal h(childrenHeight(this));

  setWidth(w + m_HORIZONTAL_MARGIN);
  setHeight(h + m_VERTICAL_MARGIN);
}

void EquationItem::setText(const QString& a_Text)
{
  m_Text = a_Text;
  // TODO: this method must update the rectangle's width / height
}

QColor EquationItem::borderColor() const // TODO: this is the border color; the brush is responsible for the background color
{
  return m_Color;
}

void EquationItem::setBorderColor(const QColor& a_Color)
{
  m_Color = a_Color;
}

void EquationItem::setOp(const QChar& a_Op)
{
  m_Op = a_Op;
}

qreal AddItemWidth::operator()(qreal a_TotalWidth, QQuickItem* a_Item) const
{
  return a_TotalWidth + a_Item->width();
}

qreal AddItemHeight::operator()(qreal a_TotalHeight, QQuickItem* a_Item) const
{
  return a_TotalHeight + a_Item->height();
}

// non-member functions

qreal childrenWidth(EquationItem* a_Item)
{
  QList<QQuickItem*> children(a_Item->childItems());
  qreal width(std::accumulate(children.begin(), children.end(), 0, AddItemWidth()));
  return width == 0 ? EquationItem::m_DEFAULT_WIDTH : width;
}

qreal childrenHeight(EquationItem* a_Item)
{
  QList<QQuickItem*> children(a_Item->childItems());
  qreal height(std::accumulate(children.begin(), children.end(), 0, AddItemHeight()));
  return height == 0 ? EquationItem::m_DEFAULT_HEIGHT : height;
}
