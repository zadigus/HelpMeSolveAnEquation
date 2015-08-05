#include "MonomialItem.hpp"

#include <QPen>
#include <QPainter>

#include <numeric>
#include <algorithm>

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

void MonomialItem::updateGeometry()
{
  QList<QQuickItem*> children(childItems());
  std::for_each(children.begin(), children.end(),
                [] (QQuickItem* a_Item)
                {
                  MonomialItem* item(qobject_cast<MonomialItem*>(a_Item));
                  if(item)
                  {
                    item->updateGeometry();
                  }
                });

  qreal w(childrenWidth(this));
  qreal h(childrenHeight(this));

  if(w != 0 && h!= 0)
  {
    qreal totalWidth = w +                                            // total width of the children
                       (children.size() - 1) * m_HORIZONTAL_OFFSET +  // space between the children
                       2 * m_HORIZONTAL_MARGIN;                       // space between the first child and my boundary
                                                                      // + space between the last child and my boundary
    qreal totalHeight = h +                                           // maximal height of the children
                        2 * m_VERTICAL_MARGIN;                        // space between the children and my boundary (top + bottom)
    setWidth(totalWidth);
    setHeight(totalHeight);
  }
  else
  {
    setWidth(m_DEFAULT_WIDTH); // TODO: replace with the size of the text
    setHeight(m_DEFAULT_HEIGHT);
  }
}

void MonomialItem::setText(const QString& a_Text)
{
  m_Text = a_Text;
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

// non-member functions

qreal childrenWidth(MonomialItem* a_Item)
{
  QList<QQuickItem*> children(a_Item->childItems());
  qreal width(std::accumulate(children.begin(), children.end(), 0,
                              [] (qreal a_TotalWidth, QQuickItem* a_Item)
                              {
                                return a_TotalWidth + a_Item->width();
                              }));
  return width;
}

qreal childrenHeight(MonomialItem* a_Item)
{
  QList<QQuickItem*> children(a_Item->childItems());
  QList<QQuickItem*>::iterator it(std::max_element(children.begin(), children.end(),
                                                   [] (QQuickItem* a_LeftItem, QQuickItem* a_RightItem)
                                                   {
                                                    return a_LeftItem->height() < a_RightItem->height();
                                                   }));
  if(it != children.end())
  {
    return (*it)->height();
  }
  return 0;
}
