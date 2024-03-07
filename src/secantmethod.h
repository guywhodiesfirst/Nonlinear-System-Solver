#ifndef SECANTMETHOD_H
#define SECANTMETHOD_H

#include "rootfindingmethod.h"
class SecantMethod : public RootFindingMethod
{
public:
    SecantMethod(Equations* eq, unsigned short pr);
    QString show_calculations()const override;
    QString get_info()const override;
};

#endif // SECANTMETHOD_H
