import QtQuick 2.0
import QtQuick.Controls 2.12

MyButton {
    onClicked: {
        let dt = schedule.getNotes();
        for(let i=0; i<dt.length; ++i)
            console.log(dt[i]);
        console.log("--------------------------------------------------");
    }
}
