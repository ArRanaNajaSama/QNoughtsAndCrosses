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

        Grid {
            id: board
            anchors {
                top: playersInfo.bottom
                topMargin: 15
                centerIn: root
            }
            columns: 3
            spacing: 5

            Rectangle {
                id: first
                color: "#aa6666";
                width: 50;
                height: 50

                MouseArea {
                    anchors.fill: parent
                    onClicked: {
                        parent.color = 'red'
                        console.log("Clicked rect # 1")
                        game.getCellNumberFromQML(0)
                    }
                }
            }
            Rectangle {
                color: "#aa6666";
                width: 50;
                height: 50
                MouseArea {
                    anchors.fill: parent
                    onClicked: {
                        parent.color = 'red'
                        console.log("Clicked 2 rect")
                        game.getCellNumberFromQML(1)
                    }
                }
            }
            Rectangle {
                color: "#aa6666";
                width: 50;
                height: 50
                MouseArea {
                    anchors.fill: parent
                    onClicked: {
                        parent.color = 'red'
                        console.log("Clicked 3 rect")
                        game.getCellNumberFromQML(2)
                    }
                }
            }
            Rectangle {
                color: "#aa6666";
                width: 50;
                height: 50
                MouseArea {
                    anchors.fill: parent
                    onClicked: {
                        parent.color = 'red'
                        console.log("Clicked 4 rect")
                        game.getCellNumberFromQML(3)
                    }
                }
            }
            Rectangle {
                color: "#aa6666";
                width: 50;
                height: 50
                MouseArea {
                    anchors.fill: parent
                    onClicked: {
                        parent.color = 'red'
                        console.log("Clicked 5 rect")
                        game.getCellNumberFromQML(4)
                    }
                }
            }
            Rectangle {
                color: "#aa6666";
                width: 50;
                height: 50
                MouseArea {
                    anchors.fill: parent
                    onClicked: {
                        parent.color = 'red'
                        console.log("Clicked 6 rect")
                        game.getCellNumberFromQML(5)
                    }
                }
            }

            Rectangle {
                color: "#aa6666";
                width: 50;
                height: 50
                MouseArea {
                    anchors.fill: parent
                    onClicked: {
                        parent.color = 'red'
                        console.log("Clicked 7 rect")
                        game.getCellNumberFromQML(6)
                    }
                }
            }
            Rectangle {
                color: "#aa6666";
                width: 50;
                height: 50
                MouseArea {
                    anchors.fill: parent
                    onClicked: {
                        parent.color = 'red'
                        console.log("Clicked 8 rect")
                        game.getCellNumberFromQML(7)
                    }
                }
            }
            Rectangle {
                color: "#aa6666";
                width: 50;
                height: 50
                MouseArea {
                    anchors.fill: parent
                    onClicked: {
                        parent.color = 'red'
                        console.log("Clicked 9 rect")
                        game.getCellNumberFromQML(8)
                    }
                }
            }
        }

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
