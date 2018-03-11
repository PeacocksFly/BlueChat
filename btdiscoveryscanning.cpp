#include "btdiscoveryscanning.h"



QWeakPointer<BtDiscoveryState> BtDiscoveryScanning::_instance;

BtDiscoveryScanning::BtDiscoveryScanning(QSharedPointer<BtDiscovery> btDiscovery)
      :BtDiscoveryState(),
       _btDiscovery(btDiscovery){

    qDebug()<<"scanalive";
    connect(this, SIGNAL(deviceDiscovered(QBluetoothDeviceInfo)),
         this, SLOT(deviceDiscovered(QBluetoothDeviceInfo)));

    connect(this, SIGNAL(finished()), this, SLOT(finishedScanning()));
}



QSharedPointer<BtDiscoveryState> BtDiscoveryScanning::instance(QSharedPointer<BtDiscovery> btDiscovery){

    QSharedPointer<BtDiscoveryState> temp = _instance.lock();
    if(temp.isNull()){
        temp.reset(new BtDiscoveryScanning(btDiscovery));
        _instance = temp;
    }
    return temp;
}


void BtDiscoveryScanning::finishedScanning(){

      changeBtDiscoveryState(_btDiscovery, BtDiscoveryStopped::instance());
}

void BtDiscoveryScanning::deviceDiscovered(const QBluetoothDeviceInfo &device){

    qDebug()<<"devicediscovered";
    if (device.isValid() && (!device.name().isEmpty()) && (!device.address().toString().isEmpty()))
        _btDiscovery->appendDiscoveredDevices(device);
}


void BtDiscoveryScanning::stop(QSharedPointer<BtDiscovery> btDiscovery){

    if(!isActive()){
        changeBtDiscoveryState(btDiscovery, BtDiscoveryStopped::instance());
        return;
    }

    QBluetoothDeviceDiscoveryAgent::stop();

    while (isActive()) ;

    changeBtDiscoveryState(btDiscovery, BtDiscoveryStopped::instance());

}
