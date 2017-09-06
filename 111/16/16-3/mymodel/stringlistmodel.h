#ifndef STRINGLISTMODEL_H
#define STRINGLISTMODEL_H

#include <QAbstractListModel>
#include <QStringList>

class StringListModel : public QAbstractListModel
{
    Q_OBJECT
public:
    StringListModel(const QStringList &strings, QObject *parent = 0)
        : QAbstractListModel(parent), stringList(strings) {}
    /**
      注意：这里因为是继承自QAbstractListModel，必须实现rowCount() 和data（）两个纯虚函数，且此模型默认只包含一列，
              不需要实现columnCount（）
    */
    int rowCount(const QModelIndex &parent = QModelIndex()) const;
    QVariant data(const QModelIndex &index, int role) const;
    QVariant headerData(int section, Qt::Orientation orientation,
                        int role = Qt::DisplayRole) const;
private:
    QStringList stringList;
};

#endif // STRINGLISTMODEL_H
