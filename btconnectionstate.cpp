#include "bluechat.h"
#include "btconnectionstate.h"

BtConnectionState::BtConnectionState():
    QBluetoothLocalDevice(){
       qDebug()<<"state construct";
}

void BtConnectionState::changeBtState(QSharedPointer<BtConnection> c, QSharedPointer<BtConnectionState> s){

      c->changeBtState(s);

}
