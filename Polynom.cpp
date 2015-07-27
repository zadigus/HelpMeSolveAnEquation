#include "Polynom.hpp"

#include "EquationItem.hpp"

Polynom::Polynom(QQuickItem* a_Parent)
  : QQuickItem(a_Parent)
  , m_EqnItem(new EquationItem(this))
//  , m_EqnItem2(new EquationItem(m_EqnItem))
{
  m_EqnItem->setText("Hahaha");
  m_EqnItem->setWidth(100);
  m_EqnItem->setHeight(100);

  EquationItem* m_EqnItem2(new EquationItem(m_EqnItem));
  m_EqnItem2->setWidth(50);
  m_EqnItem2->setHeight(50);
  m_EqnItem2->setBorderColor(QColor("blue"));
  m_EqnItem2->setX(25);
  m_EqnItem2->setY(25);
}

Polynom::~Polynom()
{

}

