import QtQuick 2.0
import QtQuick.Controls 2.12

MyButton {
    onClicked: {
        schedule.setNote(name.text, date.getDate(), progress.value);
        name.text = "";
        date.text = "";
        progress.value = 0;
    }
}
