#include "interface.h"

// Declare global pointer
RootTuple *eventHandler;

void rootinit(const char *filename, int lfilename)
{
    eventHandler = new RootTuple(strFtoC(filename, lfilename), "RootTuple");
    eventHandler->Initialise();
}//rootinit

void rootcompress(int i)
{
    eventHandler->SetCompressionLevel(i);
}//rootcompress

void rootwrite()
{
    eventHandler->Write();
}//rootwrite

void rootclose()
{
    eventHandler->Close();
    delete eventHandler;
}//rootclose

void rootaddparticle(int barcode, double px, double py, double pz, double e)
{
    eventHandler->AddParticle(barcode, px, py, pz, e);
}//rootaddparticle

void rootaddevent(double weight)
{
    eventHandler->SetWeight(weight);
    eventHandler->AddEvent();
}//rootaddevent

void rootsetdouble(double *ptr, const char* branchname, int lbranchname)
{
    eventHandler->SetDoubleBranch(strFtoC(branchname, lbranchname), ptr);
}//rootsetdouble

void rootsetfloat(float *ptr, const char* branchname, int lbranchname)
{
    eventHandler->SetFloatBranch(strFtoC(branchname, lbranchname), ptr);
}//rootsetfloat

void rootsetint(int *ptr, const char* branchname, int lbranchname)
{
    eventHandler->SetIntBranch(strFtoC(branchname, lbranchname), ptr);
}//rootsetint

void rootsetbool(bool *ptr, const char* branchname, int lbranchname)
{
    eventHandler->SetBoolBranch(strFtoC(branchname, lbranchname), ptr);
}//rootsetbool

// Converts a fortran string to a C string
std::string strFtoC(const char *str, int len)
{
    int tlen = 0;
    char tem;

    // Counts non-blank characters in a string str until a first blank character or the end of the string is met
    while(str[tlen] != ' ' && (tlen < len) && (tem = str[tlen++], tem));

    char *tstr = new char[tlen+1];
    strncpy(tstr, str, tlen);
    tstr[tlen] = '\0';

    return std::string(tstr);
}//strFtoC
