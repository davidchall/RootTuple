#include "interface.h"

// Declare global pointer
RootTuple *eventHandler;

// MacOS needs string, string, int, int
// Linux needs string, int, string, int

//void rootinit_(const char *filename, int lfilename, const char* treename, int ltreename)
void rootinit_(const char *filename, const char* treename, int lfilename, int ltreename)
{
    // Convert fortran strings to C strings
    const char *c_filename = strFtoC(filename, lfilename);
    const char *c_treename = strFtoC(treename, ltreename);

    eventHandler = new RootTuple(std::string(c_filename), std::string(c_treename));
    eventHandler->Initialise();
}//rootinit

void rootaddparticle_(int barcode, double px, double py, double pz, double e)
{
    eventHandler->AddParticle(barcode, px, py, pz, e);
}//rootaddparticle

void rootaddevent_(int iteration, double weight)
{
    eventHandler->SetIteration(iteration);
    eventHandler->SetWeight(weight);
    eventHandler->AddEvent();
}//rootaddevent

void rootwrite_()
{
    eventHandler->Write();
}//rootwrite

void rootclose_()
{
    eventHandler->Close();
}//rootclose

char* strFtoC(const char *str, int len)
{
    int tlen = 0;
    char tem;

    // Counts non-blank characters in a string str until a first blank character or the end of the string is met
    while(str[tlen] != ' ' && (tlen < len) && (tem = str[tlen++], tem));

    char *tstr = new char[tlen+1];
    strncpy(tstr, str, tlen);
    tstr[tlen] = '\0';

    return tstr;
}//strFtoC
