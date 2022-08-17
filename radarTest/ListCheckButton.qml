import QtQuick 2.0
import QtQuick.Layouts 1.2
import QtQuick.Controls 2.15

Button {
    property string buttonText: ""

    checkable: true
    text: buttonText
    background: Rectangle {
        border.width: borderWidth
        border.color: borderColor
        color: {
            if (parent.down)
                return "gray"
            else if (parent.hovered)
                return "silver"
            else if (parent.checked)
                return "red"
            else
                return "darkgrey"
        }
    }
}
