// Copyright (C) 2014 Leslie Zhai <xiang.zhai@i-soft.com.cn>

#include "init.h"

Init::Init(HttpPost* parent) 
  : HttpPost(parent)
{
    qDebug() << "DEBUG:" << __PRETTY_FUNCTION__;
}

Init::~Init() 
{
    qDebug() << "DEBUG:" << __PRETTY_FUNCTION__;
}

void Init::post(QString uin, QString sid, QString skey) 
{
    qDebug() << "DEBUG:" << __PRETTY_FUNCTION__ << "why not use skey" << skey;
    QString url = "https://wx.qq.com/cgi-bin/mmwebwx-bin/webwxinit?r=" + 
        QString::number(time(NULL));
    QString json = "{\"BaseRequest\":{\"Uin\":\"" + uin + "\",\"Sid\":\"" + 
        sid + "\",\"Skey\":\"\",\"DeviceID\":\"e519062714508114\"}}";
    qDebug() << "DEBUG:" << __PRETTY_FUNCTION__ << json;
    HttpPost::post(url, json);
}

void Init::finished(QNetworkReply*) 
{
    //qDebug() << "DEBUG:" << __PRETTY_FUNCTION__;
    //qDebug() << "DEBUG:" << QString(reply->readAll());
}
