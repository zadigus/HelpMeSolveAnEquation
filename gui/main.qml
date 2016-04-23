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
    width: 640
    height: 480
    visible: true

    EqnSideItem
    {
        id: left_side

        polynom: "2*x-7"
        polynomPosition: "50, 50"
    }
}
