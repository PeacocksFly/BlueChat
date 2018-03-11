#include "btconnection.h"


BtConnection::BtConnection():
          _btConnectionState(BtConnectionUnknown::instance())   {
      qDebug()<< "bconn construct";
}


void BtConnection::firstConnection(){

    if(_btConnectionState.isNull()) return;

    _btConnectionState->searchBtConnectionState(sharedFromThis());
}



void BtConnection::btTurnOnOff(const QString& switchState){

    if(switchState == "On")
        openBtConnection();
    else
        closeBtConnection();
}


void BtConnection::openBtConnection(){
    
    if(_btConnectionState.isNull()) return;

    _btConnectionState->open(sharedFromThis());
}


void BtConnection::closeBtConnection(){
    
    if(_btConnectionState.isNull()) return;

    _btConnectionState->close(sharedFromThis());
}


void BtConnection::changeBtConnectionState(QSharedPointer<BtConnectionState> state){

    if(_btConnectionState.isNull()) return;

    _btConnectionState = state;

    if( typeid(*(_btConnectionState.data())) == typeid(BtConnectionOpened)){
        emit btOpened();
    }
    else if (typeid(*(_btConnectionState.data())) == typeid(BtConnectionClosed)){
        emit btClosed();
    }
    else {
        emit btInvalid();
    }


}
