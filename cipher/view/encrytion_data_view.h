#ifndef ENCRYTION_DATA_VIEW_H
#define ENCRYTION_DATA_VIEW_H

#include <QWidget>
class AbstractHashEncytion;
class QTextEdit;
class QPushButton;
class QVBoxLayout;
class EncytionDataJob;
class EncrytionDataView : public QWidget {
    Q_OBJECT
   public:
    explicit EncrytionDataView(AbstractHashEncytion *encytion);

    EncytionDataJob *encytionJob_;

   private:
    void init();
    void initUI();
    void initConnect();
    QTextEdit *TxtEditMingWen_;
    QTextEdit *TxtEditMiWen_;
    QPushButton *BtnDoWork_;
    QVBoxLayout *LayoutMain_;
   signals:

   public slots:

    void slotClickDoWork();
    void slotEncrytionFinish(QString out);
};

#endif  // ENCRYTION_DATA_VIEW_H
