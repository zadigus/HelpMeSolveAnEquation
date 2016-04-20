#include "Builders/EqnGraphicalLayoutBuilder.hpp"

#include <QQuickItem>
#include <QList>
#include <QSize>

#include <algorithm>

//EqnGraphicalLayoutBuilder::EqnGraphicalLayoutBuilder(PolynomialItem* a_Root)
//{

//}

// TODO: this should all be done in a QML script

namespace EqnGraphicalLayoutBuilder {

  //------------------------------------------------------------------------------------------------------
  void setItemGeometry(QQuickItem* a_Item, qreal a_X, qreal a_Y, const QSize& a_Size)
  {
    a_Item->setSize(a_Size);
    a_Item->setX(a_X);
    a_Item->setY(a_Y);
  }

  //------------------------------------------------------------------------------------------------------
  void placeChildren(QQuickItem* a_Item, const QSize& a_Size, const QList<QQuickItem*>& a_Children, qreal a_SpaceBetweenItems, qreal a_WidthMargin, qreal a_HeightMargin)
  {
    int nbrOfChildren(a_Children.size());
    if(!nbrOfChildren)
    {
      return;
    }

    qreal totalOffsetSpace = (nbrOfChildren - 1) * a_SpaceBetweenItems;
    qreal childWidth       = (a_Item->width() - totalOffsetSpace - 2 * a_WidthMargin) / nbrOfChildren;
    qreal childHeight      = a_Item->height() - 2 * a_HeightMargin;

    QSize childSize(childWidth, childHeight);
    qreal x(a_WidthMargin);
    qreal y(a_Size.height() / 2 - childHeight / 2);

    std::for_each(a_Children.begin(), a_Children.end(),
                  [&x, y, &childSize, &a_SpaceBetweenItems, &a_WidthMargin, &a_HeightMargin] (QQuickItem* a_Item)
                  {
                    build(a_Item, x, y, childSize, a_SpaceBetweenItems, a_WidthMargin, a_HeightMargin);
                    x += childSize.width() + a_SpaceBetweenItems;
                  }
    );
  }

  //------------------------------------------------------------------------------------------------------
  void build(QQuickItem* a_Item, qreal a_X, qreal a_Y, const QSize& a_Size, qreal a_SpaceBetweenItems, qreal a_WidthMargin, qreal a_HeightMargin)
  {
    setItemGeometry(a_Item, a_X, a_Y, a_Size);
    QList<QQuickItem*> children(a_Item->childItems());
    placeChildren(a_Item, a_Size, children, a_SpaceBetweenItems, a_WidthMargin, a_HeightMargin);
  }

}
