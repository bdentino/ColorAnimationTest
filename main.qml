import QtQuick 2.2
import QtQuick.Window 2.1

Window {
    visible: true
    width: 360
    height: 360

    MouseArea {
        id: mouseArea
        anchors.fill: parent
    }

    Rectangle {
        id: testRect
        anchors.fill: parent
        color: mouseArea.pressed ? 'green' : 'yellow'
        Behavior on color { ColorAnimation { duration: 1000 } }
    }
}
