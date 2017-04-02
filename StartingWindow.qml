import QtQuick 2.3
import QtQuick.Window 2.2
import QtQuick.Controls 1.4

Window {
    id: mainWindow
    visible: true
    title: "Noughts and Crosses"
    minimumHeight: 300
    minimumWidth: 300

    Loader {
        id: pageLoader
    }

    Item {
        id: root
        anchors.fill: parent

        Grid {
            anchors {
                horizontalCenter: root.horizontalCenter
                verticalCenter: root.verticalCenter
            }
            columns: 1
            spacing: 5

            Label {
                text: "Noughts and Crosses"
            }

            Label {
                text: "Choose game mode"
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
