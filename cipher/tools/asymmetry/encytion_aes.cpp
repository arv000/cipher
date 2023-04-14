#include "encytion_aes.h"

EncytionAES::EncytionAES(QObject *parent)
    : AbstractSymmetryEncytion(parent)
{
}

QByteArray EncytionAES::EncytonData(const QByteArray &in, const QByteArray &key,
                                    const QByteArray &ivec, CIPH_MODE mode)
{
    return "";
}

QByteArray EncytionAES::EncytonDataECB(const QByteArray &in,
                                       const QByteArray &key,
                                       const QByteArray &ivec)
{
    return "";
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
