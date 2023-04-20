#ifndef ABSTRACT_SYMMETRY_ENCYTION_H
#define ABSTRACT_SYMMETRY_ENCYTION_H

#include <QObject>
enum CIPH_MODE {
    CIPH_MODE_ECB_128 = 0,
    CIPH_MODE_ECB_192,
    CIPH_MODE_ECB_256,
    CIPH_MODE_CBC_128,
    CIPH_MODE_CBC_192,
    CIPH_MODE_CBC_256,
    CIPH_MODE_CFB_128,
    CIPH_MODE_CFB_192,
    CIPH_MODE_CFB_256,
    CIPH_MODE_OFB_128,
    CIPH_MODE_OFB_192,
    CIPH_MODE_OFB_256,
    CIPH_MODE_CTR_128,
    CIPH_MODE_CTR_192,
    CIPH_MODE_CTR_256,
    CIPH_MODE_GCM_128,
    CIPH_MODE_GCM_192,
    CIPH_MODE_GCM_256,
    CIPH_MODE_CCM_128,
    CIPH_MODE_CCM_192,
    CIPH_MODE_CCM_256,
    CIPH_MODE_XTS_128,
    CIPH_MODE_XTS_256,
    CIPH_MODE_OCB_128,
    CIPH_MODE_OCB_192,
    CIPH_MODE_OCB_256
};
// int CIPH_MODE_ARRAY[] = {CIPH_MODE_ECB, CIPH_MODE_CBC, CIPH_MODE_CFB,
//                         CIPH_MODE_OFB, CIPH_MODE_CTR, CIPH_MODE_GCM,
//                         CIPH_MODE_CCM, CIPH_MODE_OCB};

#define ADD_ITEM(NAME) \
    CBBAlgorithm_->addItem(#NAME, QVariant::fromValue(static_cast<int>(NAME)));

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
