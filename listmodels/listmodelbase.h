#ifndef LISTMODELBASE_H
#define LISTMODELBASE_H

#include <memory>

#include <QtCore/QAbstractListModel>
#include <QtCore/QList>
#include <QtCore/QVariant>

/***
 Abstract list model class, should only be used with smart pointer types.
 It will leak memory if you use raw pointer, and won't compile for none
 pointer types.

 The ItemType should implement data() and roleNames() functions as those
 calls are delegated to the item and prototype.
*/

template <class ItemType>  class ListModelBase : public QAbstractListModel
{

public:
    explicit ListModelBase(ItemType prototype, QObject *parent=nullptr);
    ~ListModelBase();
    int rowCount(const QModelIndex &parent = QModelIndex()) const;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;
    QHash<int, QByteArray> roleNames() const;
    void appendRow(ItemType item);
    void appendRows(const QList<ItemType > &items);
    void insertRow(int row, ItemType item);
    bool removeRow(int row, const QModelIndex &parent = QModelIndex());
    bool removeRows(int row, int count, const QModelIndex &parent = QModelIndex());
    void replaceData(const QList<ItemType > &newData);
    ItemType takeRow(int row);
    ItemType find(const QString &id) const;
    QModelIndex indexFromItem(const ItemType item) const;
    void clear();

    // by default the model is not editable
    Qt::ItemFlags flags() const { return Qt::ItemIsSelectable || Qt::ItemIsEnabled; }
    bool isEmpty() const { return m_dataList.isEmpty(); }
    ItemType at(int index) const { return m_dataList.at(index); }
    int count() const { return m_dataList.count(); }

    bool setData(const QModelIndex &index, const QVariant &value, int role);

protected:
    QList<ItemType > m_dataList;

private:
    ItemType m_prototype;
};

#include "listmodelbase.cpp"

#endif // LISTMODELBASE_H
