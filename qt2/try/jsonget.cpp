#include "jsonget.h"

jsonget::jsonget(QObject *parent) : QObject(parent)
{
    connect(q_nam,SIGNAL(finished(QNetworkReply*)),this,SLOT(data_read(QNetworkReply*)));
}

void jsonget::make_request(QString endpoint_request){
    q_nam->get(QNetworkRequest(QUrl(endpoint_request)));
}


void jsonget::data_read(QNetworkReply *reply){
    QByteArray json_data;
    json_data = reply->readAll();
    emit(dataReadyRead(json_data));
}
