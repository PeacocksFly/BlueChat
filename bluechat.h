#ifndef BLUECHAT_H
#define BLUECHAT_H

#include <QGuiApplication>
#include <QSharedPointer>
#include "btconnection.h"
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QDebug>


class BlueChat : public QGuiApplication{

public:
    BlueChat(int argc, char *argv[]);
    
private:
    QSharedPointer<BtConnection> _btConnection;
    QSharedPointer<QQmlApplicationEngine> _qmlEngine;

};



#endif // BLUECHAT_H
