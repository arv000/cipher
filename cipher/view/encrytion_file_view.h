#ifndef ENCRYTION_FILE_VIEW_H
#define ENCRYTION_FILE_VIEW_H

#include <QWidget>
class AbstractEncytion;
class EncrytionFileView : public QWidget {
    Q_OBJECT
   public:
    explicit EncrytionFileView(AbstractEncytion *encytion);
    AbstractEncytion *encytion_;
   signals:

   public slots:
};

#endif  // ENCRYTION_FILE_VIEW_H
