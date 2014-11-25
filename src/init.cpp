// Copyright (C) 2014 Leslie Zhai <xiang.zhai@i-soft.com.cn>

#include "init.h"

Init::Init(HttpPost* parent) 
  : HttpPost(parent)
{
#if QWX_DEBUG
    qDebug() << "DEBUG:" << __PRETTY_FUNCTION__;
#endif
}

Init::~Init() 
{
#if QWX_DEBUG
    qDebug() << "DEBUG:" << __PRETTY_FUNCTION__;
#endif
}

void Init::post(QString uin, QString sid, QString skey) 
{
    qDebug() << "DEBUG:" << __PRETTY_FUNCTION__ << "why webwx NOT use skey" << skey;
    QString url = "https://wx.qq.com/cgi-bin/mmwebwx-bin/webwxinit?r=" + 
        QString::number(time(NULL));
#if QWX_DEBUG
    qDebug() << "DEBUG:" << __PRETTY_FUNCTION__ << url;
#endif
    QString json = "{\"BaseRequest\":{\"Uin\":\"" + uin + "\",\"Sid\":\"" + 
        sid + "\",\"Skey\":\"\",\"DeviceID\":\"e519062714508114\"}}";
#if QWX_DEBUG
    qDebug() << "DEBUG:" << __PRETTY_FUNCTION__ << json;
#endif
    HttpPost::post(url, json);
}

void Init::finished(QNetworkReply* reply) 
{
    QString replyStr = QString(reply->readAll());
#if QWX_DEBUG
    qDebug() << "DEBUG:" << __PRETTY_FUNCTION__;
    qDebug() << "DEBUG:" << replyStr;
#endif
}
