#include "encytion_file_job.h"
#include "abstract_encytion.h"
EncytionFileJob::EncytionFileJob(AbstractEncytion *encytion)
    : encytion_(encytion)
{
}

void EncytionFileJob::setData(QString strInFilePath)
{
    strInFilePath_ = strInFilePath;
}

void EncytionFileJob::run()
{
    if (strInFilePath_.isEmpty()) {
        return;
    }
    QString out = encytion_->EncytonFile(strInFilePath_);
    emit sigFinish(out);
}
