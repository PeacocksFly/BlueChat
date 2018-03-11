#ifndef BLUECHAT_H
#define BLUECHAT_H

#include <QGuiApplication>
#include <QSharedPointer>
#include "btconnection.h"
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QDebug>
#include "btdiscovery.h"


class BlueChat : public QGuiApplication{

public:
    BlueChat(int argc, char *argv[]);
    
private:
    QSharedPointer<BtConnection> _btConnection;
    QSharedPointer<QQmlApplicationEngine> _qmlEngine;
    QSharedPointer<BtDiscovery> _btDiscovery;

};



#endif // BLUECHAT_H
