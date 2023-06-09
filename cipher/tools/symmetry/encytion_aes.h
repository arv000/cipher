#ifndef ENCYTION_AES_H
#define ENCYTION_AES_H

#include <QObject>
#include "abstract_symmetry_encytion.h"
#include <openssl/evp.h>
#define KEY_SIZE_16B 16
#define KEY_SIZE_24B 24
#define KEY_SIZE_32B 32
class EncytionAES : public AbstractSymmetryEncytion {
    Q_OBJECT
   public:
    explicit EncytionAES(QObject *parent = nullptr);
    ~EncytionAES();
   signals:

   public slots:

    // AbstractSymmetryEncytion interface
   public:
    QByteArray EncytonData(const QByteArray &in, const QByteArray &key,
                           const QByteArray &ivec, CIPH_MODE mode) override;

   private:
    QByteArray EncytonDataECB(const QByteArray &in, const QByteArray &key,
                              const QByteArray &ivec);
    QByteArray EncytonDataCBC(const QByteArray &in, const QByteArray &key,
                              const QByteArray &ivec);
    QByteArray EncytonDataCFB(const QByteArray &in, const QByteArray &key,
                              const QByteArray &ivec);
    QByteArray EncytonDataOFB(const QByteArray &in, const QByteArray &key,
                              const QByteArray &ivec);
    QByteArray EncytonDataCTR(const QByteArray &in, const QByteArray &key,
                              const QByteArray &ivec);
    QByteArray EncytonDataGCM(const QByteArray &in, const QByteArray &key,
                              const QByteArray &ivec);
    QByteArray EncytonDataCCM(const QByteArray &in, const QByteArray &key,
                              const QByteArray &ivec);
    QByteArray EncytonDataXTS(const QByteArray &in, const QByteArray &key,
                              const QByteArray &ivec);
    QByteArray EncytonDataOCB(const QByteArray &in, const QByteArray &key,
                              const QByteArray &ivec);
    QByteArray Encyton(const QByteArray &in, const QByteArray &key,
                       const QByteArray &ivec, const EVP_CIPHER *ciper);
};

#endif  // ENCYTION_AES_H
