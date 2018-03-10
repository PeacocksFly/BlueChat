#ifndef BTCONNECTIONOPENED_H
#define BTCONNECTIONOPENED_H

#include "btconnectionstate.h"
#include <QSharedPointer>
#include "btconnectionclosed.h"
#include <QWeakPointer>

class BtConnectionOpened : public BtConnectionState{
    
public:
    static QSharedPointer<BtConnectionState> instance();
    void close(QSharedPointer<BtConnection>);

private:
    BtConnectionOpened();
    static QWeakPointer<BtConnectionState> _instance;
    
    
};


#endif // BTCONNECTIONOPENED_H
