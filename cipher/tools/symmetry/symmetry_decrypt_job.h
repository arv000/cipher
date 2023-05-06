#ifndef SYMMETRY_DECRYPT_JOB_H
#define SYMMETRY_DECRYPT_JOB_H

#include <QThread>
#include <QObject>

class SymmetryDecryptJob : public QThread
{
    Q_OBJECT
public:
    explicit SymmetryDecryptJob(QObject *parent = nullptr);

signals:

public slots:

    // QThread interface
protected:
    void run();
};

#endif // SYMMETRY_DECRYPT_JOB_H
