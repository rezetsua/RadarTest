import QtQuick 2.15
import QtQuick.Layouts 1.2
import QtQuick.Controls 2.15

Button {
    property string iconSource: ""

    icon.source: iconSource
    background: Rectangle {
        color: {
            if (parent.down)
                return buttonPressedColor
            else if (parent.hovered)
                return buttonHoveredColor
            else
                return buttonBackGroundColor
        }
    }
}
