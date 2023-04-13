#include "tools.h"

Tools::Tools(QObject *parent)
    : QObject(parent)
{
}

QString Tools::CharToHex(unsigned char *str, unsigned int strLen)
{
    char outHash[strLen * 2 + 1];
    memset(outHash, 0, strLen * 2 + 1);
    for (unsigned int i = 0; i < strLen; i++) {
        sprintf(&outHash[i * 2], "%02x", str[i]);
    }
    QString res(outHash);
    return res;
}