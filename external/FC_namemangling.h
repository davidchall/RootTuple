//----------------------------------------------------------------------
//                             RootTuple
//  Author:  David Hall
//  Date:    30th August 2012
//  Website: http://roottuple.hepforge.org/
//
//  This is an file containing an example macro to handle the FORTRAN
//  name mangling. If the user cannot use CMake, then this file should
//  be edited as appropriate and copied into the src directory. Then
//  the Makefile can be used.
//
//  The arguments of the macro should not be changed. Various name 
//  mangling configurations exist: e.g. name, NAME, name_, NAME_.
//  The one listed here should work for gfortran, g77 and ifort.
//
//----------------------------------------------------------------------

#ifndef FortranCInterface_HEADER_INCLUDED
#define FortranCInterface_HEADER_INCLUDED

/* Mangling for Fortran global symbols without underscores. */
#define FortranCInterface_GLOBAL(name,NAME) name##_

#endif
