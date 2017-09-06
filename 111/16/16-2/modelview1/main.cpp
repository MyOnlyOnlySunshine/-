#include <QApplication>
#include <QTreeView>
#include <QDebug>
#include <QStandardItemModel>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    // 创建标准项模型
    QStandardItemModel model;

    // 获取模型的根项（Root Item），根项是不可见的
    QStandardItem *parentItem = model.invisibleRootItem();

    // 创建标准项item0，并设置显示文本，图标和工具提示
    QStandardItem *item0 = new QStandardItem;
    item0->setText("A");
    QPixmap pixmap0(50, 50);
    pixmap0.fill("red");
    item0->setIcon(QIcon(pixmap0));
    item0->setToolTip("悬浮A");
    item0->setColumnCount(2);


    // 将创建的标准项作为根项的子项
    parentItem->appendRow(item0);

    // 将创建的标准项作为新的父项
    //   parentItem = item0;

    // 创建新的标准项，它将作为item0的子项
    QStandardItem *item1 = new QStandardItem;
    item1->setText("B");
    QPixmap pixmap1(50,50);
    pixmap1.fill("blue");
    item1->setIcon(QIcon(pixmap1));
    item1->setToolTip("悬浮B");

  //  parentItem->appendRow(item1);
    item0->appendRow(item1);



    QStandardItem *item3 = new QStandardItem;
    item3->setText("D");
    QPixmap pixmap3(50,50);
    pixmap3.fill("blue");
    item3->setIcon(QIcon(pixmap3));
    item3->setToolTip("悬浮D");
    item1->appendRow(item3);



    // 创建新的标准项，这里使用了另一种方法来设置文本、图标和工具提示
    QStandardItem *item2 = new QStandardItem;
    QPixmap pixmap2(50,50);
    pixmap2.fill("green");
    item2->setData("C", Qt::EditRole);
    item2->setData("悬浮C", Qt::ToolTipRole);
    item2->setData(QIcon(pixmap2), Qt::DecorationRole);
    //parentItem->appendRow(item2);
   item0->appendRow(item2);


    // 在树视图中显示模型
    QTreeView view;
    view.setModel(&model);
    view.show();

    /**
       行号、列号均从0开始
        1.列表模型与表格模型都是以作为父根项项，被称为顶层数据项，读取这些数据时，父项的模型索引可以用QModelIndex（）表示
            QModelIndex  a = model.index(0,0,QModelIndex());
        2.树模型时，每一个数据项都可能成为其他数据项的父项，当请求索引时，需提供父项的信息，如indexB，
            指定indexA为其父模型索引
        3. 模型中的数据项可以作为各种角色在其他组件中使用，允许提供不同的数据类型。数据项包含不同的角色数据为枚举类型
            详见 Qt::ItemDataRole；


        疑问？ 1.为什么随意指定行列，rowCount是1？
    */


    QModelIndex indexA = model.index(1,0 , QModelIndex());
    qDebug() << "IndexA:rowCount " << model.columnCount(indexA);

    QModelIndex indexB = model.index(0,0 , indexA);
    qDebug()<<"indexB :"<<indexB.row()<<"column :" <<indexB.column();
    qDebug() << "indexB text: " << model.data(indexB, Qt::DisplayRole);
    qDebug() << "indexB toolTip: "<< model.data(indexB, Qt::ToolTipRole).toString();


    return app.exec();
}
