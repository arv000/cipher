#include "encytion_sm3.h"
#include <QtDebug>
#include <openssl/dh.h>
#include <openssl/evp.h>
#include <openssl/sm3.h>
#include "tools.h"
EncytionSM3::EncytionSM3(QObject *parent) {}

QString EncytionSM3::EncytonData(QString string)
{
    qInfo() << "EncytionSM3 " << string;

    unsigned int len = 0;
    EVP_MD_CTX *ctx = EVP_MD_CTX_new();
    EVP_DigestInit_ex(ctx, EVP_sm3(), nullptr);
    // hash计算
    EVP_DigestUpdate(ctx, string.toStdString().c_str(),
                     string.toStdString().length());
    unsigned char result[SM3_DIGEST_LENGTH] = {};
    EVP_DigestFinal_ex(ctx, result, &len);
    //    EVP_MD_CTX_init(&ctx);
    QString res = Tools::CharToHex(result, len);
    return res;
}

int EncytionSM3::EncytonFile(QString inFilePath, QString outFilePath)
{
    qInfo() << "EncytionSM3 EncytonFile" << inFilePath;
    qInfo() << "EncytionSM3 EncytonFile" << outFilePath;
    return 0;
}
