// Copyright (C) 2014 Leslie Zhai <xiang.zhai@i-soft.com.cn>

#include "contact.h"
#include "globaldeclarations.h"

Contact::Contact(HttpPost* parent) 
  : HttpPost(parent)
{
    qDebug() << "DEBUG:" << __PRETTY_FUNCTION__;
}

Contact::~Contact() 
{
    qDebug() << "DEBUG:" << __PRETTY_FUNCTION__;
}

void Contact::post() 
{
    QString url = "https://wx.qq.com/cgi-bin/mmwebwx-bin/webwxgetcontact?r=" + 
        QString::number(time(NULL));
    QString json = "{}";
    HttpPost::post(url, json);
}

void Contact::finished(QNetworkReply* reply) 
{
    QString replyStr(reply->readAll());
    qDebug() << "DEBUG:" << __PRETTY_FUNCTION__;
    qDebug() << "DEBUG:" << replyStr;
}
