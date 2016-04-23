#include "EqnItems/EqnSideItem.hpp"

#include "EqnItems/PolynomialItem.hpp"

#include "Builders/EqnItemTreeBuilder.hpp"
#include "Builders/EqnGraphicalLayoutBuilder.hpp"

namespace N_EqnItems
{

  //------------------------------------------------------------------------------------------------------
  EqnSideItem::EqnSideItem(QQuickItem* a_Parent)
    : QQuickItem(a_Parent)
    , m_Size(500, 100)
    , m_SpaceBetweenItems(10)
    , m_VerticalMargin(5)
    , m_HorizontalMargin(5)
    , m_EqnItem(NULL)
  {

  }

  EqnSideItem::~EqnSideItem()
  {

  }

  void EqnSideItem::buildTree()
  {
    int pos(0);
    if(m_EqnItem != NULL)
    {
      delete m_EqnItem;
    }
    m_EqnItem = EqnItemTreeBuilder::parseExpression(m_Polynom, pos, this);
  }

  void EqnSideItem::buildLayout()
  {
    EqnGraphicalLayoutBuilder::build(m_EqnItem, m_Position.x(), m_Position.y(), m_Size, m_SpaceBetweenItems, m_VerticalMargin, m_HorizontalMargin);
  }

}
