// Copyright (C) 2014 Leslie Zhai <xiang.zhai@i-soft.com.cn>

#include <QDomDocument>
#include <QDomElement>

#include "cookie.h"

Cookie::Cookie(HttpGet* parent) 
  : HttpGet(parent)
{
#if QWX_DEBUG
    qDebug() << "DEBUG:" << __PRETTY_FUNCTION__;
#endif
}

Cookie::~Cookie() 
{
#if QWX_DEBUG
    qDebug() << "DEBUG:" << __PRETTY_FUNCTION__;
#endif
}

void Cookie::get(QString redirect_uri) 
{
    QString url = redirect_uri + "&fun=new";
#if QWX_DEBUG
    qDebug() << "DEBUG:" << __PRETTY_FUNCTION__ << url;
#endif
    HttpGet::get(url);
}

void Cookie::finished(QNetworkReply* reply) 
{
    QString replyStr(reply->readAll());
    QDomDocument doc;

#if QWX_DEBUG
    qDebug() << "DEBUG:" << __PRETTY_FUNCTION__;
    qDebug() << "DEBUG:" << replyStr;
#endif
    // FIXME: my mother`s (new registed) accout is not able to get cookie!? 
    // but my wife and mine are OK, weixin changed web API?
    if (doc.setContent(replyStr) == false) {
        qWarning() << "ERROR:" << __PRETTY_FUNCTION__ << "fail to parse";
        return;
    }
    QDomElement root = doc.documentElement();
    QDomElement message = root.firstChildElement("message");
    QDomElement skey = root.firstChildElement("skey");
    QDomElement sid = root.firstChildElement("wxsid");
    QDomElement uin = root.firstChildElement("wxuin");
    QDomElement ticket = root.firstChildElement("pass_ticket");
#if QWX_DEBUG
    qDebug() << "DEBUG:" << __PRETTY_FUNCTION__ << message.text() << 
        skey.text() << sid.text() << uin.text() << ticket.text();
#endif
    emit infoChanged(skey.text(), sid.text(), uin.text(), ticket.text());
}

