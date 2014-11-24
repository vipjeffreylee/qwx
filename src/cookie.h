// Copyright (C) 2014 Leslie Zhai <xiang.zhai@i-soft.com.cn>

#ifndef COOKIE_H
#define COOKIE_H

#include "httpget.h"

class Cookie : public HttpGet 
{
    Q_OBJECT

public:
    Cookie(HttpGet* parent = nullptr);
    ~Cookie();

    Q_INVOKABLE void get(QString redirect_uri);

Q_SIGNALS:
    void infoChanged(QString skey, QString sid, QString uin, QString ticket);

protected:
    void finished(QNetworkReply* reply);
};

#endif // COOKIE_H
