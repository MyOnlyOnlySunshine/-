#include <QApplication>
#include "stringlistmodel.h"
#include <QListView>
#include <QTableView>
#include <QStringListModel>
#include <qDebug>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QStringList list;
    list << "a" << "b" << "c";
    StringListModel model(list);


    QListView listView;
    listView.setModel(&model);
    listView.show();

    QTableView tableView;
    tableView.setModel(&model);
    tableView.show();

    QModelIndex indexA = model.index(0 ,0  ,QModelIndex());
  //  qDebug()<<" data " << model.data(indexA,Qt::DisplayRole).toString()<<"rowCount" <<model.rowCount() << "headData " <<model.headerData(0,Qt::Vertical,Qt::DisplayRole);

    return app.exec();
}
