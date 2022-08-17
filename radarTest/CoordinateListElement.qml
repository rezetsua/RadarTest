import QtQuick 2.15
import QtQuick.Layouts 1.2

Item {
    width: parent.width
    height: elementHeight + 2 * gap

    RowLayout {
        anchors.fill: parent
        anchors.topMargin: gap / 2
        anchors.bottomMargin: gap / 2
        anchors.leftMargin: gap
        anchors.rightMargin: gap
        spacing: gap

        Rectangle {
            Layout.fillHeight: true
            Layout.preferredWidth: elementHeight
            color: "darkgray"
            border.width: borderWidth
            border.color: borderColor

            Text {
                anchors.centerIn: parent
                text: model.id
                color: textColor
                font.pixelSize: elementHeight / 2
            }
        }

        Rectangle {
            Layout.fillHeight: true
            Layout.fillWidth: true
            color: "lightgreen"
            border.width: borderWidth
            border.color: borderColor

            Text {
                anchors.centerIn: parent
                text: model.latitude
                color: textColor
                font.pixelSize: elementHeight / 2
            }
        }

        Rectangle {
            Layout.fillHeight: true
            Layout.fillWidth: true
            color: "lightgreen"
            border.width: borderWidth
            border.color: borderColor

            Text {
                anchors.centerIn: parent
                text: model.longitude
                color: textColor
                font.pixelSize: elementHeight / 2
            }
        }
    }
}
