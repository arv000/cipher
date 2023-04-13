#include "encytion_sha256.h"
#include <QtDebug>
#include <QtDebug>
#include <openssl/dh.h>
#include <openssl/evp.h>
#include <openssl/sha.h>
#include "tools.h"
EncytionSha256::EncytionSha256(QObject *parent) {}

QString EncytionSha256::EncytonData(QString string)
{
    qInfo() << "EncytionSha256 " << string;

    unsigned int len = 0;
    EVP_MD_CTX *ctx = EVP_MD_CTX_new();
    EVP_DigestInit_ex(ctx, EVP_sha256(), nullptr);
    // hash计算
    EVP_DigestUpdate(ctx, string.toStdString().c_str(),
                     string.toStdString().length());
    unsigned char result[SHA_DIGEST_LENGTH] = {};
    EVP_DigestFinal_ex(ctx, result, &len);
    //    EVP_MD_CTX_init(&ctx);
    QString res = Tools::CharToHex(result, len);
    return res;
}

int EncytionSha256::EncytonFile(QString inFilePath, QString outFilePath)
{
    qInfo() << "EncytionSha256 EncytonFile" << inFilePath;
    qInfo() << "EncytionSha256 EncytonFile" << outFilePath;
    return 0;
}
