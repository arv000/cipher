#include "encytion_aes.h"
#include <openssl/aes.h>
#include <openssl/evp.h>
EncytionAES::EncytionAES(QObject *parent)
    : AbstractSymmetryEncytion(parent)
{
}

EncytionAES::~EncytionAES() {}

QByteArray EncytionAES::EncytonData(const QByteArray &in, const QByteArray &key,
                                    const QByteArray &ivec, CIPH_MODE mode)
{
    switch (mode) {
        case CIPH_MODE_ECB:
            return EncytonDataECB(in, key, ivec);
        case CIPH_MODE_CBC:
            return EncytonDataCBC(in, key, ivec);
        case CIPH_MODE_CFB:
            return EncytonDataCFB(in, key, ivec);
        case CIPH_MODE_OFB:
            return EncytonDataOFB(in, key, ivec);
        case CIPH_MODE_CTR:
            return EncytonDataCTR(in, key, ivec);
        case CIPH_MODE_GCM:
            return EncytonDataGCM(in, key, ivec);
        case CIPH_MODE_CCM:
            return EncytonDataCCM(in, key, ivec);
    }
    return "";
}

QByteArray EncytionAES::EncytonDataECB(const QByteArray &in,
                                       const QByteArray &key,
                                       const QByteArray &ivec)
{
    return "";
}

QByteArray EncytionAES::EncytonDataCBC(const QByteArray &in,
                                       const QByteArray &key,
                                       const QByteArray &ivec)
{
}

QByteArray EncytionAES::EncytonDataCFB(const QByteArray &in,
                                       const QByteArray &key,
                                       const QByteArray &ivec)
{
    return "";
}

QByteArray EncytionAES::EncytonDataOFB(const QByteArray &in,
                                       const QByteArray &key,
                                       const QByteArray &ivec)
{
    return "";
}

QByteArray EncytionAES::EncytonDataCTR(const QByteArray &in,
                                       const QByteArray &key,
                                       const QByteArray &ivec)
{
    return "";
}

QByteArray EncytionAES::EncytonDataGCM(const QByteArray &in,
                                       const QByteArray &key,
                                       const QByteArray &ivec)
{
    return "";
}

QByteArray EncytionAES::EncytonDataCCM(const QByteArray &in,
                                       const QByteArray &key,
                                       const QByteArray &ivec)
{
    return "";
}
QByteArray EncytionAES::EncytonDataXTS(const QByteArray &in,
                                       const QByteArray &key,
                                       const QByteArray &ivec)
{
    return "";
}

QByteArray EncytionAES::Encyton(const QByteArray &in, const QByteArray &key,
                                const QByteArray &ivec, const EVP_CIPHER *ciper)
{
    QByteArray out;
    EVP_CIPHER_CTX *ctx;
    ctx = EVP_CIPHER_CTX_new();
    EVP_CIPHER_CTX_init(ctx);
    // 指定加密算法及key和iv
    int ret =
        EVP_EncryptInit_ex(ctx, ciper, NULL, (const unsigned char *)key.data(),
                           (const unsigned char *)ivec.data());
    if (ret != 1) {
        return "";
    }

    // 进行加密操作
    int mlen = 0;
    out.resize(in.size() + AES_BLOCK_SIZE);
    ret = EVP_EncryptUpdate(ctx, (unsigned char *)out.data(), &mlen,
                            (const unsigned char *)in.data(), in.size());
    if (ret != 1) {
        return "";
    }

    // 结束加密操作
    int flen = 0;
    ret = EVP_EncryptFinal_ex(ctx, (unsigned char *)out.data() + mlen, &flen);
    if (ret != 1) {
        return "";
    }
    out.resize(mlen + flen);
    return out;
}
