#include "encrytion_data_view.h"
#include <QTextEdit>
#include <QPushButton>
#include <QVBoxLayout>
#include "tools/hash/abstract_encytion.h"
#include "tools/hash/encytion_md5.h"
#include "tools/hash/encytion_data_job.h"
#include <QDebug>
EncrytionDataView::EncrytionDataView(AbstractHashEncytion *encytion)
    : encytionJob_(new EncytionDataJob(encytion))
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
    connect(encytionJob_, &EncytionDataJob::sigFinish, this,
            &EncrytionDataView::slotEncrytionFinish);
}

void EncrytionDataView::slotClickDoWork()
{
    qInfo() << " EncrytionDataView::slotClickDoWork";
    encytionJob_->setData(TxtEditMingWen_->toPlainText());
    encytionJob_->start();
}

void EncrytionDataView::slotEncrytionFinish(QString out)
{
    TxtEditMiWen_->setText(out);
    qInfo() << "out:" << out;
}
