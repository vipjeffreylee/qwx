// Copyright (C) 2014 Leslie Zhai <xiang.zhai@i-soft.com.cn>

import QtQuick 2.2
import QtQuick.Controls 1.1
import QtQuick.Window 2.1
import cn.com.isoft.qwx 1.0

ApplicationWindow {
    id: loginWindow
    width: 500; height: 500

    property string uuid: ""

    UUID {
        id: uuidObj
        onUuidChanged: {
            loginWindow.uuid = uuid
            console.log("DEBUG:", uuid)
            qrcodeImage.source = "https://login.weixin.qq.com/qrcode/" + uuid + 
            "?t=webwx"
            scanQRcode()
            scanTimer.start()
        }
    }

    Image {
        id: qrcodeImage
    }

    Scan {
        id: scanObj
        onError: {
            console.log("ERROR:", strerror)
        }
        onScanedButWaitConfirm: {
            console.log("DEBUG: scaned but waitting for confirm ...")
        }
        onScanedAndConfirmed: {
            console.log("DEBUG: confirmed")
            scanTimer.stop()
            cookieObj.get(redirect_uri)
            contactObj.get()
        }
    }

    function scanQRcode() { scanObj.get(loginWindow.uuid) }

    Timer {
        id: scanTimer
        interval: 16000; running: false; repeat: true
        onTriggered: { scanQRcode() }
    }

    Cookie {
        id: cookieObj
    }

    Contact {
        id: contactObj
    }
}
