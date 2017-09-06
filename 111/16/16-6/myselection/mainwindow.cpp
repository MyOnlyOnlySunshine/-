#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QStandardItemModel>
#include <QTableView>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //复杂的数据结构模型，
    QStandardItemModel *model = new QStandardItemModel(7, 4, this);
    for (int row = 0; row < 7; ++row) {
        for (int column = 0; column < 4; ++column) {
            QStandardItem *item = new QStandardItem(QString("%1")
                                                    .arg(row * 4 + column));
            model->setItem(row, column, item);
        }
    }
    tableView = new QTableView;
    tableView->setModel(model);
    //把表格视图设置为window的centralWidget
    setCentralWidget(tableView);

    // 获取视图的项目选择模型
    QItemSelectionModel *selectionModel = tableView->selectionModel();

    // 定义左上角和右下角的索引，然后使用这两个索引创建选择
    /**
      QItemSelection:项目选择块，指定左上、右下来设置范围
    */
    QModelIndex topLeft;
    QModelIndex bottomRight;
    topLeft = model->index(1, 1, QModelIndex());
    bottomRight = model->index(5, 2, QModelIndex());
    QItemSelection selection(topLeft, bottomRight);

    // 使用指定的选择模式来选择项目 详见QItemSectionModel::SelectionFlags
    /**
      QItemSectionModel::SelectionFlags  选择模式 枚举类型
    */
    selectionModel->select(selection, QItemSelectionModel::Rows);
    qDebug()

}

MainWindow::~MainWindow()
{
    delete ui;
}
