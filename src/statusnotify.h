// Copyright (C) 2014 Leslie Zhai <xiang.zhai@i-soft.com.cn>

#ifndef STATUS_NOTIFY_H
#define STATUS_NOTIFY_H

#include "httppost.h"

class StatusNotify : public HttpPost 
{
    Q_OBJECT

public:
    StatusNotify(HttpPost* parent = nullptr);
    ~StatusNotify();

public:
    Q_INVOKABLE void post(QString uin, QString sid, QString skey, QString userName);

protected:
    void finished(QNetworkReply* reply);
};

#endif // STATUS_NOTIFY_H
