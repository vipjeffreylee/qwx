// Copyright (C) 2014 Leslie Zhai <xiang.zhai@i-soft.com.cn>

#ifndef SCAN_H
#define SCAN_H

#include "httpsget.h"

class Scan : public HttpsGet 
{
    Q_OBJECT

public:
    Scan(HttpsGet* parent = nullptr);
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
