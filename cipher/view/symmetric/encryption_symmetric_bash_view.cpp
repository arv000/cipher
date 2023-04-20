#include "encryption_symmetric_bash_view.h"
#include "encryption_aes_data_view.h"
#include "encryption_aes_file_view.h"
#include <QTabWidget>
EncryptionSymmetricBaseView::EncryptionSymmetricBaseView(
    AbstractSymmetryEncytion *encytion)
    : TabView_(new QTabWidget(this))
    , AESDataView_(new EncryptionAESDataView(encytion))
    , AESFileView_(new EncryptionAESFileView(encytion))
{
    TabView_->addTab(AESDataView_, "数据加密");
    TabView_->addTab(AESFileView_, "文件加密");
    TabView_->resize(800, 600);
}
