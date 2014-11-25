// Copyright (C) 2014 Leslie Zhai <xiang.zhai@i-soft.com.cn>

#include "sec_req.h"

SecReq::SecReq(HttpPost* parent) 
  : HttpPost(parent)
{
#if QWX_DEBUG
    qDebug() << "DEBUG:" << __PRETTY_FUNCTION__;
#endif
}

SecReq::~SecReq() 
{
#if QWX_DEBUG
    qDebug() << "DEBUG:" << __PRETTY_FUNCTION__;
#endif
}

void SecReq::post(QString uuid) 
{
    QString url = "https://wx.qq.com/cgi-bin/mmwebwx-bin/webwxstatreport"
        "?type=1&r=" + QString::number(time(NULL));
#if QWX_DEBUG
    qDebug() << "DEBUG:" << __PRETTY_FUNCTION__ << url;
#endif
    QString json = "{\"BaseRequest\":{\"Uin\":0,\"Sid\":0},\"Count\":1,"
        "\"List\":[{\"Type\":1,\"Text\":\"/cgi-bin/mmwebwx-bin/login, "
        "Second Request Success, uuid: " + uuid + ", time: 190765ms\"}]}";
#if QWX_DEBUG
    qDebug() << "DEBUG:" << __PRETTY_FUNCTION__ << json;
#endif
    HttpPost::post(url, json);
}

void SecReq::finished(QNetworkReply* reply) 
{
    QString replyStr = QString(reply->readAll());
#if QWX_DEBUG
    qDebug() << "DEBUG:" << __PRETTY_FUNCTION__;
    qDebug() << "DEBUG:" << replyStr;
#endif
}
