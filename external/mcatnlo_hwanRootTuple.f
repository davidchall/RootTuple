C-----------------------------------------------------------------------
C                              RootTuple
C   Author:  David Hall
C   Date:    29th August 2012
C   Website: http://roottuple.hepforge.org/
C
C   This is an example of how the RootTuple routines could be called
C   from within a Herwig analysis in order to output the generated 
C   events as ROOT ntuples. The example is written for MC@NLO, which
C   uses Herwig to do parton showering and hadronisation.
C
C-----------------------------------------------------------------------

C-----------------------------------------------------------------------
      SUBROUTINE HWABEG
C     CALLED BY HWDRIVER BEFORE FIRST EVENT ANALYZED
C-----------------------------------------------------------------------
C
C--- SET OUTPUT FILE NAME
      CALL ROOTINIT("../output.root")
      END


C-----------------------------------------------------------------------
      SUBROUTINE HWAEND
C     CALLED BY HWDRIVER EVERY NSTEP EVENTS
C     UNUSED SINCE ROOT MANAGES ITS BUFFER WELL
C-----------------------------------------------------------------------
C
      END


C-----------------------------------------------------------------------
      SUBROUTINE RCLOS
C     CALLED BY HWDRIVER AT END OF RUN
C-----------------------------------------------------------------------
C
      CALL ROOTCLOSE
      END


C-----------------------------------------------------------------------
      SUBROUTINE HWANAL
C     CALLED BY HWDRIVER FOR EACH EVENT
C-----------------------------------------------------------------------
C
      INCLUDE 'HERWIG65.INC'
      INTEGER MAXNUP
      PARAMETER (MAXNUP=500)
      INTEGER NUP,IDPRUP,IDUP,ISTUP,MOTHUP,ICOLUP
      DOUBLE PRECISION XWGTUP,SCALUP,AQEDUP,AQCDUP,PUP,VTIMUP,SPINUP,
     & XMP2,XMA2,XMB2,BETA,VA,VB,SIGMA,DELTA,S2,XKA,XKB,PTF,E,PL,
     & XSCALE,XEPHO
      COMMON/HEPEUP/NUP,IDPRUP,XWGTUP,SCALUP,AQEDUP,AQCDUP,
     &              IDUP(MAXNUP),ISTUP(MAXNUP),MOTHUP(2,MAXNUP),
     &              ICOLUP(2,MAXNUP),PUP(5,MAXNUP),VTIMUP(MAXNUP),
     &              SPINUP(MAXNUP)
      DOUBLE PRECISION UX1,UX2,UQ2
      COMMON/CPDFRWGT/UX1,UX2,UQ2
      INTEGER I
C
      IF(IERROR.NE.0) RETURN
C
C--- LOOP OVER ALL PARTICLES
C--- ADD FINAL STATE PARTICLES AND INITIAL STATE PARTONS TO NTUPLE
      DO I=1,NHEP
         IF(ISTHEP(I).EQ.1)THEN
            CALL ROOTADDPARTICLE(IDHEP(I),PHEP(1,I),PHEP(2,I),PHEP(3,I),
     &                           PHEP(4,I))
         ELSE IF(ISTHEP(I).EQ.121)THEN
            CALL ROOTADDINT(IDHEP(I),"pdf_id1")
         ELSE IF(ISTHEP(I).EQ.122)THEN
            CALL ROOTADDINT(IDHEP(I),"pdf_id2")
         ENDIF
      ENDDO
C
C--- ADD INFORMATION FOR PDF REWEIGHTING
      CALL ROOTADDDOUBLE(UX1,"pdf_x1")
      CALL ROOTADDDOUBLE(UX2,"pdf_x2")
      CALL ROOTADDDOUBLE(UQ2,"pdf_Q2")
C
      CALL ROOTADDEVENT(EVWGT)
C
      END
