#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QtCore>
#include<QFileSystemModel>
#include<QHBoxLayout>
//#include<QFileInfo>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
   // void on_MakeDIr_clicked();

    //void on_Del_clicked();

    void on_treeView_clicked(const QModelIndex &index);

private:
    Ui::MainWindow *ui;
    QFileSystemModel *myDir;
    QHBoxLayout *layout;
   // QString fBase;
    //QFileInfo *fInfo;
};

#endif // MAINWINDOW_H
