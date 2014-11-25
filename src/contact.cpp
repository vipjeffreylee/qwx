// Copyright (C) 2014 Leslie Zhai <xiang.zhai@i-soft.com.cn>

#include "contact.h"
#include "globaldeclarations.h"

Contact::Contact(HttpPost* parent) 
  : HttpPost(parent)
{
#if QWX_DEBUG
    qDebug() << "DEBUG:" << __PRETTY_FUNCTION__;
#endif
}

Contact::~Contact() 
{
#if QWX_DEBUG
    qDebug() << "DEBUG:" << __PRETTY_FUNCTION__;
#endif
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
#if QWX_DEBUG
    qDebug() << "DEBUG:" << __PRETTY_FUNCTION__;
    qDebug() << "DEBUG:" << replyStr;
#endif
}
