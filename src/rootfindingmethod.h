#ifndef ROOTFINDINGMETHOD_H
#define ROOTFINDINGMETHOD_H
#include "GeneralFunctions.h"
#include <qtextstream.h>

class RootFindingMethod
{
public:
    RootFindingMethod(Equations *eq, unsigned short pr);
    virtual QString show_calculations()const = 0;
    virtual QString get_info()const = 0;
protected:
    Equations* system;
    unsigned short precision;
};

#endif // ROOTFINDINGMETHOD_H