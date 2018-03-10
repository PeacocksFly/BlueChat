#include "btconnectionopened.h"


QWeakPointer<BtConnectionState> BtConnectionOpened::_instance;

BtConnectionOpened::BtConnectionOpened()
      :BtConnectionState(){
    qDebug()<<"opened construct";
}



QSharedPointer<BtConnectionState> BtConnectionOpened::instance(){

    QSharedPointer<BtConnectionState> temp = _instance.lock();
    if(temp.isNull()){
        temp.reset(new BtConnectionOpened);
        _instance = temp;
    }
    return temp;

}



void BtConnectionOpened::close(QSharedPointer<BtConnection> btConnection){

      setHostMode(QBluetoothLocalDevice::HostPoweredOff);

      while(hostMode() != QBluetoothLocalDevice::HostPoweredOff);

      changeBtState(btConnection, BtConnectionClosed::instance());
}
