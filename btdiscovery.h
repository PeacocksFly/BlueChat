#ifndef BTDISCOVERY_H
#define BTDISCOVERY_H

#include <QBluetoothDeviceInfo>
#include <QEnableSharedFromThis>
#include "btdiscoverystate.h"
#include "btdiscoveryscanning.h"
#include "btdiscoverystopped.h"
#include <algorithm>

class BtDiscovery : public QObject, public QEnableSharedFromThis<BtDiscovery>{

    Q_OBJECT

public:
    BtDiscovery();
    virtual ~BtDiscovery(){
        qDebug()<< "bdisc deleted";
    }
    void changeBtDiscoveryState(QSharedPointer<BtDiscoveryState>);
    void appendDiscoveredDevices(const QBluetoothDeviceInfo&);

private:
    QSharedPointer<BtDiscoveryState> _btDiscoveryState;
    QList<QBluetoothDeviceInfo> _discoveredDevices;

public slots:
    void scanBtDevices();
    void stopBtDevices();

signals:
    void btScanning();
    void btStopped();
    void clearScannedList();
    void newBtScannedDevice(QString name);

};


#endif // BTDISCOVERY_H
