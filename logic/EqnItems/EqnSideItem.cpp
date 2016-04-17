#include "EqnItems/EqnSideItem.hpp"

#include "EqnItems/PolynomialItem.hpp"

#include "Builders/EqnItemTreeBuilder.hpp"
#include "Builders/EqnGraphicalLayoutBuilder.hpp"

//------------------------------------------------------------------------------------------------------
EqnSideItem::EqnSideItem(QQuickItem* a_Parent)
  : QQuickItem(a_Parent)
{
  QString expr("2*x+4");
  int pos(0);
  m_EqnItem = EqnItemTreeBuilder::parseExpression(expr, pos, this);
  QSize size(500, 100);
  EqnGraphicalLayoutBuilder::build(m_EqnItem, 0, 0, size, 10, 5, 5);
}

EqnSideItem::~EqnSideItem()
{

}

