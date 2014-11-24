// Copyright (C) 2014 Leslie Zhai <xiang.zhai@i-soft.com.cn>

#include "uuid.h"
#include "globaldeclarations.h"

UUID::UUID(HttpsGet* parent) 
  : HttpsGet(parent)
{
    qDebug() << "DEBUG:" << __PRETTY_FUNCTION__;
    get();
}

UUID::~UUID() 
{
    qDebug() << "DEBUG:" << __PRETTY_FUNCTION__;
}

void UUID::get() 
{
    QString url = "https://login.weixin.qq.com/jslogin?appid="         
        "wx782c26e4c19acffb&redirect_uri=https://wx.qq.com/cgi-bin/mmwebwx-bin"    
        "/webwxnewloginpage&fun=new&lang=zh_CN&_=" + QString::number(time(NULL));

    HttpsGet::get(url);
}

void UUID::finished(QNetworkReply* reply) 
{
    QString replyStr(reply->readAll());
    QString uuid = "";

    qDebug() << "DEBUG:" << __PRETTY_FUNCTION__;
    qDebug() << "DEBUG:" << replyStr;
    QStringList list = replyStr.split(" = ");
    qDebug() << "DEBUG:" << __PRETTY_FUNCTION__ << list.size();
    foreach (const QString str, list) { 
        qDebug() << "DEBUG:" << __PRETTY_FUNCTION__ << str;
    }
    if (list.size() == 3) {
        // TODO: list[2] often is like "9910cd52f8874e"; so it needs to remove 
        // the first one character " and last two ";
        uuid = list[2].mid(1, list[2].size() - 3);
        emit uuidChanged(uuid);
    }
}
