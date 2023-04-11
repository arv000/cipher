#ifndef SYMMETRIC_ENCRYPTION_VIEW_H
#define SYMMETRIC_ENCRYPTION_VIEW_H

#include <QWidget>
class QLabel;
class EncryptionSymmetricView : public QWidget {
   public:
    EncryptionSymmetricView(QWidget *parent = nullptr);
    QLabel *lab_;
};

#endif  // SYMMETRIC_ENCRYPTION_VIEW_H
