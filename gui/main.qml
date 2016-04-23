import QtQuick 2.4
import QtQuick.Controls 1.3
import QtQuick.Controls.Styles 1.2
import QtQuick.Window 2.0
import QtQuick.Dialogs 1.2
import QtQuick.Layouts 1.1

ApplicationWindow
{
    id: myWindow
    title: qsTr("How to solve an equation?")
    width: 1200
    height: 480
    visible: true

    property var posX: 50
    property var posY: 50
    property var offset: 50

    EqnSideItem
    {
        id: left_side

        Component.onCompleted:
        {
            left_side.expression = "8*x-1"
            left_side.expressionPosition = Qt.point(posX, posY)
        }
    }

    EqnSideItem
    {
        id: right_side

        Component.onCompleted:
        {
            right_side.expression = "x+2"
            right_side.expressionPosition = Qt.point(posX + left_side.getWidth() + offset, posY)
        }
    }
}
