// Copyright (C) 2014 Leslie Zhai <xiang.zhai@i-soft.com.cn>

#if QWX_DEBUG
#include <QFile>
#endif
#include <QJsonDocument>                                                           
#include <QJsonObject>                                                             
#include <QJsonArray>

#include "modcontact.h"
#include "userobject.h"

ModContact::ModContact(HttpPost* parent) 
  : HttpPost(parent)
{
#if QWX_DEBUG
    qDebug() << "DEBUG:" << __PRETTY_FUNCTION__;
#endif
}

ModContact::~ModContact() 
{
#if QWX_DEBUG
    qDebug() << "DEBUG:" << __PRETTY_FUNCTION__;
#endif
}

void ModContact::post(QString uin, QString sid) 
{
    QString ts = QString::number(time(NULL));
    QString url = "https://wx.qq.com/cgi-bin/mmwebwx-bin/webwxsync?sid=" + sid 
        + "&r=" + ts;
#if QWX_DEBUG
    qDebug() << "DEBUG:" << __PRETTY_FUNCTION__ << url;
#endif
    QString json = "{\"BaseRequest\":{\"Uin\":" + uin + ",\"Sid\":\"" + sid + 
        "\"},\"SyncKey\":{\"Count\":4,\"List\":[{\"Key\":1,\"Val\":620916854},"
        "{\"Key\":2,\"Val\":620917961},{\"Key\":3,\"Val\":620917948},"
        "{\"Key\":1000,\"Val\":1388967977}]},\"rr\":" + ts + "}";
#if QWX_DEBUG
    qDebug() << "DEBUG:" << __PRETTY_FUNCTION__ << json;
#endif
    HttpPost::post(url, json);
}

QList<QObject*> ModContact::modContactList() const { return m_modContactList; }

void ModContact::finished(QNetworkReply* reply) 
{
    QString replyStr = QString(reply->readAll());
#if QWX_DEBUG
    QFile file("modcontact.json");
    if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        QTextStream out(&file);
        out << replyStr;
    }
#endif
    QJsonDocument doc = QJsonDocument::fromJson(replyStr.toUtf8());
    QJsonObject obj = doc.object();
    QJsonArray arr = obj["ModContactList"].toArray();
    foreach (const QJsonValue & val, arr) {
        QJsonObject user = val.toObject();
        m_modContactList.append(new UserObject(user["UserName"].toString(), 
            user["NickName"].toString(), user["HeadImgUrl"].toString()));
    }
    emit modContactListChanged();
}
