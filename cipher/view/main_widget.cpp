#include "main_widget.h"
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QStackedWidget>
#include <QDebug>
MainWidget::MainWidget(QWidget *parent)
    : QWidget(parent)
    , BtnSymmetricEncryption_(new QPushButton("对称加密"))
    , BtnAsymmetricEncryption_(new QPushButton("非对称加密"))
    , BtnHash_(new QPushButton("Hash值计算"))
    , LayoutMain_(new QHBoxLayout())
    , LayoutBts_(new QVBoxLayout())
    , StackedWidget_(new QStackedWidget(this))
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
    LayoutBts_->addStretch();

    LayoutMain_->addLayout(LayoutBts_);
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
    qInfo() << "slotOpenSymmetricEncryptionView";
}

void MainWidget::slotOpenAsymmetricEncryptionView()
{
    qInfo() << "slotOpenAsymmetricEncryptionView";
}

void MainWidget::slotOpenHashView() { qInfo() << "slotOpenHashView"; }
