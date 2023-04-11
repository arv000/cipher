#include "encytion_md5.h"
#include <QtDebug>
EncytionMD5::EncytionMD5(QObject *parent) {}

QString EncytionMD5::EncytonData(QString string)
{
    qInfo() << "EncytionMD5 " << string;
    return string;
}

int EncytionMD5::EncytonFile(QString inFilePath, QString outFilePath)
{
    qInfo() << "EncytionMD5 EncytonFile" << inFilePath;
    qInfo() << "EncytionMD5 EncytonFile" << outFilePath;
    return 0;
}
