#ifndef ENCRYPTION_HASH_VIEW_H
#define ENCRYPTION_HASH_VIEW_H

#include <QWidget>
class QLabel;
class EncryptionHashView : public QWidget {
    Q_OBJECT
   public:
    explicit EncryptionHashView(QWidget *parent = nullptr);
    QLabel *lab_;
   signals:

   public slots:
};

#endif  // ENCRYPTION_HASH_VIEW_H
