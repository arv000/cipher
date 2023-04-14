
#include "encryption_hash_base_view.h"
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QStackedWidget>
#include "tools/hash/abstract_encytion.h"
#include "encrytion_data_view.h"
#include "encrytion_file_view.h"
EncryptionHashBaseView::EncryptionHashBaseView(AbstractHashEncytion *encytion)
    : DataBtn_(new QPushButton("数据加密"))
    , FileBtn_(new QPushButton("文件加密"))
    , LayoutBtn_(new QHBoxLayout)
    , LayoutMain_(new QVBoxLayout)
    , DataView_(new EncrytionDataView(encytion))
    , fileView_(new EncrytionFileView(encytion))
    , stack_(new QStackedWidget())
{
    init();
}

void EncryptionHashBaseView::init()
{
    initUI();
    initConnect();
}

void EncryptionHashBaseView::initConnect()
{
    connect(DataBtn_, &QPushButton::clicked, this,
            &EncryptionHashBaseView::slotClickDataBtn);
    connect(FileBtn_, &QPushButton::clicked, this,
            &EncryptionHashBaseView::slotClickFileBtn);
}

void EncryptionHashBaseView::slotClickDataBtn() { stack_->setCurrentIndex(0); }

void EncryptionHashBaseView::slotClickFileBtn() { stack_->setCurrentIndex(1); }

void EncryptionHashBaseView::initUI()
{
    LayoutBtn_->addWidget(DataBtn_);
    LayoutBtn_->addWidget(FileBtn_);

    stack_->addWidget(DataView_);
    stack_->addWidget(fileView_);

    LayoutMain_->addLayout(LayoutBtn_);
    LayoutMain_->addWidget(stack_);
    LayoutMain_->addStretch();
    setLayout(LayoutMain_);
}
