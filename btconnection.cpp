#include "btconnection.h"


BtConnection::BtConnection():
          _btConnectionState(BtConnectionUnknown::instance())   {
      qDebug()<< "bconn construct";
}


void BtConnection::firstConnection(){

    _btConnectionState->searchBtConnectionState(sharedFromThis());
}



void BtConnection::btTurnOnOff(const QString& switchState){

    if(switchState == "On")
        openBtConnection();
    else
        closeBtConnection();
}

void BtConnection::openBtConnection(){
    
    _btConnectionState->open(sharedFromThis());
}


void BtConnection::closeBtConnection(){
    
    _btConnectionState->close(sharedFromThis());
}


void BtConnection::changeBtState(QSharedPointer<BtConnectionState> state){

    _btConnectionState.reset();
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
