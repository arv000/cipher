#ifndef ABSTRACT_SYMMETRY_DECRYPT_H
#define ABSTRACT_SYMMETRY_DECRYPT_H

#include <QObject>
#include "common.h"
class AbstractSymmetryDecrypt : public QObject
{
    Q_OBJECT
public:
    explicit AbstractSymmetryDecrypt(QObject *parent = nullptr);

    virtual QByteArray DecryptData(const QByteArray &in, const QByteArray &key,
                                   const QByteArray &ivec, CIPH_MODE mode) = 0;
};

#endif // ABSTRACT_SYMMETRY_DECRYPT_H
