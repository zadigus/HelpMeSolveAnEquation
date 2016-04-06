#include "EqnSideItem.hpp"

#include "PolynomialItem.hpp"
#include "PolynomialParser.hpp"

EqnSideItem::EqnSideItem(QQuickItem* a_Parent)
  : QQuickItem(a_Parent)
  , m_EqnItem(new PolynomialItem(this))
{
  m_EqnItem->setText("Hahaha");
  m_EqnItem->setWidth(100);
  m_EqnItem->setHeight(100);

  PolynomialItem* m_EqnItem2(new PolynomialItem(m_EqnItem));
  m_EqnItem2->setWidth(50);
  m_EqnItem2->setHeight(50);
  m_EqnItem2->setBorderColor(QColor("blue"));
  m_EqnItem2->setX(25);
  m_EqnItem2->setY(25);


  QString expr("2*x+4");
  int pos(0);
  PolynomialItem* item(PolynomialParser::parseExpression(expr, pos));
  item->updateGeometry();
  qWarning() << "Width  of root monomial = " << item->width();
  qWarning() << "Height of root monomial = " << item->height();
}

EqnSideItem::~EqnSideItem()
{

}

