// Copyright (C) 2014 Leslie Zhai <xiang.zhai@i-soft.com.cn>

#include "sec_req.h"

SecReq::SecReq(HttpPost* parent) 
  : HttpPost(parent)
{
    qDebug() << "DEBUG:" << __PRETTY_FUNCTION__;
}

SecReq::~SecReq() 
{
    qDebug() << "DEBUG:" << __PRETTY_FUNCTION__;
}

void SecReq::post(QString uuid) 
{
    QString url = "https://wx.qq.com/cgi-bin/mmwebwx-bin/webwxstatreport"
        "?type=1&r=" + QString::number(time(NULL));
    QString json = "{\"BaseRequest\":{\"Uin\":0,\"Sid\":0},\"Count\":1,"
        "\"List\":[{\"Type\":1,\"Text\":\"/cgi-bin/mmwebwx-bin/login, "
        "Second Request Success, uuid: " + uuid + ", time: 190765ms\"}]}";
    qDebug() << "DEBUG:" << __PRETTY_FUNCTION__ << json;
    HttpPost::post(url, json);
}

void SecReq::finished(QNetworkReply*) 
{
    //qDebug() << "DEBUG:" << __PRETTY_FUNCTION__;
    //qDebug() << "DEBUG:" << QString(reply->readAll());
}
