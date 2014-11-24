// Copyright (C) 2014 Leslie Zhai <xiang.zhai@i-soft.com.cn>

#ifndef SEC_REQ_H
#define SEC_REQ_H

#include "httppost.h"

class SecReq : public HttpPost 
{
    Q_OBJECT

public:
    SecReq(HttpPost* parent = nullptr);
    ~SecReq();

public:
    Q_INVOKABLE void post(QString uuid);

protected:
    void finished(QNetworkReply*);
};

#endif // SEC_REQ_H
