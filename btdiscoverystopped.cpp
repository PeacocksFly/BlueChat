#include "btdiscoverystopped.h"


QWeakPointer<BtDiscoveryState> BtDiscoveryStopped::_instance;

BtDiscoveryStopped::BtDiscoveryStopped()
      :BtDiscoveryState(){
         qDebug()<<"stopalive";
}



QSharedPointer<BtDiscoveryState> BtDiscoveryStopped::instance(){

   QSharedPointer<BtDiscoveryState> temp = _instance.lock();
   if(temp.isNull()){
          temp.reset(new BtDiscoveryStopped);
          _instance = temp;
    }
    return temp;
}



void BtDiscoveryStopped::scan(QSharedPointer<BtDiscovery> btDiscovery){

    if(isActive()){
        changeBtDiscoveryState(btDiscovery, BtDiscoveryScanning::instance(btDiscovery));
        return;
    }

     QSharedPointer<BtDiscoveryState> instanceBtDiscoveryScanning = BtDiscoveryScanning::instance(btDiscovery);

     instanceBtDiscoveryScanning->start();

     while (!instanceBtDiscoveryScanning->isActive()) ;

     changeBtDiscoveryState(btDiscovery, BtDiscoveryScanning::instance(btDiscovery));
}
