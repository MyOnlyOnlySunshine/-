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
        return QString("Column %1").arg(section) ;
    else
        return QString("Row %1").arg(section);
}

Qt::ItemFlags StringListModel::flags(const QModelIndex &index) const
{
    if (!index.isValid())
        return Qt::ItemIsEnabled;
    /**
      1. Qt::ItemFlags 详见文档
       2.按位或   |   无论左侧的表达式的值为真还是为假，都要判断右侧的表达式的值的真假;
       3. 短路或 ||   只要左侧表达式的值为真，就不再判断右侧表达式的值了；
       疑问？  为什么发送数据改变的信号时，传入两个一样的index
     */
    return QAbstractItemModel::flags(index) | Qt::ItemIsEditable;
}

bool StringListModel::setData(const QModelIndex &index,
                              const QVariant &value, int role)
{
    if (index.isValid() && role == Qt::EditRole) {
        stringList.replace(index.row(), value.toString());
         emit dataChanged(index,index);

        QTimer *timer = new QTimer(this);
              connect(timer, SIGNAL(timeout()), this, SLOT(showValue()));
              timer->start(3000);
        return true;
    }
    return false;
}

void StringListModel::showValue()
{
    qDebug()<<"listValue"<<stringList;
}
