#include "encryption_aes_file_view.h"

#include <QDebug>
EncryptionAESFileView::EncryptionAESFileView(AbstractSymmetryEncytion *encytion)
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
    , LayoutBtn_(new QHBoxLayout)
    , labMingwen_(new QLabel("文件："))
    , BtnSelectFile_(new QPushButton("选择文件"))
    , LEdtMingwen_(new QLineEdit)
    , LayoutMingwen_(new QHBoxLayout)
    , TEdtMiwen_(new QTextEdit)
{
    init();
}

void EncryptionAESFileView::init()
{
    initUI();
    initConnect();
}

void EncryptionAESFileView::initUI()
{
    LayoutPassWord_->addWidget(labPassWord_, 0, 0);
    LayoutPassWord_->addWidget(labConfirmPassWord_, 1, 0);
    LayoutPassWord_->addWidget(LEdtPassWord_, 0, 1);
    LayoutPassWord_->addWidget(LEdtConfirmPassWord_, 1, 1);

    LayoutPassWord_->addWidget(labAlgorithm_, 2, 0);
    LayoutPassWord_->addWidget(CBBAlgorithm_, 2, 1);
    ADD_ITEM(CIPH_MODE_ECB_128);
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
    LayoutMingwen_->addWidget(BtnSelectFile_);
    LayoutMain_->addLayout(LayoutPassWord_);
    LayoutMain_->addLayout(LayoutBtn_);

    LayoutMain_->addLayout(LayoutMingwen_);
    LayoutMain_->addWidget(TEdtMiwen_);
    LayoutMain_->addStretch();
    setLayout(LayoutMain_);
}
void EncryptionAESFileView::initConnect()
{
    connect(BtnSelectFile_, &QPushButton::clicked, this,
            &EncryptionAESFileView::slotSelectFile);
    connect(BtnDecrypt_, &QPushButton::clicked, this,
            &EncryptionAESFileView::slotDoDecrypt);
}

void EncryptionAESFileView::slotSelectFile() {}

void EncryptionAESFileView::slotDoDecrypt() {}
