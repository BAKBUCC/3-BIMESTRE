#ifndef TOOLS_H
#define TOOLS_H

#include <NTL/ZZ.h>
using namespace NTL;

class Tools
{
    public:
        ZZ q,r;
        Tools();
        ZZ modulo(ZZ,ZZ);
        ZZ modulo(ZZ,int);

    protected:

    private:
};

#endif // TOOLS_H
