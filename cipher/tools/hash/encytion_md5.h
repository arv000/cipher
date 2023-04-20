#ifndef ENCYTION_MD5_H
#define ENCYTION_MD5_H

#include <QObject>
#include "abstract_encytion.h"

class EncytionMD5 : public AbstractHashEncytion {
    Q_OBJECT
   public:
    explicit EncytionMD5(QObject *parent = nullptr);

   signals:

   public slots:

    // AbstractHashEncytion interface
   public:
    QByteArray EncytonData(QString string) override;
    QByteArray EncytonFile(QString inFilePath) override;
};

#endif  // ENCYTION_MD5_H
