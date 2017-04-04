import QtQuick 2.3
import QtQuick.Window 2.2
import QtQuick.Controls 1.4

Window {
    id: pvpWindow
    visible: true
    height: 350
    width: 350

    Item {
        id: root
        anchors.fill: parent

        // Players info
        Grid {
            id: playersInfo
            anchors.horizontalCenter: parent.horizontalCenter
            columns: 2
            spacing: 5

            Label {
                text: "Player X:"
                font.pixelSize: 15
            }

            Label {
                text: game.scoreX
                font.pixelSize: 15
            }

            Label {
                text: "Player O:"
                font.pixelSize: 15
            }

            Label {
                text: game.scoreO;
                font.pixelSize: 15
            }
        }

        //game board
        Rectangle {
            id: board
            anchors {
                top: playersInfo.bottom
                centerIn: root
            }
            width: 160
            height: 160
            color: "black"

            Grid {
                anchors.fill: parent
                columns: 3
                spacing: 5

                Repeater {
                    id: repeater
                    model: 9

                    Button {
                        id: btn
                        focus: true
                        iconSource: "qrc:/placeholder.png"
                        width: 50;
                        height: 50
                        onClicked: {
                            console.log("Clicked button #", index)
                            game.currCell = index;
                            switch(game.image)
                            {
                            case 1:
                                btn.iconSource = "qrc:/cross.png"
                                break;
                            case 2:
                                btn.iconSource = "qrc:/shape_circle.png"
                                break;
                            case 7:
                                btn.iconSource = "qrc:/placeholder.png"
                                break;
                            }
                        }
                    }
                }
            }
        }

        Column {
            anchors {
                top: board.bottom
                topMargin: 15
                horizontalCenter: board.horizontalCenter
            }
            spacing: 5
            //game dialog window
            Label {

                text: game.whoseTurn
                font.pixelSize: 16
            }

            Button {
                Button {
                    id: newGame
                    text: "New game"
                    onClicked: {
                        game.newGameMode()

                        for (var i = 0; i < 9; ++i)
                        {
                            repeater.itemAt(i).iconSource = "qrc:/placeholder.png"
                        }
                    }
                }
            }
        }

    }
}
