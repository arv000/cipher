#ifndef ENCYTION_SM3_H
#define ENCYTION_SM3_H

#include <QObject>
#include "abstract_encytion.h"
class EncytionSM3 : public AbstractEncytion {
    Q_OBJECT
   public:
    explicit EncytionSM3(QObject *parent = nullptr);

   signals:

   public slots:

    // AbstractEncytion interface
   public:
    QString EncytonData(QString string);
    int EncytonFile(QString inFilePath, QString outFilePath);
};

#endif  // ENCYTION_SM3_H