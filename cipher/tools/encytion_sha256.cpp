#include "encytion_sha256.h"
#include <QtDebug>
EncytionSha256::EncytionSha256(QObject *parent) {}

QString EncytionSha256::EncytonData(QString string)
{
    qInfo() << "EncytionSha256 " << string;
    return string;
}

int EncytionSha256::EncytonFile(QString inFilePath, QString outFilePath)
{
    qInfo() << "EncytionSha256 EncytonFile" << inFilePath;
    qInfo() << "EncytionSha256 EncytonFile" << outFilePath;
    return 0;
}
