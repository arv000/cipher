#ifndef ENCYTION_DATA_JOB_H
#define ENCYTION_DATA_JOB_H

#include <QObject>
#include <QThread>
class AbstractEncytion;
class EncytionDataJob : public QThread {
    Q_OBJECT
   public:
    explicit EncytionDataJob(AbstractEncytion *encytion);
    AbstractEncytion *encytion_;
    void setData(QString data);
    QString data_;
   signals:
    void sigFinish(QString strOut);
   public slots:

    // QThread interface
   protected:
    void run();
};

#endif  // ENCYTION_DATA_JOB_H
