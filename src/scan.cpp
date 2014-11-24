// Copyright (C) 2014 Leslie Zhai <xiang.zhai@i-soft.com.cn>

#include "scan.h"

Scan::Scan(HttpsGet* parent) 
  : HttpsGet(parent)
{
    qDebug() << "DEBUG:" << __PRETTY_FUNCTION__;
}

Scan::~Scan() 
{
    qDebug() << "DEBUG:" << __PRETTY_FUNCTION__;
}

void Scan::get(QString uuid) 
{
    QString url = "https://login.weixin.qq.com/cgi-bin/mmwebwx-bin/login?uuid=" 
        + uuid + "&tip=0&_=" + QString::number(time(NULL));
    qDebug() << "DEBUG:" << __PRETTY_FUNCTION__ << url;
    HttpsGet::get(url);
}

void Scan::finished(QNetworkReply* reply) 
{
    QString replyStr(reply->readAll());

    qDebug() << "DEBUG:" << __PRETTY_FUNCTION__;
    qDebug() << "DEBUG:" << replyStr;
    if (replyStr == "window.code=408;") {
        emit error(replyStr);
        return;
    }
    if (replyStr == "window.code=201;") {
        emit scanedButWaitConfirm();
        return;
    }
    if (replyStr.contains("window.code=200;")) {
        emit scanedAndConfirmed();
        return; 
    }
}
