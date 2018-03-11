#include "bluechat.h"

BlueChat::BlueChat(int argc, char *argv[])
    :QGuiApplication(argc, argv),
     _btConnection(new BtConnection),
     _qmlEngine(new QQmlApplicationEngine),
     _btDiscovery(new BtDiscovery){

           _qmlEngine->load(QUrl(QLatin1String("qrc:/main.qml")));
           _qmlEngine->rootContext()->setContextProperty("btconnection", _btConnection.data());
           _qmlEngine->rootContext()->setContextProperty("btdiscovery", _btDiscovery.data());
           _btConnection->firstConnection();
}
