#include "EqnItems/PolynomialItem.hpp"

#include <QPen>
#include <QPainter>

namespace N_EqnItems {

  //------------------------------------------------------------------------------------------------------
  PolynomialItem::PolynomialItem(QQuickItem *a_Parent)
    : QQuickPaintedItem(a_Parent)
    , m_VERTICAL_MARGIN(10)
    , m_HORIZONTAL_MARGIN(10)
    , m_HORIZONTAL_OFFSET(5)
    , m_Color(QColor("black"))
    , m_Font(QFont("Arial", 16))
  {
    connect(this, SIGNAL(borderColorChanged()), this, SLOT(update()));
  }

  //------------------------------------------------------------------------------------------------------
  PolynomialItem::~PolynomialItem()
  {

  }

  //------------------------------------------------------------------------------------------------------
  void PolynomialItem::drawText(QPainter* a_Painter)
  {
    a_Painter->setFont(m_Font);
    QFontMetrics metrics(m_Font);
    QRect textRect(metrics.tightBoundingRect(m_Text));
    QPoint center(width()/2, height()/2);
    a_Painter->drawText(center.x() - textRect.width() / 2, center.y() + textRect.height() / 2, m_Text);
  }

  //------------------------------------------------------------------------------------------------------
  void PolynomialItem::paint(QPainter* a_Painter)
  {
    QPen pen(m_Color, 2);
    a_Painter->setPen(pen);
    a_Painter->setRenderHints(QPainter::Antialiasing, true);
    a_Painter->drawRect(0, 0, width(), height());
    drawText(a_Painter);
  }

}
