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
             changeBtState(btConnection, BtConnectionClosed::instance());
         }

         else
             changeBtState(btConnection, BtConnectionOpened::instance());
    }
    else
         changeBtState(btConnection, BtConnectionInvalid::instance());

}





