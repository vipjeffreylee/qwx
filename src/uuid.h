// Copyright (C) 2014 Leslie Zhai <xiang.zhai@i-soft.com.cn>

#ifndef UUID_H
#define UUID_H

#include "httpsget.h"

class UUID : public HttpsGet 
{
    Q_OBJECT

public:
    UUID(HttpsGet* parent = nullptr);
    ~UUID();

    Q_INVOKABLE void get();

Q_SIGNALS:
    void uuidChanged(QString uuid);

protected:
    void finished(QNetworkReply* reply);
};

#endif // UUID_H
