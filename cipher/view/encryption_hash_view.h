#ifndef ENCRYPTION_HASH_VIEW_H
#define ENCRYPTION_HASH_VIEW_H

#include <QWidget>

class QLabel;
class QVBoxLayout;
class QHBoxLayout;
class QRadioButton;
class QButtonGroup;
class AbstractEncytion;
class EncrytionDataView;
class EncrytionFileView;
class QStackedWidget;
// 功能类
class EncytionMD5;
class EncytionSha256;
class EncytionSM3;
enum { MD5_VIEW = 0, SHA256_VIEW, SM3_VIEW };
class EncryptionHashView : public QWidget {
    Q_OBJECT
   public:
    explicit EncryptionHashView(QWidget *parent = nullptr);

   private:
    void init();
    void initUI();
    void initConnect();
    QLabel *lab_;
    QVBoxLayout *LayoutMain_;
    QHBoxLayout *LayoutBtn_;
    QButtonGroup *BtnGroup_;
    QRadioButton *RBtnMD5_;
    QRadioButton *RBtnSha256_;
    QRadioButton *RBtnSM3_;
    AbstractEncytion *MD5_;
    QStackedWidget *stack_;
    EncytionMD5 *funMd5_;
    EncytionSha256 *funSha256_;
    EncytionSM3 *funSM3_;
   signals:

   public slots:
    void soltClickRadioBtn(int index);
};

#endif  // ENCRYPTION_HASH_VIEW_H
