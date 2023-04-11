#ifndef ASYMMETRIC_ENCRYPTION_VIEW_H
#define ASYMMETRIC_ENCRYPTION_VIEW_H

#include <QWidget>
class QLabel;
class EncryptionAsymmetricView : public QWidget {
    Q_OBJECT
   public:
    explicit EncryptionAsymmetricView(QWidget *parent = nullptr);

   private:
    QLabel *lab_;
   signals:

   public slots:
};

#endif  // ASYMMETRIC_ENCRYPTION_VIEW_H
