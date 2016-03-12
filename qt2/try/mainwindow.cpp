#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "qnetworkaccessmanager.h"
#include "QGraphicsPixmapItem"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    current_directory = new QFileSystemModel(this);
    current_directory->setRootPath("/home");
    ui->treeView->setModel(current_directory);
    ui->img_disp->setScaledContents(true);
    ui->treeView->hideColumn(2);
    ui->treeView->hideColumn(3);                                                              //Hiding the size and other irrelevent properties
    ui->treeView->hideColumn(4);
    ui->treeView->hideColumn(1);
    connect(&data_get_frame,SIGNAL(dataReadyRead(QByteArray)),this,SLOT(action_on_data_get(QByteArray)));
}
MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::on_treeView_clicked(const QModelIndex &index)
{

   QString file_Base = current_directory->fileInfo(index).baseName() ;
   QString file_Ext =  current_directory->fileInfo(index).suffix() ;


   if(file_Ext=="avi"||file_Ext=="mp4"||file_Ext=="mkv"||file_Ext=="flv")                                   //Added flv format for flash files
   {
       data_get_frame.make_request("http://www.omdbapi.com/?t=" + file_Base + "&y=&plot=full&r=json");
       image_get= new QNetworkAccessManager(this);
       connect(image_get, SIGNAL(finished(QNetworkReply*)), this, SLOT(slot_netwManagerFinished(QNetworkReply*)));

   }

}

void MainWindow::action_on_data_get(QByteArray json_file_data)
{
    QString data_string;
    data_string = json_file_data;
    QStringList propertyNames;
    QStringList propertyKeys;
    QString strReply = json_file_data;
    QJsonDocument jsonResponse = QJsonDocument::fromJson(strReply.toUtf8());
    jsonObject = jsonResponse.object();
    QPixmap pixmap;
    QUrl image_url(jsonObject["Poster"].toString());
    QNetworkRequest request_image(image_url);
    image_get->get(request_image);
    pixmap.loadFromData(jpegData);
    int w = ui->img_disp->width();
    int h = ui->img_disp->height();
    ui->img_disp->setPixmap(pixmap);
    ui->textBrowser->setPlainText("");
    ui->textBrowser->append("Title\t\t:" + jsonObject["Title"].toString());
    ui->textBrowser->append("Year\t\t:" + jsonObject["Year"].toString());
    ui->textBrowser->append("Rated\t\t:" + jsonObject["Rated"].toString());
    ui->textBrowser->append("Released\t\t:" + jsonObject["Released"].toString());
    ui->textBrowser->append("Runtime\t\t:" + jsonObject["Runtime"].toString());
    ui->textBrowser->append("Genre\t\t:" + jsonObject["Genre"].toString());
    ui->textBrowser->append("Director\t\t:" + jsonObject["Director"].toString());
    ui->textBrowser->append("Actors\t\t:" + jsonObject["Actors"].toString());
    ui->textBrowser->append("IMDb Rating\t:" + jsonObject["imdbRating"].toString());
    ui->textBrowser->append("Plot\t\t:" + jsonObject["Plot"].toString());
}
void MainWindow::slot_netwManagerFinished(QNetworkReply *reply)
{
if (reply->error() != QNetworkReply::NoError) {
qDebug() << "Error in" << reply->url() << ":" << reply->errorString();
return;
}
jpegData = reply->readAll();

}

