#ifndef ABSTRACT_ENCYTION_H
#define ABSTRACT_ENCYTION_H

#include <QObject>
#include <QString>
class AbstractHashEncytion : public QObject {
    Q_OBJECT
   public:
    explicit AbstractHashEncytion(QObject *parent = nullptr);
    virtual QByteArray EncytonData(QString string) = 0;
    virtual QByteArray EncytonFile(QString inFilePath) = 0;
};

#endif  // ABSTRACT_ENCYTION_H
