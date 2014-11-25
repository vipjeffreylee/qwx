// Copyright (C) 2014 Leslie Zhai <xiang.zhai@i-soft.com.cn>

#ifndef PLIST_H
#define PLIST_H

#include "httppost.h"

class Plist : public HttpPost 
{
    Q_OBJECT

    Q_PROPERTY(QList<QObject*> modContactList READ modContactList NOTIFY modContactListChanged)

public:
    Plist(HttpPost* parent = nullptr);
    ~Plist();

    QList<QObject*> modContactList() const;

    Q_INVOKABLE void post(QString uin, QString sid);

Q_SIGNALS:
    void modContactListChanged();

protected:
    void finished(QNetworkReply* reply);

private:
    QList<QObject*> m_modContactList;
};

#endif // PLIST_H
