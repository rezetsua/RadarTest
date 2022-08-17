import QtQuick 2.15

ListView {
    clip: true
    model: list_model_
    delegate: CoordinateListElement {}
}
