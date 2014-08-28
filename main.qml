import QtQuick 2.2
import QtQuick.Controls 1.1

ApplicationWindow {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    menuBar: MenuBar {
        Menu {
            title: qsTr("File")
            MenuItem {
                text: qsTr("Exit")
                onTriggered: Qt.quit();
            }
        }
    }

    Text {
        width: 437
        height: 197
        text: qsTr("Bienvenidos a mi programa")
        font.pointSize: 28
        anchors.verticalCenterOffset: 1
        anchors.horizontalCenterOffset: 1
        anchors.centerIn: parent
    }
}
