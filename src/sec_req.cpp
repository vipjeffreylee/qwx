// Copyright (C) 2014 Leslie Zhai <xiang.zhai@i-soft.com.cn>

#include "sec_req.h"
#include "globaldeclarations.h"

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
    QString url = WX_SERVER_HOST + WX_CGI_PATH + "webwxstatreport?type=1&r=" + 
        QString::number(time(NULL));
#if QWX_DEBUG
    qDebug() << "DEBUG:" << __PRETTY_FUNCTION__ << url;
#endif
    QString json = "{\"BaseRequest\":{\"Uin\":0,\"Sid\":0},\"Count\":1,"
        "\"List\":[{\"Type\":1,\"Text\":\"" + WX_CGI_PATH + "login, "
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
