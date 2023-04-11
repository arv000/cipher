#include "encryption_hash_view.h"
#include <QLabel>
EncryptionHashView::EncryptionHashView(QWidget *parent)
    : QWidget(parent)
    , lab_(new QLabel("asdf2", this))
{
}
