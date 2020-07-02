#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include "Src/TaoView.h"
#include "Src/Logger/Logger.h"
//#include "Src/PluginLoader.h"
#include "Src/Trans.h"
#include <QQmlContext>
#include <QQmlEngine>

int main(int argc, char *argv[])
{
    qputenv("QT_IM_MODULE", QByteArray("qtvirtualkeyboard"));

    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);

//    Logger::initLog();
//    Trans trans;
//    trans.loadFolder(app.applicationDirPath() + "/Trans");
//    //PluginLoader loader;
//    TaoView view;

//    view.rootContext()->setContextProperty("view", &view);
//    view.rootContext()->setContextProperty("trans", &trans);
//    //view.rootContext()->setContextProperty("pluginLoader", &loader);

//    view.setSource(QUrl(QStringLiteral("qrc:/Qml/main.qml")));
//    view.moveToScreenCenter();
//    view.show();

//    return app.exec();
}
