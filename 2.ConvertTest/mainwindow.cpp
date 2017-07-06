#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "qdebug.h"
#include"QMessageBox"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    getAvailableTextCodec();
    connect(ui->textEdit,SIGNAL(textChanged()),this,SLOT(showResult()));
}

void  MainWindow:: getAvailableTextCodec()
{
  codeList = QTextCodec ::availableCodecs();
 // qDebug()<<"support"<<codeList;
  model = new QStandardItemModel(this);

  for(int i =0;i<codeList.count();i++)
  {
      QString str = QString(codeList[i]);
     QStandardItem *item = new QStandardItem(str);
     model->appendRow(item);
     ui->listView->setModel(model);
 }
}

void MainWindow::showResult()
{
    QStandardItemModel *resultModel = new QStandardItemModel(this);
    QList<QString > resultList;
    foreach (QByteArray tempA,codeList)
    {
        // QString str =QString(tempA);
         QTextCodec *codeC = QTextCodec ::codecForName(tempA);
        QByteArray arr = ui->textEdit->toPlainText().toStdString().data();
       //  QString str = codeC->fromUnicode(arr);
         QString str = codeC->toUnicode(arr);
          QStandardItem *item = new QStandardItem(str);
          resultModel->appendRow(item);
          ui->resultListView->setModel(resultModel);
    }
}

MainWindow::~MainWindow()
{
    delete ui;
    delete  model;
}

void MainWindow::on_listView_clicked(const QModelIndex &index)
{
    if(ui->textEdit->toPlainText().length()>0)
    {
         ui->resultListView->selectionModel()->setCurrentIndex(index,QItemSelectionModel::ClearAndSelect);
    }else
    {
        QMessageBox::critical(this,"错误","请输入需要转换的文字");
    }

}

void MainWindow::on_resultListView_clicked(const QModelIndex &index)
{
    ui->listView->selectionModel()->setCurrentIndex(index,QItemSelectionModel::ClearAndSelect);
}
