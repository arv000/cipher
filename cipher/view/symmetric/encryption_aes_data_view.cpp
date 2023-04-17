#include "encryption_aes_data_view.h"
#include "tools/symmetry/abstract_symmetry_encytion.h"
#include <QDebug>
EncryptionAESDataView::EncryptionAESDataView(QWidget *parent)
    : QWidget(parent)
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
    , LayoutBtn_(new QHBoxLayout)
    , labMingwen_(new QLabel("明文："))
    , LEdtMingwen_(new QLineEdit)
    , LayoutMingwen_(new QHBoxLayout)
    , TEdtMiwen_(new QTextEdit)
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

    CBBAlgorithm_->addItem(
        "AES_ECB", QVariant::fromValue(static_cast<int>(CIPH_MODE_ECB)));
    CBBAlgorithm_->addItem(
        "AES_CBC", QVariant::fromValue(static_cast<int>(CIPH_MODE_CBC)));
    CBBAlgorithm_->addItem(
        "AES_CFB", QVariant::fromValue(static_cast<int>(CIPH_MODE_CFB)));
    CBBAlgorithm_->addItem(
        "AES_OFB", QVariant::fromValue(static_cast<int>(CIPH_MODE_OFB)));
    CBBAlgorithm_->addItem(
        "AES_CTR", QVariant::fromValue(static_cast<int>(CIPH_MODE_CTR)));
    CBBAlgorithm_->addItem(
        "AES_GCM", QVariant::fromValue(static_cast<int>(CIPH_MODE_GCM)));
    CBBAlgorithm_->addItem(
        "AES_CCM", QVariant::fromValue(static_cast<int>(CIPH_MODE_CCM)));

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
}

void EncryptionAESDataView::slotDoEncytion()
{
    ;
    qInfo() << "slotDoEncytion"
            << CBBAlgorithm_->itemData(CBBAlgorithm_->currentIndex()).toInt();
}

void EncryptionAESDataView::slotDoDecrypt() { qInfo() << "slotDoDecrypt"; }
