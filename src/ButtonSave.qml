import QtQuick 2.0
import QtQuick.Controls 2.12

MyButton {
    objectName: "button_save"
    signal saveNode(string nm, variant dt, int pr)
    onClicked: {
        saveNode(name.text, date.getDate(), progress.value)
        //schedule.setNote(name.text, date.getDate(), progress.value);
        name.text = "";
        date.text = "";
        progress.value = 0;
    }
}
