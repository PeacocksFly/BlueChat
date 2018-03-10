#ifndef BTCONNECTIONUNKNOWN_H
#define BTCONNECTIONUNKNOWN_H

#include "btconnection.h"
#include "btconnectionstate.h"
#include "btconnectionclosed.h"
#include "btconnectionopened.h"
#include "btconnectioninvalid.h"
#include <QSharedPointer>
#include <QWeakPointer>
#include <QDebug>


class BtConnectionUnknown : public BtConnectionState{
    
public:
    static QSharedPointer<BtConnectionState> instance();
    void searchBtConnectionState(QSharedPointer<BtConnection>);
    virtual ~BtConnectionUnknown();
    
private:
    BtConnectionUnknown();
    static QWeakPointer<BtConnectionState> _instance;
    
};

#endif // BTCONNECTIONUNKNOWN_H
