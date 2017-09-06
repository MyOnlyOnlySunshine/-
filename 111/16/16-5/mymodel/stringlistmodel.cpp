#include "stringlistmodel.h"

int StringListModel::rowCount(const QModelIndex &) const
{
    return stringList.count();
}

QVariant StringListModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return QVariant();

    if (index.row() >= stringList.size())
        return QVariant();

    if (role == Qt::DisplayRole || role == Qt::EditRole)
        return stringList.at(index.row());
    else
        return QVariant();
}

QVariant StringListModel::headerData(int section, Qt::Orientation orientation,
                                     int role) const
{
    if (role != Qt::DisplayRole)
        return QVariant();

    if (orientation == Qt::Horizontal)
        return QString("Column %1").arg(section);
    else
        return QString("Row %1").arg(section);
}

Qt::ItemFlags StringListModel::flags(const QModelIndex &index) const
{
    if (!index.isValid())
        return Qt::ItemIsEnabled;
    return QAbstractItemModel::flags(index) | Qt::ItemIsEditable;
}

bool StringListModel::setData(const QModelIndex &index,
                              const QVariant &value, int role)
{
    if (index.isValid() && role == Qt::EditRole) {
        stringList.replace(index.row(), value.toString());
        emit dataChanged(index, index);
        return true;
    }
    return false;
}
bool StringListModel::insertRowsWithValue(int position,int rows,QString value)
{
    //g告知其他组件指定的行将要发生变化，position 将要插入的第一个 和最后一个的行号，以及父项索引模型
    beginInsertRows(QModelIndex(), position, position+rows-1);
    for (int row = 0; row < rows; ++row) {
        stringList.insert(position, value);
    }
      // 告知其他组件该模型的大小发生了变化
    endInsertRows();
    return true;
 }

//bool StringListModel::insertRows(int position, int rows,
//                                 const QModelIndex &parent)
//{
//    beginInsertRows(QModelIndex(), position, position+rows-1);
//    for (int row = 0; row < rows; ++row) {
//        stringList.insert(position, "");
//    }
//    endInsertRows();
//    return true;
//}

bool StringListModel::removeRows(int position, int rows,
                                 const QModelIndex &parent)
{
    beginRemoveRows(QModelIndex(), position, position+rows-1);
    for (int row = 0; row < rows; ++row) {
        stringList.removeAt(position);
    }
    endRemoveRows();
    return true;
}
