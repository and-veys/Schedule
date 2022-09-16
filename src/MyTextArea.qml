import QtQuick 2.0
import QtQuick.Controls 2.12

TextArea {
    font.family:                "Helvetica"
    font.pointSize:             14
    width:                      parent.width
    background:     Rectangle {
                        id:             rect
                        anchors.fill:   parent
                        color:          "white"
                        border.color:   "red"
                        border.width:   3
                    }

    function setBorder(br) { 
        button_save.enabled = (name.isName() && date.isDate())
        rect.border.width = (br ? 3 : 0);
    }
}

