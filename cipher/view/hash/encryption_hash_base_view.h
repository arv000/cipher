#ifndef ENCRYPTION_HASH_BASE_VIEW_H
#define ENCRYPTION_HASH_BASE_VIEW_H

#include <QWidget>
class EncrytionDataView;
class EncrytionFileView;
class QPushButton;
class QHBoxLayout;
class QVBoxLayout;
class AbstractHashEncytion;
class QStackedWidget;
class EncytionDataJob;
class EncryptionHashBaseView : public QWidget {
    Q_OBJECT
   public:
    explicit EncryptionHashBaseView(AbstractHashEncytion *encytion);

   private:
    void init();
    void initUI();
    void initConnect();
    QPushButton *DataBtn_;
    QPushButton *FileBtn_;
    QHBoxLayout *LayoutBtn_;
    QVBoxLayout *LayoutMain_;
    EncrytionDataView *DataView_;
    EncrytionFileView *fileView_;
    QStackedWidget *stack_;

   signals:

   public slots:
    void slotClickDataBtn();
    void slotClickFileBtn();
};

#endif  // ENCRYPTION_HASH_BASE_VIEW_H
