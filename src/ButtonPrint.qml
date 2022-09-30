import QtQuick 2.0
import QtQuick.Controls 2.12

MyButton {
      objectName: "button_print"
      signal printSchedule()
      onClicked: {
          printSchedule()
//        let dt = schedule.getNotes();
//        for(let i=0; i<dt.length; ++i)
//            console.log(dt[i]);
//        console.log("--------------------------------------------------");
    }
}
