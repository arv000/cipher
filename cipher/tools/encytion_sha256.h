#ifndef ENCYTION_SHA256_H
#define ENCYTION_SHA256_H

#include <QObject>
#include "abstract_encytion.h"
class EncytionSha256 : public AbstractEncytion {
    Q_OBJECT
   public:
    explicit EncytionSha256(QObject *parent = nullptr);

   signals:

   public slots:

    // AbstractEncytion interface
   public:
    QString EncytonData(QString string) override;
    QString EncytonFile(QString inFilePath) override;
};

#endif  // ENCYTION_SHA256_H
