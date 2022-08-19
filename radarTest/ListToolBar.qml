import QtQuick 2.15
import QtQuick.Layouts 1.2
import QtQuick.Controls 2.15

RowLayout {
    spacing: gap

    ListToolButton {
        Layout.fillHeight: true
        Layout.preferredWidth: elementHeight
        iconSource: "qrc:/icons/add_point.svg"

        ToolTip {
            delay: 1000
            timeout: 5000
            text: qsTr("Добавить точку")
            visible: parent.hovered
        }

        onClicked: list_model_.addZeroElement()
    }

    ListToolButton {
        Layout.fillHeight: true
        Layout.preferredWidth: elementHeight
        iconSource: "qrc:/icons/remove_point.svg"

        ToolTip {
            delay: 1000
            timeout: 5000
            text: qsTr("Удалить выбранные точки")
            visible: parent.hovered
        }

        onClicked: coordinateListModel.deleteSelectedElement()
    }

    Item {
        Layout.fillHeight: true
        Layout.fillWidth: true
    }
}
