// Copyright (C) 2014 Leslie Zhai <xiang.zhai@i-soft.com.cn>

import QtQuick 2.2
import QtQuick.Controls 1.1
import QtQuick.Window 2.1

ApplicationWindow {
    id: rootWindow
    width: 310; height: 500

    StackView {
        id: stackView
        width: parent.width; height: parent.height
        anchors.fill: parent
        initialItem: LoginView {}
    }
}
