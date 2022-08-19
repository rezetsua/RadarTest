#ifndef LISTMODEL_H
#define LISTMODEL_H

#include <QObject>
#include <QAbstractListModel>
#include <QJsonObject>
#include <QJsonParseError>
#include <QJsonArray>
#include <QFile>
#include <QDir>

const QString ROUTE_FILE_NAME = "route.json";

class Element
{
private:
  Element();

public:
  Element(int id);
  Element(int id, QString latitude, QString longitude);

public:
  int m_id;
  QString m_latitude;
  QString m_longitude;
};

class ListModel : public QAbstractListModel
{
  Q_OBJECT
public:
  enum Roles {
    ID = Qt::UserRole,
    Latitude,
    Longitude
  };

  explicit ListModel(QString route_file_dir_path = "", QObject *parent = nullptr);
  ~ListModel();

  int rowCount(const QModelIndex& parent) const override;
  QVariant data(const QModelIndex& index, int role = Qt::DisplayRole) const override;
  QHash<int, QByteArray> roleNames() const override;

private:
  void updateElementsID();
  int readRouteFile();
  void writeRouteFile();

public slots:
  void removeElement(const int index);
  void addZeroElement();
  void updateElementLatitude(const int index, const QString latitude);
  void updateElementLongitude(const int index, const QString longitude);

signals:

private:
  QVector<Element> m_data;
  QDir m_route_file_dir;
};

#endif // LISTMODEL_H
