#ifndef BTDISCOVERYSTOPPED_H
#define BTDISCOVERYSTOPPED_H

#include "btdiscoverystate.h"
#include "btdiscoveryscanning.h"
#include <QSharedPointer>
#include <QDebug>
#include <QWeakPointer>

class BtDiscoveryStopped : public BtDiscoveryState{

    Q_OBJECT

public:
    static QSharedPointer<BtDiscoveryState> instance();
    void scan(QSharedPointer<BtDiscovery>);
    virtual ~BtDiscoveryStopped(){
         qDebug()<<"stopdead";
    }


private:
    BtDiscoveryStopped();
    static QWeakPointer<BtDiscoveryState> _instance;


};

#endif // BTDISCOVERYSTOPPED_H
