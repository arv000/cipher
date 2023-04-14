#ifndef SYMMETRIC_ENCRYPTION_VIEW_H
#define SYMMETRIC_ENCRYPTION_VIEW_H

#include <QWidget>
class QLabel;
class QTabWidget;
class EncryptionAESView;
class EncryptionDESView;
class EncryptionSymmetricView : public QWidget {
   public:
    EncryptionSymmetricView(QWidget *parent = nullptr);
    QTabWidget *TabView_;
    EncryptionAESView *AESView_;
    EncryptionDESView *DESView_;
    QLabel *lab_;
};

#endif  // SYMMETRIC_ENCRYPTION_VIEW_H
