#ifndef ENCYTION_SM3_H
#define ENCYTION_SM3_H

#include <QObject>
#include "abstract_encytion.h"
class EncytionSM3 : public AbstractHashEncytion {
    Q_OBJECT
   public:
    explicit EncytionSM3(QObject *parent = nullptr);

   signals:

   public slots:

    // AbstractEncytion interface
   public:
    QString EncytonData(QString string) override;
    QString EncytonFile(QString inFilePath) override;
};

#endif  // ENCYTION_SM3_H
