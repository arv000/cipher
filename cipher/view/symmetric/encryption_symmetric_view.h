#ifndef SYMMETRIC_ENCRYPTION_VIEW_H
#define SYMMETRIC_ENCRYPTION_VIEW_H

#include <QWidget>
#include <QPointer>
class QLabel;
class QTabWidget;
class EncryptionSymmetricBaseView;

class EncytionAES;
class EncytionDES;
class EncytionSM4;

class EncryptionSymmetricView : public QWidget {
   public:
    EncryptionSymmetricView(QWidget *parent = nullptr);
    QTabWidget *TabView_;

    QPointer<EncytionAES> encytionAES_;
    QPointer<EncytionDES> encytionDES_;
    QPointer<EncytionSM4> encytionSM4_;

    QPointer<EncryptionSymmetricBaseView> AESView_;
    QPointer<EncryptionSymmetricBaseView> DESView_;
    QPointer<EncryptionSymmetricBaseView> SM4View_;
    QLabel *lab_;
};

#endif  // SYMMETRIC_ENCRYPTION_VIEW_H
