// Copyright (C) 2014 Leslie Zhai <xiang.zhai@i-soft.com.cn>

#ifndef UUID_H
#define UUID_H

#include "httpget.h"

class UUID : public HttpGet 
{
    Q_OBJECT

public:
    UUID(HttpGet* parent = nullptr);
    ~UUID();

    Q_INVOKABLE void get();

Q_SIGNALS:
    void error();
    void uuidChanged(QString uuid);

protected:
    void finished(QNetworkReply* reply);
};

#endif // UUID_H
