#ifndef LISTMODELBASE_H
#define LISTMODELBASE_H

#include <memory>

#include <QtCore/QAbstractListModel>
#include <QtCore/QList>
#include <QtCore/QVariant>

/***
 Abstract list model class, uses std::shared_pointer to objects it stores.

 ItemType Requirements:
 -The ItemType should implement data() and roleNames() functions as those
  calls are delegated to the item and prototype.

 -ItemType should have a dataChanged() signal which is emitted whenever data
  changes, except when it changed from within setData() then it is optional.

 -ItemType should inherit from public std::enable_shared_from_this<ItemType>.
*/

template <class ItemType>  class ListModelBase : public QAbstractListModel
{

public:
    explicit ListModelBase(std::shared_ptr<ItemType> prototype, QObject *parent=nullptr);
    virtual ~ListModelBase();
    int rowCount(const QModelIndex &parent = QModelIndex()) const;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;
    QHash<int, QByteArray> roleNames() const;
    void appendRow(std::shared_ptr<ItemType>  item);
    void appendRows(const QList<std::shared_ptr<ItemType> > &items);
    void insertRow(int row, std::shared_ptr<ItemType> item);
    bool removeRow(int row, const QModelIndex &parent = QModelIndex());
    bool removeRows(int row, int count, const QModelIndex &parent = QModelIndex());
    void replaceData(const QList<std::shared_ptr<ItemType> > &newData);
    std::shared_ptr<ItemType> takeRow(int row);
    std::shared_ptr<ItemType> find(const QString &id) const;
    QModelIndex indexFromItem(const std::shared_ptr<ItemType> item) const;
    void clear();

    // by default the model is not editable
    Qt::ItemFlags flags() const { return Qt::ItemIsSelectable || Qt::ItemIsEnabled; }
    bool isEmpty() const { return m_dataList.isEmpty(); }
    std::shared_ptr<ItemType> at(int index) const { return m_dataList.at(index); }
    int count() const { return m_dataList.count(); }

    bool setData(const QModelIndex &index, const QVariant &value, int role);

protected:
    QList<std::shared_ptr<ItemType> > m_dataList;

private slots:
    void itemDataChanged();

private:
    std::shared_ptr<ItemType> m_prototype;
};

#include "listmodelbase.cpp"

#endif // LISTMODELBASE_H
