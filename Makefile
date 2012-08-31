#-----------------------------------------------------------------------
#                              RootTuple
#   Author:  David Hall
#   Date:    30th August 2012
#   Website: http://roottuple.hepforge.org/
#
#   Makefile to be used when CMake not installed (less portable and 
#   does not provide a separate installation). The ROOT setup script
#   must be sourced before use so root-config is in the PATH variable.
#   Must also copy external/FC_namemangling.h to src directory and 
#   edit as necessary.
#
#-----------------------------------------------------------------------

# Root variables
ROOTCFLAGS := $(shell root-config --cflags)
ROOTGLIBS  := $(shell root-config --nonew --glibs) -lTreePlayer

SOURCES    := src/RootTuple.cxx src/interface.cxx
OBJECTS    := $(SOURCES:.cxx=.o)

CXXFLAGS   += -fPIC $(ROOTCFLAGS)
LDFLAGS    += -shared
LIBS       += $(ROOTGLIBS)

ifeq ($(shell uname),Darwin)
LIBEXT=.dylib
else
LIBEXT=.so
endif

all: libRootTuple

libRootTuple: $(OBJECTS)
	$(CXX) $(LDFLAGS) -o $@$(LIBEXT) $^ $(LIBS)
	mkdir -p lib
	mv libRootTuple$(LIBEXT) lib

%.o: %.cxx %.h
	$(CXX) $(CXXFLAGS) -o $@ -c $<

.PHONY: clean
clean:
	rm src/*.o lib/libRootTuple$(LIBEXT)
