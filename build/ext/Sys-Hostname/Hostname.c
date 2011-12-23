/*
 * This file was generated automatically by ExtUtils::ParseXS version 2.2210 from the
 * contents of Hostname.xs. Do not edit this file, edit Hostname.xs instead.
 *
 *	ANY CHANGES MADE HERE WILL BE LOST! 
 *
 */

#line 1 "Hostname.xs"
#define PERL_NO_GET_CONTEXT

#include "EXTERN.h"
#include "perl.h"
#include "XSUB.h"

#if defined(I_UNISTD) && defined(HAS_GETHOSTNAME)
# include <unistd.h>
#endif

/* a reasonable default */
#ifndef MAXHOSTNAMELEN
#  define MAXHOSTNAMELEN	256
#endif

/* swiped from POSIX.xs */
#if defined(__VMS) && !defined(__POSIX_SOURCE)
#  if ((__VMS_VER >= 70000000) && (__DECC_VER >= 50200000)) || (__CRTL_VER >= 70000000)
#    include <utsname.h>
#  endif
#endif

#ifdef I_SYSUTSNAME
#  include <sys/utsname.h>
#endif

#line 37 "Hostname.c"
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

#line 89 "Hostname.c"

XS(XS_Sys__Hostname_ghname); /* prototype to pass -Wmissing-prototypes */
XS(XS_Sys__Hostname_ghname)
{
#ifdef dVAR
    dVAR; dXSARGS;
#else
    dXSARGS;
#endif
    if (items != 0)
       croak_xs_usage(cv,  "");
    PERL_UNUSED_VAR(ax); /* -Wall */
    SP -= items;
    {
#line 32 "Hostname.xs"
    IV   retval = -1;
    SV  *sv;
#line 107 "Hostname.c"
#line 35 "Hostname.xs"
    EXTEND(SP, 1);
#ifdef HAS_GETHOSTNAME
    {
	char tmps[MAXHOSTNAMELEN];
	retval = PerlSock_gethostname(tmps, sizeof(tmps));
	sv = newSVpv(tmps, 0);
    }
#else
#  ifdef HAS_PHOSTNAME
    {
	PerlIO *io;
	char tmps[MAXHOSTNAMELEN];
	char   *p = tmps;
        char    c;
	io = PerlProc_popen(PHOSTNAME, "r");
	if (!io)
	    goto check_out;
	while (PerlIO_read(io, &c, sizeof(c)) == 1) {
	    if (isSPACE(c) || p - tmps >= sizeof(tmps))
		break;
	    *p++ = c;
	}
	PerlProc_pclose(io);
	retval = 0;
	sv = newSVpvn(tmps, p - tmps);
    }
#  else
#    ifdef HAS_UNAME
    {
	struct utsname u;
	if (PerlEnv_uname(&u) == -1)
	    goto check_out;
	sv = newSVpv(u.nodename, 0);
        retval = 0;
    }
#    endif
#  endif
#endif
#ifndef HAS_GETHOSTNAME
    check_out:
#endif
    if (retval == -1)
	XSRETURN_UNDEF;
    else
	PUSHs(sv_2mortal(sv));
#line 154 "Hostname.c"
	PUTBACK;
	return;
    }
}

#ifdef __cplusplus
extern "C"
#endif
XS(boot_Sys__Hostname); /* prototype to pass -Wmissing-prototypes */
XS(boot_Sys__Hostname)
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

        newXS("Sys::Hostname::ghname", XS_Sys__Hostname_ghname, file);
#if (PERL_REVISION == 5 && PERL_VERSION >= 9)
  if (PL_unitcheckav)
       call_list(PL_scopestack_ix, PL_unitcheckav);
#endif
    XSRETURN_YES;
}
