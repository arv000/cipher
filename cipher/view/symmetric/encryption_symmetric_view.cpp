#include "encryption_symmetric_view.h"
#include <QLabel>
#include <QTabWidget>
#include "encryption_symmetric_bash_view.h"
#include "encryption_des_view.h"

#include "tools/symmetry/encytion_aes.h"
#include "tools/symmetry/encytion_des.h"
#include "tools/symmetry/encytion_sm4.h"

EncryptionSymmetricView::EncryptionSymmetricView(QWidget *parent)
    : QWidget(parent)
    , TabView_(new QTabWidget(this))
    , encytionAES_(new EncytionAES)
    , encytionDES_(new EncytionDES)
    , AESView_(new EncryptionSymmetricBaseView(encytionAES_))
    , DESView_(new EncryptionSymmetricBaseView(encytionDES_))

{
    TabView_->addTab(AESView_, "AES");
    TabView_->addTab(DESView_, "DES");

    TabView_->setTabShape(QTabWidget::Triangular);
    TabView_->resize(1800, 1600);
}
