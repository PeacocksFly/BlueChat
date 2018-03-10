#ifndef BTCONNECTIONSTATE_H
#define BTCONNECTIONSTATE_H

#include <QBluetoothLocalDevice>
#include <QSharedPointer>
#include <QDebug>

class BtConnection;

class BtConnectionState: public QBluetoothLocalDevice{
       
    Q_OBJECT

public:

     virtual ~BtConnectionState(){qDebug() << "conn state deleted";}
     virtual void close(QSharedPointer<BtConnection>){}
     virtual void open(QSharedPointer<BtConnection>){}
     virtual void searchBtConnectionState(QSharedPointer<BtConnection>){}
     void changeBtState(QSharedPointer<BtConnection>, QSharedPointer<BtConnectionState>);
    
protected:
     BtConnectionState();
    


    
};



#endif // BTCONNECTIONSTATE_H
