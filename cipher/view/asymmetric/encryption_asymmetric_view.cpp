#include "encryption_asymmetric_view.h"
#include <QLabel>
EncryptionAsymmetricView::EncryptionAsymmetricView(QWidget *parent)
    : QWidget(parent)
    , lab_(new QLabel("asdf1", this))
{
}
