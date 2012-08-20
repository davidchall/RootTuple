C   Dummy routines for when not linked to RootTuple
      subroutine rootinit(name)
      character*30 name
      end

      subroutine rootcompress(i)
      integer i
      end

      subroutine rootaddparticle(code,px,py,pz,e)
      integer code
      double precision px,py,pz,e
      end

      subroutine rootaddevent(it,wt)
      integer it
      double precision wt
      end

      subroutine rootwrite
      end

      subroutine rootclose
      end
