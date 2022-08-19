import QtQuick 2.15
import QtQuick.Controls 2.15

ListView {
    clip: true
    model: list_model_
    delegate: CoordinateListElement {}
    ScrollBar.vertical: ScrollBar {
        Component.onCompleted: {
            contentItem.color = buttonPressedColor
        }
    }

    function deleteSelectedElement() {
        for(var i = count - 1; i >= 0; --i) {
            var item = itemAtIndex(i)
            if (item.children[0].children[0].checked)
                list_model_.removeElementByIndex(i)
        }
    }
}
