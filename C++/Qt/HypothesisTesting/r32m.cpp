#include "r32m.h"

static unsigned long int iu, iuhold, mult=663608941l;

double rnunif()
{
    // const double flt = 5.42101086242752217e-20;
    const double flt = 0x1p-64;
    //  const double flt = 0.232830643654e-9;
    iu *= mult;
    return flt*iu;
}

void rninit(unsigned long iufir)
{
    iu = (iufir % 2) ? iufir : (iufir + 1);
    iuhold = iu;
}

void rnrest() {
    rninit(iuhold);
}

void rnconst(unsigned long int multnew) {
    int rest = multnew % 8;
    if ((rest != 5) && (rest != 3)) {
        mult = multnew - rest + 5;
    } else {
        mult = multnew;
    }
}      

unsigned long int rnlast() {
    return iu;
}

unsigned long int rnfirst() {
    return iuhold;
}
