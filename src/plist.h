// Copyright (C) 2014 Leslie Zhai <xiang.zhai@i-soft.com.cn>

#ifndef PLIST_H
#define PLIST_H

#include "httppost.h"

class Plist : public HttpPost 
{
    Q_OBJECT

public:
    Plist(HttpPost* parent = nullptr);
    ~Plist();

public:
    Q_INVOKABLE void post(QString uin, QString sid);

protected:
    void finished(QNetworkReply* reply);
};

#endif // PLIST_H
