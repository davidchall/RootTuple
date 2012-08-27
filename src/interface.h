#ifndef interface_H
#define interface_H

// Standard C++ libraries
#include <string>

#include "FC_namemangling.h"
#include "RootTuple.h"

void rootinit(const char *filename, int lfilename);
void rootwrite();
void rootclose();

void rootaddparticle(int barcode, double px, double py, double pz, double e);
void rootaddevent(double weight);

void rootadddouble(double *ptr, const char* branchname, int lbranchname);
void rootaddfloat(float *ptr, const char* branchname, int lbranchname);
void rootaddint(int *ptr, const char* branchname, int lbranchname);
void rootaddbool(bool *ptr, const char* branchname, int lbranchname);

std::string strFtoC(const char *str, int len);

// Wrappers from FORTRAN subroutines to C++ functions
// Name mangling is accounted for by FortranCInterface_GLOBAL macro
// Problems could occur with character array argument from FORTRAN subroutine
#ifdef __cplusplus
extern "C" {
#endif
    void FortranCInterface_GLOBAL(rootinit,ROOTINIT)(const char *filename, int lfilename)
    {rootinit(filename, lfilename);};
    void FortranCInterface_GLOBAL(rootwrite,ROOTWRITE)()
    {rootwrite();};
    void FortranCInterface_GLOBAL(rootclose,ROOTCLOSE)()
    {rootclose();};

    void FortranCInterface_GLOBAL(rootaddparticle,ROOTADDPARTICLE)(int *barcode, double *px, double *py, double *pz, double *e)
    {rootaddparticle(*barcode, *px, *py, *pz, *e);};
    void FortranCInterface_GLOBAL(rootaddevent,ROOTADDEVENT)(double *weight)
    {rootaddevent(*weight);};

    void FortranCInterface_GLOBAL(rootadddouble,ROOTADDDOUBLE)(double *ptr, const char *branchname, int lbranchname)
    {rootadddouble(ptr, branchname, lbranchname);};
    void FortranCInterface_GLOBAL(rootaddfloat,ROOTADDFLOAT)(float *ptr, const char *branchname, int lbranchname)
    {rootaddfloat(ptr, branchname, lbranchname);};
    void FortranCInterface_GLOBAL(rootaddint,ROOTADDINT)(int *ptr, const char *branchname, int lbranchname)
    {rootaddint(ptr, branchname, lbranchname);};
    void FortranCInterface_GLOBAL(rootaddbool,ROOTADDBOOL)(bool *ptr, const char *branchname, int lbranchname)
    {rootaddbool(ptr, branchname, lbranchname);};
#ifdef __cplusplus
}
#endif

#endif
