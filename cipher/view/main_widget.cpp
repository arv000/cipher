#include "main_widget.h"
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QStackedWidget>
#include <QDebug>
#include "asymmetric/encryption_asymmetric_view.h"
#include "hash/encryption_hash_view.h"
#include "symmetric/encryption_symmetric_view.h"

MainWidget::MainWidget(QWidget *parent)
    : QWidget(parent)
    , BtnSymmetricEncryption_(new QPushButton("对称加密"))
    , BtnAsymmetricEncryption_(new QPushButton("非对称加密"))
    , BtnHash_(new QPushButton("Hash值计算"))
    , BtnCertificate_(new QPushButton("证书管理"))
    , LayoutMain_(new QHBoxLayout())
    , LayoutBts_(new QVBoxLayout())
    , StackedWidget_(new QStackedWidget(this))
    , encryptionAsymmetricView_(new EncryptionAsymmetricView())
    , encryptionSymmetricView_(new EncryptionSymmetricView())
    , encryptionHashView_(new EncryptionHashView())
{
    init();
}

void MainWidget::initConnect()
{
    connect(BtnSymmetricEncryption_, &QPushButton::clicked, this,
            &MainWidget::slotOpenSymmetricEncryptionView);
    connect(BtnAsymmetricEncryption_, &QPushButton::clicked, this,
            &MainWidget::slotOpenAsymmetricEncryptionView);
    connect(BtnHash_, &QPushButton::clicked, this,
            &MainWidget::slotOpenHashView);
}

void MainWidget::initUI()
{
    LayoutBts_->addWidget(BtnSymmetricEncryption_);
    LayoutBts_->addWidget(BtnAsymmetricEncryption_);
    LayoutBts_->addWidget(BtnHash_);
    LayoutBts_->addWidget(BtnCertificate_);
    LayoutBts_->addStretch();

    LayoutMain_->addLayout(LayoutBts_);

    StackedWidget_->addWidget(encryptionSymmetricView_);
    StackedWidget_->addWidget(encryptionAsymmetricView_);
    StackedWidget_->addWidget(encryptionHashView_);
    LayoutMain_->addWidget(StackedWidget_);

    setLayout(LayoutMain_);
}

void MainWidget::init()
{
    initUI();
    initConnect();
}

void MainWidget::slotOpenSymmetricEncryptionView()
{
    StackedWidget_->setCurrentIndex(0);
    qInfo() << "slotOpenSymmetricEncryptionView";
}

void MainWidget::slotOpenAsymmetricEncryptionView()
{
    StackedWidget_->setCurrentIndex(1);
    qInfo() << "slotOpenAsymmetricEncryptionView";
}

void MainWidget::slotOpenHashView()
{
    StackedWidget_->setCurrentIndex(2);
    qInfo() << "slotOpenHashView";
}
