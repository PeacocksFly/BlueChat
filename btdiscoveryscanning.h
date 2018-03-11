#ifndef BTDISCOVERYSCANNING_H
#define BTDISCOVERYSCANNING_H

#include "btdiscoverystate.h"
#include <QSharedPointer>
#include <QDebug>
#include <QWeakPointer>
#include "btdiscoverystopped.h"
#include "btdiscovery.h"
#include <QBluetoothDeviceInfo>

class BtDiscoveryScanning : public BtDiscoveryState{

    Q_OBJECT

public:
    static QSharedPointer<BtDiscoveryState> instance(QSharedPointer<BtDiscovery>);
    void stop(QSharedPointer<BtDiscovery>);
    virtual ~BtDiscoveryScanning(){
          qDebug()<<"scandead";
    }

private:
    BtDiscoveryScanning(QSharedPointer<BtDiscovery>);
    QSharedPointer<BtDiscovery> _btDiscovery;
    static QWeakPointer<BtDiscoveryState> _instance;


public slots:
     void finishedScanning();
     void deviceDiscovered(const QBluetoothDeviceInfo&);

};

#endif // BTDISCOVERYSCANNING_H
