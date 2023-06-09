#ifndef ABSTRACT_SYMMETRY_ENCYTION_H
#define ABSTRACT_SYMMETRY_ENCYTION_H

#include <QObject>
#include "common.h"

class AbstractSymmetryEncytion : public QObject {
    Q_OBJECT
   public:
    explicit AbstractSymmetryEncytion(QObject *parent = nullptr);
    /**
     * @brief EncytonData
     * @param in
     * @param key
     * @param ivec
     * @return
     */
    virtual QByteArray EncytonData(const QByteArray &in, const QByteArray &key,
                                   const QByteArray &ivec, CIPH_MODE mode) = 0;
};

#endif  // ABSTRACT_SYMMETRY_ENCYTION_H
