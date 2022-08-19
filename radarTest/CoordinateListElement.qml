import QtQuick 2.15
import QtQuick.Layouts 1.2
import QtQuick.Controls 2.12

Item {
    width: parent != null ? parent.width : 0
    height: elementHeight + 2 * gap

    RowLayout {
        anchors.fill: parent
        anchors.topMargin: gap / 2
        anchors.bottomMargin: gap / 2
        anchors.leftMargin: gap
        anchors.rightMargin: gap
        spacing: gap

        ListCheckButton {
            Layout.fillHeight: true
            Layout.preferredWidth: elementHeight
            buttonText: model.id
        }

        Rectangle {
            Layout.fillHeight: true
            Layout.fillWidth: true
            color: "lightgreen"
            border.width: borderWidth
            border.color: borderColor

            TextInput {
                anchors.centerIn: parent
                text: model.latitude
                color: acceptableInput ? textColor : accentColor
                font.pixelSize: elementHeight / 2
                selectByMouse: true
                validator: RegExpValidator {
                    regExp: /^((\d|([1-8][0-9]))|(90))°((\d|([1-5][0-9]))|(60))'((\d(\.\d)?|([1-5][0-9])(\.\d)?)|(60))"\s(С|Ю)Ш$/
                }

//                onEditingFinished:
            }
        }

        Rectangle {
            Layout.fillHeight: true
            Layout.fillWidth: true
            color: "lightgreen"
            border.width: borderWidth
            border.color: borderColor

            TextInput {
                anchors.centerIn: parent
                text: model.longitude
                color: acceptableInput ? textColor : accentColor
                font.pixelSize: elementHeight / 2
                selectByMouse: true
                validator: RegExpValidator {
                    regExp: /^(\d|[1-9][0-9]|1[0-7][0-9]|180)°((\d|([1-5][0-9]))|(60))'((\d(\.\d)?|([1-5][0-9])(\.\d)?)|(60))"\s(В|З)Д$/
                }
            }
        }
    }
}
