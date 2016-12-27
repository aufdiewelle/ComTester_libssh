#ifndef VERSION_H
#define VERSION_H

#include <QString>

class Version
{
public:
    Version();
    QString getVersion();

private:
    QString version = "v0.0.1.9";

};

#endif // VERSION_H
