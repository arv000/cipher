#ifndef ABSTRACT_ENCYTION_H
#define ABSTRACT_ENCYTION_H

#include <QObject>
#include <QString>
class AbstractEncytion : public QObject {
    Q_OBJECT
   public:
    explicit AbstractEncytion(QObject *parent = nullptr);
    virtual QString EncytonData(QString string) = 0;
    virtual QString EncytonFile(QString inFilePath) = 0;
};

#endif  // ABSTRACT_ENCYTION_H
