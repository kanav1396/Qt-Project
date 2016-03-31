#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QtCore>
#include<QFileSystemModel>
#include<QHBoxLayout>
#include<QGraphicsView>
#include<QFile>
#include<QDebug>
#include<jsonget.h>
#include <QJsonDocument>
#include<QNetworkAccessManager>
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
    void action_on_data_get(QByteArray json_file_data);
    void slot_netwManagerFinished(QNetworkReply *);

private:
    Ui::MainWindow *ui;
    QFileSystemModel *current_directory;
    QHBoxLayout *layout;
    jsonget data_get_frame;
    QJsonDocument json_doc;
    QJsonObject jsonObject;
    QByteArray jpegData;
    QNetworkAccessManager *image_get;
};

#endif // MAINWINDOW_H
