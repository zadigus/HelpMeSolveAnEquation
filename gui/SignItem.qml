import QtQuick 2.5

Rectangle
{
  id: signRect
  border.color: "black"
  border.width: 1

  width: signTextMetrics.tightBoundingRect(signText.text).width
  height: signTextMetrics.tightBoundingRect(signText.text).height

  x: -width
  y: (parent.height - height) / 2

  Text
  {
    id: signText
    text: signRect.parent.op
  }

  FontMetrics
  {
    id:  signTextMetrics
    font: signRect.parent.font
  }

}
