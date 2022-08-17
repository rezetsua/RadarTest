import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Layouts 1.2

Window {
    width: 480
    height: 480
    visible: true
    title: qsTr("Radar Test")

    property int gap: 2
    property int borderWidth: 1
    property int elementHeight: 40

    property color borderColor: "gray"
    property color textColor: "black"

    Rectangle {
        anchors.fill: parent
        color: "white"

        ColumnLayout {
            anchors.fill: parent
            anchors.margins: gap
            spacing: gap

            Rectangle {
                Layout.fillWidth: true
                Layout.preferredHeight: elementHeight + 2 * gap
                color: "lightgray"
            }

            Rectangle {
                Layout.fillWidth: true
                Layout.fillHeight: true
                color: "lightgray"

                CoordinateListModel {
                    anchors.fill: parent
                    anchors.topMargin: gap / 2
                    anchors.bottomMargin: gap / 2
                }
            }
        }
    }
}
