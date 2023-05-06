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
#include <QPointer>
#include "tools/symmetry/abstract_symmetry_encytion.h"
#include "tools/symmetry/symmetry_encytion_job.h"
class EncryptionAESDataView : public QWidget {
    Q_OBJECT
   public:
    explicit EncryptionAESDataView(AbstractSymmetryEncytion *parent);

   private:
    void init();
    void initUI();
    void initConnect();

    QPointer<SymmetryEncytionJob> EncytionJob_;

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

    QByteArray getKey(QByteArray key);
    QByteArray getKey128(QByteArray key);
    QByteArray getKey192(QByteArray key);
    QByteArray getKey256(QByteArray key);
   signals:

   public slots:
    void slotDoEncytion();
    void slotDoEncytionFinish(QByteArray res);
    void slotDoDecrypt();
    void slotDoDecryptFinish(QByteArray res);
};

#endif  // ENCRYPTION_AES_DATA_VIEW_H
