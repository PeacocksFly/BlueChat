#include "btdiscovery.h"


BtDiscovery::BtDiscovery():
          _btDiscoveryState(BtDiscoveryStopped::instance())   {

}


void BtDiscovery::scanBtDevices(){

    if(_btDiscoveryState.isNull()) return;

    _btDiscoveryState->scan(sharedFromThis());
}


void BtDiscovery::stopBtDevices(){

    if(_btDiscoveryState.isNull()) return;

    _btDiscoveryState->stop(sharedFromThis());
}


void BtDiscovery::changeBtDiscoveryState(QSharedPointer<BtDiscoveryState> state){

    if(_btDiscoveryState.isNull()) return;

    _btDiscoveryState = state;


    if( typeid(*(_btDiscoveryState.data())) == typeid(BtDiscoveryScanning)){
         emit clearScannedList();
         _discoveredDevices.clear();
         emit btScanning();
    }
    else {
         emit btStopped();
    }

}


void BtDiscovery::appendDiscoveredDevices(const QBluetoothDeviceInfo& newBtDeviceInfo){

    if (std::find(_discoveredDevices.begin(), _discoveredDevices.end(), newBtDeviceInfo) == _discoveredDevices.end()){

        _discoveredDevices.append(newBtDeviceInfo);
        emit newBtScannedDevice(newBtDeviceInfo.name());
    }
}
