#include "encytion_sm3.h"
#include <QtDebug>
EncytionSM3::EncytionSM3(QObject *parent) {}

QString EncytionSM3::EncytonData(QString string)
{
    qInfo() << "EncytionSM3 " << string;
    return string;
}

int EncytionSM3::EncytonFile(QString inFilePath, QString outFilePath)
{
    qInfo() << "EncytionSM3 EncytonFile" << inFilePath;
    qInfo() << "EncytionSM3 EncytonFile" << outFilePath;
    return 0;
}
