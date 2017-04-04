import QtQuick 2.3
import QtQuick.Window 2.2
import QtQuick.Controls 1.4

Window {
    id: mainWindow
    visible: true
    title: "Noughts and Crosses"
    height: 300
    width: 300

    Loader {
        id: pageLoader
    }

    Item {
        id: root
        anchors.fill: parent

        Column {
            anchors {
                horizontalCenter: root.horizontalCenter
                verticalCenter: root.verticalCenter
            }
            spacing: 5

            Label {
                text: "Noughts and Crosses"
                font.pixelSize: 22

            }

            Label {
                text: "Choose game mode"
                font.pixelSize: 16
            }

            Button {
                text: "Player vs Player"
                onClicked: {
                    console.log("Mode: Player vs Player")
                    pageLoader.source = "PlayerVsPlayer.qml"
                    game.pvpGameMode()
                    mainWindow.close()
                }
            }
        }
    }
}
