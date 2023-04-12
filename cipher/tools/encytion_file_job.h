#ifndef ENCYTION_FILE_JOB_H
#define ENCYTION_FILE_JOB_H

#include <QObject>
#include <QThread>
class EncytionFileJob : public QThread {
    Q_OBJECT
   public:
    explicit EncytionFileJob(QObject *parent = nullptr);

   signals:
    void sigFinish(int status);
   public slots:

    // QThread interface
   protected:
    void run();
};

#endif  // ENCYTION_FILE_JOB_H
