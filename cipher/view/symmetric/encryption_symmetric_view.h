#ifndef SYMMETRIC_ENCRYPTION_VIEW_H
#define SYMMETRIC_ENCRYPTION_VIEW_H

#include <QWidget>
#include <QPointer>
class QLabel;
class QTabWidget;
class EncryptionAESView;
class EncryptionDESView;
class EncryptionSM4View;
class EncryptionSymmetricView : public QWidget {
   public:
    EncryptionSymmetricView(QWidget *parent = nullptr);
    QTabWidget *TabView_;
    QPointer<EncryptionAESView> AESView_;
    QPointer<EncryptionDESView> DESView_;
    QPointer<EncryptionSM4View> SM4View_;
    QLabel *lab_;
};

#endif  // SYMMETRIC_ENCRYPTION_VIEW_H
