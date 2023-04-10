#ifndef MAIN_WIDGET_H
#define MAIN_WIDGET_H

#include <QWidget>
class QPushButton;
class QVBoxLayout;
class QHBoxLayout;
class QStackedWidget;
class MainWidget : public QWidget {
    Q_OBJECT
   public:
    explicit MainWidget(QWidget *parent = nullptr);

   private:
    QPushButton *BtnSymmetricEncryption_;
    QPushButton *BtnAsymmetricEncryption_;
    QPushButton *BtnHash_;
    QHBoxLayout *LayoutMain_;
    QVBoxLayout *LayoutBts_;
    QStackedWidget *StackedWidget_;

   private:
    void initConnect();
    void initUI();
    void init();

   signals:

   public slots:
    void slotOpenSymmetricEncryptionView();
    void slotOpenAsymmetricEncryptionView();
    void slotOpenHashView();
};

#endif  // MAIN_WIDGET_H
