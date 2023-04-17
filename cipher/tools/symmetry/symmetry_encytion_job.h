#ifndef SYMMETRY_ENCYTION_JOB_H
#define SYMMETRY_ENCYTION_JOB_H

#include <QThread>
#include <QObject>
#include "abstract_symmetry_encytion.h"
class SymmetryEncytionJob : public QThread {
    Q_OBJECT

   public:
    explicit SymmetryEncytionJob(AbstractSymmetryEncytion *symmetryEncytion);

    void setData(const QByteArray &in, const QByteArray &key,
                 const QByteArray &ivec, CIPH_MODE mode);

    AbstractSymmetryEncytion *symmetryEncytion_;
    QByteArray in_;
    QByteArray key_;
    QByteArray ivec_;
    CIPH_MODE mode_;

   signals:
    void sigFinish(QByteArray out);  // QThread interface
   public slots:

    // QThread interface
   protected:
    void run();
};

#endif  // SYMMETRY_ENCYTION_JOB_H
