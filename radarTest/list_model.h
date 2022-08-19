#ifndef LISTMODEL_H
#define LISTMODEL_H

#include <QObject>
#include <QAbstractListModel>

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

  explicit ListModel(QObject *parent = nullptr);

  int rowCount(const QModelIndex& parent) const override;
  QVariant data(const QModelIndex& index, int role = Qt::DisplayRole) const override;
  QHash<int, QByteArray> roleNames() const override;

private:
  void updateElementsID();

public slots:
  void removeElement(const int index);
  void addZeroElement();
  void updateElementLatitude(const int index, const QString latitude);
  void updateElementLongitude(const int index, const QString longitude);

signals:

private:
  QVector<Element> m_data;
};

#endif // LISTMODEL_H
