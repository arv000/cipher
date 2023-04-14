#include "encryption_symmetric_view.h"
#include <QLabel>
#include <QTabWidget>
#include "encryption_aes_view.h"
#include "encryption_des_view.h"
EncryptionSymmetricView::EncryptionSymmetricView(QWidget *parent)
    : QWidget(parent)
    , TabView_(new QTabWidget(this))
    , AESView_(new EncryptionAESView(TabView_))
    , DESView_(new EncryptionDESView(TabView_))
{
    TabView_->addTab(AESView_, "AES");
    TabView_->addTab(DESView_, "DES");
    TabView_->setTabShape(QTabWidget::Triangular);
    TabView_->resize(1800, 1600);
}
