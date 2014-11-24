// Copyright (C) 2014 Leslie Zhai <xiang.zhai@i-soft.com.cn>

#ifndef HTTP_POST_H
#define HTTP_POST_H

#include <QObject>
#include <QNetworkReply>
#include <QNetworkAccessManager>

class HttpPost : public QObject 
{
    Q_OBJECT

public:
    HttpPost(QObject* parent = nullptr);
    virtual ~HttpPost();

public:
    void post(QString url, QString str);

protected:
    virtual void finished(QNetworkReply* reply);

private Q_SLOTS:
    void m_finished(QNetworkReply* reply);
    void m_sslErrors(QNetworkReply* reply, const QList<QSslError> & errors);

private:
    QNetworkAccessManager m_nam;
};

#endif // HTTP_POST_H
