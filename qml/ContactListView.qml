// Copyright (C) 2014 Leslie Zhai <xiang.zhai@i-soft.com.cn>

import QtQuick 2.2
import QtQuick.Controls 1.1
import cn.com.isoft.qwx 1.0

Item {
    id: contactListView
    width: parent.width; height: parent.height

    property var modContactObj

    ListView {
        id: modContactListView
        model: contactListView.modContactObj.modContactList
        anchors.fill: parent

        delegate: Item {
            height: 30
            
            Text {
                text: modelData.NickName
            }
        }
    }
}
