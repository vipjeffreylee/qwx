// Copyright (C) 2014 Leslie Zhai <xiang.zhai@i-soft.com.cn>

#ifndef CONTACT_H
#define CONTACT_H

#include "httpsget.h"

class Contact : public HttpsGet 
{
    Q_OBJECT

public:
    Contact(HttpsGet* parent = nullptr);
    ~Contact();

    Q_INVOKABLE void get();

Q_SIGNALS:
    void contactChanged();

protected:
    void finished(QNetworkReply* reply);
};

#endif // CONTACT_H
