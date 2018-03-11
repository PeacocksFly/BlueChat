#include "bluechat.h"
#include "btconnectionstate.h"

BtConnectionState::BtConnectionState():
    QBluetoothLocalDevice(){
       qDebug()<<"state construct";
}

void BtConnectionState::changeBtConnectionState(QSharedPointer<BtConnection> c, QSharedPointer<BtConnectionState> s){

      c->changeBtConnectionState(s);

}
