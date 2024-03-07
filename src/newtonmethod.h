#ifndef NEWTONMETHOD_H
#define NEWTONMETHOD_H

#include "rootfindingmethod.h"

class NewtonMethod : public RootFindingMethod
{
public:
    NewtonMethod(Equations* eq, unsigned short pr);
    QString show_calculations()const override;
    QString get_info()const override;
};

#endif // NEWTONMETHOD_H
