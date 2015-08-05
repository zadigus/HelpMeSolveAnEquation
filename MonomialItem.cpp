#include "MonomialItem.hpp"

#include <QPen>
#include <QPainter>

#include <numeric>

MonomialItem::MonomialItem(QQuickItem *a_Parent)
  : QQuickPaintedItem(a_Parent)
  , m_Color(QColor("black"))
{

}

MonomialItem::~MonomialItem()
{

}

void MonomialItem::paint(QPainter* a_Painter)
{
  QPen pen(m_Color, 2);
  a_Painter->setPen(pen);
  a_Painter->setRenderHints(QPainter::Antialiasing, true);
  a_Painter->drawRect(0, 0, width(), height());
}

void MonomialItem::setSize()
{
  qreal w(childrenWidth(this));
  qreal h(childrenHeight(this));

  setWidth(w + m_HORIZONTAL_MARGIN);
  setHeight(h + m_VERTICAL_MARGIN);
}

void MonomialItem::setText(const QString& a_Text)
{
  m_Text = a_Text;
  // TODO: this method must update the rectangle's width / height
}

QColor MonomialItem::borderColor() const // TODO: this is the border color; the brush is responsible for the background color
{
  return m_Color;
}

void MonomialItem::setBorderColor(const QColor& a_Color)
{
  m_Color = a_Color;
}

void MonomialItem::setOp(const QChar& a_Op)
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

qreal childrenWidth(MonomialItem* a_Item)
{
  QList<QQuickItem*> children(a_Item->childItems());
  qreal width(std::accumulate(children.begin(), children.end(), 0, AddItemWidth()));
  return width == 0 ? MonomialItem::m_DEFAULT_WIDTH : width;
}

qreal childrenHeight(MonomialItem* a_Item)
{
  QList<QQuickItem*> children(a_Item->childItems());
  qreal height(std::accumulate(children.begin(), children.end(), 0, AddItemHeight()));
  return height == 0 ? MonomialItem::m_DEFAULT_HEIGHT : height;
}
