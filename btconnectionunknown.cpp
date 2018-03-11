#include "btconnectionunknown.h"


QWeakPointer<BtConnectionState> BtConnectionUnknown::_instance;

BtConnectionUnknown::BtConnectionUnknown()
      :BtConnectionState(){

     qDebug() << "unknown constructed";
}


BtConnectionUnknown::~BtConnectionUnknown(){

            qDebug() << "unknown deleted";
}



QSharedPointer<BtConnectionState> BtConnectionUnknown::instance(){

    QSharedPointer<BtConnectionState> temp = _instance.lock();
    if(temp.isNull()){
        temp.reset(new BtConnectionUnknown);
        _instance = temp;
    }
    return temp;
}


void BtConnectionUnknown::searchBtConnectionState(QSharedPointer<BtConnection> btConnection){


    if(isValid()){
         if(hostMode() == QBluetoothLocalDevice::HostPoweredOff){
             changeBtConnectionState(btConnection, BtConnectionClosed::instance());
         }

         else
             changeBtConnectionState(btConnection, BtConnectionOpened::instance());
    }
    else
         changeBtConnectionState(btConnection, BtConnectionInvalid::instance());

}





