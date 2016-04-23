#include "EqnItems/EqnSideItem.hpp"

#include "EqnItems/PolynomialItem.hpp"

#include "Builders/EqnItemTreeBuilder.hpp"

using namespace N_Builders;

namespace N_EqnItems
{

  //------------------------------------------------------------------------------------------------------
  EqnSideItem::EqnSideItem(QQuickItem* a_Parent)
    : QQuickItem(a_Parent)
    , m_EqnItem(NULL)
  {

  }

  //------------------------------------------------------------------------------------------------------
  EqnSideItem::~EqnSideItem()
  {

  }

  //------------------------------------------------------------------------------------------------------
  QPointF EqnSideItem::polynomPosition() const
  {
    return m_EqnItem != NULL ? m_EqnItem->position() : QPointF();
  }

  //------------------------------------------------------------------------------------------------------
  void EqnSideItem::setPolynomPosition(const QPointF& a_Position)
  {
    if(m_EqnItem)
    {
      m_EqnItem->setPosition(a_Position);
      emit polynomPositionChanged();
    }
  }

  //------------------------------------------------------------------------------------------------------
  void EqnSideItem::buildTree()
  {
    qInfo() << "Building tree";

    int pos(0);
    if(m_EqnItem != NULL)
    {
      delete m_EqnItem;
    }
    m_EqnItem = EqnItemTreeBuilder::parseExpression(m_Polynom, pos, this);
  }

}
