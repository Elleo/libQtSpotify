template <class ItemType>
ListModelBase<ItemType>::ListModelBase(ItemType prototype, QObject *parent)
    : QAbstractListModel(parent), m_prototype(prototype)
{ }

template <class ItemType>
int ListModelBase<ItemType>::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent)
    return m_dataList.size();
}

template <class ItemType>
QVariant ListModelBase<ItemType>::data(const QModelIndex &index, int role) const
{
    if(index.row() < 0 || index.row() >= m_dataList.size())
        return QVariant();
    return m_dataList.at(index.row())->data(role);
}

template <class ItemType>
QHash<int, QByteArray> ListModelBase<ItemType>::roleNames() const
{
    return m_prototype->roleNames();
}

template <class ItemType>
ListModelBase<ItemType>::~ListModelBase()
{
    if(m_prototype)
        delete m_prototype;
    clear();
}

template <class ItemType>
void ListModelBase<ItemType>::appendRow(ItemType item)
{
    beginInsertRows(QModelIndex(), rowCount(), rowCount());
    m_dataList.append(item);
    endInsertRows();
}

template <class ItemType>
void ListModelBase<ItemType>::appendRows(const QList<ItemType > &items)
{
    beginInsertRows(QModelIndex(),rowCount(),rowCount()+items.size()-1);
    m_dataList.append(items);
    endInsertRows();
}

template <class ItemType>
void ListModelBase<ItemType>::insertRow(int row, ItemType item)
{
    beginInsertRows(QModelIndex(),row,row);
    m_dataList.insert(row,item);
    endInsertRows();
}

template <class ItemType>
ItemType ListModelBase<ItemType>::find(const QString &id) const
{
    for(auto item : m_dataList)
        if(item->getId() == id) return item;
    return 0;
}

template <class ItemType>
QModelIndex ListModelBase<ItemType>::indexFromItem(const ItemType item) const
{
    Q_ASSERT(item);
    for(int row=0; row<m_dataList.size();++row)
        if(m_dataList.at(row) == item) return index(row);

    return QModelIndex();
}

template <class ItemType>
void ListModelBase<ItemType>::clear()
{
    beginRemoveRows(QModelIndex(),0, m_dataList.size()-1);
    m_dataList.clear();
    endRemoveRows();
}

template <class ItemType>
bool ListModelBase<ItemType>::removeRow(int row, const QModelIndex &parent)
{
    Q_UNUSED(parent);
    if(row < 0 || row >= m_dataList.size()) return false;
    beginRemoveRows(QModelIndex(), row, row);
    m_dataList.takeAt(row).clear();
    endRemoveRows();
    return true;
}

template <class ItemType>
bool ListModelBase<ItemType>::removeRows(int row, int count, const QModelIndex &parent)
{
    Q_UNUSED(parent);
    if(row < 0 || (row+count) >= m_dataList.size()) return false;
    beginRemoveRows(QModelIndex(),row,row+count-1);
    for(int i=0; i<count; ++i){
        m_dataList.takeAt(row).clear();
    }
    endRemoveRows();
    return true;

}

template <class ItemType>
ItemType ListModelBase<ItemType>::takeRow(int row){
    beginRemoveRows(QModelIndex(),row,row);
    auto item = m_dataList.takeAt(row);
    endRemoveRows();
    return item;
}

template <class ItemType>
void ListModelBase<ItemType>::replaceData(const QList<ItemType > &newData)
{
    clear();
    appendRows(newData);
}

template <class ItemType>
bool ListModelBase<ItemType>::setData(const QModelIndex &index, const QVariant &value, int role)
{
    if(index.row() >= 0 && index.row() < m_dataList.size()) {
        if(m_dataList.at(index.row())->setData(value, role)) {
            emit dataChanged(index, index, QVector<int>() << role);
            return true;
        }
    }
    return false;
}
