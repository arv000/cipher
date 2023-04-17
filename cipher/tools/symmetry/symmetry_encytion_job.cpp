#include "symmetry_encytion_job.h"

SymmetryEncytionJob::SymmetryEncytionJob(
    AbstractSymmetryEncytion *symmetryEncytion)
    : symmetryEncytion_(symmetryEncytion)
{
}

void SymmetryEncytionJob::setData(const QByteArray &in, const QByteArray &key,
                                  const QByteArray &ivec, CIPH_MODE mode)
{
    in_ = in;
    key_ = key;
    ivec_ = ivec;
    mode_ = mode;
}

void SymmetryEncytionJob::run()
{
    if (symmetryEncytion_ == nullptr) {
        return;
    }
    QByteArray out = symmetryEncytion_->EncytonData(in_, key_, ivec_, mode_);
    // emit sigFinish(out);
}
