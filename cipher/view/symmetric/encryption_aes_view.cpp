#include "encryption_aes_view.h"
#include "encryption_aes_data_view.h"
#include "encryption_aes_file_view.h"
#include <QTabWidget>
EncryptionAESView::EncryptionAESView(QWidget *parent)
    : QWidget(parent)
    , TabView_(new QTabWidget(this))
    , AESDataView_(new EncryptionAESDataView())
    , AESFileView_(new EncryptionAESFileView())
{
    TabView_->addTab(AESDataView_, "数据加密");
    TabView_->addTab(AESFileView_, "文件加密");
    TabView_->resize(800, 600);
}
