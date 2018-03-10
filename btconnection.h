#ifndef BTCONNECTION_H
#define BTCONNECTION_H

#include <QObject>
#include <QSharedPointer>
#include <QEnableSharedFromThis>
#include "btconnectionstate.h"
#include "btconnectionunknown.h"
#include <QDebug>
#include <typeinfo>

class BtConnection : public QObject, public QEnableSharedFromThis<BtConnection>{
    
    Q_OBJECT

public:  
    BtConnection();
    virtual ~BtConnection(){
        qDebug()<< "bconn deleted";
    }
    void changeBtState(QSharedPointer<BtConnectionState>);
    void firstConnection();

private:
    void openBtConnection();
    void closeBtConnection();
    QSharedPointer<BtConnectionState> _btConnectionState;

public slots:
    void btTurnOnOff(const QString&);


signals:
    void btOpened();
    void btClosed();
    void btInvalid();
       
};



#endif // BTCONNECTION_H
