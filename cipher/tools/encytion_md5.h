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
    QString EncytonData(QString string);
    int EncytonFile(QString inFilePath, QString outFilePath);
};

#endif  // ENCYTION_MD5_H
