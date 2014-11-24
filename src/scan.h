// Copyright (C) 2014 Leslie Zhai <xiang.zhai@i-soft.com.cn>

#ifndef SCAN_H
#define SCAN_H

#include "httpget.h"

class Scan : public HttpGet 
{
    Q_OBJECT

public:
    Scan(HttpGet* parent = nullptr);
    ~Scan();

    Q_INVOKABLE void get(QString uuid);

Q_SIGNALS:
    void error(QString strerror);
    void scanedButWaitConfirm();
    void scanedAndConfirmed(QString redirect_uri);

protected:
    void finished(QNetworkReply* reply);
};

#endif // SCAN_H
