#ifndef VERSION_H
#define VERSION_H

#include <QString>

class Version
{
public:
    Version();
    QString getVersion();

private:
    QString version = "v1.0.1.0";

};

#endif // VERSION_H
