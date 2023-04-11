#include "encrytion_data_view.h"
#include <QTextEdit>
#include <QPushButton>
#include <QVBoxLayout>
#include "tools/abstract_encytion.h"
#include "tools/encytion_md5.h"
EncrytionDataView::EncrytionDataView(AbstractEncytion *encytion)
    : encytion_(encytion)
    , TxtEditMingWen_(new QTextEdit)
    , TxtEditMiWen_(new QTextEdit)
    , BtnDoWork_(new QPushButton("加密"))
    , LayoutMain_(new QVBoxLayout)
{
    init();
}

void EncrytionDataView::init()
{
    initUI();
    initConnect();
}

void EncrytionDataView::initUI()
{
    LayoutMain_->addWidget(TxtEditMingWen_);
    LayoutMain_->addWidget(BtnDoWork_);
    LayoutMain_->addWidget(TxtEditMiWen_);
    setLayout(LayoutMain_);
}

void EncrytionDataView::initConnect()
{
    connect(BtnDoWork_, &QPushButton::clicked, this,
            &EncrytionDataView::slotClickDoWork);
}

void EncrytionDataView::slotClickDoWork()
{
    encytion_->EncytonData("slotClickDoWork");
}
