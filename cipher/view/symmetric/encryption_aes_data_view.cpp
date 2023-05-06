#include "encryption_aes_data_view.h"
#include "tools/hash/encytion_sha256.h"
#include <tools/tools.h>
#include <QDebug>
EncryptionAESDataView::EncryptionAESDataView(AbstractSymmetryEncytion *encytion)
    : EncytionJob_(new SymmetryEncytionJob(encytion))
    , labPassWord_(new QLabel("密码", this))
    , labConfirmPassWord_(new QLabel("确认密码", this))
    , LEdtPassWord_(new QLineEdit())
    , LEdtConfirmPassWord_(new QLineEdit())
    , CBBAlgorithm_(new QComboBox())
    , labAlgorithm_(new QLabel("算法选择"))
    , LayoutPassWord_(new QGridLayout())
    , LayoutMain_(new QVBoxLayout())
    , BtnEncytion_(new QPushButton("加密"))
    , BtnDecrypt_(new QPushButton("解密"))
    , LayoutBtn_(new QHBoxLayout())
    , labMingwen_(new QLabel("明文："))
    , LEdtMingwen_(new QLineEdit())
    , LayoutMingwen_(new QHBoxLayout())
    , TEdtMiwen_(new QTextEdit())
{
    init();
}

void EncryptionAESDataView::init()
{
    initUI();
    initConnect();
}

void EncryptionAESDataView::initUI()
{
    LayoutPassWord_->addWidget(labPassWord_, 0, 0);
    LayoutPassWord_->addWidget(labConfirmPassWord_, 1, 0);
    LayoutPassWord_->addWidget(LEdtPassWord_, 0, 1);
    LayoutPassWord_->addWidget(LEdtConfirmPassWord_, 1, 1);

    LayoutPassWord_->addWidget(labAlgorithm_, 2, 0);
    LayoutPassWord_->addWidget(CBBAlgorithm_, 2, 1);
    ADD_ITEM(CIPH_MODE_CBC_128);
    ADD_ITEM(CIPH_MODE_ECB_128);
    ADD_ITEM(CIPH_MODE_ECB_192);
    ADD_ITEM(CIPH_MODE_ECB_256);
    ADD_ITEM(CIPH_MODE_CBC_128);
    ADD_ITEM(CIPH_MODE_CBC_192);
    ADD_ITEM(CIPH_MODE_CBC_256);
    ADD_ITEM(CIPH_MODE_CFB_128);
    ADD_ITEM(CIPH_MODE_CFB_192);
    ADD_ITEM(CIPH_MODE_CFB_256);
    ADD_ITEM(CIPH_MODE_OFB_128);
    ADD_ITEM(CIPH_MODE_OFB_192);
    ADD_ITEM(CIPH_MODE_OFB_256);
    ADD_ITEM(CIPH_MODE_CTR_128);
    ADD_ITEM(CIPH_MODE_CTR_192);
    ADD_ITEM(CIPH_MODE_CTR_256);
    ADD_ITEM(CIPH_MODE_GCM_128);
    ADD_ITEM(CIPH_MODE_GCM_192);
    ADD_ITEM(CIPH_MODE_GCM_256);
    ADD_ITEM(CIPH_MODE_CCM_128);
    ADD_ITEM(CIPH_MODE_CCM_192);
    ADD_ITEM(CIPH_MODE_CCM_256);
    ADD_ITEM(CIPH_MODE_XTS_128);
    ADD_ITEM(CIPH_MODE_XTS_256);
    ADD_ITEM(CIPH_MODE_OCB_128);
    ADD_ITEM(CIPH_MODE_OCB_192);
    ADD_ITEM(CIPH_MODE_OCB_256);

    LEdtPassWord_->setEchoMode(QLineEdit::EchoMode::Password);
    LEdtConfirmPassWord_->setEchoMode(QLineEdit::EchoMode::Password);
    LayoutBtn_->addStretch();
    LayoutBtn_->addWidget(BtnEncytion_);
    LayoutBtn_->addWidget(BtnDecrypt_);

    LayoutMingwen_->addWidget(labMingwen_);
    LayoutMingwen_->addWidget(LEdtMingwen_);

    LayoutMain_->addLayout(LayoutPassWord_);
    LayoutMain_->addLayout(LayoutBtn_);
    LayoutMain_->addLayout(LayoutMingwen_);
    LayoutMain_->addWidget(TEdtMiwen_);
    LayoutMain_->addStretch();
    setLayout(LayoutMain_);
}
void EncryptionAESDataView::initConnect()
{
    connect(BtnEncytion_, &QPushButton::clicked, this,
            &EncryptionAESDataView::slotDoEncytion);
    connect(BtnDecrypt_, &QPushButton::clicked, this,
            &EncryptionAESDataView::slotDoDecrypt);
    connect(EncytionJob_, &SymmetryEncytionJob::sigFinish, this,
            &EncryptionAESDataView::slotDoEncytionFinish);
}

QByteArray EncryptionAESDataView::getKey(QByteArray key)
{
    CIPH_MODE sel = static_cast<CIPH_MODE>(
        CBBAlgorithm_->itemData(CBBAlgorithm_->currentIndex()).toInt());
    switch (sel) {
        case CIPH_MODE_ECB_128:
        case CIPH_MODE_CBC_128:
        case CIPH_MODE_CFB_128:
        case CIPH_MODE_OFB_128:
        case CIPH_MODE_CTR_128:
        case CIPH_MODE_GCM_128:
        case CIPH_MODE_CCM_128:
        case CIPH_MODE_XTS_128:
        case CIPH_MODE_OCB_128:
            return getKey128(key);
        case CIPH_MODE_ECB_192:
        case CIPH_MODE_CBC_192:
        case CIPH_MODE_CFB_192:
        case CIPH_MODE_OFB_192:
        case CIPH_MODE_CTR_192:
        case CIPH_MODE_GCM_192:
        case CIPH_MODE_CCM_192:
        case CIPH_MODE_OCB_192:
            return getKey192(key);
        case CIPH_MODE_ECB_256:
        case CIPH_MODE_CBC_256:
        case CIPH_MODE_CFB_256:
        case CIPH_MODE_OFB_256:
        case CIPH_MODE_CTR_256:
        case CIPH_MODE_GCM_256:
        case CIPH_MODE_CCM_256:
        case CIPH_MODE_XTS_256:
        case CIPH_MODE_OCB_256:
            return getKey256(key);
    }
    return "";
}

QByteArray EncryptionAESDataView::getKey128(QByteArray key) { return key; }

QByteArray EncryptionAESDataView::getKey192(QByteArray key) { return key; }

QByteArray EncryptionAESDataView::getKey256(QByteArray key)
{
    EncytionSha256 sha;
    QByteArray key_res = sha.EncytonData(QString(key));
    return key_res;
}

void EncryptionAESDataView::slotDoEncytion()
{
    qInfo() << "slotDoEncytion"
            << CBBAlgorithm_->itemData(CBBAlgorithm_->currentIndex()).toInt();
    QByteArray key = getKey(LEdtPassWord_->text().toLocal8Bit());
    EncytionJob_->setData(
        LEdtMingwen_->text().toLatin1(), key, "aafd",
        static_cast<CIPH_MODE>(
            CBBAlgorithm_->itemData(CBBAlgorithm_->currentIndex()).toInt()));
    EncytionJob_->start();
}
void EncryptionAESDataView::slotDoDecrypt() { qInfo() << "slotDoDecrypt"; }

void EncryptionAESDataView::slotDoDecryptFinish(QByteArray res)
{

}

void EncryptionAESDataView::slotDoEncytionFinish(QByteArray res) {
   QString str = Tools::QBarrayToHex(res,res.length());
   TEdtMiwen_->setText(str);
}


