#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include "list_model.h"

int main(int argc, char *argv[])
{
#if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
  QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif
  QGuiApplication app(argc, argv);
  QQmlApplicationEngine engine;

  ListModel list_model_(app.applicationDirPath());
  engine.rootContext()->setContextProperty("list_model_", &list_model_);

  engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
  return app.exec();
}
