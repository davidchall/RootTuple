#ifndef interface_H
#define interface_H

// Standard C++ libraries
#include <cstring>

#include "RootTuple.h"

#ifdef __cplusplus
extern "C" {
#endif
	void rootinit_(const char *filename, int lfilename, const char* treename, int ltreename);
	void rootaddparticle_(int barcode, double px, double py, double pz, double e);
	void rootaddevent_(int iteration, double weight);
	void rootwrite_();
	void rootclose_();
#ifdef __cplusplus
}
#endif

void rootinit_(const char *filename, int lfilename, const char* treename, int ltreename);
void rootaddparticle_(int barcode, double px, double py, double pz, double e);
void rootaddevent_(int iteration, double weight);
void rootwrite_();
void rootclose_();
char* strFtoC(const char *str, int len);

#endif
