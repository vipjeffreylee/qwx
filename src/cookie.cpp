// Copyright (C) 2014 Leslie Zhai <xiang.zhai@i-soft.com.cn>

#include <QDomDocument>
#include <QDomElement>

#include "cookie.h"
#include "globaldeclarations.h"

Cookie::Cookie(HttpGet* parent) 
  : HttpGet(parent)
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
    HttpGet::get(url);
}

void Cookie::finished(QNetworkReply* reply) 
{
    QString replyStr(reply->readAll());
    QDomDocument doc;

    qDebug() << "DEBUG:" << __PRETTY_FUNCTION__;
    qDebug() << "DEBUG:" << replyStr;
    // FIXME: my mother`s weixin accout is not able to get cookie!? but my wife
    // and I are OK ;)
    if (doc.setContent(replyStr) == false) {
        qWarning() << "ERROR:" << __PRETTY_FUNCTION__ << "fail to parse";
        return;
    }
    QDomElement root = doc.documentElement();
    QDomElement message = root.firstChildElement("message");
    //qDebug() << "DEBUG:" << __PRETTY_FUNCTION__ << message.text();
    QDomElement skey = root.firstChildElement("skey");
    //qDebug() << "DEBUG:" << __PRETTY_FUNCTION__ << skey.text();
    QDomElement sid = root.firstChildElement("wxsid");
    //qDebug() << "DEBUG:" << __PRETTY_FUNCTION__ << sid.text();
    QDomElement uin = root.firstChildElement("wxuin");
    //qDebug() << "DEBUG:" << __PRETTY_FUNCTION__ << uin.text();
    QDomElement ticket = root.firstChildElement("pass_ticket");
    //qDebug() << "DEBUG:" << __PRETTY_FUNCTION__ << ticket.text();
    emit infoChanged(skey.text(), sid.text(), uin.text(), ticket.text());
}

