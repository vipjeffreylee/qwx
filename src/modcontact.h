// Copyright (C) 2014 Leslie Zhai <xiang.zhai@i-soft.com.cn>

#ifndef MOD_CONTACT_H
#define MOD_CONTACT_H

#include "httppost.h"

class ModContact : public HttpPost 
{
    Q_OBJECT

    Q_PROPERTY(QList<QObject*> modContactList READ modContactList NOTIFY modContactListChanged)

public:
    ModContact(HttpPost* parent = nullptr);
    ~ModContact();

    QList<QObject*> modContactList() const;

    Q_INVOKABLE void post(QString uin, QString sid);

Q_SIGNALS:
    void error();
    void modContactListChanged();

protected:
    void finished(QNetworkReply* reply);

private:
    QList<QObject*> m_modContactList;
};

#endif // MOD_CONTACT_H
