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

void rootaddparticle(int barcode, double px, double py, double pz, double e)
{
    eventHandler->AddParticle(barcode, px, py, pz, e);
}//rootaddparticle

void rootaddevent(int iteration, double weight)
{
    eventHandler->SetIteration(iteration);
    eventHandler->SetWeight(weight);
    eventHandler->AddEvent();
}//rootaddevent

void rootwrite()
{
    eventHandler->Write();
}//rootwrite

void rootclose()
{
    eventHandler->Close();
    delete eventHandler;
}//rootclose

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
