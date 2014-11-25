// Copyright (C) 2014 Leslie Zhai <xiang.zhai@i-soft.com.cn>

#include "statusnotify.h"
#include "globaldeclarations.h"

StatusNotify::StatusNotify(HttpPost* parent) 
  : HttpPost(parent)
{
#if QWX_DEBUG
    qDebug() << "DEBUG:" << __PRETTY_FUNCTION__;
#endif
}

StatusNotify::~StatusNotify() 
{
#if QWX_DEBUG
    qDebug() << "DEBUG:" << __PRETTY_FUNCTION__;
#endif
}

void StatusNotify::post(QString uin, QString sid, QString skey, QString userName) 
{
    QString ts = QString::number(time(NULL));
    qDebug() << "DEBUG:" << __PRETTY_FUNCTION__ << "why webwx NOT use skey" << skey;
    QString url = WX_SERVER_HOST + WX_CGI_PATH + "webwxstatusnotify?r=" + ts;
#if QWX_DEBUG
    qDebug() << "DEBUG:" << __PRETTY_FUNCTION__ << url;
#endif
    QString json = "{\"BaseRequest\":{\"Uin\":" + uin + ",\"Sid\":\"" + sid 
        + "\",\"Skey\":\"\",\"DeviceID\":\"" + DEVICE_ID + "\"},\"Code\":3,"
        "\"FromUserName\":\"" + userName + "\",\"ToUserName\":\"" + userName 
        + "\",\"ClientMsgId\":\"" + ts + "\"}";
#if QWX_DEBUG
    qDebug() << "DEBUG:" << __PRETTY_FUNCTION__ << json;
#endif
    HttpPost::post(url, json);
}

void StatusNotify::finished(QNetworkReply* reply) 
{
    QString replyStr = QString(reply->readAll());
#if QWX_DEBUG
    qDebug() << "DEBUG:" << __PRETTY_FUNCTION__;
    qDebug() << "DEBUG:" << replyStr;
#endif
}
