// Copyright (C) 2014 Leslie Zhai <xiang.zhai@i-soft.com.cn>

#ifndef HTTP_GET_H
#define HTTP_GET_H

#include <QObject>
#include <QNetworkReply>
#include <QNetworkAccessManager>

class HttpGet : public QObject 
{
    Q_OBJECT

public:
    HttpGet(QObject* parent = nullptr);
    virtual ~HttpGet();

public:
    void get(QString url);

protected:
    virtual void finished(QNetworkReply* reply);

private Q_SLOTS:
    void m_finished(QNetworkReply* reply);
    void m_sslErrors(QNetworkReply* reply, const QList<QSslError> & errors);

private:
    QNetworkAccessManager m_nam;
};

#endif // HTTP_GET_H
