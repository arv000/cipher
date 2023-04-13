#include "encytion_md5.h"
#include <QtDebug>
#include <openssl/dh.h>
#include <openssl/evp.h>
#include <openssl/md5.h>
#include "tools.h"
EncytionMD5::EncytionMD5(QObject *parent) {}

QString EncytionMD5::EncytonData(QString string)
{
    qInfo() << "EncytionMD5 " << string;

    unsigned int len = 0;
    EVP_MD_CTX *ctx = EVP_MD_CTX_new();
    EVP_DigestInit_ex(ctx, EVP_md5(), nullptr);
    // hash计算
    EVP_DigestUpdate(ctx, string.toStdString().c_str(),
                     string.toStdString().length());
    unsigned char result[MD5_DIGEST_LENGTH] = {};
    EVP_DigestFinal_ex(ctx, result, &len);
    //    EVP_MD_CTX_init(&ctx);
    QString res = Tools::CharToHex(result, len);
    return res;
}

int EncytionMD5::EncytonFile(QString inFilePath, QString outFilePath)
{
    qInfo() << "EncytionMD5 EncytonFile" << inFilePath;
    qInfo() << "EncytionMD5 EncytonFile" << outFilePath;
    return 0;
}
