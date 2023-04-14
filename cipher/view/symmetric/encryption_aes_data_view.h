#ifndef ENCRYPTION_AES_DATA_VIEW_H
#define ENCRYPTION_AES_DATA_VIEW_H

#include <QWidget>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QTextEdit>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QGridLayout>
#include <QComboBox>
class EncryptionAESDataView : public QWidget {
    Q_OBJECT
   public:
    explicit EncryptionAESDataView(QWidget *parent = nullptr);
    QLabel *labPassWord_;
    QLabel *labConfirmPassWord_;
    QLineEdit *LEdtPassWord_;
    QLineEdit *LEdtConfirmPassWord_;
    QComboBox *CBBAlgorithm_;
    QLabel *labAlgorithm_;
    QGridLayout *LayoutPassWord_;
    QVBoxLayout *LayoutMain_;
    QPushButton *BtnEncytion_;
    QPushButton *BtnDecrypt_;
    QHBoxLayout *LayoutBtn_;
    QLabel *labMingwen_;
    QLineEdit *LEdtMingwen_;
    QHBoxLayout *LayoutMingwen_;
    QTextEdit *TEdtMiwen_;
   signals:

   public slots:
};

#endif  // ENCRYPTION_AES_DATA_VIEW_H
