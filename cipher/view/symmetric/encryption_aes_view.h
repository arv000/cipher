#ifndef ENCRYPTION_AES_VIEW_H
#define ENCRYPTION_AES_VIEW_H

#include <QWidget>
class QTabWidget;
class EncryptionAESDataView;
class EncryptionAESFileView;
class EncryptionAESView : public QWidget {
    Q_OBJECT
   public:
    explicit EncryptionAESView(QWidget *parent = nullptr);
    QTabWidget *TabView_;
    EncryptionAESDataView *AESDataView_;
    EncryptionAESFileView *AESFileView_;
};

#endif  // ENCRYPTION_AES_VIEW_H
