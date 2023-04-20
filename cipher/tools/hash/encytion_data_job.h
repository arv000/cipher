#ifndef ENCYTION_DATA_JOB_H
#define ENCYTION_DATA_JOB_H

#include <QObject>
#include <QThread>
class AbstractHashEncytion;
class EncytionDataJob : public QThread {
    Q_OBJECT
   public:
    explicit EncytionDataJob(AbstractHashEncytion *encytion);
    AbstractHashEncytion *encytion_;
    void setData(QString data);
    QString data_;
   signals:
    void sigFinish(QByteArray strOut);
   public slots:

    // QThread interface
   protected:
    void run();
};

#endif  // ENCYTION_DATA_JOB_H
