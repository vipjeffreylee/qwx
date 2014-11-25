// Copyright (C) 2014 Leslie Zhai <xiang.zhai@i-soft.com.cn>

#include <QtQml>
#include <QtQuick/QQuickView>

#include "globaldeclarations.h"
#include "qtsingleapplication/QtSingleApplication"
#include "uuid.h"
#include "scan.h"
#include "cookie.h"
#include "sec_req.h"
#include "init.h"
#include "modcontact.h"
#include "contact.h"
#include "statusnotify.h"
#include "send_msg.h"

int main(int argc, char* argv[]) 
{                                                                        
    QtSingleApplication app(argc, argv);
    if (app.isRunning()) return 0;
    app.setApplicationName(CODE_NAME);
    app.setApplicationVersion(APPLICATION_VERSION);

    qmlRegisterType<UUID>("cn.com.isoft.qwx", 1, 0, "UUID");
    qmlRegisterType<Scan>("cn.com.isoft.qwx", 1, 0, "Scan");
    qmlRegisterType<Cookie>("cn.com.isoft.qwx", 1, 0, "Cookie");
    qmlRegisterType<SecReq>("cn.com.isoft.qwx", 1, 0, "SecReq");
    qmlRegisterType<Init>("cn.com.isoft.qwx", 1, 0, "Init");
    qmlRegisterType<ModContact>("cn.com.isoft.qwx", 1, 0, "ModContact");
    qmlRegisterType<Contact>("cn.com.isoft.qwx", 1, 0, "Contact");
    qmlRegisterType<StatusNotify>("cn.com.isoft.qwx", 1, 0, "StatusNotify");
    qmlRegisterType<SendMsg>("cn.com.isoft.qwx", 1, 0, "SendMsg");

    QQmlApplicationEngine engine(QUrl("qrc:/qml/main.qml")); 
    QObject* topLevel = engine.rootObjects().value(0);
    QQuickWindow* window = qobject_cast<QQuickWindow*>(topLevel); 
    if (!window) {
        qWarning("Error: Your root item has to be a Window.");
        return -1;
    }
    window->show();

    return app.exec();
}
