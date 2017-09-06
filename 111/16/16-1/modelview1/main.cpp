#include <QApplication>
#include <QFileSystemModel>
#include <QTreeView>
#include <QListView>
#include <qDebug>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    // 创建文件系统模型
    QFileSystemModel model;

    // 指定要查找的目录
    /**
      currentPath() : 应用程序的工作目录
      homePath（) :用户主目录
      rootPath（）： 根目录
      tempPath（）： 系统临时目录
     */
    //model中 用户指定根节点
    model.setRootPath(QDir::currentPath());
    // 创建树型视图
    QTreeView tree;
    // 为视图指定模型
   tree.setModel(&model);
    // 指定根索引  告诉view需要显示哪个目录的信息。需要传入modelIndex，用index去获取数据
    /**
      为了确保分离数据的获取与显示分离，qt中引入模型索引（QModelIndex），包含一个指针，
      指向创建他们的模型，是对一块数据的临时引用，用来检索或修改模型数据。若需要对数据长久引用
      应该使用QPersistentModelIndex创建模型索引；
      若要获取一个数据项的模型索引，必须指定模型的行、列、父项模型索； 或模型路径
    */
   tree.setRootIndex(model.index(QDir::currentPath()));
    // 创建列表视图
    QListView list;
    list.setModel(&model);
    list.setRootIndex(model.index(QDir::currentPath()));
    tree.show();
    list.show();
  qDebug()<<  model.rowCount()<<" one "<<model.columnCount()<<"two "<<model.hasChildren();

    return app.exec();
}
