#include "PolynomialItem.hpp"

#include "MonomialItem.hpp"
#include "PolynomialParser.hpp"

PolynomialItem::PolynomialItem(QQuickItem* a_Parent)
  : QQuickItem(a_Parent)
  , m_EqnItem(new MonomialItem(this))
{
  m_EqnItem->setText("Hahaha");
  m_EqnItem->setWidth(100);
  m_EqnItem->setHeight(100);

  MonomialItem* m_EqnItem2(new MonomialItem(m_EqnItem));
  m_EqnItem2->setWidth(50);
  m_EqnItem2->setHeight(50);
  m_EqnItem2->setBorderColor(QColor("blue"));
  m_EqnItem2->setX(25);
  m_EqnItem2->setY(25);


  QString expr("2*x+4");
  int pos(0);
  MonomialItem* item(PolynomialParser::parseExpression(expr, pos));
  item->updateGeometry();
  qWarning() << "Width  of root monomial = " << item->width();
  qWarning() << "Height of root monomial = " << item->height();
}

PolynomialItem::~PolynomialItem()
{

}

