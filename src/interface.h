#ifndef interface_H
#define interface_H

// Standard C++ libraries
#include <string>

#include "FC_namemangling.h"
#include "RootTuple.h"

void rootinit(const char *filename, int lfilename);
void rootaddparticle(int *barcode, double *px, double *py, double *pz, double *e);
void rootaddevent(int *iteration, double *weight);
void rootwrite();
void rootclose();

std::string strFtoC(const char *str, int len);

// Wrappers from FORTRAN subroutines to C++ functions
// Name mangling is accounted for by FortranCInterface_GLOBAL macro
// Problems could occur with character array argument from FORTRAN subroutine
#ifdef __cplusplus
extern "C" {
#endif
    void FortranCInterface_GLOBAL(rootinit,ROOTINIT)(const char *filename, int lfilename)
    {rootinit(filename, lfilename);};
    void FortranCInterface_GLOBAL(rootaddparticle,ROOTADDPARTICLE)(int *barcode, double *px, double *py, double *pz, double *e)
    {rootaddparticle(barcode, px, py, pz, e);};
    void FortranCInterface_GLOBAL(rootaddevent,ROOTADDEVENT)(int *iteration, double *weight)
    {rootaddevent(iteration, weight);};
    void FortranCInterface_GLOBAL(rootwrite,ROOTWRITE)()
    {rootwrite();};
    void FortranCInterface_GLOBAL(rootclose,ROOTCLOSE)()
    {rootclose();};
#ifdef __cplusplus
}
#endif

#endif
