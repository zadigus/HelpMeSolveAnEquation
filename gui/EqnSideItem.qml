import QtQuick 2.4
import EquationSolver 1.0

EqnSideItem
{
    onPolynomPositionChanged:
    {
        console.info("new position = " + polynomPosition.x + ", " + polynomPosition.y);
    }

    onPolynomChanged:
    {
        console.info("building tree and layout")
        buildTree();
        buildLayout();
    }

    function rootEqnItem() // returns EqnSideItem::m_EqnItem
    {
        return children[0];
    }
}
