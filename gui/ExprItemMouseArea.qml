import QtQuick 2.0

MouseArea
{
    id: mouse_area

    anchors.fill: parent

    z: parent.z

    onClicked:
    {
        console.log("Clicked an element of type " + parent.exprType)
        parent.borderColor = 'red'
    }
}
