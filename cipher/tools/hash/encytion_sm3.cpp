#include "encytion_sm3.h"
#include <QtDebug>
#include <openssl/dh.h>
#include <openssl/evp.h>
#include <openssl/sm3.h>
#include "../tools.h"
EncytionSM3::EncytionSM3(QObject *) {}

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
    EVP_MD_CTX_free(ctx);
    return res;
}

QString EncytionSM3::EncytonFile(QString inFilePath)
{
    qInfo() << "EncytionSha256 EncytonFile" << inFilePath;
    unsigned int len = 0;

    EVP_MD_CTX *ctx = EVP_MD_CTX_new();
    EVP_DigestInit_ex(ctx, EVP_sm3(), nullptr);
    FILE *fp = nullptr;
    fp = fopen(inFilePath.toStdString().c_str(), "rb+");
    if (nullptr == fp) {
        return "";
    }
    char szDataBuff[SM3_DIGEST_LENGTH];
    unsigned long nLineLen;
    unsigned long a = 1;
    while (!feof(fp)) {
        memset(szDataBuff, 0x00, sizeof(szDataBuff));
        nLineLen = fread(szDataBuff, a,
                         static_cast<unsigned long>(SM3_DIGEST_LENGTH), fp);
        if (nLineLen) {
            EVP_DigestUpdate(ctx, szDataBuff, static_cast<int>(nLineLen));
        }
    }
    fclose(fp);
    unsigned char result[SM3_DIGEST_LENGTH] = {};
    EVP_DigestFinal_ex(ctx, result, &len);
    EVP_MD_CTX_free(ctx);
    QString res = Tools::CharToHex(result, len);
    return res;
}
