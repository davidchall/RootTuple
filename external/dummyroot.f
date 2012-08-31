C-----------------------------------------------------------------------
C                              RootTuple
C   Author:  David Hall
C   Date:    29th August 2012
C   Website: http://roottuple.hepforge.org/
C
C   This file provides dummy FORTRAN subroutines for the routines
C   provided by the RootTuple library.
C
C-----------------------------------------------------------------------

      subroutine rootinit(name)
      character*30 name
      write(*,*)'This program has not been linked to RootTuple'
      end

      subroutine rootwrite
      end

      subroutine rootclose
      end

      subroutine rootaddparticle(code,px,py,pz,e)
      integer code
      double precision px,py,pz,e
      end

      subroutine rootaddevent(wgt)
      double precision wgt
      end

      subroutine rootadddouble(val,branch)
      double precision val
      character*30 branch
      end

      subroutine rootaddfloat(val,branch)
      real val
      character*30 branch
      end

      subroutine rootaddint(val,branch)
      integer val
      character*30 branch
      end

      subroutine rootaddbool(val,branch)
      logical val
      character*30 branch
      end

