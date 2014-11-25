// Copyright (C) 2014 Leslie Zhai <xiang.zhai@i-soft.com.cn>

#include "send_msg.h"
#include "globaldeclarations.h"

SendMsg::SendMsg(HttpPost* parent) 
  : HttpPost(parent)
{
#if QWX_DEBUG
    qDebug() << "DEBUG:" << __PRETTY_FUNCTION__;
#endif
}

SendMsg::~SendMsg() 
{
#if QWX_DEBUG
    qDebug() << "DEBUG:" << __PRETTY_FUNCTION__;
#endif
}

void SendMsg::post(QString uin, 
                   QString sid, 
                   QString skey, 
                   QString fromUserName, 
                   QString toUserName, 
                   QString content) 
{
    QString ts = QString::number(time(NULL));
    QString url = WX_SERVER_HOST + WX_CGI_PATH + "webwxsendmsg?sid=" + sid 
        + "&r=" + ts;
#if QWX_DEBUG
    qDebug() << "DEBUG:" << __PRETTY_FUNCTION__ << url;
#endif
    QString json = "{\"BaseRequest\":{\"Uin\":" + uin + ",\"Sid\":\"" + sid 
        + "\",\"Skey\":\"" + skey + "\",\"DeviceID\":\"" + DEVICE_ID 
        + "\"},\"Msg\":{\"FromUserName\":\"" + fromUserName 
        + "\",\"ToUserName\":\"" + toUserName 
        + "\",\"Type\":1,\"Content\":\"" + content + "\",\"ClientMsgId\":" + ts 
        + ",\"LocalID\":" + ts + "}}";
#if QWX_DEBUG
    qDebug() << "DEBUG:" << __PRETTY_FUNCTION__ << json;
#endif
    HttpPost::post(url, json);
}

void SendMsg::finished(QNetworkReply* reply) 
{
    QString replyStr = QString(reply->readAll());
#if QWX_DEBUG
    qDebug() << "DEBUG:" << __PRETTY_FUNCTION__;
    qDebug() << "DEBUG:" << replyStr;
#endif
}
