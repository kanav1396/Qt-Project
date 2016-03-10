#include "mainwindow.h"
#include "ui_mainwindow.h"



MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    current_directory = new QFileSystemModel(this);
    current_directory->setRootPath("/home");
    ui->treeView->setModel(current_directory);
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
       ui->textBrowser->setPlainText(file_Base);
       data_get_frame.make_request("http://www.omdbapi.com/?t=" + file_Base + "&y=&plot=short&r=json");
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
    QJsonObject jsonObject = jsonResponse.object();
    ui->textBrowser->append("Title\t:" + jsonObject["Title"].toString());
    ui->textBrowser->append("Year\t:" + jsonObject["Year"].toString());
    ui->textBrowser->append("Rated\t:" + jsonObject["Rated"].toString());
    ui->textBrowser->append("Released\t:" + jsonObject["Released"].toString());
    ui->textBrowser->append("Runtime\t:" + jsonObject["Runtime"].toString());
    ui->textBrowser->append("Genre\t:" + jsonObject["Genre"].toString());
    ui->textBrowser->append("Director\t:" + jsonObject["Director"].toString());
    ui->textBrowser->append("Actors\t:" + jsonObject["Actors"].toString());
    ui->textBrowser->append("Plot\t:" + jsonObject["Plot"].toString());
}

