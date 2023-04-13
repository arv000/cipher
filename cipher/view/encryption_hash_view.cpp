#include "encryption_hash_view.h"
#include <QLabel>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QRadioButton>
#include <QButtonGroup>
#include <QStackedWidget>
#include "encryption_hash_base_view.h"

#include "tools/abstract_encytion.h"
#include "tools/encytion_md5.h"
#include "tools/encytion_sha256.h"
#include "tools/encytion_sm3.h"

EncryptionHashView::EncryptionHashView(QWidget* parent)
    : QWidget(parent)
    , LayoutMain_(new QVBoxLayout(this))
    , LayoutBtn_(new QHBoxLayout())
    , BtnGroup_(new QButtonGroup(this))
    , RBtnMD5_(new QRadioButton("MD5"))
    , RBtnSha256_(new QRadioButton("SHA256"))
    , RBtnSM3_(new QRadioButton("SM3"))
    , stack_(new QStackedWidget())
    , funMd5_(new EncytionMD5())
    , funSha256_(new EncytionSha256())
    , funSM3_(new EncytionSM3())
{
    init();
}

void EncryptionHashView::init()
{
    initUI();
    initConnect();
}

void EncryptionHashView::initUI()
{
    BtnGroup_->addButton(RBtnMD5_, MD5_VIEW);
    BtnGroup_->addButton(RBtnSha256_, SHA256_VIEW);
    BtnGroup_->addButton(RBtnSM3_, SM3_VIEW);
    LayoutBtn_->addWidget(RBtnMD5_);
    LayoutBtn_->addWidget(RBtnSha256_);
    LayoutBtn_->addWidget(RBtnSM3_);
    RBtnMD5_->setEnabled(true);
    RBtnMD5_->setChecked(true);
    LayoutBtn_->addStretch();
    LayoutMain_->addLayout(LayoutBtn_);

    EncryptionHashBaseView* md5view = new EncryptionHashBaseView(funMd5_);
    EncryptionHashBaseView* sha256view = new EncryptionHashBaseView(funSha256_);
    EncryptionHashBaseView* sm3view = new EncryptionHashBaseView(funSM3_);
    stack_->insertWidget(MD5_VIEW, md5view);
    stack_->insertWidget(SHA256_VIEW, sha256view);
    stack_->insertWidget(SM3_VIEW, sm3view);
    stack_->setCurrentIndex(MD5_VIEW);
    LayoutMain_->addWidget(stack_);
    LayoutMain_->addStretch();

    this->setLayout(LayoutMain_);
}

void EncryptionHashView::initConnect()
{
    connect(BtnGroup_, SIGNAL(buttonClicked(int)), this,
            SLOT(soltClickRadioBtn(int)));
}

void EncryptionHashView::soltClickRadioBtn(int index)
{
    stack_->setCurrentIndex(index);
}
