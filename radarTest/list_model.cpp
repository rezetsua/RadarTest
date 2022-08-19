#include "list_model.h"

ListModel::ListModel(QString route_file_dir_path, QObject *parent)
  : m_route_file_dir(route_file_dir_path), QAbstractListModel{parent}
{
    readRouteFile();
}

ListModel::~ListModel()
{
    writeRouteFile();
}

int ListModel::rowCount(const QModelIndex &parent) const
{
  if (parent.isValid()) {
      return 0;
  }
  return m_data.count();
}

QVariant ListModel::data(const QModelIndex &index, int role) const
{
  if (!index.isValid()) {
      return QVariant();
  }

  if (role == ID)
      return m_data[index.row()].m_id;
  else if (role == Latitude)
      return m_data[index.row()].m_latitude;
  else if (role == Longitude)
      return m_data[index.row()].m_longitude;
  else
      return QVariant();
}

QHash<int, QByteArray> ListModel::roleNames() const
{
  QHash<int, QByteArray> roles;
  roles[ID] = "id";
  roles[Latitude] = "latitude";
  roles[Longitude] = "longitude";
  return roles;
}

void ListModel::updateElementsID()
{
    for (int i = 0; i < m_data.size(); ++i)
        m_data[i].m_id = i + 1;
}

int ListModel::readRouteFile()
{
    QJsonParseError parse_error;
    try {
      if (!m_route_file_dir.exists()) {
        qWarning() << m_route_file_dir.path();
        throw QString("Non-existent directory");
      }
      QFile route_file(m_route_file_dir.absolutePath() + "/" +
                         ROUTE_FILE_NAME);
      if (!route_file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qWarning() << route_file.fileName();
        throw QString("Non-existent file path");
      }
      // Копируем содержимое json файла
      QJsonObject j_obj = QJsonDocument::fromJson(route_file.readAll(), &parse_error).object();
      route_file.close();

      // Копируем массив точек маршрута
      QJsonArray route_array = j_obj.value("route").toArray();

      // Заполняем наш вектор данными из json'a
      for (int i = 0; i < route_array.size(); i++) {
        QJsonObject coordinate = route_array[i].toObject();
        m_data.append(Element(m_data.size() + 1,
                              coordinate.value("latitude").toString(),
                              coordinate.value("longitude").toString()));
      }

    } catch (QString &str) {
      qWarning() << str;
    }
    return parse_error.error;
}

void ListModel::writeRouteFile()
{
    QFile route_file;
    try {
      if (m_route_file_dir.isEmpty()) {
        QString error_string("Директория сохранения маршрута не обнаружена");
        throw error_string;
      };

    } catch (const QString &str) {
      qWarning() << str;
      return;
    }
    route_file.setFileName(m_route_file_dir.absolutePath() + "/" +
                             ROUTE_FILE_NAME);
    try {
      // Открываем и очищаем файл
      if (!route_file.open(QIODevice::ReadWrite | QIODevice::Truncate)) {
        QString error_string("File ");
        error_string.append(ROUTE_FILE_NAME).append(" not open");
        throw error_string;
      }

      QJsonArray route_array;
      // Записываем прессеты в массив
      for (int i = 0; i < m_data.size(); i++) {
          QJsonObject coordinate;
          coordinate.insert("latitude", QJsonValue::fromVariant(m_data[i].m_latitude));
          coordinate.insert("longitude", QJsonValue::fromVariant(m_data[i].m_longitude));
          route_array.push_back(coordinate);
      }
      QJsonObject route_list;
      route_list.insert("route", route_array);

      QJsonDocument doc(route_list);
      route_file.write(doc.toJson());
      route_file.close();
    } catch (const QString &str) {
      qWarning() << str;
    }
}

void ListModel::removeElement(const int index)
{
    assert(index >= 0 && index < m_data.size());
    beginRemoveRows(QModelIndex(), index, index);
    m_data.remove(index);
    endRemoveRows();
    updateElementsID();
    emit dataChanged(createIndex(0,0), createIndex(m_data.count(), 0));
}

void ListModel::addZeroElement()
{
    beginInsertRows(QModelIndex(), m_data.count(), m_data.count());
    m_data.append(Element(m_data.size() + 1, "0°0'0.0\" СШ", "0°0'0.0\" ВД"));
    endInsertRows();
    emit dataChanged(createIndex(0,0), createIndex(m_data.count(), 0));
}

void ListModel::updateElementLatitude(const int index, const QString latitude)
{
    assert(index >= 0 && index < m_data.size());
    m_data[index].m_latitude = latitude;
    emit dataChanged(createIndex(0,0), createIndex(m_data.count(), 0));
}

void ListModel::updateElementLongitude(const int index, const QString longitude)
{
    assert(index >= 0 && index < m_data.size());
    m_data[index].m_longitude = longitude;
    emit dataChanged(createIndex(0,0), createIndex(m_data.count(), 0));
}

Element::Element(int id) : m_id(id)
{

}

Element::Element(int id, QString latitude, QString longitude) :
  m_id(id), m_latitude(latitude), m_longitude(longitude)
{

}
