// Copyright (C) 2014 Leslie Zhai <xiang.zhai@i-soft.com.cn>

#ifndef COOKIE_H
#define COOKIE_H

#include "httpsget.h"

class Cookie : public HttpsGet 
{
    Q_OBJECT

public:
    Cookie(HttpsGet* parent = nullptr);
    ~Cookie();

    Q_INVOKABLE void get(QString redirect_uri);

protected:
    void finished(QNetworkReply* reply);
};

#endif // COOKIE_H
