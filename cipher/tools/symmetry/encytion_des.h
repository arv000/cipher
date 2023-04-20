#ifndef ENCYTION_DES_H
#define ENCYTION_DES_H

#include <QObject>
#include "abstract_symmetry_encytion.h"
class EncytionDES : public AbstractSymmetryEncytion {
    Q_OBJECT
   public:
    explicit EncytionDES(QObject *parent = nullptr);

   signals:

   public slots:

    // AbstractSymmetryEncytion interface
   public:
    QByteArray EncytonData(const QByteArray &in, const QByteArray &key,
                           const QByteArray &ivec, CIPH_MODE mode);
};

#endif  // ENCYTION_DES_H
