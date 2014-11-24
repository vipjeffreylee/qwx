// Copyright (C) 2014 Leslie Zhai <xiang.zhai@i-soft.com.cn>

#include "httpsget.h"

HttpsGet::HttpsGet(QObject* parent) 
  : QObject(parent)
{
    qDebug() << "DEBUG:" << __PRETTY_FUNCTION__;
}

HttpsGet::~HttpsGet() 
{
    qDebug() << "DEBUG:" << __PRETTY_FUNCTION__;
}

void HttpsGet::get(QString url) 
{
    connect(&m_nam, SIGNAL(finished(QNetworkReply*)), 
            this, SLOT(m_finished(QNetworkReply*)));
    connect(&m_nam, &QNetworkAccessManager::sslErrors, 
            this, &HttpsGet::m_sslErrors);
    qDebug() << "DEBUG:" << __PRETTY_FUNCTION__ << url;
    m_nam.get(QNetworkRequest(url));
}

void HttpsGet::finished(QNetworkReply*) {}

void HttpsGet::m_finished(QNetworkReply* reply) 
{
    this->finished(reply);
    disconnect(&m_nam, SIGNAL(finished(QNetworkReply*)), 
               this, SLOT(m_finished(QNetworkReply*)));
}

void HttpsGet::m_sslErrors(QNetworkReply* reply, const QList<QSslError> & errors) 
{
    reply->ignoreSslErrors(errors);
    qDebug() << "DEBUG:" << __PRETTY_FUNCTION__ << reply << errors;
}
