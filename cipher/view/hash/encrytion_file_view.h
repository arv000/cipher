#ifndef ENCRYTION_FILE_VIEW_H
#define ENCRYTION_FILE_VIEW_H

#include <QWidget>
class AbstractHashEncytion;
class QPushButton;
class QFileDialog;
class QLineEdit;
class QTextEdit;
class QVBoxLayout;
class QHBoxLayout;
class EncytionFileJob;
class EncrytionFileView : public QWidget {
    Q_OBJECT
   public:
    explicit EncrytionFileView(AbstractHashEncytion *encytion);
    EncytionFileJob *encytionJob_;

   private:
    void init();
    void initUI();
    void initConnect();
    QVBoxLayout *LayoutMain_;
    QHBoxLayout *LayoutFile_;
    QPushButton *BtnFileSelect_;
    QPushButton *BtnDoWork_;
    QLineEdit *LineEditFilePath_;
    QTextEdit *TextEditResoult_;
   signals:

   public slots:
    void slotSelectFilePath();
    void slotDoWork();
    void slotEncrytionFinish(QByteArray out);
};

#endif  // ENCRYTION_FILE_VIEW_H
