#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    myDir = new QFileSystemModel(this);
    myDir->setRootPath("C:/");
    //layout = new QHBoxLayout(this);
  //layout->addWidget(ui->treeView);
    ui->treeView->setModel(myDir);
  //  layout->addWidget(ui->treeView);
   //layout->addWidget(ui->label);
   // layout->addWidget(ui->centralWidget);
   // layout->addWidget(ui->textBrowser);

    //setLayout(layout);
  //  fBase = "LOL";
    //ui->label->setText(fBase);
    //ui->plainTextEdit->
    //connect(myDir,SIGNAL(directoryLoaded(QString)),ui->label,SLOT
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_treeView_clicked(const QModelIndex &index)
{
  // QString fPath = myDir->fileInfo(index).absoluteFilePath();
   //QFileInfo fInfo =
   QString fBase = myDir->fileInfo(index).baseName() ;
   QString fExt =  myDir->fileInfo(index).suffix() ;
   if(fExt=="avi"||fExt=="mp4"||fExt=="mkv")
   {
       ui->textBrowser->setPlainText(fBase);//->setText(fBase);
   }

}

