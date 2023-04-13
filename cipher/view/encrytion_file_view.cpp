#include "encrytion_file_view.h"
#include "tools/abstract_encytion.h"
#include "tools/encytion_file_job.h"
#include <QPushButton>
#include <QFileDialog>
#include <QLineEdit>
#include <QTextEdit>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QDebug>
EncrytionFileView::EncrytionFileView(AbstractEncytion *encytion)
    : encytionJob_(new EncytionFileJob(encytion))
    , LayoutMain_(new QVBoxLayout())
    , LayoutFile_(new QHBoxLayout())
    , BtnFileSelect_(new QPushButton("选择文件"))
    , BtnDoWork_(new QPushButton("加密"))
    , LineEditFilePath_(new QLineEdit)
    , TextEditResoult_(new QTextEdit)

{
    init();
}

void EncrytionFileView::init()
{
    initUI();
    initConnect();
}

void EncrytionFileView::initUI()
{
    LayoutFile_->addWidget(LineEditFilePath_);
    LayoutFile_->addWidget(BtnFileSelect_);
    LayoutMain_->addLayout(LayoutFile_);
    LayoutMain_->addWidget(TextEditResoult_);
    LayoutMain_->addWidget(BtnDoWork_);
    setLayout(LayoutMain_);
}

void EncrytionFileView::initConnect()
{
    connect(BtnFileSelect_, &QPushButton::clicked, this,
            &EncrytionFileView::slotSelectFilePath);
    connect(encytionJob_, &EncytionFileJob::sigFinish, this,
            &EncrytionFileView::slotEncrytionFinish);
    connect(BtnDoWork_, &QPushButton::clicked, this,
            &EncrytionFileView::slotDoWork);
}

void EncrytionFileView::slotSelectFilePath()
{
    QString fileName = QFileDialog::getOpenFileName(this, tr("文件选取"), "/",
                                                    tr("文本文件(*txt)"));
    LineEditFilePath_->setText(fileName);
}

void EncrytionFileView::slotDoWork()
{
    encytionJob_->setData(LineEditFilePath_->text());
    encytionJob_->start();
}

void EncrytionFileView::slotEncrytionFinish(QString out)
{
    qInfo() << out;
    TextEditResoult_->setText(out);
}
