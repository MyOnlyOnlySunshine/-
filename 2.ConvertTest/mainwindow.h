#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QTextCodec>
#include<QList>
#include<QStandardItemModel>
#include<QStandardItem>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void  getAvailableTextCodec();
   QStandardItemModel  *model;
   QList<QByteArray>  codeList ;

private slots:
   void showResult();

   void on_listView_clicked(const QModelIndex &index);

   void on_resultListView_clicked(const QModelIndex &index);

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
