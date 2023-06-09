#include "encytion_data_job.h"
#include "abstract_encytion.h"
#include <QDebug>
EncytionDataJob::EncytionDataJob(AbstractHashEncytion *encytion)
    : encytion_(encytion)
{
}

void EncytionDataJob::setData(QString data) { data_ = data; }

void EncytionDataJob::run()
{
    qInfo() << "EncytionDataJob::run" << data_;
    if (data_.isEmpty()) {
        return;
    }
    QByteArray res = encytion_->EncytonData(data_);
    emit sigFinish(res);
}
