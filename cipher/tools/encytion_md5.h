#ifndef ENCYTION_MD5_H
#define ENCYTION_MD5_H

#include <QObject>
#include "abstract_encytion.h"

class EncytionMD5 : public AbstractEncytion {
    Q_OBJECT
   public:
    explicit EncytionMD5(QObject *parent = nullptr);

   signals:

   public slots:

    // AbstractEncytion interface
   public:
    QString EncytonData(QString string) override;
    QString EncytonFile(QString inFilePath) override;
};

#endif  // ENCYTION_MD5_H
