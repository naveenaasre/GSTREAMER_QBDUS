/*
 * This file was generated by qdbusxml2cpp version 0.8
 * Command line was: qdbusxml2cpp -p application_interface application.xml
 *
 * qdbusxml2cpp is Copyright (C) 2020 The Qt Company Ltd.
 *
 * This is an auto-generated file.
 * Do not edit! All changes made to it will be lost.
 */

#ifndef APPLICATION_INTERFACE_H
#define APPLICATION_INTERFACE_H

#include <QtCore/QObject>
#include <QtCore/QByteArray>
#include <QtCore/QList>
#include <QtCore/QMap>
#include <QtCore/QString>
#include <QtCore/QStringList>
#include <QtCore/QVariant>
#include <QtDBus/QtDBus>
class OrgExampleExamplesAppInterfaceInterface: public QDBusAbstractInterface
{
    Q_OBJECT
public:
    static inline const char *staticInterfaceName()
    { return "org.example.Examples.AppInterface"; }

public:
    OrgExampleExamplesAppInterfaceInterface(const QString &service, const QString &path, const QDBusConnection &connection, QObject *parent = nullptr);

    ~OrgExampleExamplesAppInterfaceInterface();

public Q_SLOTS: // METHODS
    inline QDBusPendingReply<> play(QString &song)
    {
        QList<QVariant> argumentList;
        argumentList << QVariant::fromValue(song);
        return asyncCallWithArgumentList(QStringLiteral("play"), argumentList);
    }

    inline QDBusPendingReply<> pause()
    {
        QList<QVariant> argumentList;
        return asyncCallWithArgumentList(QStringLiteral("pause"), argumentList);
    }

    inline QDBusPendingReply<> nextsong(QString &songPath)
    {
        QList<QVariant> argumentList;
        argumentList << QVariant::fromValue(songPath);
        return asyncCallWithArgumentList(QStringLiteral("nextsong"), argumentList);
    }

    inline QDBusPendingReply<> prevsong(QString &songPath)
    {
        QList<QVariant> argumentList;
        argumentList << QVariant::fromValue(songPath);
        return asyncCallWithArgumentList(QStringLiteral("prevsong"), argumentList);
    }
    inline QDBusPendingReply<> stop()
    {
        QList<QVariant> argumentList;
        // argumentList << QVariant::fromValue(songPath);
        return asyncCallWithArgumentList(QStringLiteral("stop"), argumentList);
    }


};

namespace org {
namespace example {
namespace Examples {
typedef ::OrgExampleExamplesAppInterfaceInterface AppInterface;
}
}
}
#endif




















