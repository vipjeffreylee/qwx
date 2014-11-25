// Copyright (C) 2014 Leslie Zhai <xiang.zhai@i-soft.com.cn>

import QtQuick 2.2
import QtQuick.Controls 1.1
import cn.com.isoft.qwx 1.0

Item {
    id: contactListView
    width: parent.width; height: parent.height

    property var modContactObj
    property string uin
    property string sid
    property string skey

    SendMsg {
        id: sendMsgObj
    }

    ListView {
        id: modContactListView
        model: contactListView.modContactObj.modContactList
        anchors.fill: parent

        delegate: Item {
            height: 30
            
            /* FIXME: ./src/modcontact.cpp it ONLY works in web browser ...
            Image {
                source: modelData.HeadImgUrl
            }
            */

            Text {
                text: modelData.NickName

                MouseArea {
                    anchors.fill: parent
                    onClicked: {
                        console.log("DEBUG: only for test sending msg")
                        // TODO: it needs to get current login user account ;)
                        sendMsgObj.post(contactListView.uin, 
                                        contactListView.sid, 
                                        contactListView.skey, 
                                        "sirtoozee", // TODO: only for test 
                                        modelData.UserName, 
                                        "hello, " + modelData.NickName + " 消息来自qwx ;)")
                    }
                }
            }
        }
    }
}
