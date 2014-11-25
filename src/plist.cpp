// Copyright (C) 2014 Leslie Zhai <xiang.zhai@i-soft.com.cn>

#include <QFile>
#include <QJsonDocument>                                                           
#include <QJsonObject>                                                             
#include <QJsonArray>

#include "plist.h"
#include "userobject.h"

Plist::Plist(HttpPost* parent) 
  : HttpPost(parent)
{
    qDebug() << "DEBUG:" << __PRETTY_FUNCTION__;
}

Plist::~Plist() 
{
    qDebug() << "DEBUG:" << __PRETTY_FUNCTION__;
}

void Plist::post(QString uin, QString sid) 
{
    QString ts = QString::number(time(NULL));
    QString url = "https://wx.qq.com/cgi-bin/mmwebwx-bin/webwxsync?sid=" + sid 
        + "&r=" + ts;
    qDebug() << "DEBUG:" << __PRETTY_FUNCTION__ << url;
    QString json = "{\"BaseRequest\":{\"Uin\":" + uin + ",\"Sid\":\"" + sid + 
        "\"},\"SyncKey\":{\"Count\":4,\"List\":[{\"Key\":1,\"Val\":620916854},"
        "{\"Key\":2,\"Val\":620917961},{\"Key\":3,\"Val\":620917948},"
        "{\"Key\":1000,\"Val\":1388967977}]},\"rr\":" + ts + "}";
    qDebug() << "DEBUG:" << __PRETTY_FUNCTION__ << json;
    HttpPost::post(url, json);
}

QList<QObject*> Plist::modContactList() const { return m_modContactList; }

void Plist::finished(QNetworkReply* reply) 
{
    QString replyStr = QString(reply->readAll());
    // TODO: reply json string is too long to print out for DEBUG
    QFile file("plist.txt");
    if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        QTextStream out(&file);
        out << replyStr;
    }
    QJsonDocument doc = QJsonDocument::fromJson(replyStr.toUtf8());
    QJsonObject obj = doc.object();
    QJsonArray arr = obj["ModContactList"].toArray();
    foreach (const QJsonValue & val, arr) {
        QJsonObject user = val.toObject();
        qDebug() << "DEBUG:" << __PRETTY_FUNCTION__ << user["NickName"].toString();
        m_modContactList.append(new UserObject(user["UserName"].toString(), 
            user["NickName"].toString(), user["HeadImgUrl"].toString()));
    }
    emit modContactListChanged();
}
