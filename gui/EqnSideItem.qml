import QtQuick 2.4
import EquationSolver 1.0

EqnSideItem
{
    LayoutProperties
    {
        id: myLayoutProps

        polynomSize: "500x100"
        spaceBetweenItems: 10
        verticalMargin: 5
        horizontalMargin: 5

        onLayoutChanged:
        {
            console.info("size              = " + polynomSize.width + "x" + polynomSize.height)
            console.info("spaceBetweenItems = " + spaceBetweenItems)
            console.info("vertical margin   = " + verticalMargin)
            console.info("horizontal margin = " + horizontalMargin)

            parent.buildLayout()
        }
    }

    onExpressionPositionChanged:
    {
        console.info("New position = " + expressionPosition.x + ", " + expressionPosition.y)
    }

    onExpressionChanged:
    {
        console.info("Building tree")
        buildTree()
        console.info("Building layout")
        buildLayout(rootEqnItem(), expressionPosition.x, expressionPosition.y, myLayoutProps.polynomSize.width, myLayoutProps.polynomSize.height)
    }

    function buildLayout(item, x, y, w, h)
    {
        buildGeometry(item, x, y, w, h)
        buildChildrenLayout(item, w, h)
    }

    function buildGeometry(item, x, y, w, h)
    {
        item.width = w
        item.height = h
        item.x = x
        item.y = y
    }

    function buildChildrenLayout(item, w, h)
    {
        var nbrOfChildren = item.children.length

        if(!nbrOfChildren)
        {
            return
        }

        var space   = myLayoutProps.spaceBetweenItems
        var vMargin = myLayoutProps.verticalMargin
        var hMargin = myLayoutProps.horizontalMargin

        var totalOffsetSpace = (nbrOfChildren - 1) * space;
        var childWidth       = (item.width - totalOffsetSpace - 2 * hMargin) / nbrOfChildren;
        var childHeight      = item.height - 2 * vMargin;

        var x = hMargin
        var y = h / 2 - childHeight / 2

        for(var i = 0; i < item.children.length; ++i)
        {
            buildLayout(item.children[i], x, y, childWidth, childHeight)
            x += childWidth + space
        }
    }

    function getWidth()
    {
        return myLayoutProps.polynomSize.width
    }

    function rootEqnItem() // returns root PolynomialItem
    {
        return children[0]
    }

}
