#ifndef TOOLS_H
#define TOOLS_H

#include <QObject>

class Tools : public QObject {
    Q_OBJECT
   public:
    explicit Tools(QObject *parent = nullptr);
    static QString CharToHex(unsigned char *str, unsigned int strLen);
   signals:

   public slots:
};

#endif  // TOOLS_H
