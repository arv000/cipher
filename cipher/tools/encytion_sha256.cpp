#include "encytion_sha256.h"
#include <QtDebug>
#include <QtDebug>
#include <openssl/dh.h>
#include <openssl/evp.h>
#include <openssl/sha.h>
#include "tools.h"
EncytionSha256::EncytionSha256(QObject *) {}

QString EncytionSha256::EncytonData(QString string)
{
    qInfo() << "EncytionSha256 " << string;

    unsigned int len = 0;
    EVP_MD_CTX *ctx = EVP_MD_CTX_new();
    EVP_DigestInit_ex(ctx, EVP_sha256(), nullptr);
    // hash计算
    EVP_DigestUpdate(ctx, string.toStdString().c_str(),
                     string.toStdString().length());
    unsigned char result[SHA256_DIGEST_LENGTH] = {};
    EVP_DigestFinal_ex(ctx, result, &len);
    QString res = Tools::CharToHex(result, len);
    EVP_MD_CTX_free(ctx);
    return res;
}

QString EncytionSha256::EncytonFile(QString inFilePath)
{
    qInfo() << "EncytionSha256 EncytonFile" << inFilePath;
    unsigned int len = 0;

    EVP_MD_CTX *ctx = EVP_MD_CTX_new();
    EVP_DigestInit_ex(ctx, EVP_sha256(), nullptr);
    FILE *fp = nullptr;
    fp = fopen(inFilePath.toStdString().c_str(), "rb+");
    if (nullptr == fp) {
        return "";
    }
    char szDataBuff[SHA256_DIGEST_LENGTH];
    unsigned long nLineLen;
    unsigned long a = 1;
    while (!feof(fp)) {
        memset(szDataBuff, 0x00, sizeof(szDataBuff));
        nLineLen = fread(szDataBuff, a,
                         static_cast<unsigned long>(SHA256_DIGEST_LENGTH), fp);
        if (nLineLen) {
            EVP_DigestUpdate(ctx, szDataBuff, static_cast<int>(nLineLen));
        }
    }
    fclose(fp);
    unsigned char result[SHA256_DIGEST_LENGTH] = {};
    EVP_DigestFinal_ex(ctx, result, &len);
    EVP_MD_CTX_free(ctx);
    QString res = Tools::CharToHex(result, len);
    return res;
}
