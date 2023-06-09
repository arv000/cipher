#ifndef ENCYTION_FILE_JOB_H
#define ENCYTION_FILE_JOB_H

#include <QObject>
#include <QThread>
class AbstractHashEncytion;
class EncytionFileJob : public QThread {
    Q_OBJECT
   public:
    explicit EncytionFileJob(AbstractHashEncytion *encytion);
    AbstractHashEncytion *encytion_;
    QString strInFilePath_;
    QString strOutFilePath_;
    void setData(QString strInFilePath);
   signals:
    void sigFinish(QByteArray out);
   public slots:

    // QThread interface
   protected:
    void run();
};

#endif  // ENCYTION_FILE_JOB_H
