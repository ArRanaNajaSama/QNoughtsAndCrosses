import QtQuick 2.3
import QtQuick.Window 2.2
import QtQuick.Controls 1.4

Window {
    visible: true
    minimumHeight: 300
    minimumWidth: 300

    Item {
        id: root
        anchors.fill: main
        height: main.minimumHeight
        width: main.minimumWidth

        Grid {
            id: playersInfo
            columns: 2

            Label {
                text: "Player 1:"
            }

            TextField {
                text: "0"
                readOnly: true
            }

            Label {
                text: "Player 2:"
            }

            TextField {
                text: "0"
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
            text: "Player X turn!"
            readOnly: true
        }
    }
}
