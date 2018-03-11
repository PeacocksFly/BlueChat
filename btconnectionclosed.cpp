#include "btconnectionclosed.h"


QWeakPointer<BtConnectionState> BtConnectionClosed::_instance;

BtConnectionClosed::BtConnectionClosed()
      :BtConnectionState(){

    qDebug()<<"closed construct";
}



QSharedPointer<BtConnectionState> BtConnectionClosed::instance(){

    QSharedPointer<BtConnectionState> temp = _instance.lock();
    if(temp.isNull()){
        temp.reset(new BtConnectionClosed);
        _instance = temp;
    }
    return temp;
}



void BtConnectionClosed::open(QSharedPointer<BtConnection> btConnection){

     powerOn();

     while(hostMode() == QBluetoothLocalDevice::HostPoweredOff);

     changeBtConnectionState(btConnection, BtConnectionOpened::instance());
}
