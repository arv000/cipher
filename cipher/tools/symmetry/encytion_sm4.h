#ifndef ENCYTION_SM4_H
#define ENCYTION_SM4_H

#include <QObject>
#include "abstract_symmetry_encytion.h"
class EncytionSM4 : public AbstractSymmetryEncytion {
    Q_OBJECT
   public:
    explicit EncytionSM4(QObject *parent = nullptr);

   signals:

   public slots:

    // AbstractSymmetryEncytion interface
   public:
    QByteArray EncytonData(const QByteArray &in, const QByteArray &key,
                           const QByteArray &ivec, CIPH_MODE mode);
};

#endif  // ENCYTION_SM4_H
