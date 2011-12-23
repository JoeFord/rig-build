/*
 * This file was generated automatically by ExtUtils::ParseXS version 2.2210 from the
 * contents of Typemap.xs. Do not edit this file, edit Typemap.xs instead.
 *
 *	ANY CHANGES MADE HERE WILL BE LOST! 
 *
 */

#line 1 "Typemap.xs"
/*
   XS code to test the typemap entries

   Copyright (C) 2001 Tim Jenness.
   All Rights Reserved

*/

#define PERL_NO_GET_CONTEXT

#include "EXTERN.h"   /* std perl include */
#include "perl.h"     /* std perl include */
#include "XSUB.h"     /* XSUB include */

/* Prototypes for external functions */
FILE * xsfopen( const char * );
int xsfclose( FILE * );
int xsfprintf( FILE *, const char *);

/* Type definitions required for the XS typemaps */
typedef SV * SVREF; /* T_SVREF */
typedef int SysRet; /* T_SYSRET */
typedef int Int;    /* T_INT */
typedef int intRef; /* T_PTRREF */
typedef int intObj; /* T_PTROBJ */
typedef int intRefIv; /* T_REF_IV_PTR */
typedef int intArray; /* T_ARRAY */
typedef short shortOPQ;   /* T_OPAQUE */
typedef int intOpq;   /* T_OPAQUEPTR */

/* A structure to test T_OPAQUEPTR */
struct t_opaqueptr {
  int a;
  int b;
  double c;
};

typedef struct t_opaqueptr astruct;

/* Some static memory for the tests */
static I32 xst_anint;
static intRef xst_anintref;
static intObj xst_anintobj;
static intRefIv xst_anintrefiv;
static intOpq xst_anintopq;

/* Helper functions */

/* T_ARRAY - allocate some memory */
intArray * intArrayPtr( int nelem ) {
    intArray * array;
    Newx(array, nelem, intArray);
    return array;
}


#line 67 "Typemap.c"
#ifndef PERL_UNUSED_VAR
#  define PERL_UNUSED_VAR(var) if (0) var = var
#endif

#ifndef PERL_ARGS_ASSERT_CROAK_XS_USAGE
#define PERL_ARGS_ASSERT_CROAK_XS_USAGE assert(cv); assert(params)

/* prototype to pass -Wmissing-prototypes */
STATIC void
S_croak_xs_usage(pTHX_ const CV *const cv, const char *const params);

STATIC void
S_croak_xs_usage(pTHX_ const CV *const cv, const char *const params)
{
    const GV *const gv = CvGV(cv);

    PERL_ARGS_ASSERT_CROAK_XS_USAGE;

    if (gv) {
        const char *const gvname = GvNAME(gv);
        const HV *const stash = GvSTASH(gv);
        const char *const hvname = stash ? HvNAME(stash) : NULL;

        if (hvname)
            Perl_croak(aTHX_ "Usage: %s::%s(%s)", hvname, gvname, params);
        else
            Perl_croak(aTHX_ "Usage: %s(%s)", gvname, params);
    } else {
        /* Pants. I don't think that it should be possible to get here. */
        Perl_croak(aTHX_ "Usage: CODE(0x%"UVxf")(%s)", PTR2UV(cv), params);
    }
}
#undef  PERL_ARGS_ASSERT_CROAK_XS_USAGE

#ifdef PERL_IMPLICIT_CONTEXT
#define croak_xs_usage(a,b)	S_croak_xs_usage(aTHX_ a,b)
#else
#define croak_xs_usage		S_croak_xs_usage
#endif

#endif

/* NOTE: the prototype of newXSproto() is different in versions of perls,
 * so we define a portable version of newXSproto()
 */
#ifdef newXS_flags
#define newXSproto_portable(name, c_impl, file, proto) newXS_flags(name, c_impl, file, proto, 0)
#else
#define newXSproto_portable(name, c_impl, file, proto) (PL_Sv=(SV*)newXS(name, c_impl, file), sv_setpv(PL_Sv, proto), (CV*)PL_Sv)
#endif /* !defined(newXS_flags) */

#line 119 "Typemap.c"

XS(XS_XS__Typemap_T_SV); /* prototype to pass -Wmissing-prototypes */
XS(XS_XS__Typemap_T_SV)
{
#ifdef dVAR
    dVAR; dXSARGS;
#else
    dXSARGS;
#endif
    if (items != 1)
       croak_xs_usage(cv,  "sv");
    {
	SV *	sv = ST(0);
	SV *	RETVAL;
#line 81 "Typemap.xs"
  /* create a new sv for return that is a copy of the input
     do not simply copy the pointer since the SV will be marked
     mortal by the INPUT typemap when it is pushed back onto the stack */
  RETVAL = sv_mortalcopy( sv );
  /* increment the refcount since the default INPUT typemap mortalizes
     by default and we don't want to decrement the ref count twice
     by mistake */
  SvREFCNT_inc(RETVAL);
#line 143 "Typemap.c"
	ST(0) = RETVAL;
	sv_2mortal(ST(0));
    }
    XSRETURN(1);
}


XS(XS_XS__Typemap_T_SVREF); /* prototype to pass -Wmissing-prototypes */
XS(XS_XS__Typemap_T_SVREF)
{
#ifdef dVAR
    dVAR; dXSARGS;
#else
    dXSARGS;
#endif
    if (items != 1)
       croak_xs_usage(cv,  "svref");
    {
	SVREF	svref;
	SVREF	RETVAL;

	STMT_START {
		SV* const xsub_tmp_sv = ST(0);
		SvGETMAGIC(xsub_tmp_sv);
		if (SvROK(xsub_tmp_sv)){
		    svref = SvRV(xsub_tmp_sv);
		}
		else{
		    Perl_croak(aTHX_ "%s: %s is not a reference",
				"XS::Typemap::T_SVREF",
				"svref");
		}
	} STMT_END;
#line 102 "Typemap.xs"
  RETVAL = svref;
#line 179 "Typemap.c"
	ST(0) = newRV((SV*)RETVAL);
	sv_2mortal(ST(0));
    }
    XSRETURN(1);
}


XS(XS_XS__Typemap_T_AVREF); /* prototype to pass -Wmissing-prototypes */
XS(XS_XS__Typemap_T_AVREF)
{
#ifdef dVAR
    dVAR; dXSARGS;
#else
    dXSARGS;
#endif
    if (items != 1)
       croak_xs_usage(cv,  "av");
    {
	AV *	av;
	AV *	RETVAL;

	STMT_START {
		SV* const xsub_tmp_sv = ST(0);
		SvGETMAGIC(xsub_tmp_sv);
		if (SvROK(xsub_tmp_sv) && SvTYPE(SvRV(xsub_tmp_sv)) == SVt_PVAV){
		    av = (AV*)SvRV(xsub_tmp_sv);
		}
		else{
		    Perl_croak(aTHX_ "%s: %s is not an ARRAY reference",
				"XS::Typemap::T_AVREF",
				"av");
		}
	} STMT_END;
#line 117 "Typemap.xs"
  RETVAL = av;
#line 215 "Typemap.c"
	ST(0) = newRV((SV*)RETVAL);
	sv_2mortal(ST(0));
    }
    XSRETURN(1);
}


XS(XS_XS__Typemap_T_HVREF); /* prototype to pass -Wmissing-prototypes */
XS(XS_XS__Typemap_T_HVREF)
{
#ifdef dVAR
    dVAR; dXSARGS;
#else
    dXSARGS;
#endif
    if (items != 1)
       croak_xs_usage(cv,  "hv");
    {
	HV *	hv;
	HV *	RETVAL;

	STMT_START {
		SV* const xsub_tmp_sv = ST(0);
		SvGETMAGIC(xsub_tmp_sv);
		if (SvROK(xsub_tmp_sv) && SvTYPE(SvRV(xsub_tmp_sv)) == SVt_PVHV){
		    hv = (HV*)SvRV(xsub_tmp_sv);
		}
		else{
		    Perl_croak(aTHX_ "%s: %s is not a HASH reference",
				"XS::Typemap::T_HVREF",
				"hv");
		}
	} STMT_END;
#line 132 "Typemap.xs"
  RETVAL = hv;
#line 251 "Typemap.c"
	ST(0) = newRV((SV*)RETVAL);
	sv_2mortal(ST(0));
    }
    XSRETURN(1);
}


XS(XS_XS__Typemap_T_CVREF); /* prototype to pass -Wmissing-prototypes */
XS(XS_XS__Typemap_T_CVREF)
{
#ifdef dVAR
    dVAR; dXSARGS;
#else
    dXSARGS;
#endif
    if (items != 1)
       croak_xs_usage(cv,  "cv");
    {
	CV *	cv;
	CV *	RETVAL;

	STMT_START {
		SV* const xsub_tmp_sv = ST(0);
		SvGETMAGIC(xsub_tmp_sv);
		if (SvROK(xsub_tmp_sv) && SvTYPE(SvRV(xsub_tmp_sv)) == SVt_PVCV){
		    cv = (CV*)SvRV(xsub_tmp_sv);
		}
		else{
		    Perl_croak(aTHX_ "%s: %s is not a CODE reference",
				"XS::Typemap::T_CVREF",
				"cv");
		}
	} STMT_END;
#line 148 "Typemap.xs"
  RETVAL = cv;
#line 287 "Typemap.c"
	ST(0) = newRV((SV*)RETVAL);
	sv_2mortal(ST(0));
    }
    XSRETURN(1);
}


XS(XS_XS__Typemap_T_SYSRET_pass); /* prototype to pass -Wmissing-prototypes */
XS(XS_XS__Typemap_T_SYSRET_pass)
{
#ifdef dVAR
    dVAR; dXSARGS;
#else
    dXSARGS;
#endif
    if (items != 0)
       croak_xs_usage(cv,  "");
    {
	SysRet	RETVAL;
#line 175 "Typemap.xs"
  RETVAL = 0;
#line 309 "Typemap.c"
	ST(0) = sv_newmortal();
	if (RETVAL != -1) {
	    if (RETVAL == 0)
		sv_setpvn(ST(0), "0 but true", 10);
	    else
		sv_setiv(ST(0), (IV)RETVAL);
	}
    }
    XSRETURN(1);
}


XS(XS_XS__Typemap_T_SYSRET_fail); /* prototype to pass -Wmissing-prototypes */
XS(XS_XS__Typemap_T_SYSRET_fail)
{
#ifdef dVAR
    dVAR; dXSARGS;
#else
    dXSARGS;
#endif
    if (items != 0)
       croak_xs_usage(cv,  "");
    {
	SysRet	RETVAL;
#line 184 "Typemap.xs"
  RETVAL = -1;
#line 336 "Typemap.c"
	ST(0) = sv_newmortal();
	if (RETVAL != -1) {
	    if (RETVAL == 0)
		sv_setpvn(ST(0), "0 but true", 10);
	    else
		sv_setiv(ST(0), (IV)RETVAL);
	}
    }
    XSRETURN(1);
}


XS(XS_XS__Typemap_T_UV); /* prototype to pass -Wmissing-prototypes */
XS(XS_XS__Typemap_T_UV)
{
#ifdef dVAR
    dVAR; dXSARGS;
#else
    dXSARGS;
#endif
    if (items != 1)
       croak_xs_usage(cv,  "uv");
    {
	unsigned int	uv = (unsigned int)SvUV(ST(0));
	unsigned int	RETVAL;
	dXSTARG;
#line 198 "Typemap.xs"
  RETVAL = uv;
#line 365 "Typemap.c"
	XSprePUSH; PUSHu((UV)RETVAL);
    }
    XSRETURN(1);
}


XS(XS_XS__Typemap_T_IV); /* prototype to pass -Wmissing-prototypes */
XS(XS_XS__Typemap_T_IV)
{
#ifdef dVAR
    dVAR; dXSARGS;
#else
    dXSARGS;
#endif
    if (items != 1)
       croak_xs_usage(cv,  "iv");
    {
	long	iv = (long)SvIV(ST(0));
	long	RETVAL;
	dXSTARG;
#line 213 "Typemap.xs"
  RETVAL = iv;
#line 388 "Typemap.c"
	XSprePUSH; PUSHi((IV)RETVAL);
    }
    XSRETURN(1);
}


XS(XS_XS__Typemap_T_ENUM); /* prototype to pass -Wmissing-prototypes */
XS(XS_XS__Typemap_T_ENUM)
{
#ifdef dVAR
    dVAR; dXSARGS;
#else
    dXSARGS;
#endif
    if (items != 0)
       croak_xs_usage(cv,  "");
    {
	svtype	RETVAL;
	dXSTARG;
#line 240 "Typemap.xs"
  RETVAL = SVt_PVHV;
#line 410 "Typemap.c"
	XSprePUSH; PUSHi((IV)RETVAL);
    }
    XSRETURN(1);
}


XS(XS_XS__Typemap_T_BOOL); /* prototype to pass -Wmissing-prototypes */
XS(XS_XS__Typemap_T_BOOL)
{
#ifdef dVAR
    dVAR; dXSARGS;
#else
    dXSARGS;
#endif
    if (items != 1)
       croak_xs_usage(cv,  "in");
    {
	bool	in = (bool)SvTRUE(ST(0));
	bool	RETVAL;
#line 255 "Typemap.xs"
  RETVAL = in;
#line 432 "Typemap.c"
	ST(0) = boolSV(RETVAL);
	sv_2mortal(ST(0));
    }
    XSRETURN(1);
}


XS(XS_XS__Typemap_T_U_SHORT); /* prototype to pass -Wmissing-prototypes */
XS(XS_XS__Typemap_T_U_SHORT)
{
#ifdef dVAR
    dVAR; dXSARGS;
#else
    dXSARGS;
#endif
    if (items != 1)
       croak_xs_usage(cv,  "in");
    {
	U16	in = (unsigned short)SvUV(ST(0));
	U16	RETVAL;
	dXSTARG;
#line 285 "Typemap.xs"
  RETVAL = in;
#line 456 "Typemap.c"
	XSprePUSH; PUSHu((UV)RETVAL);
    }
    XSRETURN(1);
}


XS(XS_XS__Typemap_T_U_LONG); /* prototype to pass -Wmissing-prototypes */
XS(XS_XS__Typemap_T_U_LONG)
{
#ifdef dVAR
    dVAR; dXSARGS;
#else
    dXSARGS;
#endif
    if (items != 1)
       croak_xs_usage(cv,  "in");
    {
	U32	in = (unsigned long)SvUV(ST(0));
	U32	RETVAL;
	dXSTARG;
#line 310 "Typemap.xs"
  RETVAL = in;
#line 479 "Typemap.c"
	XSprePUSH; PUSHu((UV)RETVAL);
    }
    XSRETURN(1);
}


XS(XS_XS__Typemap_T_CHAR); /* prototype to pass -Wmissing-prototypes */
XS(XS_XS__Typemap_T_CHAR)
{
#ifdef dVAR
    dVAR; dXSARGS;
#else
    dXSARGS;
#endif
    if (items != 1)
       croak_xs_usage(cv,  "in");
    {
	char	in = (char)*SvPV_nolen(ST(0));
	char	RETVAL;
	dXSTARG;
#line 324 "Typemap.xs"
  RETVAL = in;
#line 502 "Typemap.c"
	XSprePUSH; PUSHp((char *)&RETVAL, 1);
    }
    XSRETURN(1);
}


XS(XS_XS__Typemap_T_U_CHAR); /* prototype to pass -Wmissing-prototypes */
XS(XS_XS__Typemap_T_U_CHAR)
{
#ifdef dVAR
    dVAR; dXSARGS;
#else
    dXSARGS;
#endif
    if (items != 1)
       croak_xs_usage(cv,  "in");
    {
	unsigned char	in = (unsigned char)SvUV(ST(0));
	unsigned char	RETVAL;
	dXSTARG;
#line 339 "Typemap.xs"
  RETVAL = in;
#line 525 "Typemap.c"
	XSprePUSH; PUSHu((UV)RETVAL);
    }
    XSRETURN(1);
}


XS(XS_XS__Typemap_T_FLOAT); /* prototype to pass -Wmissing-prototypes */
XS(XS_XS__Typemap_T_FLOAT)
{
#ifdef dVAR
    dVAR; dXSARGS;
#else
    dXSARGS;
#endif
    if (items != 1)
       croak_xs_usage(cv,  "in");
    {
	float	in = (float)SvNV(ST(0));
	float	RETVAL;
	dXSTARG;
#line 355 "Typemap.xs"
  RETVAL = in;
#line 548 "Typemap.c"
	XSprePUSH; PUSHn((double)RETVAL);
    }
    XSRETURN(1);
}


XS(XS_XS__Typemap_T_NV); /* prototype to pass -Wmissing-prototypes */
XS(XS_XS__Typemap_T_NV)
{
#ifdef dVAR
    dVAR; dXSARGS;
#else
    dXSARGS;
#endif
    if (items != 1)
       croak_xs_usage(cv,  "in");
    {
	NV	in = (NV)SvNV(ST(0));
	NV	RETVAL;
	dXSTARG;
#line 371 "Typemap.xs"
  RETVAL = in;
#line 571 "Typemap.c"
	XSprePUSH; PUSHn((NV)RETVAL);
    }
    XSRETURN(1);
}


XS(XS_XS__Typemap_T_DOUBLE); /* prototype to pass -Wmissing-prototypes */
XS(XS_XS__Typemap_T_DOUBLE)
{
#ifdef dVAR
    dVAR; dXSARGS;
#else
    dXSARGS;
#endif
    if (items != 1)
       croak_xs_usage(cv,  "in");
    {
	double	in = (double)SvNV(ST(0));
	double	RETVAL;
	dXSTARG;
#line 386 "Typemap.xs"
  RETVAL = in;
#line 594 "Typemap.c"
	XSprePUSH; PUSHn((double)RETVAL);
    }
    XSRETURN(1);
}


XS(XS_XS__Typemap_T_PV); /* prototype to pass -Wmissing-prototypes */
XS(XS_XS__Typemap_T_PV)
{
#ifdef dVAR
    dVAR; dXSARGS;
#else
    dXSARGS;
#endif
    if (items != 1)
       croak_xs_usage(cv,  "in");
    {
	char *	in = (char *)SvPV_nolen(ST(0));
	char *	RETVAL;
	dXSTARG;
#line 400 "Typemap.xs"
  RETVAL = in;
#line 617 "Typemap.c"
	sv_setpv(TARG, RETVAL); XSprePUSH; PUSHTARG;
    }
    XSRETURN(1);
}


XS(XS_XS__Typemap_T_PTR_OUT); /* prototype to pass -Wmissing-prototypes */
XS(XS_XS__Typemap_T_PTR_OUT)
{
#ifdef dVAR
    dVAR; dXSARGS;
#else
    dXSARGS;
#endif
    if (items != 1)
       croak_xs_usage(cv,  "in");
    {
	int	in = (int)SvIV(ST(0));
	void *	RETVAL;
	dXSTARG;
#line 418 "Typemap.xs"
  xst_anint = in;
  RETVAL = &xst_anint;
#line 641 "Typemap.c"
	XSprePUSH; PUSHi(PTR2IV(RETVAL));
    }
    XSRETURN(1);
}


XS(XS_XS__Typemap_T_PTR_IN); /* prototype to pass -Wmissing-prototypes */
XS(XS_XS__Typemap_T_PTR_IN)
{
#ifdef dVAR
    dVAR; dXSARGS;
#else
    dXSARGS;
#endif
    if (items != 1)
       croak_xs_usage(cv,  "ptr");
    {
	void *	ptr = INT2PTR(void *,SvIV(ST(0)));
	int	RETVAL;
	dXSTARG;
#line 429 "Typemap.xs"
  RETVAL = *(int *)ptr;
#line 664 "Typemap.c"
	XSprePUSH; PUSHi((IV)RETVAL);
    }
    XSRETURN(1);
}


XS(XS_XS__Typemap_T_PTRREF_OUT); /* prototype to pass -Wmissing-prototypes */
XS(XS_XS__Typemap_T_PTRREF_OUT)
{
#ifdef dVAR
    dVAR; dXSARGS;
#else
    dXSARGS;
#endif
    if (items != 1)
       croak_xs_usage(cv,  "in");
    {
	intRef	in = (intRef)SvIV(ST(0));
	intRef *	RETVAL;
#line 452 "Typemap.xs"
  xst_anintref = in;
  RETVAL = &xst_anintref;
#line 687 "Typemap.c"
	ST(0) = sv_newmortal();
	sv_setref_pv(ST(0), Nullch, (void*)RETVAL);
    }
    XSRETURN(1);
}


XS(XS_XS__Typemap_T_PTRREF_IN); /* prototype to pass -Wmissing-prototypes */
XS(XS_XS__Typemap_T_PTRREF_IN)
{
#ifdef dVAR
    dVAR; dXSARGS;
#else
    dXSARGS;
#endif
    if (items != 1)
       croak_xs_usage(cv,  "ptr");
    {
	intRef *	ptr;
	intRef	RETVAL;
	dXSTARG;

	if (SvROK(ST(0))) {
	    IV tmp = SvIV((SV*)SvRV(ST(0)));
	    ptr = INT2PTR(intRef *,tmp);
	}
	else
	    Perl_croak(aTHX_ "%s: %s is not a reference",
			"XS::Typemap::T_PTRREF_IN",
			"ptr");
#line 463 "Typemap.xs"
  RETVAL = *ptr;
#line 720 "Typemap.c"
	XSprePUSH; PUSHi((IV)RETVAL);
    }
    XSRETURN(1);
}


XS(XS_XS__Typemap_T_PTROBJ_OUT); /* prototype to pass -Wmissing-prototypes */
XS(XS_XS__Typemap_T_PTROBJ_OUT)
{
#ifdef dVAR
    dVAR; dXSARGS;
#else
    dXSARGS;
#endif
    if (items != 1)
       croak_xs_usage(cv,  "in");
    {
	intObj	in = (intObj)SvIV(ST(0));
	intObj *	RETVAL;
#line 490 "Typemap.xs"
  xst_anintobj = in;
  RETVAL = &xst_anintobj;
#line 743 "Typemap.c"
	ST(0) = sv_newmortal();
	sv_setref_pv(ST(0), "intObjPtr", (void*)RETVAL);
    }
    XSRETURN(1);
}


XS(XS_intObjPtr_T_PTROBJ_IN); /* prototype to pass -Wmissing-prototypes */
XS(XS_intObjPtr_T_PTROBJ_IN)
{
#ifdef dVAR
    dVAR; dXSARGS;
#else
    dXSARGS;
#endif
    if (items != 1)
       croak_xs_usage(cv,  "ptr");
    {
	intObj *	ptr;
	intObj	RETVAL;
	dXSTARG;

	if (SvROK(ST(0)) && sv_derived_from(ST(0), "intObjPtr")) {
	    IV tmp = SvIV((SV*)SvRV(ST(0)));
	    ptr = INT2PTR(intObj *,tmp);
	}
	else
	    Perl_croak(aTHX_ "%s: %s is not of type %s",
			"intObjPtr::T_PTROBJ_IN",
			"ptr", "intObjPtr");
#line 503 "Typemap.xs"
  RETVAL = *ptr;
#line 776 "Typemap.c"
	XSprePUSH; PUSHi((IV)RETVAL);
    }
    XSRETURN(1);
}


XS(XS_XS__Typemap_T_REF_IV_PTR_OUT); /* prototype to pass -Wmissing-prototypes */
XS(XS_XS__Typemap_T_REF_IV_PTR_OUT)
{
#ifdef dVAR
    dVAR; dXSARGS;
#else
    dXSARGS;
#endif
    if (items != 1)
       croak_xs_usage(cv,  "in");
    {
	intRefIv	in = (intRefIv)SvIV(ST(0));
	intRefIv *	RETVAL;
#line 533 "Typemap.xs"
  xst_anintrefiv = in;
  RETVAL = &xst_anintrefiv;
#line 799 "Typemap.c"
	ST(0) = sv_newmortal();
	sv_setref_pv(ST(0), "intRefIvPtr", (void*)RETVAL);
    }
    XSRETURN(1);
}


XS(XS_intRefIvPtr_T_REF_IV_PTR_IN); /* prototype to pass -Wmissing-prototypes */
XS(XS_intRefIvPtr_T_REF_IV_PTR_IN)
{
#ifdef dVAR
    dVAR; dXSARGS;
#else
    dXSARGS;
#endif
    if (items != 1)
       croak_xs_usage(cv,  "ptr");
    {
	intRefIv *	ptr;
	intRefIv	RETVAL;
	dXSTARG;

	if (sv_isa(ST(0), "intRefIvPtr")) {
	    IV tmp = SvIV((SV*)SvRV(ST(0)));
	    ptr = INT2PTR(intRefIv *, tmp);
	}
	else
	    Perl_croak(aTHX_ "%s: %s is not of type %s",
			"intRefIvPtr::T_REF_IV_PTR_IN",
			"ptr", "intRefIvPtr");
#line 546 "Typemap.xs"
  RETVAL = *ptr;
#line 832 "Typemap.c"
	XSprePUSH; PUSHi((IV)RETVAL);
    }
    XSRETURN(1);
}


XS(XS_XS__Typemap_T_OPAQUEPTR_IN); /* prototype to pass -Wmissing-prototypes */
XS(XS_XS__Typemap_T_OPAQUEPTR_IN)
{
#ifdef dVAR
    dVAR; dXSARGS;
#else
    dXSARGS;
#endif
    if (items != 1)
       croak_xs_usage(cv,  "val");
    {
	intOpq	val = (intOpq)SvIV(ST(0));
	intOpq *	RETVAL;
	dXSTARG;
#line 589 "Typemap.xs"
  xst_anintopq = val;
  RETVAL = &xst_anintopq;
#line 856 "Typemap.c"
	XSprePUSH; PUSHp((char *)RETVAL, sizeof(*RETVAL));
    }
    XSRETURN(1);
}


XS(XS_XS__Typemap_T_OPAQUEPTR_OUT); /* prototype to pass -Wmissing-prototypes */
XS(XS_XS__Typemap_T_OPAQUEPTR_OUT)
{
#ifdef dVAR
    dVAR; dXSARGS;
#else
    dXSARGS;
#endif
    if (items != 1)
       croak_xs_usage(cv,  "ptr");
    {
	intOpq *	ptr = (intOpq *)SvPV_nolen(ST(0));
	intOpq	RETVAL;
	dXSTARG;
#line 598 "Typemap.xs"
  RETVAL = *ptr;
#line 879 "Typemap.c"
	XSprePUSH; PUSHi((IV)RETVAL);
    }
    XSRETURN(1);
}


XS(XS_XS__Typemap_T_OPAQUEPTR_OUT_short); /* prototype to pass -Wmissing-prototypes */
XS(XS_XS__Typemap_T_OPAQUEPTR_OUT_short)
{
#ifdef dVAR
    dVAR; dXSARGS;
#else
    dXSARGS;
#endif
    if (items != 1)
       croak_xs_usage(cv,  "ptr");
    {
	shortOPQ *	ptr = (shortOPQ *)SvPV_nolen(ST(0));
	short	RETVAL;
	dXSTARG;
#line 606 "Typemap.xs"
  RETVAL = *ptr;
#line 902 "Typemap.c"
	XSprePUSH; PUSHi((IV)RETVAL);
    }
    XSRETURN(1);
}


XS(XS_XS__Typemap_T_OPAQUEPTR_IN_struct); /* prototype to pass -Wmissing-prototypes */
XS(XS_XS__Typemap_T_OPAQUEPTR_IN_struct)
{
#ifdef dVAR
    dVAR; dXSARGS;
#else
    dXSARGS;
#endif
    if (items != 3)
       croak_xs_usage(cv,  "a, b, c");
    {
	int	a = (int)SvIV(ST(0));
	int	b = (int)SvIV(ST(1));
	double	c = (double)SvNV(ST(2));
#line 617 "Typemap.xs"
  struct t_opaqueptr test;
#line 925 "Typemap.c"
	astruct *	RETVAL;
	dXSTARG;
#line 619 "Typemap.xs"
  test.a = a;
  test.b = b;
  test.c = c;
  RETVAL = &test;
#line 933 "Typemap.c"
	XSprePUSH; PUSHp((char *)RETVAL, sizeof(*RETVAL));
    }
    XSRETURN(1);
}


XS(XS_XS__Typemap_T_OPAQUEPTR_OUT_struct); /* prototype to pass -Wmissing-prototypes */
XS(XS_XS__Typemap_T_OPAQUEPTR_OUT_struct)
{
#ifdef dVAR
    dVAR; dXSARGS;
#else
    dXSARGS;
#endif
    if (items != 1)
       croak_xs_usage(cv,  "test");
    PERL_UNUSED_VAR(ax); /* -Wall */
    SP -= items;
    {
	astruct *	test = (astruct *)SvPV_nolen(ST(0));
#line 630 "Typemap.xs"
  XPUSHs(sv_2mortal(newSViv(test->a)));
  XPUSHs(sv_2mortal(newSViv(test->b)));
  XPUSHs(sv_2mortal(newSVnv(test->c)));
#line 958 "Typemap.c"
	PUTBACK;
	return;
    }
}


XS(XS_XS__Typemap_T_OPAQUE_IN); /* prototype to pass -Wmissing-prototypes */
XS(XS_XS__Typemap_T_OPAQUE_IN)
{
#ifdef dVAR
    dVAR; dXSARGS;
#else
    dXSARGS;
#endif
    if (items != 1)
       croak_xs_usage(cv,  "val");
    {
	int	val = (int)SvIV(ST(0));
	shortOPQ	RETVAL;
	dXSTARG;
#line 658 "Typemap.xs"
  RETVAL = (shortOPQ)val;
#line 981 "Typemap.c"
	XSprePUSH; PUSHp((char *)&RETVAL, sizeof(RETVAL));
    }
    XSRETURN(1);
}


XS(XS_XS__Typemap_T_OPAQUE_OUT); /* prototype to pass -Wmissing-prototypes */
XS(XS_XS__Typemap_T_OPAQUE_OUT)
{
#ifdef dVAR
    dVAR; dXSARGS;
#else
    dXSARGS;
#endif
    if (items != 1)
       croak_xs_usage(cv,  "val");
    {
	shortOPQ	val = *(shortOPQ *)SvPV_nolen(ST(0));
	IV	RETVAL;
	dXSTARG;
#line 666 "Typemap.xs"
  RETVAL = (IV)val;
#line 1004 "Typemap.c"
	XSprePUSH; PUSHi((IV)RETVAL);
    }
    XSRETURN(1);
}


XS(XS_XS__Typemap_T_OPAQUE_array); /* prototype to pass -Wmissing-prototypes */
XS(XS_XS__Typemap_T_OPAQUE_array)
{
#ifdef dVAR
    dVAR; dXSARGS;
#else
    dXSARGS;
#endif
    if (items != 3)
       croak_xs_usage(cv,  "a, b, c");
    {
	int	a = (int)SvIV(ST(0));
	int	b = (int)SvIV(ST(1));
	int	c = (int)SvIV(ST(2));
#line 695 "Typemap.xs"
  int array[3];
#line 1027 "Typemap.c"
	int *	RETVAL;
#line 697 "Typemap.xs"
  array[0] = a;
  array[1] = b;
  array[2] = c;
  RETVAL = array;
#line 1034 "Typemap.c"
	ST(0) = sv_newmortal();
	sv_setpvn(ST(0), (char *)RETVAL, 3 * sizeof(int));
    }
    XSRETURN(1);
}


XS(XS_XS__Typemap_T_ARRAY); /* prototype to pass -Wmissing-prototypes */
XS(XS_XS__Typemap_T_ARRAY)
{
#ifdef dVAR
    dVAR; dXSARGS;
#else
    dXSARGS;
#endif
    if (items < 2)
       croak_xs_usage(cv,  "dummy, array, ...");
    {
	int	dummy = 0;
	intArray *	array;
#line 771 "Typemap.xs"
  U32 size_RETVAL;
#line 1057 "Typemap.c"
	intArray *	RETVAL;

	U32 ix_array = 1;
	array = intArrayPtr(items -= 1);
	while (items--) {
	    	array[ix_array - 1] = (int)SvIV(ST(ix_array));
	    ix_array++;
	}
        /* this is the number of elements in the array */
        ix_array -= 1;
#line 773 "Typemap.xs"
  dummy += 0; /* Fix -Wall */
  size_RETVAL = ix_array;
  RETVAL = array;
#line 1072 "Typemap.c"
        {
	    U32 ix_RETVAL;
	    EXTEND(SP,size_RETVAL);
	    for (ix_RETVAL = 0; ix_RETVAL < size_RETVAL; ix_RETVAL++) {
		ST(ix_RETVAL) = sv_newmortal();
		sv_setiv(ST(ix_RETVAL), (IV)RETVAL[ix_RETVAL]);
	    }
        }
#line 779 "Typemap.xs"
  Safefree(array);
  XSRETURN(size_RETVAL);
#line 1084 "Typemap.c"
    }
    XSRETURN(1);
}


XS(XS_XS__Typemap_T_STDIO_open); /* prototype to pass -Wmissing-prototypes */
XS(XS_XS__Typemap_T_STDIO_open)
{
#ifdef dVAR
    dVAR; dXSARGS;
#else
    dXSARGS;
#endif
    if (items != 1)
       croak_xs_usage(cv,  "file");
    {
	const char *	file = (const char *)SvPV_nolen(ST(0));
	FILE *	RETVAL;
#line 794 "Typemap.xs"
  RETVAL = xsfopen( file );
#line 1105 "Typemap.c"
	ST(0) = sv_newmortal();
	{
	    GV *gv = newGVgen("XS::Typemap");
	    PerlIO *fp = PerlIO_importFILE(RETVAL,0);
	    if ( fp && do_open(gv, "+<&", 3, FALSE, 0, 0, fp) )
		sv_setsv(ST(0), sv_bless(newRV((SV*)gv), gv_stashpv("XS::Typemap",1)));
	    else
		ST(0) = &PL_sv_undef;
	}
    }
    XSRETURN(1);
}


XS(XS_XS__Typemap_T_STDIO_close); /* prototype to pass -Wmissing-prototypes */
XS(XS_XS__Typemap_T_STDIO_close)
{
#ifdef dVAR
    dVAR; dXSARGS;
#else
    dXSARGS;
#endif
    if (items != 1)
       croak_xs_usage(cv,  "f");
    {
	PerlIO *	f = IoIFP(sv_2io(ST(0)));
#line 802 "Typemap.xs"
  FILE * stream;
#line 1134 "Typemap.c"
	SysRet	RETVAL;
#line 804 "Typemap.xs"
  /* Get the FILE* */
  stream = PerlIO_findFILE( f );  
  /* Release the FILE* from the PerlIO system so that we do
     not close the file twice */
  PerlIO_releaseFILE(f,stream);
  /* Must release the file before closing it */
  RETVAL = xsfclose( stream );
#line 1144 "Typemap.c"
	ST(0) = sv_newmortal();
	if (RETVAL != -1) {
	    if (RETVAL == 0)
		sv_setpvn(ST(0), "0 but true", 10);
	    else
		sv_setiv(ST(0), (IV)RETVAL);
	}
    }
    XSRETURN(1);
}


XS(XS_XS__Typemap_T_STDIO_print); /* prototype to pass -Wmissing-prototypes */
XS(XS_XS__Typemap_T_STDIO_print)
{
#ifdef dVAR
    dVAR; dXSARGS;
#else
    dXSARGS;
#endif
    if (items != 2)
       croak_xs_usage(cv,  "stream, string");
    {
	FILE *	stream = PerlIO_findFILE(IoIFP(sv_2io(ST(0))));
	const char *	string = (const char *)SvPV_nolen(ST(1));
	int	RETVAL;
	dXSTARG;
#line 819 "Typemap.xs"
  RETVAL = xsfprintf( stream, string );
#line 1174 "Typemap.c"
	XSprePUSH; PUSHi((IV)RETVAL);
    }
    XSRETURN(1);
}

#ifdef __cplusplus
extern "C"
#endif
XS(boot_XS__Typemap); /* prototype to pass -Wmissing-prototypes */
XS(boot_XS__Typemap)
{
#ifdef dVAR
    dVAR; dXSARGS;
#else
    dXSARGS;
#endif
#if (PERL_REVISION == 5 && PERL_VERSION < 9)
    char* file = __FILE__;
#else
    const char* file = __FILE__;
#endif

    PERL_UNUSED_VAR(cv); /* -W */
    PERL_UNUSED_VAR(items); /* -W */
#ifdef XS_APIVERSION_BOOTCHECK
    XS_APIVERSION_BOOTCHECK;
#endif
    XS_VERSION_BOOTCHECK ;

        newXS("XS::Typemap::T_SV", XS_XS__Typemap_T_SV, file);
        newXS("XS::Typemap::T_SVREF", XS_XS__Typemap_T_SVREF, file);
        newXS("XS::Typemap::T_AVREF", XS_XS__Typemap_T_AVREF, file);
        newXS("XS::Typemap::T_HVREF", XS_XS__Typemap_T_HVREF, file);
        newXS("XS::Typemap::T_CVREF", XS_XS__Typemap_T_CVREF, file);
        newXS("XS::Typemap::T_SYSRET_pass", XS_XS__Typemap_T_SYSRET_pass, file);
        newXS("XS::Typemap::T_SYSRET_fail", XS_XS__Typemap_T_SYSRET_fail, file);
        newXS("XS::Typemap::T_UV", XS_XS__Typemap_T_UV, file);
        newXS("XS::Typemap::T_IV", XS_XS__Typemap_T_IV, file);
        newXS("XS::Typemap::T_ENUM", XS_XS__Typemap_T_ENUM, file);
        newXS("XS::Typemap::T_BOOL", XS_XS__Typemap_T_BOOL, file);
        newXS("XS::Typemap::T_U_SHORT", XS_XS__Typemap_T_U_SHORT, file);
        newXS("XS::Typemap::T_U_LONG", XS_XS__Typemap_T_U_LONG, file);
        newXS("XS::Typemap::T_CHAR", XS_XS__Typemap_T_CHAR, file);
        newXS("XS::Typemap::T_U_CHAR", XS_XS__Typemap_T_U_CHAR, file);
        newXS("XS::Typemap::T_FLOAT", XS_XS__Typemap_T_FLOAT, file);
        newXS("XS::Typemap::T_NV", XS_XS__Typemap_T_NV, file);
        newXS("XS::Typemap::T_DOUBLE", XS_XS__Typemap_T_DOUBLE, file);
        newXS("XS::Typemap::T_PV", XS_XS__Typemap_T_PV, file);
        newXS("XS::Typemap::T_PTR_OUT", XS_XS__Typemap_T_PTR_OUT, file);
        newXS("XS::Typemap::T_PTR_IN", XS_XS__Typemap_T_PTR_IN, file);
        newXS("XS::Typemap::T_PTRREF_OUT", XS_XS__Typemap_T_PTRREF_OUT, file);
        newXS("XS::Typemap::T_PTRREF_IN", XS_XS__Typemap_T_PTRREF_IN, file);
        newXS("XS::Typemap::T_PTROBJ_OUT", XS_XS__Typemap_T_PTROBJ_OUT, file);
        newXS("intObjPtr::T_PTROBJ_IN", XS_intObjPtr_T_PTROBJ_IN, file);
        newXS("XS::Typemap::T_REF_IV_PTR_OUT", XS_XS__Typemap_T_REF_IV_PTR_OUT, file);
        newXS("intRefIvPtr::T_REF_IV_PTR_IN", XS_intRefIvPtr_T_REF_IV_PTR_IN, file);
        newXS("XS::Typemap::T_OPAQUEPTR_IN", XS_XS__Typemap_T_OPAQUEPTR_IN, file);
        newXS("XS::Typemap::T_OPAQUEPTR_OUT", XS_XS__Typemap_T_OPAQUEPTR_OUT, file);
        newXS("XS::Typemap::T_OPAQUEPTR_OUT_short", XS_XS__Typemap_T_OPAQUEPTR_OUT_short, file);
        newXS("XS::Typemap::T_OPAQUEPTR_IN_struct", XS_XS__Typemap_T_OPAQUEPTR_IN_struct, file);
        newXS("XS::Typemap::T_OPAQUEPTR_OUT_struct", XS_XS__Typemap_T_OPAQUEPTR_OUT_struct, file);
        newXS("XS::Typemap::T_OPAQUE_IN", XS_XS__Typemap_T_OPAQUE_IN, file);
        newXS("XS::Typemap::T_OPAQUE_OUT", XS_XS__Typemap_T_OPAQUE_OUT, file);
        newXS("XS::Typemap::T_OPAQUE_array", XS_XS__Typemap_T_OPAQUE_array, file);
        newXS("XS::Typemap::T_ARRAY", XS_XS__Typemap_T_ARRAY, file);
        newXS("XS::Typemap::T_STDIO_open", XS_XS__Typemap_T_STDIO_open, file);
        newXS("XS::Typemap::T_STDIO_close", XS_XS__Typemap_T_STDIO_close, file);
        newXS("XS::Typemap::T_STDIO_print", XS_XS__Typemap_T_STDIO_print, file);
#if (PERL_REVISION == 5 && PERL_VERSION >= 9)
  if (PL_unitcheckav)
       call_list(PL_scopestack_ix, PL_unitcheckav);
#endif
    XSRETURN_YES;
}

