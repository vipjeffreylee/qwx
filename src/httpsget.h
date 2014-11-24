// Copyright (C) 2014 Leslie Zhai <xiang.zhai@i-soft.com.cn>

#ifndef HTTPS_GET_H
#define HTTPS_GET_H

#include <QObject>
#include <QNetworkReply>
#include <QNetworkAccessManager>

class HttpsGet : public QObject 
{
    Q_OBJECT

public:
    HttpsGet(QObject* parent = nullptr);
    virtual ~HttpsGet();

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

#endif // HTTPS_GET_H
