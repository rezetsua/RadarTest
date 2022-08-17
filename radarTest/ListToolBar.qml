import QtQuick 2.15
import QtQuick.Layouts 1.2
import QtQuick.Controls 2.15

RowLayout {
    spacing: gap

    ListToolButton {
        Layout.fillHeight: true
        Layout.preferredWidth: elementHeight
        iconSource: "qrc:/icons/add_point.svg"
    }

    ListToolButton {
        Layout.fillHeight: true
        Layout.preferredWidth: elementHeight
        iconSource: "qrc:/icons/remove_point.svg"
    }

    Item {
        Layout.fillHeight: true
        Layout.fillWidth: true
    }
}
