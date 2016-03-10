#ifndef JSONGET_H
#define JSONGET_H

#include <QObject>
#include <QNetworkAccessManager>
#include <QNetworkReply>



class jsonget : public QObject
{
    Q_OBJECT
public:
    explicit jsonget(QObject *parent = 0);
    void make_request(QString endpoint_request);
signals:

void dataReadyRead(QByteArray);

public slots:
void data_read(QNetworkReply*);

private:
    QNetworkAccessManager *q_nam = new QNetworkAccessManager(this);
};

#endif // JSONGET_H
