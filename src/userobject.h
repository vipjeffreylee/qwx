// Copyright (C) 2014 Leslie Zhai <xiang.zhai@i-soft.com.cn>

#ifndef USER_OBJECT_H
#define USER_OBJECT_H

#include <QObject>
#include <QString>

class UserObject : public QObject 
{
    Q_OBJECT

    Q_PROPERTY(QString UserName READ UserName WRITE setUserName NOTIFY UserNameChanged)
    Q_PROPERTY(QString NickName READ NickName WRITE setNickName NOTIFY NickNameChanged)
    Q_PROPERTY(QString HeadImgUrl READ HeadImgUrl WRITE setHeadImgUrl NOTIFY HeadImgUrlChanged)

public:
    UserObject(const QString UserName, 
               const QString NickName, 
               const QString HeadImgUrl, 
               QObject* parent = nullptr) 
      : QObject(parent) 
    {
        m_UserName = UserName; m_NickName = NickName; m_HeadImgUrl = HeadImgUrl;
    }

    QString UserName() const { return m_UserName; }
    void setUserName(const QString & UserName) 
    { m_UserName = UserName; emit UserNameChanged(); }

    QString NickName() const { return m_NickName; }
    void setNickName(const QString & NickName) 
    { m_NickName = NickName; emit NickNameChanged(); }

    QString HeadImgUrl() const { return m_HeadImgUrl; }
    void setHeadImgUrl(const QString & HeadImgUrl) 
    { m_HeadImgUrl = HeadImgUrl; emit HeadImgUrlChanged(); }

Q_SIGNALS:
    void UserNameChanged();
    void NickNameChanged();
    void HeadImgUrlChanged();

private:
    QString m_UserName;
    QString m_NickName;
    QString m_HeadImgUrl;
};

#endif // USER_OBJECT_H
