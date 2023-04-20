#include "encytion_md5.h"
#include <QtDebug>
#include <QFile>
#include <QDataStream>
#include <openssl/dh.h>
#include <openssl/evp.h>
#include <openssl/md5.h>
#include "../tools.h"
EncytionMD5::EncytionMD5(QObject *) {}

QByteArray EncytionMD5::EncytonData(QString string)
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

    EVP_MD_CTX_free(ctx);
     return QByteArray(reinterpret_cast<char *>(result), static_cast<int>(len));
}

QByteArray EncytionMD5::EncytonFile(QString inFilePath)
{
    qInfo() << "EncytionMD5 EncytonFile" << inFilePath;
    unsigned int len = 0;

    EVP_MD_CTX *ctx = EVP_MD_CTX_new();
    EVP_DigestInit_ex(ctx, EVP_md5(), nullptr);
    FILE *fp = nullptr;
    fp = fopen(inFilePath.toStdString().c_str(), "rb+");
    if (nullptr == fp) {
        return "";
    }
    char szDataBuff[MD5_DIGEST_LENGTH];
    unsigned long nLineLen;
    unsigned long a = 1;
    while (!feof(fp)) {
        memset(szDataBuff, 0x00, sizeof(szDataBuff));
        nLineLen = fread(szDataBuff, a,
                         static_cast<unsigned long>(MD5_DIGEST_LENGTH), fp);
        if (nLineLen) {
            EVP_DigestUpdate(ctx, szDataBuff, nLineLen);
        }
    }
    fclose(fp);
    unsigned char result[MD5_DIGEST_LENGTH] = {};
    EVP_DigestFinal_ex(ctx, result, &len);
    EVP_MD_CTX_free(ctx);
    return QByteArray(reinterpret_cast<char *>(result), static_cast<int>(len));
}
