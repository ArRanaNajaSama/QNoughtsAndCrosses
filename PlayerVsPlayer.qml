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
                text: "Player 1:"
                font.pixelSize: 14
            }

            Label {
                text: game.scoreX
                font.pixelSize: 14
            }

            Label {
                text: "Player 2:"
                font.pixelSize: 14
            }

            Label {
                text: game.scoreO;
                font.pixelSize: 14
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
                    model: 9

                    Button {
                        id: btn
                        iconSource: "qrc:/placeholder.png"
                        width: 50;
                        height: 50
                        onClicked: {
                            console.log("Clicked rect #", index)
                            game.currCell = index;
                            //game.getCellNumberFromQML(index)
                            if (game.image == 1)
                            {
                                btn.iconSource = "qrc:/cross.png"
                            } else {
                                btn.iconSource = "qrc:/shape_circle.png"
                            }
                        }
                    }
                }
            }
        }

        //game dialog window
        TextField {
            anchors {
                top: board.bottom
                topMargin: 15
                horizontalCenter: board.horizontalCenter
            }
            text: game.whoseTurn
            readOnly: true
            selectByMouse: false
        }
    }
}
