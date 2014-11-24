// Copyright (C) 2014 Leslie Zhai <xiang.zhai@i-soft.com.cn>

#include "cookie.h"
#include "globaldeclarations.h"

Cookie::Cookie(HttpsGet* parent) 
  : HttpsGet(parent)
{
    qDebug() << "DEBUG:" << __PRETTY_FUNCTION__;
}

Cookie::~Cookie() 
{
    qDebug() << "DEBUG:" << __PRETTY_FUNCTION__;
}

void Cookie::get(QString redirect_uri) 
{
    QString url = redirect_uri + "&fun=new";
    qDebug() << "DEBUG:" << __PRETTY_FUNCTION__ << url;
    HttpsGet::get(url);
}

void Cookie::finished(QNetworkReply* reply) 
{
    QString replyStr(reply->readAll());

    qDebug() << "DEBUG:" << __PRETTY_FUNCTION__;
    qDebug() << "DEBUG:" << replyStr;
}

