#include "list_model.h"

ListModel::ListModel(QObject *parent)
  : QAbstractListModel{parent}
{
  m_data.append(Element(m_data.size() + 1, "54°56'32.7\" СШ", "85°20'21.7\" ВД"));
  m_data.append(Element(m_data.size() + 1, "54°56'32.7\" СШ", "85°20'21.7\" ВД"));
  m_data.append(Element(m_data.size() + 1, "54°56'32.7\" СШ", "85°20'21.7\" ВД"));
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

Element::Element(int id) : m_id(id)
{

}

Element::Element(int id, QString latitude, QString longitude) :
  m_id(id), m_latitude(latitude), m_longitude(longitude)
{

}
