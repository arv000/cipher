#ifndef ENCRYPTION_AES_VIEW_H
#define ENCRYPTION_AES_VIEW_H

#include <QWidget>
class QTabWidget;
class EncryptionAESDataView;
class EncryptionAESFileView;
class AbstractSymmetryEncytion;
class EncryptionSymmetricBaseView : public QWidget {
    Q_OBJECT
   public:
    explicit EncryptionSymmetricBaseView(AbstractSymmetryEncytion *encytion);
    QTabWidget *TabView_;
    EncryptionAESDataView *AESDataView_;
    EncryptionAESFileView *AESFileView_;
};

#endif  // ENCRYPTION_AES_VIEW_H
