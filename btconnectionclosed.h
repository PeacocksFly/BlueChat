#ifndef BTCONNECTIONCLOSED_H
#define BTCONNECTIONCLOSED_H

#include "btconnectionstate.h"
#include <QSharedPointer>
#include <QDebug>
#include "btconnectionopened.h"
#include <QWeakPointer>

class BtConnectionClosed : public BtConnectionState{
    
    Q_OBJECT

public:
    static QSharedPointer<BtConnectionState> instance();
    void open(QSharedPointer<BtConnection>);
    virtual ~BtConnectionClosed(){
        qDebug() << "closed deleted";
    }


private:
    BtConnectionClosed();
    static QWeakPointer<BtConnectionState> _instance;

    
};

#endif // BTCONNECTIONCLOSED_H
