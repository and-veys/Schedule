import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.12
//import MY.Schedule 1.0

Rectangle {
    color:          "lightgreen"
    width:          500
    height:         300
    visible:        true
    Column {
        id:             col_1
        spacing:        10
        x:              10
        y:              10
        width:          parent.width - 20
        Caption {
            text:           "Задание"
        }
        TextAreaName {
            id:                 name
            focus:              true
        }
    }
    Column {
        id:                     col_2
        spacing:                10
        anchors.left:           col_1.left;
        anchors.top:            col_1.bottom;
        anchors.topMargin:      10
        width:                  progress.width
        Caption {
            text:                "Прогресс"
        }
        SpinBox {
            id:                     progress
            from:                   0
            to:                     10
            value:                  0
            font.family:            name.font.family
            font.pointSize:         name.font.pointSize
        }
    }
    Column {
        id:                     col_3
        spacing:                10
        anchors.left:           col_2.right
        anchors.right:          col_1.right
        anchors.top:            col_2.top;
        anchors.leftMargin:     10
        Caption {
            text:                "Конечный срок"
        }
        TextAreaDate {
            id:                 date
        }
    }
    Row {
        anchors.left:               col_1. left
        anchors.bottom:             parent.bottom
        anchors.right:              col_1.right
        anchors.bottomMargin:       button_save.height+10
        ButtonSave {
            id:                     button_save
            text:                   "Сохранить"
            enabled:                false
        }
        ButtonPrint {
            anchors.right:          parent.right
            id:                     button_print
            text:                   "Посмотреть все задания"
        }
    }
//    Schedule {
//        id:         schedule
//    }

}


