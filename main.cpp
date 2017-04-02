#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QtQml/QQmlContext>
#include <QObject>

#include "GameLogic.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);
    QQmlApplicationEngine engine;

    GameLogic game;

    engine.rootContext()->setContextProperty("game", &game);

    engine.load(QUrl(QStringLiteral("qrc:/StartingWindow.qml")));
    return app.exec();
}
