#ifndef COMMON_H
#define COMMON_H
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

#define ADD_ITEM(NAME) \
    CBBAlgorithm_->addItem(#NAME, QVariant::fromValue(static_cast<int>(NAME)));

#endif // COMMON_H