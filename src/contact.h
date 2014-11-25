// Copyright (C) 2014 Leslie Zhai <xiang.zhai@i-soft.com.cn>

#ifndef CONTACT_H
#define CONTACT_H

#include "httppost.h"

class Contact : public HttpPost 
{
    Q_OBJECT

public:
    Contact(HttpPost* parent = nullptr);
    ~Contact();

    Q_INVOKABLE void post();

Q_SIGNALS:
    void contactChanged();

protected:
    void finished(QNetworkReply* reply);
};

#endif // CONTACT_H
