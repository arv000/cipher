#ifndef ENCYTION_AES_H
#define ENCYTION_AES_H

#include <QObject>
#include "abstract_symmetry_encytion.h"
class EncytionAES : public AbstractSymmetryEncytion {
    Q_OBJECT
   public:
    explicit EncytionAES(QObject *parent = nullptr);

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
};

#endif  // ENCYTION_AES_H
