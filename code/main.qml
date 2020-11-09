// import QtQuick 1.0 // to target S60 5th Edition or Maemo 5
import QtQuick 1.1
import Qt 4.7

Rectangle {
    width: 360
    height: 360
    radius: 10

    Rectangle {
        id: rectangle1
        x: 35
        y: 24
        width: 276
        height: 93
        color: "#f54819"
        anchors.leftMargin: 35
        anchors.topMargin: 24
        anchors.rightMargin: 49
        anchors.bottomMargin: 244
        anchors.fill: parent
    }

    Text {
        id: text1
        x: 85
        y: 209
        text: qsTr("text")
        font.pixelSize: 80
    }
}
