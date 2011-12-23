/*******************************************************************************
*
*  !!!!! Do NOT edit this file directly! -- Edit PPPort_xs.PL instead. !!!!!
*
*  This file was automatically generated from the definition files in the
*  parts/inc/ subdirectory by PPPort_xs.PL. To learn more about how all this
*  works, please read the F<HACKERS> file that came with this distribution.
*
********************************************************************************
*
*  Perl/Pollution/Portability
*
********************************************************************************
*
*  $Revision: 15 $
*  $Author: mhx $
*  $Date: 2009/01/18 14:10:48 +0100 $
*
********************************************************************************
*
*  Version 3.x, Copyright (C) 2004-2009, Marcus Holland-Moritz.
*  Version 2.x, Copyright (C) 2001, Paul Marquess.
*  Version 1.x, Copyright (C) 1999, Kenneth Albanowski.
*
*  This program is free software; you can redistribute it and/or
*  modify it under the same terms as Perl itself.
*
*******************************************************************************/

/* ========== BEGIN XSHEAD ================================================== */



/* =========== END XSHEAD =================================================== */

#include "EXTERN.h"
#include "perl.h"
#include "XSUB.h"

/* ========== BEGIN XSINIT ================================================== */

/* ---- code from parts/inc/warn ---- */
#define NEED_warner

/* ---- code from parts/inc/newRV ---- */
#define NEED_newRV_noinc

/* ---- code from parts/inc/newSVpv ---- */
#define NEED_newSVpvn_flags

/* ---- code from parts/inc/SvPV ---- */
#define NEED_sv_2pv_flags
#define NEED_sv_pvn_force_flags
#define NEED_sv_2pvbyte

/* ---- code from parts/inc/strlfuncs ---- */
#define NEED_my_strlcat
#define NEED_my_strlcpy

/* ---- code from parts/inc/grok ---- */
#define NEED_grok_number
#define NEED_grok_numeric_radix
#define NEED_grok_bin
#define NEED_grok_hex
#define NEED_grok_oct

/* ---- code from parts/inc/newCONSTSUB ---- */
#define NEED_newCONSTSUB

/* ---- code from parts/inc/call ---- */
#define NEED_eval_pv
#define NEED_load_module
#define NEED_vload_module

/* ---- code from parts/inc/pv_tools ---- */
#define NEED_pv_escape
#define NEED_pv_pretty
#define NEED_pv_display

/* ---- code from parts/inc/variables ---- */
#define NEED_PL_signals
#define NEED_PL_parser
#define DPPP_PL_parser_NO_DUMMY_WARNING

/* ---- code from parts/inc/sprintf ---- */
#define NEED_my_sprintf

/* ---- code from parts/inc/snprintf ---- */
#define NEED_my_snprintf

/* ---- code from parts/inc/sv_xpvf ---- */
#define NEED_vnewSVpvf
#define NEED_sv_catpvf_mg
#define NEED_sv_catpvf_mg_nocontext
#define NEED_sv_setpvf_mg
#define NEED_sv_setpvf_mg_nocontext

/* ---- code from parts/inc/newSV_type ---- */
#define NEED_newSV_type

/* ---- code from parts/inc/shared_pv ---- */
#define NEED_newSVpvn_share

/* =========== END XSINIT =================================================== */

#include "ppport.h"

/* ========== BEGIN XSMISC ================================================== */

/* ---- code from parts/inc/exception ---- */
/* defined in module3.c */
int exception(int throw_e);

/* ---- code from parts/inc/newCONSTSUB ---- */
void call_newCONSTSUB_1(void)
{
#ifdef PERL_NO_GET_CONTEXT
	dTHX;
#endif
	newCONSTSUB(gv_stashpv("Devel::PPPort", FALSE), "test_value_1", newSViv(1));
}

extern void call_newCONSTSUB_2(void);
extern void call_newCONSTSUB_3(void);

/* ---- code from parts/inc/variables ---- */
U32 get_PL_signals_1(void)
{
  return PL_signals;
}

extern U32 get_PL_signals_2(void);
extern U32 get_PL_signals_3(void);
int no_dummy_parser_vars(int);
int dummy_parser_warning(void);

#define ppp_TESTVAR(var)          STMT_START { mXPUSHi(&var != NULL); count++; } STMT_END

#define ppp_PARSERVAR(type, var)  STMT_START {                   \
                                    type volatile my_ ## var;    \
                                    type volatile *my_p_ ## var; \
                                    my_ ## var = var;            \
                                    my_p_ ## var = &var;         \
                                    var = my_ ## var;            \
                                    var = *my_p_ ## var;         \
                                    mXPUSHi(&var != NULL);       \
                                    count++;                     \
                                  } STMT_END

#define ppp_PARSERVAR_dummy       STMT_START {                   \
                                    mXPUSHi(1);                  \
                                    count++;                     \
                                  } STMT_END

#if (PERL_BCDVERSION < 0x5004000)
# define ppp_rsfp_t FILE *
#else
# define ppp_rsfp_t PerlIO *
#endif

#if (PERL_BCDVERSION < 0x5006000)
# define ppp_expect_t expectation
#elif (PERL_BCDVERSION < 0x5009005)
# define ppp_expect_t int
#else
# define ppp_expect_t U8
#endif

#if (PERL_BCDVERSION < 0x5009005)
# define ppp_lex_state_t U32
#else
# define ppp_lex_state_t U8
#endif

#if (PERL_BCDVERSION < 0x5006000)
# define ppp_in_my_t bool
#elif (PERL_BCDVERSION < 0x5009005)
# define ppp_in_my_t I32
#else
# define ppp_in_my_t U16
#endif

#if (PERL_BCDVERSION < 0x5009005)
# define ppp_error_count_t I32
#else
# define ppp_error_count_t U8
#endif

/* ---- code from parts/inc/MY_CXT ---- */
#define MY_CXT_KEY "Devel::PPPort::_guts" XS_VERSION

typedef struct {
  /* Put Global Data in here */
  int dummy;
} my_cxt_t;

START_MY_CXT

/* ---- code from parts/inc/sv_xpvf ---- */
static SV * test_vnewSVpvf(pTHX_ const char *pat, ...)
{
  SV *sv;
  va_list args;
  va_start(args, pat);
#if (PERL_BCDVERSION >= 0x5004000)
  sv = vnewSVpvf(pat, &args);
#else
  sv = newSVpv((char *) pat, 0);
#endif
  va_end(args);
  return sv;
}

static void test_sv_vcatpvf(pTHX_ SV *sv, const char *pat, ...)
{
  va_list args;
  va_start(args, pat);
#if (PERL_BCDVERSION >= 0x5004000)
  sv_vcatpvf(sv, pat, &args);
#else
  sv_catpv(sv, (char *) pat);
#endif
  va_end(args);
}

static void test_sv_vsetpvf(pTHX_ SV *sv, const char *pat, ...)
{
  va_list args;
  va_start(args, pat);
#if (PERL_BCDVERSION >= 0x5004000)
  sv_vsetpvf(sv, pat, &args);
#else
  sv_setpv(sv, (char *) pat);
#endif
  va_end(args);
}

/* ---- code from parts/inc/misc ---- */
typedef XSPROTO(XSPROTO_test_t);
typedef XSPROTO_test_t *XSPROTO_test_t_ptr;

XS(XS_Devel__PPPort_dXSTARG);  /* prototype */
XS(XS_Devel__PPPort_dXSTARG)
{
  dXSARGS;
  dXSTARG;
  IV iv;
  SP -= items;
  iv = SvIV(ST(0)) + 1;
  PUSHi(iv);
  XSRETURN(1);
}

XS(XS_Devel__PPPort_dAXMARK);  /* prototype */
XS(XS_Devel__PPPort_dAXMARK)
{
  dSP;
  dAXMARK;
  dITEMS;
  IV iv;
  SP -= items;
  iv = SvIV(ST(0)) - 1;
  mPUSHi(iv);
  XSRETURN(1);
}

/* =========== END XSMISC =================================================== */

MODULE = Devel::PPPort		PACKAGE = Devel::PPPort

BOOT:
	/* ---- code from parts/inc/MY_CXT ---- */
	{
	  MY_CXT_INIT;
	  /* If any of the fields in the my_cxt_t struct need
	   * to be initialised, do it here.
	   */
	  MY_CXT.dummy = 42;
	}
	
	/* ---- code from parts/inc/misc ---- */
	{
	  XSPROTO_test_t_ptr p = &XS_Devel__PPPort_dXSTARG;
	  newXS("Devel::PPPort::dXSTARG", *p, file);
	}
	newXS("Devel::PPPort::dAXMARK", XS_Devel__PPPort_dAXMARK, file);
	

##----------------------------------------------------------------------
##  XSUBs for testing the implementation in parts/inc/memory
##----------------------------------------------------------------------

int
checkmem()
  PREINIT:
    char *p;

  CODE:
    RETVAL = 0;
    Newx(p, 6, char);
    CopyD("Hello", p, 6, char);
    if (memEQ(p, "Hello", 6))
      RETVAL++;
    ZeroD(p, 6, char);
    if (memEQ(p, "\0\0\0\0\0\0", 6))
      RETVAL++;
    Poison(p, 6, char);
    if (memNE(p, "\0\0\0\0\0\0", 6))
      RETVAL++;
    Safefree(p);

    Newxz(p, 6, char);
    if (memEQ(p, "\0\0\0\0\0\0", 6))
      RETVAL++;
    Safefree(p);

    Newxc(p, 3, short, char);
    Safefree(p);

  OUTPUT:
    RETVAL

##----------------------------------------------------------------------
##  XSUBs for testing the implementation in parts/inc/SvREFCNT
##----------------------------------------------------------------------

void
SvREFCNT()
	PREINIT:
		SV *sv, *svr;
	PPCODE:
		sv = newSV(0);
		mXPUSHi(SvREFCNT(sv) == 1);
		svr = SvREFCNT_inc(sv);
		mXPUSHi(sv == svr);
		mXPUSHi(SvREFCNT(sv) == 2);
		svr = SvREFCNT_inc_simple(sv);
		mXPUSHi(sv == svr);
		mXPUSHi(SvREFCNT(sv) == 3);
		svr = SvREFCNT_inc_NN(sv);
		mXPUSHi(sv == svr);
		mXPUSHi(SvREFCNT(sv) == 4);
		svr = SvREFCNT_inc_simple_NN(sv);
		mXPUSHi(sv == svr);
		mXPUSHi(SvREFCNT(sv) == 5);
		SvREFCNT_inc_void(sv);
		mXPUSHi(SvREFCNT(sv) == 6);
		SvREFCNT_inc_simple_void(sv);
		mXPUSHi(SvREFCNT(sv) == 7);
		SvREFCNT_inc_void_NN(sv);
		mXPUSHi(SvREFCNT(sv) == 8);
		SvREFCNT_inc_simple_void_NN(sv);
		mXPUSHi(SvREFCNT(sv) == 9);
		while (SvREFCNT(sv) > 1)
		  SvREFCNT_dec(sv);
		mXPUSHi(SvREFCNT(sv) == 1);
		SvREFCNT_dec(sv);
		XSRETURN(14);

##----------------------------------------------------------------------
##  XSUBs for testing the implementation in parts/inc/mPUSH
##----------------------------------------------------------------------

void
mPUSHs()
	PPCODE:
	EXTEND(SP, 3);
	mPUSHs(newSVpv("foo", 0));
	mPUSHs(newSVpv("bar13", 3));
	mPUSHs(newSViv(42));
	XSRETURN(3);

void
mPUSHp()
	PPCODE:
	EXTEND(SP, 3);
	mPUSHp("one", 3);
	mPUSHp("two", 3);
	mPUSHp("three", 5);
	XSRETURN(3);

void
mPUSHn()
	PPCODE:
	EXTEND(SP, 3);
	mPUSHn(0.5);
	mPUSHn(-0.25);
	mPUSHn(0.125);
	XSRETURN(3);

void
mPUSHi()
	PPCODE:
	EXTEND(SP, 3);
	mPUSHi(-1);
	mPUSHi(2);
	mPUSHi(-3);
	XSRETURN(3);

void
mPUSHu()
	PPCODE:
	EXTEND(SP, 3);
	mPUSHu(1);
	mPUSHu(2);
	mPUSHu(3);
	XSRETURN(3);

void
mXPUSHs()
	PPCODE:
	mXPUSHs(newSVpv("foo", 0));
	mXPUSHs(newSVpv("bar13", 3));
	mXPUSHs(newSViv(42));
	XSRETURN(3);

void
mXPUSHp()
	PPCODE:
	mXPUSHp("one", 3);
	mXPUSHp("two", 3);
	mXPUSHp("three", 5);
	XSRETURN(3);

void
mXPUSHn()
	PPCODE:
	mXPUSHn(0.5);
	mXPUSHn(-0.25);
	mXPUSHn(0.125);
	XSRETURN(3);

void
mXPUSHi()
	PPCODE:
	mXPUSHi(-1);
	mXPUSHi(2);
	mXPUSHi(-3);
	XSRETURN(3);

void
mXPUSHu()
	PPCODE:
	mXPUSHu(1);
	mXPUSHu(2);
	mXPUSHu(3);
	XSRETURN(3);

##----------------------------------------------------------------------
##  XSUBs for testing the implementation in parts/inc/warn
##----------------------------------------------------------------------

void
warner()
	CODE:
#if (PERL_BCDVERSION >= 0x5004000)
		warner(packWARN(WARN_MISC), "warner %s:%d", "bar", 42);
#endif

void
Perl_warner()
	CODE:
#if (PERL_BCDVERSION >= 0x5004000)
		Perl_warner(aTHX_ packWARN(WARN_MISC), "Perl_warner %s:%d", "bar", 42);
#endif

void
Perl_warner_nocontext()
	CODE:
#if (PERL_BCDVERSION >= 0x5004000)
		Perl_warner_nocontext(packWARN(WARN_MISC), "Perl_warner_nocontext %s:%d", "bar", 42);
#endif

void
ckWARN()
	CODE:
#if (PERL_BCDVERSION >= 0x5004000)
		if (ckWARN(WARN_MISC))
		  Perl_warner_nocontext(packWARN(WARN_MISC), "ckWARN %s:%d", "bar", 42);
#endif

##----------------------------------------------------------------------
##  XSUBs for testing the implementation in parts/inc/magic
##----------------------------------------------------------------------

void
sv_catpv_mg(sv, string)
	SV *sv;
	char *string;
	CODE:
		sv_catpv_mg(sv, string);

void
sv_catpvn_mg(sv, sv2)
	SV *sv;
	SV *sv2;
	PREINIT:
		char *str;
		STRLEN len;
	CODE:
		str = SvPV(sv2, len);
		sv_catpvn_mg(sv, str, len);

void
sv_catsv_mg(sv, sv2)
	SV *sv;
	SV *sv2;
	CODE:
		sv_catsv_mg(sv, sv2);

void
sv_setiv_mg(sv, iv)
	SV *sv;
	IV iv;
	CODE:
		sv_setiv_mg(sv, iv);

void
sv_setnv_mg(sv, nv)
	SV *sv;
	NV nv;
	CODE:
		sv_setnv_mg(sv, nv);

void
sv_setpv_mg(sv, pv)
	SV *sv;
	char *pv;
	CODE:
		sv_setpv_mg(sv, pv);

void
sv_setpvn_mg(sv, sv2)
	SV *sv;
	SV *sv2;
	PREINIT:
		char *str;
		STRLEN len;
	CODE:
		str = SvPV(sv2, len);
		sv_setpvn_mg(sv, str, len);

void
sv_setsv_mg(sv, sv2)
	SV *sv;
	SV *sv2;
	CODE:
		sv_setsv_mg(sv, sv2);

void
sv_setuv_mg(sv, uv)
	SV *sv;
	UV uv;
	CODE:
		sv_setuv_mg(sv, uv);

void
sv_usepvn_mg(sv, sv2)
	SV *sv;
	SV *sv2;
	PREINIT:
		char *str, *copy;
		STRLEN len;
	CODE:
		str = SvPV(sv2, len);
		New(42, copy, len+1, char);
		Copy(str, copy, len+1, char);
		sv_usepvn_mg(sv, copy, len);

int
SvVSTRING_mg(sv)
	SV *sv;
	CODE:
		RETVAL = SvVSTRING_mg(sv) != NULL;
	OUTPUT:
		RETVAL

int
sv_magic_portable(sv)
	SV *sv
	PREINIT:
		MAGIC *mg;
		const char *foo = "foo";
	CODE:
#if (PERL_BCDVERSION >= 0x5004000)
		sv_magic_portable(sv, 0, '~', foo, 0);
		mg = mg_find(sv, '~');
		RETVAL = mg->mg_ptr == foo;
#else
		sv_magic(sv, 0, '~', (char *) foo, strlen(foo));
		mg = mg_find(sv, '~');
		RETVAL = strEQ(mg->mg_ptr, foo);
#endif
		sv_unmagic(sv, '~');
	OUTPUT:
		RETVAL

##----------------------------------------------------------------------
##  XSUBs for testing the implementation in parts/inc/exception
##----------------------------------------------------------------------

int
exception(throw_e)
  int throw_e
  OUTPUT:
    RETVAL

##----------------------------------------------------------------------
##  XSUBs for testing the implementation in parts/inc/newRV
##----------------------------------------------------------------------

U32
newRV_inc_REFCNT()
	PREINIT:
		SV *sv, *rv;
	CODE:
		sv = newSViv(42);
		rv = newRV_inc(sv);
		SvREFCNT_dec(sv);
		RETVAL = SvREFCNT(sv);
		sv_2mortal(rv);
	OUTPUT:
		RETVAL

U32
newRV_noinc_REFCNT()
	PREINIT:
		SV *sv, *rv;
	CODE:
		sv = newSViv(42);
		rv = newRV_noinc(sv);
		RETVAL = SvREFCNT(sv);
		sv_2mortal(rv);
	OUTPUT:
		RETVAL

##----------------------------------------------------------------------
##  XSUBs for testing the implementation in parts/inc/newSVpv
##----------------------------------------------------------------------

void
newSVpvn()
	PPCODE:
		mXPUSHs(newSVpvn("test", 4));
		mXPUSHs(newSVpvn("test", 2));
		mXPUSHs(newSVpvn("test", 0));
		mXPUSHs(newSVpvn(NULL, 2));
		mXPUSHs(newSVpvn(NULL, 0));
		XSRETURN(5);

void
newSVpvn_flags()
	PPCODE:
		XPUSHs(newSVpvn_flags("test", 4, SVs_TEMP));
		XPUSHs(newSVpvn_flags("test", 2, SVs_TEMP));
		XPUSHs(newSVpvn_flags("test", 0, SVs_TEMP));
		XPUSHs(newSVpvn_flags(NULL, 2, SVs_TEMP));
		XPUSHs(newSVpvn_flags(NULL, 0, SVs_TEMP));
		XSRETURN(5);

void
newSVpvn_utf8()
	PPCODE:
		XPUSHs(newSVpvn_flags("test", 4, SVs_TEMP|SVf_UTF8));
		XSRETURN(1);

##----------------------------------------------------------------------
##  XSUBs for testing the implementation in parts/inc/format
##----------------------------------------------------------------------

void
croak_NVgf(num)
	NV num
	PPCODE:
		Perl_croak(aTHX_ "%.20" NVgf "\n", num);

##----------------------------------------------------------------------
##  XSUBs for testing the implementation in parts/inc/SvPV
##----------------------------------------------------------------------

IV
SvPVbyte(sv)
	SV *sv
	PREINIT:
		char *str;
		STRLEN len;
	CODE:
		str = SvPVbyte(sv, len);
		RETVAL = strEQ(str, "mhx") ? (IV) len : (IV) -1;
	OUTPUT:
		RETVAL

IV
SvPV_nolen(sv)
	SV *sv
	PREINIT:
		char *str;
	CODE:
		str = SvPV_nolen(sv);
		RETVAL = strEQ(str, "mhx") ? 42 : 0;
	OUTPUT:
		RETVAL

IV
SvPV_const(sv)
	SV *sv
	PREINIT:
		const char *str;
		STRLEN len;
	CODE:
		str = SvPV_const(sv, len);
		RETVAL = len + (strEQ(str, "mhx") ? 40 : 0);
	OUTPUT:
		RETVAL

IV
SvPV_mutable(sv)
	SV *sv
	PREINIT:
		char *str;
		STRLEN len;
	CODE:
		str = SvPV_mutable(sv, len);
		RETVAL = len + (strEQ(str, "mhx") ? 41 : 0);
	OUTPUT:
		RETVAL

IV
SvPV_flags(sv)
	SV *sv
	PREINIT:
		char *str;
		STRLEN len;
	CODE:
		str = SvPV_flags(sv, len, SV_GMAGIC);
		RETVAL = len + (strEQ(str, "mhx") ? 42 : 0);
	OUTPUT:
		RETVAL

IV
SvPV_flags_const(sv)
	SV *sv
	PREINIT:
		const char *str;
		STRLEN len;
	CODE:
		str = SvPV_flags_const(sv, len, SV_GMAGIC);
		RETVAL = len + (strEQ(str, "mhx") ? 43 : 0);
	OUTPUT:
		RETVAL

IV
SvPV_flags_const_nolen(sv)
	SV *sv
	PREINIT:
		const char *str;
	CODE:
		str = SvPV_flags_const_nolen(sv, SV_GMAGIC);
		RETVAL = strEQ(str, "mhx") ? 47 : 0;
	OUTPUT:
		RETVAL

IV
SvPV_flags_mutable(sv)
	SV *sv
	PREINIT:
		char *str;
		STRLEN len;
	CODE:
		str = SvPV_flags_mutable(sv, len, SV_GMAGIC);
		RETVAL = len + (strEQ(str, "mhx") ? 45 : 0);
	OUTPUT:
		RETVAL

IV
SvPV_force(sv)
	SV *sv
	PREINIT:
		char *str;
		STRLEN len;
	CODE:
		str = SvPV_force(sv, len);
		RETVAL = len + (strEQ(str, "mhx") ? 46 : 0);
	OUTPUT:
		RETVAL

IV
SvPV_force_nolen(sv)
	SV *sv
	PREINIT:
		char *str;
	CODE:
		str = SvPV_force_nolen(sv);
		RETVAL = strEQ(str, "mhx") ? 50 : 0;
	OUTPUT:
		RETVAL

IV
SvPV_force_mutable(sv)
	SV *sv
	PREINIT:
		char *str;
		STRLEN len;
	CODE:
		str = SvPV_force_mutable(sv, len);
		RETVAL = len + (strEQ(str, "mhx") ? 48 : 0);
	OUTPUT:
		RETVAL

IV
SvPV_force_nomg(sv)
	SV *sv
	PREINIT:
		char *str;
		STRLEN len;
	CODE:
		str = SvPV_force_nomg(sv, len);
		RETVAL = len + (strEQ(str, "mhx") ? 49 : 0);
	OUTPUT:
		RETVAL

IV
SvPV_force_nomg_nolen(sv)
	SV *sv
	PREINIT:
		char *str;
	CODE:
		str = SvPV_force_nomg_nolen(sv);
		RETVAL = strEQ(str, "mhx") ? 53 : 0;
	OUTPUT:
		RETVAL

IV
SvPV_force_flags(sv)
	SV *sv
	PREINIT:
		char *str;
		STRLEN len;
	CODE:
		str = SvPV_force_flags(sv, len, SV_GMAGIC);
		RETVAL = len + (strEQ(str, "mhx") ? 51 : 0);
	OUTPUT:
		RETVAL

IV
SvPV_force_flags_nolen(sv)
	SV *sv
	PREINIT:
		char *str;
	CODE:
		str = SvPV_force_flags_nolen(sv, SV_GMAGIC);
		RETVAL = strEQ(str, "mhx") ? 55 : 0;
	OUTPUT:
		RETVAL

IV
SvPV_force_flags_mutable(sv)
	SV *sv
	PREINIT:
		char *str;
		STRLEN len;
	CODE:
		str = SvPV_force_flags_mutable(sv, len, SV_GMAGIC);
		RETVAL = len + (strEQ(str, "mhx") ? 53 : 0);
	OUTPUT:
		RETVAL

IV
SvPV_nolen_const(sv)
	SV *sv
	PREINIT:
		const char *str;
	CODE:
		str = SvPV_nolen_const(sv);
		RETVAL = strEQ(str, "mhx") ? 57 : 0;
	OUTPUT:
		RETVAL

IV
SvPV_nomg(sv)
	SV *sv
	PREINIT:
		char *str;
		STRLEN len;
	CODE:
		str = SvPV_nomg(sv, len);
		RETVAL = len + (strEQ(str, "mhx") ? 55 : 0);
	OUTPUT:
		RETVAL

IV
SvPV_nomg_const(sv)
	SV *sv
	PREINIT:
		const char *str;
		STRLEN len;
	CODE:
		str = SvPV_nomg_const(sv, len);
		RETVAL = len + (strEQ(str, "mhx") ? 56 : 0);
	OUTPUT:
		RETVAL

IV
SvPV_nomg_const_nolen(sv)
	SV *sv
	PREINIT:
		const char *str;
	CODE:
		str = SvPV_nomg_const_nolen(sv);
		RETVAL = strEQ(str, "mhx") ? 60 : 0;
	OUTPUT:
		RETVAL

void
SvPV_renew(sv, nlen, insv)
	SV *sv
	IV nlen
	SV *insv
	PREINIT:
		STRLEN slen;
		const char *str;
	PPCODE:
		str = SvPV_const(insv, slen);
		XPUSHs(sv);
		mXPUSHi(SvLEN(sv));
		SvPV_renew(sv, nlen);
		Copy(str, SvPVX(sv), slen + 1, char);
		SvCUR_set(sv, slen);
		mXPUSHi(SvLEN(sv));

##----------------------------------------------------------------------
##  XSUBs for testing the implementation in parts/inc/strlfuncs
##----------------------------------------------------------------------

void
my_strlfunc()
	PREINIT:
		char buf[8];
		int len;
	PPCODE:
                len = my_strlcpy(buf, "foo", sizeof(buf));
		mXPUSHi(len);
		mXPUSHs(newSVpv(buf, 0));
		len = my_strlcat(buf, "bar", sizeof(buf));
		mXPUSHi(len);
		mXPUSHs(newSVpv(buf, 0));
		len = my_strlcat(buf, "baz", sizeof(buf));
		mXPUSHi(len);
		mXPUSHs(newSVpv(buf, 0));
		len = my_strlcpy(buf, "1234567890", sizeof(buf));
		mXPUSHi(len);
		mXPUSHs(newSVpv(buf, 0));
		len = my_strlcpy(buf, "1234", sizeof(buf));
		mXPUSHi(len);
		mXPUSHs(newSVpv(buf, 0));
		len = my_strlcat(buf, "567890123456", sizeof(buf));
		mXPUSHi(len);
		mXPUSHs(newSVpv(buf, 0));
		XSRETURN(12);

##----------------------------------------------------------------------
##  XSUBs for testing the implementation in parts/inc/grok
##----------------------------------------------------------------------

UV
grok_number(string)
	SV *string
	PREINIT:
		const char *pv;
		STRLEN len;
	CODE:
		pv = SvPV(string, len);
		if (!grok_number(pv, len, &RETVAL))
		  XSRETURN_UNDEF;
	OUTPUT:
		RETVAL

UV
grok_bin(string)
	SV *string
	PREINIT:
		char *pv;
		I32 flags;
		STRLEN len;
	CODE:
		pv = SvPV(string, len);
		RETVAL = grok_bin(pv, &len, &flags, NULL);
	OUTPUT:
		RETVAL

UV
grok_hex(string)
	SV *string
	PREINIT:
		char *pv;
		I32 flags;
		STRLEN len;
	CODE:
		pv = SvPV(string, len);
		RETVAL = grok_hex(pv, &len, &flags, NULL);
	OUTPUT:
		RETVAL

UV
grok_oct(string)
	SV *string
	PREINIT:
		char *pv;
		I32 flags;
		STRLEN len;
	CODE:
		pv = SvPV(string, len);
		RETVAL = grok_oct(pv, &len, &flags, NULL);
	OUTPUT:
		RETVAL

UV
Perl_grok_number(string)
	SV *string
	PREINIT:
		const char *pv;
		STRLEN len;
	CODE:
		pv = SvPV(string, len);
		if (!Perl_grok_number(aTHX_ pv, len, &RETVAL))
		  XSRETURN_UNDEF;
	OUTPUT:
		RETVAL

UV
Perl_grok_bin(string)
	SV *string
	PREINIT:
		char *pv;
		I32 flags;
		STRLEN len;
	CODE:
		pv = SvPV(string, len);
		RETVAL = Perl_grok_bin(aTHX_ pv, &len, &flags, NULL);
	OUTPUT:
		RETVAL

UV
Perl_grok_hex(string)
	SV *string
	PREINIT:
		char *pv;
		I32 flags;
		STRLEN len;
	CODE:
		pv = SvPV(string, len);
		RETVAL = Perl_grok_hex(aTHX_ pv, &len, &flags, NULL);
	OUTPUT:
		RETVAL

UV
Perl_grok_oct(string)
	SV *string
	PREINIT:
		char *pv;
		I32 flags;
		STRLEN len;
	CODE:
		pv = SvPV(string, len);
		RETVAL = Perl_grok_oct(aTHX_ pv, &len, &flags, NULL);
	OUTPUT:
		RETVAL

##----------------------------------------------------------------------
##  XSUBs for testing the implementation in parts/inc/newCONSTSUB
##----------------------------------------------------------------------

void
call_newCONSTSUB_1()

void
call_newCONSTSUB_2()

void
call_newCONSTSUB_3()

##----------------------------------------------------------------------
##  XSUBs for testing the implementation in parts/inc/uv
##----------------------------------------------------------------------

SV *
sv_setuv(uv)
	UV uv
	CODE:
		RETVAL = newSViv(1);
		sv_setuv(RETVAL, uv);
	OUTPUT:
		RETVAL

SV *
newSVuv(uv)
	UV uv
	CODE:
		RETVAL = newSVuv(uv);
	OUTPUT:
		RETVAL

UV
sv_2uv(sv)
	SV *sv
	CODE:
		RETVAL = sv_2uv(sv);
	OUTPUT:
		RETVAL

UV
SvUVx(sv)
	SV *sv
	CODE:
		sv--;
		RETVAL = SvUVx(++sv);
	OUTPUT:
		RETVAL

void
XSRETURN_UV()
	PPCODE:
		XSRETURN_UV(42);

void
PUSHu()
	PREINIT:
		dTARG;
	PPCODE:
		TARG = sv_newmortal();
		EXTEND(SP, 1);
		PUSHu(42);
		XSRETURN(1);

void
XPUSHu()
	PREINIT:
		dTARG;
	PPCODE:
		TARG = sv_newmortal();
		XPUSHu(43);
		XSRETURN(1);

##----------------------------------------------------------------------
##  XSUBs for testing the implementation in parts/inc/call
##----------------------------------------------------------------------

I32
G_SCALAR()
	CODE:
		RETVAL = G_SCALAR;
	OUTPUT:
		RETVAL

I32
G_ARRAY()
	CODE:
		RETVAL = G_ARRAY;
	OUTPUT:
		RETVAL

I32
G_DISCARD()
	CODE:
		RETVAL = G_DISCARD;
	OUTPUT:
		RETVAL

void
eval_sv(sv, flags)
	SV* sv
	I32 flags
	PREINIT:
		I32 i;
	PPCODE:
		PUTBACK;
		i = eval_sv(sv, flags);
		SPAGAIN;
		EXTEND(SP, 1);
		mPUSHi(i);

void
eval_pv(p, croak_on_error)
	char* p
	I32 croak_on_error
	PPCODE:
		PUTBACK;
		EXTEND(SP, 1);
		PUSHs(eval_pv(p, croak_on_error));

void
call_sv(sv, flags, ...)
	SV* sv
	I32 flags
	PREINIT:
		I32 i;
	PPCODE:
		for (i=0; i<items-2; i++)
		  ST(i) = ST(i+2); /* pop first two args */
		PUSHMARK(SP);
		SP += items - 2;
		PUTBACK;
		i = call_sv(sv, flags);
		SPAGAIN;
		EXTEND(SP, 1);
		mPUSHi(i);

void
call_pv(subname, flags, ...)
	char* subname
	I32 flags
	PREINIT:
		I32 i;
	PPCODE:
		for (i=0; i<items-2; i++)
		  ST(i) = ST(i+2); /* pop first two args */
		PUSHMARK(SP);
		SP += items - 2;
		PUTBACK;
		i = call_pv(subname, flags);
		SPAGAIN;
		EXTEND(SP, 1);
		mPUSHi(i);

void
call_argv(subname, flags, ...)
	char* subname
	I32 flags
	PREINIT:
		I32 i;
		char *args[8];
	PPCODE:
		if (items > 8)  /* play safe */
		  XSRETURN_UNDEF;
		for (i=2; i<items; i++)
		  args[i-2] = SvPV_nolen(ST(i));
		args[items-2] = NULL;
		PUTBACK;
		i = call_argv(subname, flags, args);
		SPAGAIN;
		EXTEND(SP, 1);
		mPUSHi(i);

void
call_method(methname, flags, ...)
	char* methname
	I32 flags
	PREINIT:
		I32 i;
	PPCODE:
		for (i=0; i<items-2; i++)
		  ST(i) = ST(i+2); /* pop first two args */
		PUSHMARK(SP);
		SP += items - 2;
		PUTBACK;
		i = call_method(methname, flags);
		SPAGAIN;
		EXTEND(SP, 1);
		mPUSHi(i);

void
call_sv_G_METHOD(sv, flags, ...)
	SV* sv
	I32 flags
	PREINIT:
		I32 i;
	PPCODE:
		for (i=0; i<items-2; i++)
		  ST(i) = ST(i+2); /* pop first two args */
		PUSHMARK(SP);
		SP += items - 2;
		PUTBACK;
		i = call_sv(sv, flags | G_METHOD);
		SPAGAIN;
		EXTEND(SP, 1);
		mPUSHi(i);

void
load_module(flags, name, version, ...)
	U32 flags
	SV *name
	SV *version
	CODE:
		/* Both SV parameters are donated to the ops built inside
		   load_module, so we need to bump the refcounts.  */
		Perl_load_module(aTHX_ flags, SvREFCNT_inc_simple(name),
		                 SvREFCNT_inc_simple(version), NULL);

##----------------------------------------------------------------------
##  XSUBs for testing the implementation in parts/inc/gv
##----------------------------------------------------------------------

int
GvSVn()
	PREINIT:
		GV* gv;
	CODE:
		RETVAL = 0;
		gv = gv_fetchpvs("Devel::PPPort::GvTest", GV_ADDMULTI, SVt_PVGV);
		if (GvSVn(gv) != NULL)
		{
		  RETVAL++;
		}
	OUTPUT:
		RETVAL

int
isGV_with_GP()
	PREINIT:
		GV* gv;
	CODE:
		RETVAL = 0;
		gv = gv_fetchpvs("Devel::PPPort::GvTest", GV_ADDMULTI, SVt_PVGV);
		if (isGV_with_GP(gv))
		{
		  RETVAL++;
		}
		if (!isGV(&PL_sv_undef))
		{
		  RETVAL++;
		}
	OUTPUT:
		RETVAL

##----------------------------------------------------------------------
##  XSUBs for testing the implementation in parts/inc/threads
##----------------------------------------------------------------------

IV
no_THX_arg(sv)
	SV *sv
	CODE:
		RETVAL = 1 + sv_2iv(sv);
	OUTPUT:
		RETVAL

void
with_THX_arg(error)
	char *error
	PPCODE:
		Perl_croak(aTHX_ "%s", error);

##----------------------------------------------------------------------
##  XSUBs for testing the implementation in parts/inc/pv_tools
##----------------------------------------------------------------------

void
pv_escape_can_unicode()
	PPCODE:
#if defined(is_utf8_string) && defined(utf8_to_uvchr)
		XSRETURN_YES;
#else
		XSRETURN_NO;
#endif

void
pv_pretty()
	PREINIT:
		char *rv;
	PPCODE:
		EXTEND(SP, 8);
		ST(0) = sv_newmortal();
		rv = pv_pretty(ST(0), "foobarbaz",
				9, 40, NULL, NULL, 0);
		ST(1) = sv_2mortal(newSVpv(rv, 0));
		ST(2) = sv_newmortal();
		rv = pv_pretty(ST(2), "pv_p\retty\n",
				10, 40, "left", "right", PERL_PV_PRETTY_LTGT);
		ST(3) = sv_2mortal(newSVpv(rv, 0));
		ST(4) = sv_newmortal();
		rv = pv_pretty(ST(4), "N\303\275 Batter\303\255",
				12, 20, NULL, NULL, PERL_PV_ESCAPE_UNI_DETECT);
		ST(5) = sv_2mortal(newSVpv(rv, 0));
		ST(6) = sv_newmortal();
		rv = pv_pretty(ST(6), "\303\201g\303\246tis Byrjun",
				15, 18, NULL, NULL, PERL_PV_ESCAPE_UNI_DETECT|PERL_PV_PRETTY_ELLIPSES);
		ST(7) = sv_2mortal(newSVpv(rv, 0));
		XSRETURN(8);

void
pv_display()
	PREINIT:
		char *rv;
	PPCODE:
		EXTEND(SP, 4);
		ST(0) = sv_newmortal();
		rv = pv_display(ST(0), "foob\0rbaz", 9, 10, 20);
		ST(1) = sv_2mortal(newSVpv(rv, 0));
		ST(2) = sv_newmortal();
		rv = pv_display(ST(2), "pv_display", 10, 11, 5);
		ST(3) = sv_2mortal(newSVpv(rv, 0));
		XSRETURN(4);

##----------------------------------------------------------------------
##  XSUBs for testing the implementation in parts/inc/variables
##----------------------------------------------------------------------

int
compare_PL_signals()
	CODE:
		{
		  U32 ref = get_PL_signals_1();
		  RETVAL = ref == get_PL_signals_2() && ref == get_PL_signals_3();
		}
	OUTPUT:
		RETVAL

SV *
PL_sv_undef()
	CODE:
		RETVAL = newSVsv(&PL_sv_undef);
	OUTPUT:
		RETVAL

SV *
PL_sv_yes()
	CODE:
		RETVAL = newSVsv(&PL_sv_yes);
	OUTPUT:
		RETVAL

SV *
PL_sv_no()
	CODE:
		RETVAL = newSVsv(&PL_sv_no);
	OUTPUT:
		RETVAL

int
PL_na(string)
	char *string
	CODE:
		PL_na = strlen(string);
		RETVAL = PL_na;
	OUTPUT:
		RETVAL

SV *
PL_Sv()
	CODE:
		PL_Sv = newSVpv("mhx", 0);
		RETVAL = PL_Sv;
	OUTPUT:
		RETVAL

SV *
PL_tokenbuf()
	CODE:
		RETVAL = newSViv(PL_tokenbuf[0]);
	OUTPUT:
		RETVAL

SV *
PL_parser()
	CODE:
		RETVAL = newSViv(PL_parser != NULL);
	OUTPUT:
		RETVAL

SV *
PL_hexdigit()
	CODE:
		RETVAL = newSVpv((char *) PL_hexdigit, 0);
	OUTPUT:
		RETVAL

SV *
PL_hints()
	CODE:
		RETVAL = newSViv((IV) PL_hints);
	OUTPUT:
		RETVAL

void
PL_ppaddr(string)
	char *string
	PPCODE:
		PUSHMARK(SP);
		mXPUSHs(newSVpv(string, 0));
		PUTBACK;
		ENTER;
		(void)*(PL_ppaddr[OP_UC])(aTHXR);
		SPAGAIN;
		LEAVE;
		XSRETURN(1);

void
other_variables()
	PREINIT:
		int count = 0;
	PPCODE:
		ppp_TESTVAR(PL_DBsignal);
		ppp_TESTVAR(PL_DBsingle);
		ppp_TESTVAR(PL_DBsub);
		ppp_TESTVAR(PL_DBtrace);
		ppp_TESTVAR(PL_compiling);
		ppp_TESTVAR(PL_curcop);
		ppp_TESTVAR(PL_curstash);
		ppp_TESTVAR(PL_debstash);
		ppp_TESTVAR(PL_defgv);
		ppp_TESTVAR(PL_diehook);
#if defined(PL_phase) || defined(PL_Iphase)
		ppp_PARSERVAR_dummy;
#else
		ppp_TESTVAR(PL_dirty);
#endif
		ppp_TESTVAR(PL_dowarn);
		ppp_TESTVAR(PL_errgv);
		ppp_TESTVAR(PL_laststatval);
		ppp_TESTVAR(PL_no_modify);
		ppp_TESTVAR(PL_perl_destruct_level);
		ppp_TESTVAR(PL_perldb);
		ppp_TESTVAR(PL_stack_base);
		ppp_TESTVAR(PL_stack_sp);
		ppp_TESTVAR(PL_statcache);
		ppp_TESTVAR(PL_stdingv);
		ppp_TESTVAR(PL_sv_arenaroot);
		ppp_TESTVAR(PL_tainted);
		ppp_TESTVAR(PL_tainting);

		ppp_PARSERVAR(ppp_expect_t, PL_expect);
		ppp_PARSERVAR(line_t, PL_copline);
		ppp_PARSERVAR(ppp_rsfp_t, PL_rsfp);
		ppp_PARSERVAR(AV *, PL_rsfp_filters);
		ppp_PARSERVAR(SV *, PL_linestr);
		ppp_PARSERVAR(char *, PL_bufptr);
		ppp_PARSERVAR(char *, PL_bufend);
		ppp_PARSERVAR(ppp_lex_state_t, PL_lex_state);
		ppp_PARSERVAR(SV *, PL_lex_stuff);
		ppp_PARSERVAR(ppp_error_count_t, PL_error_count);
		ppp_PARSERVAR(ppp_in_my_t, PL_in_my);
#if (PERL_BCDVERSION >= 0x5005000)
		ppp_PARSERVAR(HV*, PL_in_my_stash);
#else
		ppp_PARSERVAR_dummy;
#endif
		XSRETURN(count);

int
no_dummy_parser_vars(check)
	int check

int
dummy_parser_warning()

##----------------------------------------------------------------------
##  XSUBs for testing the implementation in parts/inc/MY_CXT
##----------------------------------------------------------------------

int
MY_CXT_1()
	CODE:
		dMY_CXT;
		RETVAL = MY_CXT.dummy == 42;
		++MY_CXT.dummy;
	OUTPUT:
		RETVAL

int
MY_CXT_2()
	CODE:
		dMY_CXT;
		RETVAL = MY_CXT.dummy == 43;
	OUTPUT:
		RETVAL

int
MY_CXT_CLONE()
	CODE:
		MY_CXT_CLONE;
		RETVAL = 42;
	OUTPUT:
		RETVAL

##----------------------------------------------------------------------
##  XSUBs for testing the implementation in parts/inc/sprintf
##----------------------------------------------------------------------

void
my_sprintf()
	PREINIT:
		char buf[128];
		int len;
	PPCODE:
		len = my_sprintf(buf, "foo%s%d", "bar", 42);
		mXPUSHi(len);
		mXPUSHs(newSVpv(buf, 0));
		XSRETURN(2);

##----------------------------------------------------------------------
##  XSUBs for testing the implementation in parts/inc/snprintf
##----------------------------------------------------------------------

void
my_snprintf()
	PREINIT:
		char buf[128];
		int len;
	PPCODE:
		len = my_snprintf(buf, sizeof buf, "foo%s%d", "bar", 42);
		mXPUSHi(len);
		mXPUSHs(newSVpv(buf, 0));
		XSRETURN(2);

##----------------------------------------------------------------------
##  XSUBs for testing the implementation in parts/inc/cop
##----------------------------------------------------------------------

char *
CopSTASHPV()
	CODE:
		RETVAL = CopSTASHPV(PL_curcop);
	OUTPUT:
		RETVAL

char *
CopFILE()
	CODE:
		RETVAL = CopFILE(PL_curcop);
	OUTPUT:
		RETVAL

##----------------------------------------------------------------------
##  XSUBs for testing the implementation in parts/inc/sv_xpvf
##----------------------------------------------------------------------

SV *
vnewSVpvf()
	CODE:
		RETVAL = test_vnewSVpvf(aTHX_ "%s-%d", "Perl", 42);
	OUTPUT:
		RETVAL

SV *
sv_vcatpvf(sv)
	SV *sv
	CODE:
		RETVAL = newSVsv(sv);
		test_sv_vcatpvf(aTHX_ RETVAL, "%s-%d", "Perl", 42);
	OUTPUT:
		RETVAL

SV *
sv_vsetpvf(sv)
	SV *sv
	CODE:
		RETVAL = newSVsv(sv);
		test_sv_vsetpvf(aTHX_ RETVAL, "%s-%d", "Perl", 42);
	OUTPUT:
		RETVAL

void
sv_catpvf_mg(sv)
	SV *sv
	CODE:
#if (PERL_BCDVERSION >= 0x5004000)
		sv_catpvf_mg(sv, "%s-%d", "Perl", 42);
#endif

void
Perl_sv_catpvf_mg(sv)
	SV *sv
	CODE:
#if (PERL_BCDVERSION >= 0x5004000)
		Perl_sv_catpvf_mg(aTHX_ sv, "%s-%d", "-Perl", 43);
#endif

void
sv_catpvf_mg_nocontext(sv)
	SV *sv
	CODE:
#if (PERL_BCDVERSION >= 0x5004000)
#ifdef PERL_IMPLICIT_CONTEXT
		sv_catpvf_mg_nocontext(sv, "%s-%d", "-Perl", 44);
#else
		sv_catpvf_mg(sv, "%s-%d", "-Perl", 44);
#endif
#endif

void
sv_setpvf_mg(sv)
	SV *sv
	CODE:
#if (PERL_BCDVERSION >= 0x5004000)
		sv_setpvf_mg(sv, "%s-%d", "mhx", 42);
#endif

void
Perl_sv_setpvf_mg(sv)
	SV *sv
	CODE:
#if (PERL_BCDVERSION >= 0x5004000)
		Perl_sv_setpvf_mg(aTHX_ sv, "%s-%d", "foo", 43);
#endif

void
sv_setpvf_mg_nocontext(sv)
	SV *sv
	CODE:
#if (PERL_BCDVERSION >= 0x5004000)
#ifdef PERL_IMPLICIT_CONTEXT
		sv_setpvf_mg_nocontext(sv, "%s-%d", "bar", 44);
#else
		sv_setpvf_mg(sv, "%s-%d", "bar", 44);
#endif
#endif

##----------------------------------------------------------------------
##  XSUBs for testing the implementation in parts/inc/newSV_type
##----------------------------------------------------------------------

int
newSV_type()
	PREINIT:
		SV* sv;
	CODE:
		RETVAL = 0;
		sv = newSV_type(SVt_NULL);
		if (SvTYPE(sv) == SVt_NULL)
		{
		  RETVAL++;
		}
		SvREFCNT_dec(sv);

		sv = newSV_type(SVt_PVIV);
		if (SvTYPE(sv) == SVt_PVIV)
		{
		  RETVAL++;
		}
		SvREFCNT_dec(sv);

		sv = newSV_type(SVt_PVHV);
		if (SvTYPE(sv) == SVt_PVHV)
		{
		  RETVAL++;
		}
		SvREFCNT_dec(sv);

		sv = newSV_type(SVt_PVAV);
		if (SvTYPE(sv) == SVt_PVAV)
		{
		  RETVAL++;
		}
		SvREFCNT_dec(sv);
	OUTPUT:
		RETVAL

##----------------------------------------------------------------------
##  XSUBs for testing the implementation in parts/inc/pvs
##----------------------------------------------------------------------

void
newSVpvs()
	PPCODE:
		mXPUSHs(newSVpvs("newSVpvs"));
		XSRETURN(1);

void
newSVpvs_flags()
	PPCODE:
		XPUSHs(newSVpvs_flags("newSVpvs_flags", SVs_TEMP));
		XSRETURN(1);

void
sv_catpvs(sv)
	SV *sv
	PPCODE:
		sv_catpvs(sv, "sv_catpvs");

void
sv_setpvs(sv)
	SV *sv
	PPCODE:
		sv_setpvs(sv, "sv_setpvs");

void
hv_fetchs(hv)
	SV *hv
	PREINIT:
		SV **s;
	PPCODE:
		s = hv_fetchs((HV *) SvRV(hv), "hv_fetchs", 0);
		XPUSHs(sv_mortalcopy(*s));
		XSRETURN(1);

void
hv_stores(hv, sv)
	SV *hv
	SV *sv
	PPCODE:
		(void) hv_stores((HV *) SvRV(hv), "hv_stores", SvREFCNT_inc_simple(sv));

SV*
gv_fetchpvn_flags()
	CODE:
		RETVAL = newRV_inc((SV*)gv_fetchpvn_flags("Devel::PPPort::VERSION", sizeof("Devel::PPPort::VERSION")-1, 0, SVt_PV));
	OUTPUT:
		RETVAL

SV*
gv_fetchpvs()
	CODE:
		RETVAL = newRV_inc((SV*)gv_fetchpvs("Devel::PPPort::VERSION", 0, SVt_PV));
	OUTPUT:
		RETVAL

SV*
gv_stashpvs()
	CODE:
		RETVAL = newRV_inc((SV*)gv_stashpvs("Devel::PPPort", 0));
	OUTPUT:
		RETVAL

##----------------------------------------------------------------------
##  XSUBs for testing the implementation in parts/inc/limits
##----------------------------------------------------------------------

IV
iv_size()
	CODE:
		RETVAL = IVSIZE == sizeof(IV);
	OUTPUT:
		RETVAL

IV
uv_size()
	CODE:
		RETVAL = UVSIZE == sizeof(UV);
	OUTPUT:
		RETVAL

IV
iv_type()
	CODE:
		RETVAL = sizeof(IVTYPE) == sizeof(IV);
	OUTPUT:
		RETVAL

IV
uv_type()
	CODE:
		RETVAL = sizeof(UVTYPE) == sizeof(UV);
	OUTPUT:
		RETVAL

##----------------------------------------------------------------------
##  XSUBs for testing the implementation in parts/inc/shared_pv
##----------------------------------------------------------------------

int
newSVpvn_share()
	PREINIT:
		const char *s;
		SV *sv;
		STRLEN len;
		U32 hash;
	CODE:
		RETVAL = 0;
		s = "mhx";
		len = 3;
		PERL_HASH(hash, (char *) s, len);
		sv = newSVpvn_share(s, len, 0);
		s = 0;
		RETVAL += strEQ(SvPV_nolen_const(sv), "mhx");
		RETVAL += SvCUR(sv) == len;
		RETVAL += SvSHARED_HASH(sv) == hash;
		SvREFCNT_dec(sv);
		s = "foobar";
		len = 6;
		PERL_HASH(hash, (char *) s, len);
		sv = newSVpvn_share(s, -(I32) len, hash);
		s = 0;
		RETVAL += strEQ(SvPV_nolen_const(sv), "foobar");
		RETVAL += SvCUR(sv) == len;
		RETVAL += SvSHARED_HASH(sv) == hash;
		SvREFCNT_dec(sv);
	OUTPUT:
		RETVAL

##----------------------------------------------------------------------
##  XSUBs for testing the implementation in parts/inc/Sv_set
##----------------------------------------------------------------------

IV
TestSvUV_set(sv, val)
	SV *sv
	UV val
	CODE:
		SvUV_set(sv, val);
		RETVAL = SvUVX(sv) == val ? 42 : -1;
	OUTPUT:
		RETVAL

IV
TestSvPVX_const(sv)
        SV *sv
        CODE:
                RETVAL = strEQ(SvPVX_const(sv), "mhx") ? 43 : -1;
        OUTPUT:
                RETVAL

IV
TestSvPVX_mutable(sv)
        SV *sv
        CODE:
                RETVAL = strEQ(SvPVX_mutable(sv), "mhx") ? 44 : -1;
        OUTPUT:
                RETVAL

void
TestSvSTASH_set(sv, name)
        SV *sv
	char *name
        CODE:
		sv = SvRV(sv);
		SvREFCNT_dec(SvSTASH(sv));
                SvSTASH_set(sv, (HV*) SvREFCNT_inc(gv_stashpv(name, 0)));

##----------------------------------------------------------------------
##  XSUBs for testing the implementation in parts/inc/HvNAME
##----------------------------------------------------------------------

char*
HvNAME_get(hv)
	HV *hv

int
HvNAMELEN_get(hv)
	HV *hv

##----------------------------------------------------------------------
##  XSUBs for testing the implementation in parts/inc/misc
##----------------------------------------------------------------------

int
ptrtests()
	PREINIT:
		int var, *p = &var;

	CODE:
		RETVAL = 0;
		RETVAL += PTR2nat(p) != 0       ?  1 : 0;
		RETVAL += PTR2ul(p) != 0UL      ?  2 : 0;
		RETVAL += PTR2UV(p) != (UV) 0   ?  4 : 0;
		RETVAL += PTR2IV(p) != (IV) 0   ?  8 : 0;
		RETVAL += PTR2NV(p) != (NV) 0   ? 16 : 0;
		RETVAL += p > NUM2PTR(int *, 0) ? 32 : 0;

	OUTPUT:
		RETVAL

int
gv_stashpvn(name, create)
	char *name
	I32 create
	CODE:
		RETVAL = gv_stashpvn(name, strlen(name), create) != NULL;
	OUTPUT:
		RETVAL

int
get_sv(name, create)
	char *name
	I32 create
	CODE:
		RETVAL = get_sv(name, create) != NULL;
	OUTPUT:
		RETVAL

int
get_av(name, create)
	char *name
	I32 create
	CODE:
		RETVAL = get_av(name, create) != NULL;
	OUTPUT:
		RETVAL

int
get_hv(name, create)
	char *name
	I32 create
	CODE:
		RETVAL = get_hv(name, create) != NULL;
	OUTPUT:
		RETVAL

int
get_cv(name, create)
	char *name
	I32 create
	CODE:
		RETVAL = get_cv(name, create) != NULL;
	OUTPUT:
		RETVAL

void
xsreturn(two)
	int two
	PPCODE:
		mXPUSHp("test1", 5);
		if (two)
		  mXPUSHp("test2", 5);
		if (two)
		  XSRETURN(2);
		else
		  XSRETURN(1);

SV*
boolSV(value)
	int value
	CODE:
		RETVAL = newSVsv(boolSV(value));
	OUTPUT:
		RETVAL

SV*
DEFSV()
	CODE:
		RETVAL = newSVsv(DEFSV);
	OUTPUT:
		RETVAL

void
DEFSV_modify()
	PPCODE:
		XPUSHs(sv_mortalcopy(DEFSV));
		ENTER;
		SAVE_DEFSV;
		DEFSV_set(newSVpvs("DEFSV"));
		XPUSHs(sv_mortalcopy(DEFSV));
		/* Yes, this leaks the above scalar; 5.005 with threads for some reason */
		/* frees it upon LEAVE, thus mortalizing it causes "attempt to free..." */
		/* sv_2mortal(DEFSV); */
		LEAVE;
		XPUSHs(sv_mortalcopy(DEFSV));
		XSRETURN(3);

int
ERRSV()
	CODE:
		RETVAL = SvTRUE(ERRSV);
	OUTPUT:
		RETVAL

SV*
UNDERBAR()
	CODE:
		{
		  dUNDERBAR;
		  RETVAL = newSVsv(UNDERBAR);
		}
	OUTPUT:
		RETVAL

void
prepush()
	CODE:
		{
		  dXSTARG;
		  XSprePUSH;
		  PUSHi(42);
		  XSRETURN(1);
		}

int
PERL_ABS(a)
	int a

void
SVf(x)
	SV *x
	PPCODE:
#if (PERL_BCDVERSION >= 0x5004000)
		x = sv_2mortal(newSVpvf("[%"SVf"]", SVfARG(x)));
#endif
		XPUSHs(x);
		XSRETURN(1);

void
Perl_ppaddr_t(string)
	char *string
	PREINIT:
		Perl_ppaddr_t lower;
	PPCODE:
		lower = PL_ppaddr[OP_LC];
		PUSHMARK(SP);
		mXPUSHs(newSVpv(string, 0));
		PUTBACK;
		ENTER;
		(void)*(lower)(aTHXR);
		SPAGAIN;
		LEAVE;
		XSRETURN(1);
