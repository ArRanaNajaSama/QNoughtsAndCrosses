import QtQuick 2.3
import QtQuick.Window 2.2
import QtQuick.Controls 1.4

Window {
    id: pvpWindow
    visible: true
    minimumHeight: 300
    minimumWidth: 300

    Item {
        id: root
        anchors.fill: parent

        // Players info
        Grid {
            id: playersInfo
            columns: 2

            Label {
                text: "Player 1:"
            }

            TextField {
                text: game.scoreX
                readOnly: true
            }

            Label {
                text: "Player 2:"
            }

            TextField {
                text: game.scoreO;
                readOnly: true
            }
        }

        //game board
        Rectangle {
            id: board
            anchors {
                top: playersInfo.bottom
                topMargin: 15
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
                            game.getCellNumberFromQML(index)
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
        }
    }
}
