import QtQuick 2.0
import QtQuick.Controls 2.12

MyTextArea {
    onTextChanged:  {
        setBorder(!isName());
    }
    function isName() {
        return text != "";
    }
}
