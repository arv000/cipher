#ifndef ENCRYPTION_AES_FILE_VIEW_H
#define ENCRYPTION_AES_FILE_VIEW_H

#include <QWidget>
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
class EncryptionAESFileView : public QWidget {
    Q_OBJECT
   public:
    explicit EncryptionAESFileView(AbstractSymmetryEncytion *parent);
    void init();
    void initUI();
    void initConnect();

   private:
    QPointer<SymmetryEncytionJob> EncytionJob_;
    QPointer<QLabel> labPassWord_;
    QPointer<QLabel> labConfirmPassWord_;
    QPointer<QLineEdit> LEdtPassWord_;
    QPointer<QLineEdit> LEdtConfirmPassWord_;
    QPointer<QComboBox> CBBAlgorithm_;
    QPointer<QLabel> labAlgorithm_;
    QPointer<QGridLayout> LayoutPassWord_;
    QPointer<QVBoxLayout> LayoutMain_;
    QPointer<QPushButton> BtnEncytion_;
    QPointer<QPushButton> BtnDecrypt_;
    QPointer<QHBoxLayout> LayoutBtn_;
    QPointer<QLabel> labMingwen_;
    QPointer<QPushButton> BtnSelectFile_;
    QPointer<QLineEdit> LEdtMingwen_;
    QPointer<QHBoxLayout> LayoutMingwen_;
    QPointer<QTextEdit> TEdtMiwen_;
   signals:

   public slots:
    void slotSelectFile();
    void slotDoDecrypt();
};

#endif  // ENCRYPTION_AES_FILE_VIEW_H
