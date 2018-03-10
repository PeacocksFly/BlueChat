#include "bluechat.h"

BlueChat::BlueChat(int argc, char *argv[])
    :QGuiApplication(argc, argv),
     _btConnection(new BtConnection),
     _qmlEngine(new QQmlApplicationEngine){

      _qmlEngine->load(QUrl(QLatin1String("qrc:/main.qml")));
      _qmlEngine->rootContext()->setContextProperty("btconnection", _btConnection.data());


      _btConnection->firstConnection();
}
