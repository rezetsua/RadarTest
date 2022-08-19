import QtQuick 2.0
import QtQuick.Layouts 1.2
import QtQuick.Controls 2.15

Button {
    property string buttonText: ""

    checkable: true
    text: buttonText
    contentItem: Text {
        anchors.fill: parent
        verticalAlignment: Text.AlignVCenter
        horizontalAlignment: Text.AlignHCenter
        text: buttonText
        color: parent.checked ? accentColor : textColor
        font.pixelSize: elementHeight / 2
    }

    background: Rectangle {
        border.width: borderWidth
        border.color: parent.checked ? accentColor : borderColor
        color: {
            if (parent.down)
                return buttonPressedColor
            else if (parent.hovered)
                return buttonHoveredColor
            else
                return buttonBackGroundColor
        }
    }

    ToolTip {
        delay: 1000
        timeout: 5000
        text: qsTr("Выбрать")
        visible: parent.hovered
    }
}
