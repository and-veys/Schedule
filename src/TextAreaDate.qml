import QtQuick 2.0
import QtQuick.Controls 2.12
MyTextArea {
        onTextChanged:  {
            setBorder(!isDate())
        }
        function isDate() {
            let dt = getDate();
            return !(dt === null);

        }
        function getDate() {
            let sp = text.split(".");
            if(sp.length !== 3) return null;
            for(let i=0; i<3; ++i) {
                sp[i] = Number(sp[i]);
                if(isNaN(sp[i])) return null;
            }
            let dt = new Date(sp[2], sp[1]-1, sp[0]);
            let now = new Date();
            if(dt < now) return null;
            let d = dt.getDate();
            let m = dt.getMonth()+1;
            let y = dt.getFullYear();
            if(d !== sp[0] || m !== sp[1] || y !== sp[2]) return null;
            return sp;
        }
}
