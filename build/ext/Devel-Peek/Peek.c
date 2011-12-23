/*
 * This file was generated automatically by ExtUtils::ParseXS version 2.2210 from the
 * contents of Peek.xs. Do not edit this file, edit Peek.xs instead.
 *
 *	ANY CHANGES MADE HERE WILL BE LOST! 
 *
 */

#line 1 "Peek.xs"
#define PERL_NO_GET_CONTEXT
#include "EXTERN.h"
#include "perl.h"
#include "XSUB.h"

static bool
_runops_debug(int flag)
{
    dTHX;
    const bool d = PL_runops == Perl_runops_debug;

    if (flag >= 0)
	PL_runops = flag ? Perl_runops_debug : Perl_runops_standard;
    return d;
}

static SV *
DeadCode(pTHX)
{
#ifdef PURIFY
    return Nullsv;
#else
    SV* sva;
    SV* sv;
    SV* ret = newRV_noinc((SV*)newAV());
    register SV* svend;
    int tm = 0, tref = 0, ts = 0, ta = 0, tas = 0;

    for (sva = PL_sv_arenaroot; sva; sva = (SV*)SvANY(sva)) {
	svend = &sva[SvREFCNT(sva)];
	for (sv = sva + 1; sv < svend; ++sv) {
	    if (SvTYPE(sv) == SVt_PVCV) {
		CV *cv = (CV*)sv;
		AV* padlist = CvPADLIST(cv), *argav;
		SV** svp;
		SV** pad;
		int i = 0, j, levelm, totm = 0, levelref, totref = 0;
		int levels, tots = 0, levela, tota = 0, levelas, totas = 0;
		int dumpit = 0;

		if (CvISXSUB(sv)) {
		    continue;		/* XSUB */
		}
		if (!CvGV(sv)) {
		    continue;		/* file-level scope. */
		}
		if (!CvROOT(cv)) {
		    /* PerlIO_printf(Perl_debug_log, "  no root?!\n"); */
		    continue;		/* autoloading stub. */
		}
		do_gvgv_dump(0, Perl_debug_log, "GVGV::GV", CvGV(sv));
		if (CvDEPTH(cv)) {
		    PerlIO_printf(Perl_debug_log, "  busy\n");
		    continue;
		}
		svp = AvARRAY(padlist);
		while (++i <= AvFILL(padlist)) { /* Depth. */
		    SV **args;
		    
		    pad = AvARRAY((AV*)svp[i]);
		    argav = (AV*)pad[0];
		    if (!argav || (SV*)argav == &PL_sv_undef) {
			PerlIO_printf(Perl_debug_log, "    closure-template\n");
			continue;
		    }
		    args = AvARRAY(argav);
		    levelm = levels = levelref = levelas = 0;
		    levela = sizeof(SV*) * (AvMAX(argav) + 1);
		    if (AvREAL(argav)) {
			for (j = 0; j < AvFILL(argav); j++) {
			    if (SvROK(args[j])) {
				PerlIO_printf(Perl_debug_log, "     ref in args!\n");
				levelref++;
			    }
			    /* else if (SvPOK(args[j]) && SvPVX(args[j])) { */
			    else if (SvTYPE(args[j]) >= SVt_PV && SvLEN(args[j])) {
				levelas += SvLEN(args[j])/SvREFCNT(args[j]);
			    }
			}
		    }
		    for (j = 1; j < AvFILL((AV*)svp[1]); j++) {	/* Vars. */
			if (SvROK(pad[j])) {
			    levelref++;
			    do_sv_dump(0, Perl_debug_log, pad[j], 0, 4, 0, 0);
			    dumpit = 1;
			}
			/* else if (SvPOK(pad[j]) && SvPVX(pad[j])) { */
			else if (SvTYPE(pad[j]) >= SVt_PVAV) {
			    if (!SvPADMY(pad[j])) {
				levelref++;
				do_sv_dump(0, Perl_debug_log, pad[j], 0, 4, 0, 0);
				dumpit = 1;
			    }
			}
			else if (SvTYPE(pad[j]) >= SVt_PV && SvLEN(pad[j])) {
			    levels++;
			    levelm += SvLEN(pad[j])/SvREFCNT(pad[j]);
				/* Dump(pad[j],4); */
			}
		    }
		    PerlIO_printf(Perl_debug_log, "    level %i: refs: %i, strings: %i in %i,\targsarray: %i, argsstrings: %i\n", 
			    i, levelref, levelm, levels, levela, levelas);
		    totm += levelm;
		    tota += levela;
		    totas += levelas;
		    tots += levels;
		    totref += levelref;
		    if (dumpit)
			do_sv_dump(0, Perl_debug_log, (SV*)cv, 0, 2, 0, 0);
		}
		if (AvFILL(padlist) > 1) {
		    PerlIO_printf(Perl_debug_log, "  total: refs: %i, strings: %i in %i,\targsarrays: %i, argsstrings: %i\n", 
			    totref, totm, tots, tota, totas);
		}
		tref += totref;
		tm += totm;
		ts += tots;
		ta += tota;
		tas += totas;
	    }
	}
    }
    PerlIO_printf(Perl_debug_log, "total: refs: %i, strings: %i in %i\targsarray: %i, argsstrings: %i\n", tref, tm, ts, ta, tas);

    return ret;
#endif /* !PURIFY */
}

#if defined(MYMALLOC)
#   define mstat(str) dump_mstats(str)
#else
#   define mstat(str) \
	PerlIO_printf(Perl_debug_log, "%s: perl not compiled with MYMALLOC\n",str);
#endif

#if defined(MYMALLOC)

/* Very coarse overestimate, 2-per-power-of-2, one more to determine NBUCKETS. */
#  define _NBUCKETS (2*8*IVSIZE+1)

struct mstats_buffer 
{
    perl_mstats_t buffer;
    UV buf[_NBUCKETS*4];
};

static void
_fill_mstats(struct mstats_buffer *b, int level)
{
    dTHX;
    b->buffer.nfree  = b->buf;
    b->buffer.ntotal = b->buf + _NBUCKETS;
    b->buffer.bucket_mem_size = b->buf + 2*_NBUCKETS;
    b->buffer.bucket_available_size = b->buf + 3*_NBUCKETS;
    Zero(b->buf, (level ? 4*_NBUCKETS: 2*_NBUCKETS), unsigned long);
    get_mstats(&(b->buffer), _NBUCKETS, level);
}

static void
fill_mstats(SV *sv, int level)
{
    dTHX;

    if (SvREADONLY(sv))
	croak("Cannot modify a readonly value");
    SvGROW(sv, sizeof(struct mstats_buffer)+1);
    _fill_mstats((struct mstats_buffer*)SvPVX(sv),level);
    SvCUR_set(sv, sizeof(struct mstats_buffer));
    *SvEND(sv) = '\0';
    SvPOK_only(sv);
}

static void
_mstats_to_hv(HV *hv, const struct mstats_buffer *b, int level)
{
    dTHX;
    SV **svp;
    int type;

    svp = hv_fetch(hv, "topbucket", 9, 1);
    sv_setiv(*svp, b->buffer.topbucket);

    svp = hv_fetch(hv, "topbucket_ev", 12, 1);
    sv_setiv(*svp, b->buffer.topbucket_ev);

    svp = hv_fetch(hv, "topbucket_odd", 13, 1);
    sv_setiv(*svp, b->buffer.topbucket_odd);

    svp = hv_fetch(hv, "totfree", 7, 1);
    sv_setiv(*svp, b->buffer.totfree);

    svp = hv_fetch(hv, "total", 5, 1);
    sv_setiv(*svp, b->buffer.total);

    svp = hv_fetch(hv, "total_chain", 11, 1);
    sv_setiv(*svp, b->buffer.total_chain);

    svp = hv_fetch(hv, "total_sbrk", 10, 1);
    sv_setiv(*svp, b->buffer.total_sbrk);

    svp = hv_fetch(hv, "sbrks", 5, 1);
    sv_setiv(*svp, b->buffer.sbrks);

    svp = hv_fetch(hv, "sbrk_good", 9, 1);
    sv_setiv(*svp, b->buffer.sbrk_good);

    svp = hv_fetch(hv, "sbrk_slack", 10, 1);
    sv_setiv(*svp, b->buffer.sbrk_slack);

    svp = hv_fetch(hv, "start_slack", 11, 1);
    sv_setiv(*svp, b->buffer.start_slack);

    svp = hv_fetch(hv, "sbrked_remains", 14, 1);
    sv_setiv(*svp, b->buffer.sbrked_remains);
    
    svp = hv_fetch(hv, "minbucket", 9, 1);
    sv_setiv(*svp, b->buffer.minbucket);
    
    svp = hv_fetch(hv, "nbuckets", 8, 1);
    sv_setiv(*svp, b->buffer.nbuckets);

    if (_NBUCKETS < b->buffer.nbuckets) 
	warn("FIXME: internal mstats buffer too short");
    
    for (type = 0; type < (level ? 4 : 2); type++) {
	UV *p = 0, *p1 = 0, i;
	AV *av;
	static const char *types[4] = { 
	    "free", "used", "mem_size", "available_size"    
	};

	svp = hv_fetch(hv, types[type], strlen(types[type]), 1);

	if (SvOK(*svp) && !(SvROK(*svp) && SvTYPE(SvRV(*svp)) == SVt_PVAV))
	    croak("Unexpected value for the key '%s' in the mstats hash", types[type]);
	if (!SvOK(*svp)) {
	    av = newAV();
	    (void)SvUPGRADE(*svp, SVt_RV);
	    SvRV_set(*svp, (SV*)av);
	    SvROK_on(*svp);
	} else
	    av = (AV*)SvRV(*svp);

	av_extend(av, b->buffer.nbuckets - 1);
	/* XXXX What is the official way to reduce the size of the array? */
	switch (type) {
	case 0:
	    p = b->buffer.nfree;
	    break;
	case 1:
	    p = b->buffer.ntotal;
	    p1 = b->buffer.nfree;
	    break;
	case 2:
	    p = b->buffer.bucket_mem_size;
	    break;
	case 3:
	    p = b->buffer.bucket_available_size;
	    break;
	}
	for (i = 0; i < b->buffer.nbuckets; i++) {
	    svp = av_fetch(av, i, 1);
	    if (type == 1)
		sv_setiv(*svp, p[i]-p1[i]);
	    else
		sv_setuv(*svp, p[i]);
	}
    }
}

static void
mstats_fillhash(SV *sv, int level)
{
    struct mstats_buffer buf;

    if (!(SvROK(sv) && SvTYPE(SvRV(sv)) == SVt_PVHV))
	croak("Not a hash reference");
    _fill_mstats(&buf, level);
    _mstats_to_hv((HV *)SvRV(sv), &buf, level);
}

static void
mstats2hash(SV *sv, SV *rv, int level)
{
    if (!(SvROK(rv) && SvTYPE(SvRV(rv)) == SVt_PVHV))
	croak("Not a hash reference");
    if (!SvPOK(sv))
	croak("Undefined value when expecting mstats buffer");
    if (SvCUR(sv) != sizeof(struct mstats_buffer))
	croak("Wrong size for a value with a mstats buffer");
    _mstats_to_hv((HV *)SvRV(rv), (struct mstats_buffer*)SvPVX(sv), level);
}
#else	/* defined(MYMALLOC) */ 
static void
fill_mstats(SV *sv, int level)
{
    PERL_UNUSED_ARG(sv);
    PERL_UNUSED_ARG(level);
    croak("Cannot report mstats without Perl malloc");
}

static void
mstats_fillhash(SV *sv, int level)
{
    PERL_UNUSED_ARG(sv);
    PERL_UNUSED_ARG(level);
    croak("Cannot report mstats without Perl malloc");
}

static void
mstats2hash(SV *sv, SV *rv, int level)
{
    PERL_UNUSED_ARG(sv);
    PERL_UNUSED_ARG(rv);
    PERL_UNUSED_ARG(level);
    croak("Cannot report mstats without Perl malloc");
}
#endif	/* defined(MYMALLOC) */ 

#define _CvGV(cv)					\
	(SvROK(cv) && (SvTYPE(SvRV(cv))==SVt_PVCV)	\
	 ? SvREFCNT_inc(CvGV((CV*)SvRV(cv))) : &PL_sv_undef)

#line 334 "Peek.c"
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

#line 386 "Peek.c"

XS(XS_Devel__Peek_mstat); /* prototype to pass -Wmissing-prototypes */
XS(XS_Devel__Peek_mstat)
{
#ifdef dVAR
    dVAR; dXSARGS;
#else
    dXSARGS;
#endif
    if (items < 0 || items > 1)
       croak_xs_usage(cv,  "str=\"Devel::Peek::mstat: \"");
    {
	const char *	str;

	if (items < 1)
	    str = "Devel::Peek::mstat: ";
	else {
	    str = (const char *)SvPV_nolen(ST(0));
	}

	mstat(str);
    }
    XSRETURN_EMPTY;
}


XS(XS_Devel__Peek_fill_mstats); /* prototype to pass -Wmissing-prototypes */
XS(XS_Devel__Peek_fill_mstats)
{
#ifdef dVAR
    dVAR; dXSARGS;
#else
    dXSARGS;
#endif
    if (items < 1 || items > 2)
       croak_xs_usage(cv,  "sv, level= 0");
    {
	SV *	sv = ST(0);
	int	level;

	if (items < 2)
	    level = 0;
	else {
	    level = (int)SvIV(ST(1));
	}

	fill_mstats(sv, level);
    }
    XSRETURN_EMPTY;
}


XS(XS_Devel__Peek_mstats_fillhash); /* prototype to pass -Wmissing-prototypes */
XS(XS_Devel__Peek_mstats_fillhash)
{
#ifdef dVAR
    dVAR; dXSARGS;
#else
    dXSARGS;
#endif
    if (items < 1 || items > 2)
       croak_xs_usage(cv,  "sv, level= 0");
    {
	SV *	sv = ST(0);
	int	level;

	if (items < 2)
	    level = 0;
	else {
	    level = (int)SvIV(ST(1));
	}

	mstats_fillhash(sv, level);
    }
    XSRETURN_EMPTY;
}


XS(XS_Devel__Peek_mstats2hash); /* prototype to pass -Wmissing-prototypes */
XS(XS_Devel__Peek_mstats2hash)
{
#ifdef dVAR
    dVAR; dXSARGS;
#else
    dXSARGS;
#endif
    if (items < 2 || items > 3)
       croak_xs_usage(cv,  "sv, rv, level= 0");
    {
	SV *	sv = ST(0);
	SV *	rv = ST(1);
	int	level;

	if (items < 3)
	    level = 0;
	else {
	    level = (int)SvIV(ST(2));
	}

	mstats2hash(sv, rv, level);
    }
    XSRETURN_EMPTY;
}


XS(XS_Devel__Peek_Dump); /* prototype to pass -Wmissing-prototypes */
XS(XS_Devel__Peek_Dump)
{
#ifdef dVAR
    dVAR; dXSARGS;
#else
    dXSARGS;
#endif
    if (items < 1 || items > 2)
       croak_xs_usage(cv,  "sv, lim=4");
    PERL_UNUSED_VAR(ax); /* -Wall */
    SP -= items;
    {
	SV *	sv = ST(0);
	I32	lim;

	if (items < 2)
	    lim = 4;
	else {
	    lim = (I32)SvIV(ST(1));
	}
#line 346 "Peek.xs"
{
    SV *pv_lim_sv = perl_get_sv("Devel::Peek::pv_limit", 0);
    const STRLEN pv_lim = pv_lim_sv ? SvIV(pv_lim_sv) : 0;
    SV *dumpop = perl_get_sv("Devel::Peek::dump_ops", 0);
    const U16 save_dumpindent = PL_dumpindent;
    PL_dumpindent = 2;
    do_sv_dump(0, Perl_debug_log, sv, 0, lim,
	       (bool)(dumpop && SvTRUE(dumpop)), pv_lim);
    PL_dumpindent = save_dumpindent;
}
#line 524 "Peek.c"
	PUTBACK;
	return;
    }
}


XS(XS_Devel__Peek_DumpArray); /* prototype to pass -Wmissing-prototypes */
XS(XS_Devel__Peek_DumpArray)
{
#ifdef dVAR
    dVAR; dXSARGS;
#else
    dXSARGS;
#endif
    if (items < 1)
       croak_xs_usage(cv,  "lim, ...");
    PERL_UNUSED_VAR(ax); /* -Wall */
    SP -= items;
    {
	I32	lim = (I32)SvIV(ST(0));
#line 361 "Peek.xs"
{
    long i;
    SV *pv_lim_sv = perl_get_sv("Devel::Peek::pv_limit", 0);
    const STRLEN pv_lim = pv_lim_sv ? SvIV(pv_lim_sv) : 0;
    SV *dumpop = perl_get_sv("Devel::Peek::dump_ops", 0);
    const U16 save_dumpindent = PL_dumpindent;
    PL_dumpindent = 2;

    for (i=1; i<items; i++) {
	PerlIO_printf(Perl_debug_log, "Elt No. %ld  0x%"UVxf"\n", i - 1, PTR2UV(ST(i)));
	do_sv_dump(0, Perl_debug_log, ST(i), 0, lim,
		   (bool)(dumpop && SvTRUE(dumpop)), pv_lim);
    }
    PL_dumpindent = save_dumpindent;
}
#line 561 "Peek.c"
	PUTBACK;
	return;
    }
}


XS(XS_Devel__Peek_DumpProg); /* prototype to pass -Wmissing-prototypes */
XS(XS_Devel__Peek_DumpProg)
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
#line 380 "Peek.xs"
{
    warn("dumpindent is %d", (int)PL_dumpindent);
    if (PL_main_root)
	op_dump(PL_main_root);
}
#line 587 "Peek.c"
	PUTBACK;
	return;
    }
}


XS(XS_Devel__Peek_SvREFCNT); /* prototype to pass -Wmissing-prototypes */
XS(XS_Devel__Peek_SvREFCNT)
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
	I32	RETVAL;
	dXSTARG;

	RETVAL = SvREFCNT(sv);
	XSprePUSH; PUSHi((IV)RETVAL);
    }
    XSRETURN(1);
}


XS(XS_Devel__Peek_SvREFCNT_inc); /* prototype to pass -Wmissing-prototypes */
XS(XS_Devel__Peek_SvREFCNT_inc)
{
#ifdef dVAR
    dVAR; dXSARGS;
#else
    dXSARGS;
#endif
    if (items != 1)
       croak_xs_usage(cv,  "sv");
    PERL_UNUSED_VAR(ax); /* -Wall */
    SP -= items;
    {
	SV *	sv = ST(0);
	SV *	RETVAL;
#line 396 "Peek.xs"
{
    RETVAL = SvREFCNT_inc(sv);
    PUSHs(RETVAL);
}
#line 636 "Peek.c"
	PUTBACK;
	return;
    }
}


XS(XS_Devel__Peek_SvREFCNT_dec); /* prototype to pass -Wmissing-prototypes */
XS(XS_Devel__Peek_SvREFCNT_dec)
{
#ifdef dVAR
    dVAR; dXSARGS;
#else
    dXSARGS;
#endif
    if (items != 1)
       croak_xs_usage(cv,  "sv");
    PERL_UNUSED_VAR(ax); /* -Wall */
    SP -= items;
    {
	SV *	sv = ST(0);
#line 407 "Peek.xs"
{
    SvREFCNT_dec(sv);
    PUSHs(sv);
}
#line 662 "Peek.c"
	PUTBACK;
	return;
    }
}


XS(XS_Devel__Peek_DeadCode); /* prototype to pass -Wmissing-prototypes */
XS(XS_Devel__Peek_DeadCode)
{
#ifdef dVAR
    dVAR; dXSARGS;
#else
    dXSARGS;
#endif
    if (items != 0)
       croak_xs_usage(cv,  "");
    {
	SV *	RETVAL;
#line 415 "Peek.xs"
    RETVAL = DeadCode(aTHX);
#line 683 "Peek.c"
	ST(0) = RETVAL;
	sv_2mortal(ST(0));
    }
    XSRETURN(1);
}


XS(XS_Devel__Peek_CvGV); /* prototype to pass -Wmissing-prototypes */
XS(XS_Devel__Peek_CvGV)
{
#ifdef dVAR
    dVAR; dXSARGS;
#else
    dXSARGS;
#endif
    if (items != 1)
       croak_xs_usage(cv,  "cv");
    {
	SV *	cv = ST(0);
	SV *	RETVAL;

	RETVAL = _CvGV(cv);
	ST(0) = RETVAL;
	sv_2mortal(ST(0));
    }
    XSRETURN(1);
}


XS(XS_Devel__Peek_runops_debug); /* prototype to pass -Wmissing-prototypes */
XS(XS_Devel__Peek_runops_debug)
{
#ifdef dVAR
    dVAR; dXSARGS;
#else
    dXSARGS;
#endif
    if (items < 0 || items > 1)
       croak_xs_usage(cv,  "flag= -1");
    {
	bool	RETVAL;
	int	flag;

	if (items < 1)
	    flag = -1;
	else {
	    flag = (int)SvIV(ST(0));
	}

	RETVAL = _runops_debug(flag);
	ST(0) = boolSV(RETVAL);
	sv_2mortal(ST(0));
    }
    XSRETURN(1);
}

#ifdef __cplusplus
extern "C"
#endif
XS(boot_Devel__Peek); /* prototype to pass -Wmissing-prototypes */
XS(boot_Devel__Peek)
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

        newXS("Devel::Peek::mstat", XS_Devel__Peek_mstat, file);
        newXS("Devel::Peek::fill_mstats", XS_Devel__Peek_fill_mstats, file);
        (void)newXSproto_portable("Devel::Peek::mstats_fillhash", XS_Devel__Peek_mstats_fillhash, file, "\\%;$");
        (void)newXSproto_portable("Devel::Peek::mstats2hash", XS_Devel__Peek_mstats2hash, file, "$\\%;$");
        newXS("Devel::Peek::Dump", XS_Devel__Peek_Dump, file);
        newXS("Devel::Peek::DumpArray", XS_Devel__Peek_DumpArray, file);
        newXS("Devel::Peek::DumpProg", XS_Devel__Peek_DumpProg, file);
        newXS("Devel::Peek::SvREFCNT", XS_Devel__Peek_SvREFCNT, file);
        newXS("Devel::Peek::SvREFCNT_inc", XS_Devel__Peek_SvREFCNT_inc, file);
        newXS("Devel::Peek::SvREFCNT_dec", XS_Devel__Peek_SvREFCNT_dec, file);
        newXS("Devel::Peek::DeadCode", XS_Devel__Peek_DeadCode, file);
        newXS("Devel::Peek::CvGV", XS_Devel__Peek_CvGV, file);
        newXS("Devel::Peek::runops_debug", XS_Devel__Peek_runops_debug, file);
#if (PERL_REVISION == 5 && PERL_VERSION >= 9)
  if (PL_unitcheckav)
       call_list(PL_scopestack_ix, PL_unitcheckav);
#endif
    XSRETURN_YES;
}

