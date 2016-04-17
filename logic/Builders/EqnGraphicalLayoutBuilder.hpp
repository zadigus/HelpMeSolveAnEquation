#ifndef EQNGRAPHICALLAYOUTBUILDER_H
#define EQNGRAPHICALLAYOUTBUILDER_H

#include <QtGlobal>

class QQuickItem;

class QSize;

/*class EqnGraphicalLayoutBuilder
{
  public:
    EqnGraphicalLayoutBuilder(PolynomialItem* a_Root);
};*/

// TODO: this should be a class

namespace EqnGraphicalLayoutBuilder {

  void build(QQuickItem* a_Item, qreal a_X, qreal a_Y, const QSize& a_Size, qreal a_SpaceBetweenItems, qreal a_WidthMargin, qreal a_HeightMargin);
  void setItemGeometry(QQuickItem* a_Item, qreal a_X, qreal a_Y, const QSize& a_Size);
  void placeChildren(QQuickItem* a_Item, const QSize& a_Size, const QList<QQuickItem*>& a_Children, qreal a_SpaceBetweenItems, qreal a_WidthMargin, qreal a_HeightMargin);
}

#endif // EQNGRAPHICALLAYOUTBUILDER_H
