#include "encytion_aes.h"
#include <openssl/aes.h>
#include <openssl/evp.h>
#include <QDebug>
EncytionAES::EncytionAES(QObject *parent)
    : AbstractSymmetryEncytion()
{
}

EncytionAES::~EncytionAES() {}

QByteArray EncytionAES::EncytonData(const QByteArray &in, const QByteArray &key,
                                    const QByteArray &ivec, CIPH_MODE mode)
{
    qInfo() << "EncytionAES:EncytonData";
    switch (mode) {
        case CIPH_MODE_ECB_128:
        case CIPH_MODE_ECB_192:
        case CIPH_MODE_ECB_256:
            return EncytonDataECB(in, key, ivec);
        case CIPH_MODE_CBC_128:
        case CIPH_MODE_CBC_192:
        case CIPH_MODE_CBC_256:
            return EncytonDataCBC(in, key, ivec);
        case CIPH_MODE_CFB_128:
        case CIPH_MODE_CFB_192:
        case CIPH_MODE_CFB_256:
            return EncytonDataCFB(in, key, ivec);
        case CIPH_MODE_OFB_128:
        case CIPH_MODE_OFB_192:
        case CIPH_MODE_OFB_256:
            return EncytonDataOFB(in, key, ivec);
        case CIPH_MODE_CTR_128:
        case CIPH_MODE_CTR_192:
        case CIPH_MODE_CTR_256:
            return EncytonDataCTR(in, key, ivec);
        case CIPH_MODE_GCM_128:
        case CIPH_MODE_GCM_192:
        case CIPH_MODE_GCM_256:
            return EncytonDataGCM(in, key, ivec);
        case CIPH_MODE_CCM_128:
        case CIPH_MODE_CCM_192:
        case CIPH_MODE_CCM_256:
            return EncytonDataCCM(in, key, ivec);
        case CIPH_MODE_XTS_128:
        case CIPH_MODE_XTS_256:
            return EncytonDataXTS(in, key, ivec);
        case CIPH_MODE_OCB_128:
        case CIPH_MODE_OCB_192:
        case CIPH_MODE_OCB_256:
            return EncytonDataCCM(in, key, ivec);
    }
    return "";
}

QByteArray EncytionAES::EncytonDataECB(const QByteArray &in,
                                       const QByteArray &key,
                                       const QByteArray &ivec)
{
    const EVP_CIPHER *cipher = nullptr;
    if (key.size() == KEY_SIZE_16B) {
        cipher = EVP_aes_128_ecb();
    } else if (key.size() == KEY_SIZE_24B) {
        cipher = EVP_aes_192_ecb();
    } else {
        cipher = EVP_aes_256_ecb();
    }
    return Encyton(in, key, ivec, cipher);
}

QByteArray EncytionAES::EncytonDataCBC(const QByteArray &in,
                                       const QByteArray &key,
                                       const QByteArray &ivec)
{
    const EVP_CIPHER *cipher = nullptr;
    if (key.size() == KEY_SIZE_16B) {
        cipher = EVP_aes_128_cbc();
    } else if (key.size() == KEY_SIZE_24B) {
        cipher = EVP_aes_192_cbc();
    } else {
        cipher = EVP_aes_256_cbc();
    }
    return Encyton(in, key, ivec, cipher);
}

QByteArray EncytionAES::EncytonDataCFB(const QByteArray &in,
                                       const QByteArray &key,
                                       const QByteArray &ivec)
{
    const EVP_CIPHER *cipher = nullptr;
    if (key.size() == KEY_SIZE_16B) {
        cipher = EVP_aes_128_cfb1();
    } else if (key.size() == KEY_SIZE_24B) {
        cipher = EVP_aes_192_cfb1();
    } else {
        cipher = EVP_aes_256_cfb1();
    }
    return Encyton(in, key, ivec, cipher);
}

QByteArray EncytionAES::EncytonDataOFB(const QByteArray &in,
                                       const QByteArray &key,
                                       const QByteArray &ivec)
{
    const EVP_CIPHER *cipher = nullptr;
    if (key.size() == KEY_SIZE_16B) {
        cipher = EVP_aes_128_cfb1();
    } else if (key.size() == KEY_SIZE_24B) {
        cipher = EVP_aes_192_cfb1();
    } else {
        cipher = EVP_aes_256_cfb1();
    }
    return Encyton(in, key, ivec, cipher);
}

QByteArray EncytionAES::EncytonDataCTR(const QByteArray &in,
                                       const QByteArray &key,
                                       const QByteArray &ivec)
{
    const EVP_CIPHER *cipher = nullptr;
    if (key.size() == KEY_SIZE_16B) {
        cipher = EVP_aes_128_ctr();
    } else if (key.size() == KEY_SIZE_24B) {
        cipher = EVP_aes_192_ctr();
    } else {
        cipher = EVP_aes_256_ctr();
    }
    return Encyton(in, key, ivec, cipher);
}

QByteArray EncytionAES::EncytonDataGCM(const QByteArray &in,
                                       const QByteArray &key,
                                       const QByteArray &ivec)
{
    const EVP_CIPHER *cipher = nullptr;
    if (key.size() == KEY_SIZE_16B) {
        cipher = EVP_aes_128_gcm();
    } else if (key.size() == KEY_SIZE_24B) {
        cipher = EVP_aes_192_gcm();
    } else {
        cipher = EVP_aes_256_gcm();
    }
    return Encyton(in, key, ivec, cipher);
}

QByteArray EncytionAES::EncytonDataCCM(const QByteArray &in,
                                       const QByteArray &key,
                                       const QByteArray &ivec)
{
    const EVP_CIPHER *cipher = nullptr;
    if (key.size() == KEY_SIZE_16B) {
        cipher = EVP_aes_128_gcm();
    } else if (key.size() == KEY_SIZE_24B) {
        cipher = EVP_aes_192_gcm();
    } else {
        cipher = EVP_aes_256_gcm();
    }
    return Encyton(in, key, ivec, cipher);
}
QByteArray EncytionAES::EncytonDataXTS(const QByteArray &in,
                                       const QByteArray &key,
                                       const QByteArray &ivec)
{
    const EVP_CIPHER *cipher = nullptr;
    if (key.size() == KEY_SIZE_16B) {
        cipher = EVP_aes_128_xts();
    } else {
        cipher = EVP_aes_256_xts();
    }
    return Encyton(in, key, ivec, cipher);
}

QByteArray EncytionAES::EncytonDataOCB(const QByteArray &in,
                                       const QByteArray &key,
                                       const QByteArray &ivec)
{
    const EVP_CIPHER *cipher = nullptr;
    if (key.size() == KEY_SIZE_16B) {
        cipher = EVP_aes_128_ocb();
    } else if (key.size() == KEY_SIZE_24B) {
        cipher = EVP_aes_192_ocb();
    } else {
        cipher = EVP_aes_256_ocb();
    }
    return Encyton(in, key, ivec, cipher);
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
