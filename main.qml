import QtQuick 2.4
import QtQuick.Controls 1.3
import QtQuick.Controls.Styles 1.2
import QtQuick.Window 2.0
import QtQuick.Dialogs 1.2
import QtQuick.Layouts 1.1
import EquationSolver 1.0

ApplicationWindow {
  id: myWindow
  title: qsTr("How to solve an equation?")
  width: 640
  height: 480
  visible: true

  /*EquationItem {
    id: equationItem
    anchors.centerIn: parent
    width: 100
    height: 100
    text: "2*x-x/19+4"
    color: "blue"
  }*/

  Polynom {
    id: polynom
  }
}
