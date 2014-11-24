// Copyright (C) 2014 Leslie Zhai <xiang.zhai@i-soft.com.cn>

#include "httpget.h"

HttpGet::HttpGet(QObject* parent) 
  : QObject(parent)
{
    //qDebug() << "DEBUG:" << __PRETTY_FUNCTION__;
}

HttpGet::~HttpGet() 
{
    //qDebug() << "DEBUG:" << __PRETTY_FUNCTION__;
}

void HttpGet::get(QString url) 
{
    connect(&m_nam, SIGNAL(finished(QNetworkReply*)), 
            this, SLOT(m_finished(QNetworkReply*)));
    connect(&m_nam, &QNetworkAccessManager::sslErrors, 
            this, &HttpGet::m_sslErrors);
    m_nam.get(QNetworkRequest(url));
}

void HttpGet::finished(QNetworkReply*) {}

void HttpGet::m_finished(QNetworkReply* reply) 
{
    this->finished(reply);
    disconnect(&m_nam, SIGNAL(finished(QNetworkReply*)), 
               this, SLOT(m_finished(QNetworkReply*)));
}

void HttpGet::m_sslErrors(QNetworkReply* reply, const QList<QSslError> & errors) 
{
    reply->ignoreSslErrors(errors);
    qDebug() << "DEBUG:" << __PRETTY_FUNCTION__ << reply << errors;
}
