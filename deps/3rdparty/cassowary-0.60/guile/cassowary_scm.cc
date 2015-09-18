// $Id: cassowary_scm.cc,v 1.30 2000/03/12 21:40:58 gjb Exp $
// Copyright (C) 1998-2000 Greg J. Badros, <greg.badros@alumni.duke.edu>
//
// A Guile Scheme wrapper for the Cassowary Constraint Solving Toolkit
//
// TODO
// Catch internal errors throughout
// convenience wrappers (e.g., cl-half)
// expression-side-effecting
// standard strength variables
// extra strength args to add-constraint, add-editvar
// cl-begin-edit, cl-end-edit, cl-suggest-value

#ifdef HAVE_CONFIG_H
#include <cassowary/config.h>
#endif

#define CASSOWARY_SCM_IMPLEMENTATION
#include "cassowary_scm.h"
#include "cassowary_scm.hpp"

#include <guile/gh.h>

#include <iostream.h>
#include <assert.h>
#include <strstream.h>
#include "cl-snarf.h"

#include "ClVariable.h"
#include "ClSymbolicWeight.h"
#include "ClLinearExpression.h"
#include "ClLinearEquation.h"
#include "ClLinearInequality.h"
#include "ClSimplexSolver.h"
#include "ClErrors.h"
#include "ClReader.h"

#include <vector>

// C++ version of this macro -- uses true and false, not True and False
#define COPY_BOOL_OR_ERROR_DEFAULT_FALSE(var,flag,pos,func) \
  do { \
  if (flag == SCM_BOOL_T) var = true; \
  else if (flag == SCM_BOOL_F || flag == SCM_UNDEFINED) var = false; \
  else scm_wrong_type_arg(func,pos,flag); \
  } while (0)


#ifdef HAVE_SCM_MAKE_SMOB_TYPE_MFPE
/* new-style SMOBs -- this gives smobs names, too */
#define MAKE_SMOBFUNS(T) /* nothing */
#define REGISTER_SMOBFUNS(T) \
 do { \
    scm_tc16_ ## T = scm_make_smob_type_mfpe( #T, 0, &(mark_ ##T), &(free_ ## T), &(print_ ## T), NULL); \
  } while (0)
#else
/* Old-style SMOBs */
#define MAKE_SMOBFUNS(T) \
static scm_smobfuns T ## _smobfuns = { \
  &mark_ ## T, \
  &free_ ## T, \
  &print_ ## T,  0 }

#define REGISTER_SMOBFUNS(T) scm_tc16_ ## T = scm_newsmob(& T ## _smobfuns)
#endif


#define CL_VAR_INIT(cvar, name, val) \
  do { scm_ ## cvar = \
      scm_sysintern(name, val); } while (0)

#define CL_VAR_INIT_PERMANENT(cvar, name, val) \
  do { scm_ ## cvar =  \
      scm_sysintern(name, val); scm_permanent_object(scm_ ## cvar); \
  } while (0)


#define CL_VAR(cvar, name) \
  do { scm_ ## cvar = \
      scm_sysintern0(name); } while (0)


/* FIXGJB: Note that cvar is ignored for now */
#define CL_VAR_READ_ONLY(cvar, name,val) \
  do { scm_sysintern(name,val); \
     } while (0)

extern "C" {

#define NEW(x) ((x *) safemalloc(sizeof(x)))
#define NEWC(c,x) ((x *) safemalloc((c)*sizeof(x)))
#define FREE(x) free(x)

inline SCM SCM_BOOL_FromF(bool f) { return (f? SCM_BOOL_T: SCM_BOOL_F); }
inline bool FUnsetSCM(SCM scm) { return (scm == SCM_UNDEFINED || scm == SCM_BOOL_F); }


//// ClVariable wrapper
#undef SCMTYPEID
#define SCMTYPEID scm_tc16_cl_variable

long SCMTYPEID;

SCM mark_cl_variable(SCM scm)
{
  SCM_SETGC8MARK(scm);
  return SCM_BOOL_F;
}

size_t free_cl_variable(SCM scm)
{
  //  ClVariable *pclv = PclvFromScm(scm);
  //  delete pclv;  // FIXGJB: don't delete until memory audit
  return 0;
}

int print_cl_variable(SCM scm, SCM port, scm_print_state *pstate)
{
  strstream ss;
  ClVariable *pclv = PclvFromScm(scm);
  ss << "#<cl_variable " << *pclv << ">" << ends;
  scm_puts(ss.str(), port);
  return 1;
}

CL_PROC(cl_variable_p, "cl-variable?", 1, 0, 0,
        (SCM obj),
"Return #t if OBJ is a constraint variable, #f otherwise.")
#define FUNC_NAME s_cl_variable_p
{
  return SCM_BOOL_FromF(FIsClVariableScm(obj));
}
#undef FUNC_NAME

CL_PROC(make_cl_variable, "make-cl-variable", 0, 2, 0,
        (SCM name, SCM value),
"Return a newly-created constraint variable.\n\
The created variable has the name NAME, and an initial\n\
value of VALUE.  Be sure to add a stay constraint on the\n\
variable if you want its value to not change.")
#define FUNC_NAME s_make_cl_variable
{
  char *szName = NULL;
  double n = 0;

  if (!FUnsetSCM(name)) {
    if (!gh_string_p(name)) {
      scm_wrong_type_arg(FUNC_NAME, 1, name);
    } else {
      szName = gh_scm2newstr(name,NULL);
    }
  }

  if (!FUnsetSCM(value)) {
    if (!gh_number_p(value)) {
      scm_wrong_type_arg(FUNC_NAME, 2, value);
    } else {
      n = gh_scm2double(value);
    }
  }

  ClVariable *pclv = NULL;

  if (szName) {
    pclv = new ClVariable(szName, n);
    FREE(szName);
  } else {
    pclv = new ClVariable(n);
  }

  SCM answer = ScmMakeClVariable(pclv);
  pclv->SetPv(PvFromScm(answer));
  return answer;
}
#undef FUNC_NAME


CL_PROC (clv_attach_x, "clv-attach!", 2, 0, 0,
         (SCM var, SCM obj),
"Attach OBJ to VAR, undoing any previous attachments.\n\
Use `clv-attached-object' to retreive OBJ later.\n\
Consider instead using `set-object-property' and `object-property'.")
#define FUNC_NAME s_clv_attach_x
{
  ClVariable *pclv = NULL;
  if (!FIsClVariableScm(var)) scm_wrong_type_arg(FUNC_NAME,1,var);
  pclv = PclvFromScm(var);
  /* FIXGJB: should unprotect the prior object, or mark it
     but to mark it I'd need to be sure that all cl-variables'
     Pv() is a scheme object */
  scm_protect_object(obj);
  pclv->SetPv(PvFromScm(obj));
  return SCM_UNSPECIFIED;
}
#undef FUNC_NAME

CL_PROC (clv_attached_object, "clv-attached-object", 1, 0, 0,
         (SCM var),
"Return the object attached to cl-variable VAR.\n\
Returns #f if no object was attached using `clv-attach!'.\n\
Consider instead using `set-object-property' and `object-property'.")
#define FUNC_NAME s_clv_attached_object
{
  ClVariable *pclv = NULL;
  SCM obj = SCM_BOOL_F;
  if (!FIsClVariableScm(var)) scm_wrong_type_arg(FUNC_NAME,1,var);
  pclv = PclvFromScm(var);
  if (pclv->Pv()) {
    obj = ScmFromPv(pclv->Pv());
  }
  return obj;
}
#undef FUNC_NAME


CL_PROC(cl_value, "cl-value", 1, 0, 0,
        (SCM clv),
"Return the current value of the constraint variable CLV.\n\
The value is a double.  Use `cl-int-value' to return an integer.")
#define FUNC_NAME s_cl_value
{
  if (!FIsClVariableScm(clv)) {
    scm_wrong_type_arg(FUNC_NAME, 1, clv);
  }

  ClVariable *pclv = PclvFromScm(clv);
  return gh_double2scm(pclv->Value());
}
#undef FUNC_NAME

CL_PROC(cl_int_value, "cl-int-value", 1, 0, 0,
        (SCM clv),
"Return the value of the constraint variable CLV as an integer.\n\
Internally, the value is a double.  This rounds that real number to\n\
an integer before returning the value.")
#define FUNC_NAME s_cl_int_value
{
  if (!FIsClVariableScm(clv)) {
    scm_wrong_type_arg(FUNC_NAME, 1, clv);
  }

  ClVariable *pclv = PclvFromScm(clv);
  return gh_int2scm(pclv->IntValue());
}
#undef FUNC_NAME



//// ClSymbolicWeight wrapper
#undef SCMTYPEID
#define SCMTYPEID scm_tc16_cl_weight

long SCMTYPEID;

SCM
mark_cl_weight(SCM scm)
{
  SCM_SETGC8MARK(scm);
  return SCM_BOOL_F;
}

size_t
free_cl_weight(SCM scm)
{
  ClSymbolicWeight *pclsw = PclswFromScm(scm);
  delete pclsw;
  return 0;
}

int
print_cl_weight(SCM scm, SCM port, scm_print_state *pstate)
{
  strstream ss;
  ClSymbolicWeight *pclsw = PclswFromScm(scm);
  ss << "#<cl-weight " << *pclsw << ">" << ends;
  scm_puts(ss.str(), port);
  return 1;
}

CL_PROC(cl_weight_p, "cl-weight?", 1, 0, 0,
        (SCM obj),
"Return #t if OBJ is a constraint weight object, #f otherwise.")
#define FUNC_NAME s_cl_weight_p
{
  return SCM_BOOL_FromF(FIsClSymbolicWeightScm(obj));
}
#undef FUNC_NAME

CL_PROC(make_cl_weight, "make-cl-weight", 3, 0, 0,
        (SCM w1, SCM w2, SCM w3),
"Return a newly-created constraint symbolic weight object.\n\
Symbolic weights are sequences of real numbers that are sorted\n\
in lexicographical order (e.g., 1,0,0 > 0,999,999).  cl-weight\n\
objects are used when creating cl-strength objects.  By convention,\n\
the sequences are three elements long: W1, W2, and W3.  Longer\n\
cl-weight objects could be supported in the future.  See also\n\
`make-cl-strength-3' which is a convenience procedure for building a\n\
cl-strength object given the sequence of numbers directly.")
#define FUNC_NAME s_make_cl_weight
{
  if (!gh_number_p(w1)) scm_wrong_type_arg(FUNC_NAME, 1, w1);
  if (!gh_number_p(w2)) scm_wrong_type_arg(FUNC_NAME, 2, w2);
  if (!gh_number_p(w3)) scm_wrong_type_arg(FUNC_NAME, 3, w3);

  ClSymbolicWeight *pclsw = new ClSymbolicWeight(gh_scm2double(w1),
                                                 gh_scm2double(w2),
                                                 gh_scm2double(w3));

  SCM answer;

  SCM_DEFER_INTS;
  SCM_NEWCELL(answer);
  SCM_SETCAR(answer, (SCM) SCMTYPEID);
  SCM_SETCDR(answer, (SCM) pclsw);
  SCM_ALLOW_INTS;

  return answer;
}
#undef FUNC_NAME


//// ClStrength wrapper
#undef SCMTYPEID
#define SCMTYPEID scm_tc16_cl_strength

long SCMTYPEID;

SCM
mark_cl_strength(SCM scm)
{
  SCM_SETGC8MARK(scm);
  return SCM_BOOL_F;
}

size_t
free_cl_strength(SCM scm)
{
  ClStrength *pcls = PclsFromScm(scm);
  delete pcls;
  return 0;
}

int
print_cl_strength(SCM scm, SCM port, scm_print_state *pstate)
{
  strstream ss;
  ClStrength *pcls = PclsFromScm(scm);
  ss << "#<cl-strength " << *pcls << ">" << ends;
  scm_puts(ss.str(), port);
  return 1;
}

CL_PROC(cl_strength_p, "cl-strength?", 1, 0, 0,
        (SCM obj),
"Return #t if OBJ is a constraint strength, #f otherwise.")
#define FUNC_NAME s_cl_strength_p
{
  return SCM_BOOL_FromF(FIsClStrengthScm(obj));
}
#undef FUNC_NAME

static SCM
ScmMakeClStrength(ClStrength *pcls)
{
  SCM answer;

  SCM_DEFER_INTS;
  SCM_NEWCELL(answer);
  SCM_SETCAR(answer, (SCM) SCMTYPEID);
  SCM_SETCDR(answer, (SCM) pcls);
  pcls->SetPv(PvFromScm(answer));
  SCM_ALLOW_INTS;

  
  return answer;
}

CL_PROC(make_cl_strength, "make-cl-strength", 2, 0, 0,
        (SCM name, SCM weight),
"Return a newly-created constraint strength object.\n\
The object is given the name NAME, a string, and the symbolic\n\
strengh WEIGHT, a cl-weight.  Constraint strength objects\n\
are used when specifying the strength of a constraint.  There are\n\
several predefined cl-strenght objects: \"cls-required\", \"cls-strong\",\n\
\"cls-medium\", and \"cls-weak\".  These four constraint strengths\n\
are often enough for a suitably expressive constraint-hierarchy,\n\
but new strengths can be introduced if necessary.")
#define FUNC_NAME s_make_cl_strength
{
  if (!gh_string_p(name))
    scm_wrong_type_arg(FUNC_NAME,1,name);

  if (!FIsClSymbolicWeightScm(weight))
    scm_wrong_type_arg(FUNC_NAME,2,weight);
  
  char *szName = gh_scm2newstr(name,NULL);
  ClSymbolicWeight *pclsw = PclswFromScm(weight);
  ClStrength *pcls = new ClStrength(szName,*pclsw);
  delete szName;

  SCM answer = ScmMakeClStrength(pcls);
  scm_protect_object(answer);
  return answer;
}
#undef FUNC_NAME


CL_PROC(make_cl_strength_3, "make-cl-strength-3", 4, 0, 0,
        (SCM name, SCM w1, SCM w2, SCM w3),
"Return a newly-created constraint strength object.\n\
The object is given the name NAME, a string, and a symbolic weight of\n\
length three with the sequence of values: W1, W2, W3.  This is a\n\
convenience procedure that has the same semantics as building a\n\
cl-weight object with the values and using that to build a cl-strength \n\
object.")
#define FUNC_NAME s_make_cl_strength_3
{
  if (!gh_string_p(name)) scm_wrong_type_arg(FUNC_NAME, 1, name);
  if (!gh_number_p(w1)) scm_wrong_type_arg(FUNC_NAME, 2, w1);
  if (!gh_number_p(w2)) scm_wrong_type_arg(FUNC_NAME, 3, w2);
  if (!gh_number_p(w3)) scm_wrong_type_arg(FUNC_NAME, 4, w3);

  char *szName = gh_scm2newstr(name,NULL);
  ClStrength *pcls = new ClStrength(szName,
                                    gh_scm2double(w1),
                                    gh_scm2double(w2),
                                    gh_scm2double(w3));
  delete szName;

  SCM answer = ScmMakeClStrength(pcls);
  scm_protect_object(answer);

  return answer;
}
#undef FUNC_NAME



//// ClLinearExpression wrapper
#undef SCMTYPEID
#define SCMTYPEID scm_tc16_cl_expression


long SCMTYPEID;

SCM
mark_cl_expression(SCM scm)
{
  SCM_SETGC8MARK(scm);
  return SCM_BOOL_F;
}

size_t
free_cl_expression(SCM scm)
{
  ClLinearExpression *pexpr = PexprFromScm(scm);
  delete pexpr;
  return 0;
}

int
print_cl_expression(SCM scm, SCM port, scm_print_state *pstate)
{
  strstream ss;
  ClLinearExpression *pexpr = PexprFromScm(scm);
  ss << "#<cl_expression " << *pexpr << ">" << ends;
  scm_puts(ss.str(), port);
  return 1;
}

CL_PROC(cl_expression_p, "cl-expression?", 1, 0, 0,
        (SCM obj),
"Return #t if OBJ is a constraint expression, #f otherwise.")
#define FUNC_NAME s_cl_expression_p
{
  return SCM_BOOL_FromF(FIsClLinearExpressionScm(obj));
}
#undef FUNC_NAME

CL_PROC(make_cl_expression, "make-cl-expression", 1, 0, 0,
        (SCM clv),
"Return a newly-create constraint expression object.\n\
The expression is contains just the value CLV.  Often constraint\n\
variables can be used interchangeably with constraint expressions, but\n\
this procedure can be used to force building a simple expression.")
#define FUNC_NAME s_make_cl_expression
{
  ClLinearExpression *pexpr = NULL;

  if (!FIsClVariableScm(clv) && !gh_number_p(clv)) {
    scm_wrong_type_arg(FUNC_NAME, 1, clv);
  } 
  if (FIsClVariableScm(clv)) {
    pexpr = new ClLinearExpression(*PclvFromScm(clv));
  } else {
    pexpr = new ClLinearExpression(gh_scm2double(clv));
  }


  return ScmMakeClLinearExpression(pexpr);
}
#undef FUNC_NAME

static ClLinearExpression *
PexprNewConvertSCM(SCM scm)
{
  if (gh_number_p(scm)) {
    return new ClLinearExpression(gh_scm2double(scm));
  }
  if (FIsClVariableScm(scm)) {
    return new ClLinearExpression(*PclvFromScm(scm));
  }
  if (FIsClLinearExpressionScm(scm)) {
    return new ClLinearExpression(*PexprFromScm(scm));
  }
  return NULL;
}


CL_PROC(cl_plus, "cl-plus", 2, 0, 0,
        (SCM exprA, SCM exprB),
"Return the cl-expression that is the sum of EXPRA and EXPRB.\n\
Both EXPRA and EXPRB may be cl-expression objects or cl-variable\n\
objects.")
#define FUNC_NAME s_cl_plus
{
  ClLinearExpression *pexprA = NULL;
  ClLinearExpression *pexprB = NULL;
  
  if (NULL == (pexprA = PexprNewConvertSCM(exprA))) {
    scm_wrong_type_arg(FUNC_NAME, 1, exprA);
  }
  if (NULL == (pexprB = PexprNewConvertSCM(exprB))) {
    scm_wrong_type_arg(FUNC_NAME, 2, exprB);
  }
  
  pexprA->AddExpression(*pexprB);
  delete pexprB;

  SCM answer;

  SCM_DEFER_INTS;
  SCM_NEWCELL(answer);
  SCM_SETCAR(answer, (SCM) SCMTYPEID);
  SCM_SETCDR(answer, (SCM) pexprA);
  SCM_ALLOW_INTS;

  return answer;
}
#undef FUNC_NAME


CL_PROC(cl_minus, "cl-minus", 2, 0, 0,
        (SCM exprA, SCM exprB),
"Return the cl-expression that is the difference of EXPRA and EXPRB.\n\
Both EXPRA and EXPRB may be cl-expression objects or cl-variable\n\
objects.")
#define FUNC_NAME s_cl_minus
{
  ClLinearExpression *pexprA = NULL;
  ClLinearExpression *pexprB = NULL;

  if (NULL == (pexprA = PexprNewConvertSCM(exprA))) {
    scm_wrong_type_arg(FUNC_NAME, 1, exprA);
  }
  if (NULL == (pexprB = PexprNewConvertSCM(exprB))) {
    scm_wrong_type_arg(FUNC_NAME, 2, exprB);
  }
  
  pexprA->AddExpression(*pexprB,-1);
  delete pexprB;

  SCM answer;

  SCM_DEFER_INTS;
  SCM_NEWCELL(answer);
  SCM_SETCAR(answer, (SCM) SCMTYPEID);
  SCM_SETCDR(answer, (SCM) pexprA);
  SCM_ALLOW_INTS;

  return answer;
}
#undef FUNC_NAME


CL_PROC(cl_times, "cl-times", 2, 0, 0,
        (SCM exprA, SCM exprB),
"Return the cl-expression that is the product of EXPRA and EXPRB.\n\
Both EXPRA and EXPRB may be cl-expression objects or cl-variable\n\
objects.  Note that the product may not introduce non-linear terms--\n\
if it does (e.g., if EXPRA and EXPRB both contain the same\n\
cl-variable), an error will result.")
#define FUNC_NAME s_cl_times
{
  ClLinearExpression *pexprA = NULL;
  ClLinearExpression *pexprB = NULL;

  if (NULL == (pexprA = PexprNewConvertSCM(exprA))) {
    scm_wrong_type_arg(FUNC_NAME, 1, exprA);
  }
  if (NULL == (pexprB = PexprNewConvertSCM(exprB))) {
    scm_wrong_type_arg(FUNC_NAME, 2, exprB);
  }

  try {
    ClLinearExpression *pexpr = p_Times(*pexprA,*pexprB);
    delete pexprA;
    delete pexprB;
    SCM answer;
    
    SCM_DEFER_INTS;
    SCM_NEWCELL(answer);
    SCM_SETCAR(answer, (SCM) SCMTYPEID);
    SCM_SETCDR(answer, (SCM) pexpr);
    SCM_ALLOW_INTS;
    
    return answer;
  } catch (const ExCLNonlinearExpression &e) {
    delete pexprA;
    delete pexprB;
    scm_misc_error(FUNC_NAME, "NonlinearExpression exception", SCM_EOL);
  }

}
#undef FUNC_NAME


CL_PROC(cl_divide, "cl-divide", 2, 0, 0,
        (SCM exprA, SCM exprB),
"Return the cl-expression that is the quotient of EXPRA and EXPRB.\n\
Both EXPRA and EXPRB may be cl-expression objects or cl-variable\n\
objects. Note that the product may not introduce non-linear terms--\n\
if it does (e.g., if EXPRA and EXPRB both contain the same\n\
cl-variable), an error will result.")
#define FUNC_NAME s_cl_divide
{
  ClLinearExpression *pexprA = NULL;
  ClLinearExpression *pexprB = NULL;

  if (NULL == (pexprA = PexprNewConvertSCM(exprA))) {
    scm_wrong_type_arg(FUNC_NAME, 1, exprA);
  }
  if (NULL == (pexprB = PexprNewConvertSCM(exprB))) {
    scm_wrong_type_arg(FUNC_NAME, 2, exprB);
  }

  try {
    ClLinearExpression *pexpr = p_Divide(*pexprA,*pexprB);
    delete pexprA;
    delete pexprB;
    SCM answer;
    
    SCM_DEFER_INTS;
    SCM_NEWCELL(answer);
    SCM_SETCAR(answer, (SCM) SCMTYPEID);
    SCM_SETCDR(answer, (SCM) pexpr);
    SCM_ALLOW_INTS;
    
    return answer;
  } catch (const ExCLNonlinearExpression &e) {
    delete pexprA;
    delete pexprB;
    scm_misc_error(FUNC_NAME, e.description().c_str(), SCM_EOL);
  }
  return SCM_BOOL_F;
}
#undef FUNC_NAME



//// ClLinearEquation wrapper
#undef SCMTYPEID
#define SCMTYPEID scm_tc16_cl_equation

long SCMTYPEID;

SCM
mark_cl_equation(SCM scm)
{
  SCM_SETGC8MARK(scm);
  return SCM_BOOL_F;
}

size_t
free_cl_equation(SCM scm)
{
  ClLinearEquation *peq = PeqFromScm(scm);
  delete peq;
  return 0;
}

int
print_cl_equation(SCM scm, SCM port, scm_print_state *pstate)
{
  strstream ss;
  ClLinearEquation *peq = PeqFromScm(scm);
  ss << "#<cl-equation " << *peq << ">" << ends;
  scm_puts(ss.str(), port);
  return 1;
}

CL_PROC(cl_equation_p, "cl-equation?", 1, 0, 0,
        (SCM obj),
"Return #t if OBJ is a constraint equation, #f otherwise.\n\
Constraint equations also respond #t to `cl-constraint?' queries,\n\
since they are also constraint objects.")
#define FUNC_NAME s_cl_equation_p
{
  return SCM_BOOL_FromF(FIsClLinearEquationScm(obj));
}
#undef FUNC_NAME

CL_PROC(make_cl_equation, "make-cl-equation", 1, 2, 0,
        (SCM expr, SCM strength, SCM factor),
"Return a newly-created constraint equation.\n\
The resulting constraint is that EXPR is equal to 0.  EXPR is a\n\
cl-expression or cl-variable object.  The constraint is given strength\n\
STRENGTH, a cl-strength, and has a weight factor of FACTOR, a real\n\
number.  STRENGTH defaults to cls-required, FACTOR defaults to 1.")
#define FUNC_NAME s_make_cl_equation
{
  ClLinearExpression *pexpr = NULL;

  if (NULL == (pexpr = PexprNewConvertSCM(expr))) {
    scm_wrong_type_arg(FUNC_NAME, 1, expr);
  }

  const ClStrength *pcls = &ClsRequired();
  if (FIsClStrengthScm(strength)) {
    pcls = PclsFromScm(strength);
  } else if (!FUnsetSCM(strength)) {
    scm_wrong_type_arg(FUNC_NAME,2,strength);
  }

  double nWeight = 1.0;
  if (gh_number_p(factor)) {
    nWeight = gh_scm2double(factor);
  } else if (!FUnsetSCM(factor)) {
    scm_wrong_type_arg(FUNC_NAME,3,factor);
  }

  ClLinearEquation *peq = new ClLinearEquation(*pexpr,*pcls,nWeight);

  SCM answer = ScmMakeClLinearEquation(peq);
  peq->SetPv(PvFromScm(answer));
  return answer;
}
#undef FUNC_NAME

CL_PROC(make_cl_equality, "make-cl-equality", 2, 2, 0,
        (SCM exprA, SCM exprB, SCM strength, SCM factor),
"Return a newly-created constraint equation.\n\
The resulting constraint is that EXPRA is equal to EXPRB.  EXPRA and\n\
EXPRB are cl-expression or cl-variable objects.  The constraint is\n\
given strength STRENGTH, a cl-strength, and has a weight factor of\n\
FACTOR, a real number.  STRENGTH defaults to cls-required, FACTOR\n\
defaults to 1.  Consider `make-cl-constraint' as a higher-level\n\
interface to building arbitrary constraints.\n\
\n\
This is a convenience procedure that has the same\n\
semantics as `make-cl-equation' with the difference of EXPRA and\n\
EXPRB.  Note that if neither expression contains a variable, an\n\
error will be signalled.")
#define FUNC_NAME s_make_cl_equality
{
  ClLinearExpression *pexprA = NULL;
  ClLinearExpression *pexprB = NULL;

  if (NULL == (pexprA = PexprNewConvertSCM(exprA))) {
    scm_wrong_type_arg(FUNC_NAME, 1, exprA);
  }
  if (NULL == (pexprB = PexprNewConvertSCM(exprB))) {
    scm_wrong_type_arg(FUNC_NAME, 2, exprB);
  }
  if (!(FIsClLinearExpressionScm(exprA) || FIsClVariableScm(exprA) ||
        FIsClLinearExpressionScm(exprB) || FIsClVariableScm(exprB))) {
    scm_misc_error(FUNC_NAME,"One of arguments must contain a variable",SCM_EOL);
  }
  const ClStrength *pcls = &ClsRequired();
  if (FIsClStrengthScm(strength)) {
    pcls = PclsFromScm(strength);
  } else if (!FUnsetSCM(strength)) {
    scm_wrong_type_arg(FUNC_NAME,3,strength);
  }

  double nWeight = 1.0;
  if (gh_number_p(factor)) {
    nWeight = gh_scm2double(factor);
  } else if (!FUnsetSCM(factor)) {
    scm_wrong_type_arg(FUNC_NAME,4,factor);
  }

  ClLinearEquation *peq = new ClLinearEquation(*pexprA,*pexprB,*pcls,nWeight);

  SCM answer;

  SCM_DEFER_INTS;
  SCM_NEWCELL(answer);
  SCM_SETCAR(answer, (SCM) SCMTYPEID);
  SCM_SETCDR(answer, (SCM) peq);
  SCM_ALLOW_INTS;

  return answer;
}
#undef FUNC_NAME




//// ClLinearInequality wrapper
#undef SCMTYPEID
#define SCMTYPEID scm_tc16_cl_inequality

long SCMTYPEID;

SCM
mark_cl_inequality(SCM scm)
{
  SCM_SETGC8MARK(scm);
  return SCM_BOOL_F;
}

size_t
free_cl_inequality(SCM scm)
{
  ClLinearInequality *pineq = PineqFromScm(scm);
  delete pineq;
  return 0;
}

int
print_cl_inequality(SCM scm, SCM port, scm_print_state *pstate)
{
  strstream ss;
  ClLinearInequality *pineq = PineqFromScm(scm);
  ss << "#<cl-inequality " << *pineq << ">" << ends;
  scm_puts(ss.str(), port);
  return 1;
}

CL_PROC(cl_inequality_p, "cl-inequality?", 1, 0, 0,
        (SCM obj),
"Return #t if OBJ is a constraint inequality object, #t otherwise.\n\
Constraint inequalities also respond #t to `cl-constraint?' queries,\n\
since they are also constraint objects.")
#define FUNC_NAME s_cl_inequality_p
{
  return SCM_BOOL_FromF(FIsClLinearInequalityScm(obj));
}
#undef FUNC_NAME

CL_PROC(make_cl_inequality, "make-cl-inequality", 3, 2, 0,
        (SCM exprA, SCM op, SCM exprB, SCM strength, SCM factor),
"Return a newly-constructed constraint inequality object.\n\
EXPRA and EXPRB are cl-expression or cl-variable objects.  If OP is\n\
`<=' then the constraint is that EXPRA <= EXPRB; if OP is `>=' then\n\
the constraint is that EXPRA >= EXPRB.  Note that the arithmetic\n\
comparison procedure objects are just used for their identity. If OP\n\
is any other object, an error is signalled. The constraint is given\n\
strength STRENGTH, a cl-strength, and has a weight factor of FACTOR, a\n\
real number.  STRENGTH defaults to cls-required, FACTOR defaults to 1.\n\
Consider `make-cl-constraint' as a higher-level interface to building\n\
arbitrary constraints.")
#define FUNC_NAME s_make_cl_inequality
{
  ClLinearExpression *pexprA = NULL;
  ClLinearExpression *pexprB = NULL;

  if (NULL == (pexprA = PexprNewConvertSCM(exprA))) {
    scm_wrong_type_arg(FUNC_NAME, 1, exprA);
  }
  if (NULL == (pexprB = PexprNewConvertSCM(exprB))) {
    scm_wrong_type_arg(FUNC_NAME, 3, exprB);
  }
  if (!(FIsClLinearExpressionScm(exprA) || FIsClVariableScm(exprA) ||
        FIsClLinearExpressionScm(exprB) || FIsClVariableScm(exprB))) {
    scm_misc_error(FUNC_NAME,"One of arguments must contain a variable",SCM_EOL);
  }

  const ClStrength *pcls = &ClsRequired();
  if (FIsClStrengthScm(strength)) {
    pcls = PclsFromScm(strength);
  } else if (!FUnsetSCM(strength)) {
    scm_wrong_type_arg(FUNC_NAME,4,strength);
  }

  double nWeight = 1.0;
  if (gh_number_p(factor)) {
    nWeight = gh_scm2double(factor);
  } else if (!FUnsetSCM(factor)) {
    scm_wrong_type_arg(FUNC_NAME,5,factor);
  }

  ClLinearInequality *pineq;
  if (op == gh_lookup("<=")) {
    pineq = new ClLinearInequality(*pexprA,cnLEQ,*pexprB,*pcls,nWeight);
  } else if (op == gh_lookup(">=")) {
    pineq = new ClLinearInequality(*pexprA,cnGEQ,*pexprB,*pcls,nWeight);
  }

  SCM answer = ScmMakeClLinearInequality(pineq);
  pineq->SetPv(PvFromScm(answer));
  return answer;
}
#undef FUNC_NAME


//// ClStayConstraint wrapper
#undef SCMTYPEID
#define SCMTYPEID scm_tc16_cl_stay_constraint

long SCMTYPEID;

SCM
mark_cl_stay_constraint(SCM scm)
{
  SCM_SETGC8MARK(scm);
  return SCM_BOOL_F;
}

size_t
free_cl_stay_constraint(SCM scm)
{
  ClConstraint *pcn = PcnFromScm(scm);
  delete pcn;
  return 0;
}

int
print_cl_stay_constraint(SCM scm, SCM port, scm_print_state *pstate)
{
  strstream ss;
  ClConstraint *pcn = PcnFromScm(scm);
  ss << "#<cl-stay-constraint " << *pcn << ">" << ends;
  scm_puts(ss.str(), port);
  return 1;
}

CL_PROC(cl_stay_constraint_p, "cl-stay-constraint?", 1, 0, 0,
        (SCM obj),
"Return #t if OBJ is a stay constraint object, #t otherwise.\n\
Stay constraints also respond #t to `cl-constraint?' queries,\n\
since they are also constraint objects.")
#define FUNC_NAME s_cl_stay_constraint_p
{
  return SCM_BOOL_FromF(FIsClStayConstraintScm(obj));
}
#undef FUNC_NAME


CL_PROC(make_cl_stay_constraint, "make-cl-stay-constraint", 1, 2, 0,
        (SCM cl_var, SCM strength, SCM factor),
"Return a stay constraint for CL-VAR to stay at its current value.\n\
Weight the constraint according to STRENGTH and FACTOR.  Use\n\
`cl-add-constraint' to add the resulting constraint into a solver,\n\
or use the `cl-add-stay' convenience function instead.")
#define FUNC_NAME s_make_cl_stay_constraint
{
  if (!FIsClVariableScm(cl_var)) {
    scm_wrong_type_arg(FUNC_NAME,1,cl_var);
  }
  ClVariable *pclv = PclvFromScm(cl_var);

  const ClStrength *pcls = &ClsWeak();
  if (FIsClStrengthScm(strength)) {
    pcls = PclsFromScm(strength);
  } else if (!FUnsetSCM(strength)) {
    scm_wrong_type_arg(FUNC_NAME,2,strength);
  }

  double nWeight = 1.0;
  if (gh_number_p(factor)) {
    nWeight = gh_scm2double(factor);
  } else if (!FUnsetSCM(factor)) {
    scm_wrong_type_arg(FUNC_NAME,3,factor);
  }

  SCM answer = ScmMakeClStayConstraint(new ClStayConstraint(*pclv, *pcls, nWeight));
  return answer;
}
#undef FUNC_NAME




//// cl-constraint -- a wrapper for cl-equation and cl-inequality
/// NOT a new SMOB type, just for convenience

CL_PROC(cl_constraint_p, "cl-constraint?", 1, 0, 0,
        (SCM obj),
"Return #t if OBJ is some kind of constraint object, #f otherwise.\n\
There are three kinds of objects for which this procedure\n\
will return #t: \"cl-inequality\", \"cl-equation\", and\n\
\"cl-stay-constraint\" objects.  Since it is often useful to treat\n\
either as a general constraint, this procedure exists to simplify that\n\
test.")
#define FUNC_NAME s_cl_constraint_p
{
  return SCM_BOOL_FromF(FIsClConstraintScm(obj));
}
#undef FUNC_NAME

CL_PROC(cl_constraint_strength, "cl-constraint-strength", 1, 0, 0,
        (SCM constraint),
"Return the cl-strength object for constraint CONSTRAINT.")
#define FUNC_NAME s_cl_constraint_strength
{
  if (!FIsClConstraintScm(constraint)) {
    scm_wrong_type_arg(FUNC_NAME,1,constraint);
  }
  ClConstraint *pconstraint = PcnFromScm(constraint);
  return ScmFromPv(pconstraint->strength().Pv());
}
#undef FUNC_NAME


CL_PROC(cl_constraint_weight, "cl-constraint-weight", 1, 0, 0,
        (SCM constraint),
"Return the weighting factor (a number) for constraint CONSTRAINT.")
#define FUNC_NAME s_cl_constraint_weight
{
  if (!FIsClConstraintScm(constraint)) {
    scm_wrong_type_arg(FUNC_NAME,1,constraint);
  }
  ClConstraint *pconstraint = PcnFromScm(constraint);
  return gh_double2scm(pconstraint->weight());
}
#undef FUNC_NAME


CL_PROC(cl_constraint_is_in_solver_p, "cl-constraint-is-in-solver?", 1, 0, 0,
        (SCM constraint),
"Return #t if CONSTRAINT has been added to a solver, #f otherwise.")
#define FUNC_NAME s_cl_constraint_is_in_solver_p
{
  if (!FIsClConstraintScm(constraint)) {
    scm_wrong_type_arg(FUNC_NAME,1,constraint);
  }
  ClConstraint *pconstraint = PcnFromScm(constraint);
  return SCM_BOOL_FromF(pconstraint->FIsInSolver());
}
#undef FUNC_NAME


CL_PROC(cl_constraint_change_strength_x, "cl-constraint-change-strength!", 2, 0, 0,
        (SCM constraint, SCM strength),
"Set CONSTRAINT's strength to STRENGTH.\n\
This is only allowed if the constraint is not in any solver.\n\
Returns #t if successful, #f otherwise.")
#define FUNC_NAME s_cl_constraint_change_strength_x
{
  if (!FIsClConstraintScm(constraint)) {
    scm_wrong_type_arg(FUNC_NAME,1,constraint);
  }
  if (!FIsClStrengthScm(strength)) {
    scm_wrong_type_arg(FUNC_NAME,2,strength);
  }
  ClConstraint *pconstraint = PcnFromScm(constraint);
  ClStrength *pcls = PclsFromScm(strength);
  try {
    pconstraint->ChangeStrength(*pcls);
  } catch (const ExCLTooDifficult &) {
    return SCM_BOOL_F;
  }
  return SCM_BOOL_T;
}
#undef FUNC_NAME


CL_PROC(cl_constraint_change_weight_x, "cl-constraint-change-weight!", 2, 0, 0,
        (SCM constraint, SCM weight),
"Set CONSTRAINT's weighting factor to WEIGHT (a number).\n\
This is only allowed if the constraint is not in any solver.\n\
Returns #t if successful, #f otherwise.")
#define FUNC_NAME s_cl_constraint_change_weight_x
{
  if (!FIsClConstraintScm(constraint)) {
    scm_wrong_type_arg(FUNC_NAME,1,constraint);
  }
  if (!gh_number_p(weight)) {
    scm_wrong_type_arg(FUNC_NAME,2,weight);
  }
  ClConstraint *pconstraint = PcnFromScm(constraint);
  double nWeight = gh_scm2double(weight);
  try {
    pconstraint->ChangeWeight(nWeight);
  } catch (const ExCLTooDifficult &) {
    return SCM_BOOL_F;
  }
  return SCM_BOOL_T;
}
#undef FUNC_NAME



class ClVarLookupByGuileProc: public ClVarLookupFunction {
public:
  ClVarLookupByGuileProc(SCM proc) : _proc(proc) { }
  ClVariable *operator()(const string &str) const
    {
      SCM string_id = gh_str02scm(str.c_str());
      SCM answer = gh_call1(_proc,string_id);
      if (!FIsClVariableScm(answer))
        return NULL;
      return PclvFromScm(answer);
    }
private:
  SCM _proc;
};


CL_PROC(make_cl_constraint_from_string, "make-cl-constraint-from-string", 2, 2, 0,
        (SCM str, SCM lookup_proc, SCM strength, SCM factor),
"Return a newly-constructed constraint object or #f if parse fails.\n\
STR is a string specifying the desired constraint.  The\n\
created constraint is given strength STRENGTH, a cl-strength, and has\n\
a weight factor of FACTOR, a real number.  STRENGTH defaults to\n\
cls-required, FACTOR defaults to 1.  LOOKUP-PROC must be a procedure\n\
that takes a single string argument and returns either a `cl-variable' object\n\
or #f if there is no such variable with that name.  (It may choose to\n\
create a return a new `cl-variable' object.")
#define FUNC_NAME s_make_cl_constraint_from_string
{
  char *sz = gh_scm2newstr(str,NULL);
  istrstream xiLine(sz);

  if (!gh_procedure_p(lookup_proc)) {
    scm_wrong_type_arg(FUNC_NAME,2,lookup_proc);
  }

  const ClStrength *pcls = &ClsRequired();
  if (FIsClStrengthScm(strength)) {
    pcls = PclsFromScm(strength);
  } else if (!FUnsetSCM(strength)) {
    scm_wrong_type_arg(FUNC_NAME,3,strength);
  }

  double nWeight = 1.0;
  if (gh_number_p(factor)) {
    nWeight = gh_scm2double(factor);
  } else if (!FUnsetSCM(factor)) {
    scm_wrong_type_arg(FUNC_NAME,4,factor);
  }

  ClConstraint *pcn = PcnParseConstraint(xiLine,ClVarLookupByGuileProc(lookup_proc));

  pcn->ChangeStrength(*pcls);
  pcn->ChangeWeight(nWeight);

  SCM id = (SCM) scm_tc16_cl_equation;
  if (pcn->IsInequality())
    id = (SCM) scm_tc16_cl_inequality;

  return ScmMakeClConstraint(pcn,id);
}
#undef FUNC_NAME



CL_PROC(make_cl_constraint, "make-cl-constraint", 3, 2, 0,
        (SCM exprA, SCM op, SCM exprB, SCM strength, SCM factor),
"Return a newly-constructed constraint object.\n\
EXPRA and EXPRB are cl-expression or cl-variable objects.  OP is one\n\
of `=', `<=', or `>=', anything else will signal an error.  Note that\n\
the arithmetic comparison procedures are just used for their identity.\n\
The returned object is a cl-equation constraint object if OP is `=';\n\
it is a cl-inequality constraint object if OP is `<=' or `>='.  The\n\
created constraint is given strength STRENGTH, a cl-strength, and has\n\
a weight factor of FACTOR, a real number.  STRENGTH defaults to\n\
cls-required, FACTOR defaults to 1.")
#define FUNC_NAME s_make_cl_constraint
{
  ClLinearExpression *pexprA = NULL;
  ClLinearExpression *pexprB = NULL;

  if (NULL == (pexprA = PexprNewConvertSCM(exprA))) {
    scm_wrong_type_arg(FUNC_NAME, 1, exprA);
  }
  if (NULL == (pexprB = PexprNewConvertSCM(exprB))) {
    scm_wrong_type_arg(FUNC_NAME, 3, exprB);
  }
  if (!(FIsClLinearExpressionScm(exprA) || FIsClVariableScm(exprA) ||
        FIsClLinearExpressionScm(exprB) || FIsClVariableScm(exprB))) {
    scm_misc_error(FUNC_NAME,"One of arguments must contain a variable",SCM_EOL);
  }

  const ClStrength *pcls = &ClsRequired();
  if (FIsClStrengthScm(strength)) {
    pcls = PclsFromScm(strength);
  } else if (!FUnsetSCM(strength)) {
    scm_wrong_type_arg(FUNC_NAME,4,strength);
  }

  double nWeight = 1.0;
  if (gh_number_p(factor)) {
    nWeight = gh_scm2double(factor);
  } else if (!FUnsetSCM(factor)) {
    scm_wrong_type_arg(FUNC_NAME,5,factor);
  }

  ClConstraint *pcn = NULL;
  SCM id = (SCM) scm_tc16_cl_inequality;
  if (op == gh_lookup("<=")) {
    pcn = new ClLinearInequality(*pexprA,cnLEQ,*pexprB,*pcls,nWeight);
  } else if (op == gh_lookup(">=")) {
    pcn = new ClLinearInequality(*pexprA,cnGEQ,*pexprB,*pcls,nWeight);
  } else if (op == gh_lookup("=")) {
    pcn = new ClLinearEquation(*pexprA,*pexprB,*pcls,nWeight);
    id = (SCM) scm_tc16_cl_equation;
  } else {
    scm_wrong_type_arg(FUNC_NAME, 2, op);
  }
 
  return ScmMakeClConstraint(pcn,id);
}
#undef FUNC_NAME



//// ClSimplexSolver wrapper
#undef SCMTYPEID
#define SCMTYPEID scm_tc16_cl_solver

long SCMTYPEID;

SCM
mark_cl_solver(SCM scm)
{
  SCM_SETGC8MARK(scm);
  return SCM_BOOL_F;
}

size_t
free_cl_solver(SCM scm)
{
  ClSimplexSolver *psolver = PsolverFromScm(scm);
  delete psolver;
  return 0;
}

int
print_cl_solver(SCM scm, SCM port, scm_print_state *pstate)
{
  strstream ss;
  ClSimplexSolver *psolver = PsolverFromScm(scm);
  ss << "#<cl-solver ";
  psolver->PrintInternalInfo(ss);
  ss << ">" << ends;
  scm_puts(ss.str(), port);
  return 1;
}


CL_PROC(cl_solver_debug_print, "cl-solver-debug-print", 1, 1, 0,
        (SCM solver, SCM port),
"Output a complete dump of SOLVER onto output port PORT.\n\
The output contains the contents of the tableau contained in SOLVER,\n\
as well as the other internal state.  It can be useful for debugging,\n\
as the printable form of constraint solver objects contains only a\n\
brief summary of the contents of the solver.")
#define FUNC_NAME s_cl_solver_debug_print
{
  if (!FIsClSimplexSolverScm(solver))
    scm_wrong_type_arg(FUNC_NAME,1,solver);
  if (FUnsetSCM(port))
    port = scm_current_output_port();
  if (scm_output_port_p(port) == SCM_BOOL_F)
    scm_wrong_type_arg(FUNC_NAME,2,port);
  
  strstream ss;
  ClSimplexSolver *psolver = PsolverFromScm(solver);
  psolver->PrintOnVerbose(ss);
  ss << ends;
  scm_puts(ss.str(), port);
  return SCM_UNSPECIFIED;
}
#undef FUNC_NAME


CL_PROC(cl_solver_p, "cl-solver?", 1, 0, 0,
        (SCM obj),
"Return #t if OBJ is a constraint solver object, #f otherwise.")
#define FUNC_NAME s_cl_solver_p
{
  return SCM_BOOL_FromF(FIsClSimplexSolverScm(obj));
}
#undef FUNC_NAME

CL_PROC(make_cl_solver, "make-cl-solver", 0, 0, 0,
        (),
"Return a newly-created constraint solver object.\n\
Often, an application will need only one of these objects,  but\n\
multiple independent solvers may exist as long as they do not\n\
share constraint variable objects.")
#define FUNC_NAME s_make_cl_solver
{
  ClSimplexSolver *psolver = new ClSimplexSolver();

  SCM answer;

  SCM_DEFER_INTS;
  SCM_NEWCELL(answer);
  SCM_SETCAR(answer, (SCM) SCMTYPEID);
  SCM_SETCDR(answer, (SCM) psolver);
  SCM_ALLOW_INTS;

  psolver->SetPv(PvFromScm(answer));

  return answer;
}
#undef FUNC_NAME

CL_PROC(cl_set_auto_solve_x, "cl-set-auto-solve!", 2, 0, 0,
        (SCM solver, SCM flag),
"Choose whether SOLVER autosolves or not.\n\
FLAG should be either #t or #f.")
#define FUNC_NAME s_cl_set_auto_solve_x
{
  if (!FIsClSimplexSolverScm(solver)) {
    scm_wrong_type_arg(FUNC_NAME,1,solver);
  }
  bool f;
  COPY_BOOL_OR_ERROR_DEFAULT_FALSE(f,flag,2,FUNC_NAME);
  ClSimplexSolver *psolver = PsolverFromScm(solver);

  psolver->SetAutosolve(f);

  return SCM_UNSPECIFIED;
}
#undef FUNC_NAME

CL_PROC(cl_set_auto_reset_stay_constants_x, "cl-set-auto-reset-stay-constants!", 2, 0, 0,
        (SCM solver, SCM flag),
"Choose whether SOLVER automatically resets stay constants or not.\n\
FLAG should be either #t or #f.")
#define FUNC_NAME s_cl_set_auto_reset_stay_constants_x
{
  if (!FIsClSimplexSolverScm(solver)) {
    scm_wrong_type_arg(FUNC_NAME,1,solver);
  }
  bool f;
  COPY_BOOL_OR_ERROR_DEFAULT_FALSE(f,flag,2,FUNC_NAME);
  ClSimplexSolver *psolver = PsolverFromScm(solver);

  psolver->SetAutoResetStayConstants(f);

  return SCM_UNSPECIFIED;
}
#undef FUNC_NAME



CL_PROC(cl_add_constraint, "cl-add-constraint", 1, 0, 1,
        (SCM solver, SCM args),
"Add the constraints, ARGS, to the solver SOLVER.\n\
Each constraint given after the SOLVER argument is added to that\n\
solver in turn.  Once one cannot be added (e.g., due to its addition\n\
causing an insoluble system), this procedure will return #f without\n\
trying to add the remaining constraints.  If all constraints are added \n\
successfully, this procedure will return #t.  (If none of the\n\
constraints have strength \"cls-required\", then the system will remain\n\
soluble.)  If an error is signalled because one object in the list ARGS\n\
is not a constraint object, the preceding arguments will have already\n\
been added.")
#define FUNC_NAME s_cl_add_constraint
{
  if (!FIsClSimplexSolverScm(solver)) {
    scm_wrong_type_arg(FUNC_NAME,1,solver);
  }
    
  ClSimplexSolver *psolver = PsolverFromScm(solver);

  try {
    for (int i = 0; SCM_NNULLP (args); args = SCM_CDR (args), ++i) {
      SCM constraint = SCM_CAR(args);
      if (!FIsClConstraintScm(constraint)) {
        scm_wrong_type_arg(FUNC_NAME,2,args);
      }
      ClConstraint *pconstraint = PcnFromScm(constraint);
      psolver->AddConstraint(*pconstraint);
      scm_protect_object(constraint);
      pconstraint->SetPv(PvFromScm(constraint));
    }
  } catch (const ExCLRequiredFailure &e) {
    // scm_misc_error(FUNC_NAME,e.description, SCM_EOL);
    return SCM_BOOL_F;
  }

  return SCM_BOOL_T;
}
#undef FUNC_NAME

CL_PROC(cl_remove_constraint, "cl-remove-constraint", 1, 0, 1,
        (SCM solver, SCM args),
"Remove the constraints, ARGS, from the solver SOLVER.\n\
Each constraint given after the SOLVER argument is removed from that\n\
solver in turn.  Once one cannot be removed (e.g., due to its never\n\
having been added to SOLVER), this procedure will return #f without\n\
trying to remove the remaining constraints.  If all constraints are\n\
removed successfully, this procedure will return #t.  If an error is\n\
signalled because one object in the list ARGS is not a constraint\n\
object, the preceding arguments will have already been removed.")
#define FUNC_NAME s_cl_remove_constraint
{
  if (!FIsClSimplexSolverScm(solver)) {
    scm_wrong_type_arg(FUNC_NAME,1,solver);
  }

  ClSimplexSolver *psolver = PsolverFromScm(solver);

  try {
    for (int i = 0; SCM_NNULLP (args); args = SCM_CDR (args), ++i) {
      SCM constraint = SCM_CAR(args);
      if (!FIsClConstraintScm(constraint)) {
        scm_wrong_type_arg(FUNC_NAME,2,args);
      }
      ClConstraint *pconstraint = PcnFromScm(constraint);
      psolver->RemoveConstraint(*pconstraint);
      pconstraint->SetPv(0);
      scm_unprotect_object(constraint);  
    }
  } catch (const ExCLConstraintNotFound &e) {
    // scm_misc_error(FUNC_NAME,e.description(),SCM_EOL);
    return SCM_BOOL_F;
  }

  return SCM_BOOL_T;
}
#undef FUNC_NAME


CL_PROC(cl_add_editvar, "cl-add-editvar", 2, 2, 0,
        (SCM solver, SCM cl_vars, SCM strength, SCM factor),
"Add edit constraints on variables CL-VARS to SOLVER.\n\
CL-VARS is a or a list of cl-variable object(s) that you wish to permit to change under\n\
the solver's control.  An edit-constraint for each cl-variable object\n\
is added in turn.   Each of the edit constraints will have strength\n\
STRENGTH (#f for default of cls-strong) and weight FACTOR (#f for\n\
default of 1).  If any element of CL-VARS is not a cl-variable, an error is\n\
thrown (after the preceding variables have been handled).  After\n\
selecting the edit variables with this procedure, you must call\n\
`cl-begin-edit' before using `cl-suggest-value'.  To remove the edit\n\
variables, use `cl-end-edit' when done changing the variables'\n\
values.")
#define FUNC_NAME s_cl_add_editvar
{
  if (!FIsClSimplexSolverScm(solver)) {
    scm_wrong_type_arg(FUNC_NAME,1,solver);
  }
  ClSimplexSolver *psolver = PsolverFromScm(solver);

  const ClStrength *pcls = &ClsStrong();
  if (FIsClStrengthScm(strength)) {
    pcls = PclsFromScm(strength);
  } else if (!FUnsetSCM(strength)) {
    scm_wrong_type_arg(FUNC_NAME,3,strength);
  }

  double nWeight = 1.0;
  if (gh_number_p(factor)) {
    nWeight = gh_scm2double(factor);
  } else if (!FUnsetSCM(factor)) {
    scm_wrong_type_arg(FUNC_NAME,4,factor);
  }

  try {
    if (gh_list_p(cl_vars)) {
      for (int i = 0; SCM_NNULLP (cl_vars); cl_vars = SCM_CDR (cl_vars), ++i) {
        SCM var = SCM_CAR(cl_vars);
        if (!FIsClVariableScm(var)) {
          scm_wrong_type_arg(FUNC_NAME,2,cl_vars);
        }
        ClVariable *pclv = PclvFromScm(var);
        psolver->AddEditVar(*pclv,*pcls,nWeight);
      }
    } else {
      if (!FIsClVariableScm(cl_vars)) {
        scm_wrong_type_arg(FUNC_NAME,2,cl_vars);
      }
      ClVariable *pclv = PclvFromScm(cl_vars);
      psolver->AddEditVar(*pclv,*pcls,nWeight);
    }
  } catch (const ExCLEditMisuse &e) {
    scm_misc_error(FUNC_NAME, e.description().c_str(), SCM_EOL);
  }

  return SCM_UNSPECIFIED;
}
#undef FUNC_NAME


CL_PROC(cl_add_stay, "cl-add-stay", 2, 2, 0,
        (SCM solver, SCM cl_vars, SCM strength, SCM factor),
"Add stay constraints on variables CL-VARS to SOLVER.\n\
CL-VARS is a or list of cl-variable(s) that you wish to remain (i.e., stay) at\n\
their current values unless another constraint forces them to change.\n\
In normal uses of the solver, all variables should have stay\n\
constraints added on them before they are used in a constraint added\n\
to the solver.  Each of the stay constraints will have strength\n\
STRENGTH (#f for default of cls-weak) and weight FACTOR (#f for\n\
default of 1).\n\
\n\
Future versions of the solver may add the stay\n\
constraint implicitly upon a variable's first use.  Until then,\n\
though, be sure to add stay constraints on all the cl-variable objects\n\
you intend to use with the given SOLVER.")
#define FUNC_NAME s_cl_add_stay
{
  if (!FIsClSimplexSolverScm(solver)) {
    scm_wrong_type_arg(FUNC_NAME,1,solver);
  }
  ClSimplexSolver *psolver = PsolverFromScm(solver);

  const ClStrength *pcls = &ClsWeak();
  if (FIsClStrengthScm(strength)) {
    pcls = PclsFromScm(strength);
  } else if (!FUnsetSCM(strength)) {
    scm_wrong_type_arg(FUNC_NAME,3,strength);
  }

  double nWeight = 1.0;
  if (gh_number_p(factor)) {
    nWeight = gh_scm2double(factor);
  } else if (!FUnsetSCM(factor)) {
    scm_wrong_type_arg(FUNC_NAME,4,factor);
  }

  try {
    if (gh_list_p(cl_vars)) {
      for (int i = 0; SCM_NNULLP (cl_vars); cl_vars = SCM_CDR (cl_vars), ++i) {
        SCM var = SCM_CAR(cl_vars);
        if (!FIsClVariableScm(var)) {
          scm_wrong_type_arg(FUNC_NAME,2,cl_vars);
        }
        ClVariable *pclv = PclvFromScm(var);
        psolver->AddStay(*pclv,*pcls,nWeight);
      }
    } else {
      if (!FIsClVariableScm(cl_vars)) {
        scm_wrong_type_arg(FUNC_NAME,2,cl_vars);
      }
      ClVariable *pclv = PclvFromScm(cl_vars);
      psolver->AddStay(*pclv,*pcls,nWeight);
    }
  } catch (const ExCLError &e) {
    scm_misc_error(FUNC_NAME, e.description().c_str(), SCM_EOL);
  }

  return SCM_UNSPECIFIED;
}
#undef FUNC_NAME




CL_PROC(cl_begin_edit, "cl-begin-edit", 1, 0, 0,
        (SCM solver),
"Begin changing values of the edit variables of SOLVER.\n\
This procedure must be invoked after adding edit variables to SOLVER\n\
(via `cl-add-editvar') and before using `cl-suggest-values' to change\n\
those edit variables' values.  Every `cl-begin-edit' invocation should \n\
have a matching `cl-end-edit' call.")
#define FUNC_NAME s_cl_begin_edit
{
  if (!FIsClSimplexSolverScm(solver)) {
    scm_wrong_type_arg(FUNC_NAME,1,solver);
  }
  ClSimplexSolver *psolver = PsolverFromScm(solver);

  psolver->BeginEdit();

  return SCM_UNSPECIFIED;
}
#undef FUNC_NAME

CL_PROC(cl_end_edit, "cl-end-edit", 1, 0, 0,
        (SCM solver),
"Finish changing the values of the edit variables in SOLVER.\n\
This procedure must be invoked once for every invocation of \n\
`cl-begin-edit'.   It will force a final re-solve before removing\n\
any edit variables that have been added via `cl-add-editvar'.")
#define FUNC_NAME s_cl_end_edit
{
  if (!FIsClSimplexSolverScm(solver)) {
    scm_wrong_type_arg(FUNC_NAME,1,solver);
  }
  ClSimplexSolver *psolver = PsolverFromScm(solver);

  psolver->EndEdit();

  return SCM_UNSPECIFIED;
}
#undef FUNC_NAME


CL_PROC (cl_is_constraint_satisfied_p, "cl-is-constraint-satisfied?", 2, 0, 0,
         (SCM solver, SCM cn),
"Return #t if CN is satisfied in SOLVER, #f otherwise.")
#define FUNC_NAME s_cl_is_constraint_satisfied_p
{
  if (!FIsClSimplexSolverScm(solver)) {
    scm_wrong_type_arg(FUNC_NAME,1,solver);
  }
  if (!FIsClConstraintScm(cn)) {
    scm_wrong_type_arg(FUNC_NAME,2,cn);
  }
  ClSimplexSolver *psolver = PsolverFromScm(solver);
  ClConstraint *pcn = PcnFromScm(cn);
  return gh_bool2scm(psolver->FIsConstraintSatisfied(pcn));
}
#undef FUNC_NAME



CL_PROC(cl_suggest_value, "cl-suggest-value", 3, 0, 0,
        (SCM solver, SCM var, SCM value),
"Try to change VAR's value to VALUE within SOLVER.\n\
You may only call this procedure after using `cl-add-editvar' to add\n\
VAR as an edit variable for SOLVER, and after invoking `cl-begin-edit'\n\
on SOLVER.  After you call `cl-begin-edit', you may invoke this\n\
procedure on all the edit variables.  The changing of the values of\n\
those variables (and the affect on other variables within SOLVER) will\n\
not happen until after invoking `cl-resolve' on SOLVER.  Then the\n\
possibly changed values can be retrieved via `cl-value' or\n\
`cl-int-value'.  Note that the constraints that have been added to\n\
SOLVER may not permit changing VAR to VALUE.")
#define FUNC_NAME s_cl_suggest_value
{
  if (!FIsClSimplexSolverScm(solver)) {
    scm_wrong_type_arg(FUNC_NAME,1,solver);
  }
  if (!FIsClVariableScm(var)) {
    scm_wrong_type_arg(FUNC_NAME,2,var);
  }
  if (!gh_number_p(value)) {
    scm_wrong_type_arg(FUNC_NAME,3,value);
  }
  ClSimplexSolver *psolver = PsolverFromScm(solver);
  ClVariable *pclv = PclvFromScm(var);
  double n = gh_scm2double(value);

  try {
    psolver->SuggestValue(*pclv,n);
  } catch (const ExCLError &e) {
    scm_misc_error(FUNC_NAME, e.description().c_str(), SCM_EOL);
  }
  return SCM_UNSPECIFIED;
}
#undef FUNC_NAME


CL_PROC(cl_resolve, "cl-resolve", 1, 0, 1,
        (SCM solver, SCM args),
"Ask SOLVER to re-solve its system using the suggested values.\n\
You may only call this procedure between invocations of\n\
`cl-begin-edit' and `cl-end-edit'.  After `cl-begin-edit', you may use\n\
`cl-suggest-value' on SOLVER to tell it the desired new values for the\n\
various edit variables you have added using `cl-add-editvar', and then\n\
call this procedure with only the first argument to have SOLVER update\n\
the values of all the variables in the system.\n\
\n\
Alternatively, after adding edit-variables in a particular order, you\n\
may call `cl-begin-edit' then this procedure with ARGS set as\n\
suggested values for the edit-variables.  The order of the values in\n\
the `cl-resolve' invocation must match the order of the variables in\n\
the `cl-add-editvar' invocation(s).\n\
\n\
In either case, you must invoke `cl-end-edit' to remove the edit\n\
variables from the solver after you are done changing their values.")
#define FUNC_NAME s_cl_resolve
{
  if (!FIsClSimplexSolverScm(solver)) {
    scm_wrong_type_arg(FUNC_NAME,1,solver);
  }
  ClSimplexSolver *psolver = PsolverFromScm(solver);

  if (FUnsetSCM(args)) {
    psolver->Resolve();
    return SCM_UNSPECIFIED;
  }

  vector<double> rgval;

  for (int i = 0; SCM_NNULLP (args); args = SCM_CDR (args), ++i) {
    SCM val = SCM_CAR(args);
    if (!gh_number_p(val)) {
      scm_wrong_type_arg(FUNC_NAME,2,args);
    }
    rgval.push_back(gh_scm2double(val));
  }

  try {
    if (rgval.size() == 0)
      psolver->Resolve(); // No arg version is different fn
    else
      psolver->Resolve(rgval);
  } catch (const ExCLBadResolve &e) {
    scm_misc_error(FUNC_NAME, e.description().c_str(), SCM_EOL);
  }
  
  return SCM_UNSPECIFIED;
}
#undef FUNC_NAME


CL_PROC (cl_constraint_list, "cl-constraint-list", 1, 1, 0,
         (SCM solver, SCM internal_also_p),
"Return the list of constraints in SOLVER.\n\
Each object in the returned list is a cl-constraint object (i.e.,\n\
it is either a cl-linear-equation or a cl-inequality). If\n\
INTERNAL-ALSO? is #f or not given, then only the constraints added via \n\
the guile interface will be listed.  If INTERNAL-ALSO? is #t, then all \n\
constraints added to the solver (even those added by primitive code\n\
directly) will be listed.")
#define FUNC_NAME s_cl_constraint_list
{
  SCM list = SCM_EOL;
  if (!FIsClSimplexSolverScm(solver)) {
    scm_wrong_type_arg(FUNC_NAME,1,solver);
  }
  bool fInternalAlso;
  COPY_BOOL_OR_ERROR_DEFAULT_FALSE(fInternalAlso,internal_also_p,2,FUNC_NAME);
    
  ClSimplexSolver *psolver = PsolverFromScm(solver);

  const ClConstraintToVarMap mapCns = psolver->ConstraintMap();

  ClConstraintToVarMap::const_iterator it_marker = mapCns.begin();

  for ( ; it_marker != mapCns.end() ; ++it_marker) {
    const ClConstraint *pcn = (*it_marker).first;
    SCM cn = SCM_UNDEFINED;
    void *pv = pcn->Pv();
    if (pv) cn = ScmFromPv(pv);
    else if (fInternalAlso) {
      const ClLinearEquation *peq = 
        dynamic_cast<const ClLinearEquation *>(pcn);
      if (peq) {
        cn = ScmMakeClLinearEquation(peq);
      } else {
        const ClLinearInequality *pineq = 
          dynamic_cast<const ClLinearInequality *>(pcn);
        if (pineq)
          cn = ScmMakeClLinearInequality(pineq);
      }
    }
    if (cn != SCM_UNDEFINED)
      list = gh_cons(cn,list);
  }

  return list;
}
#undef FUNC_NAME




//// cassowary_scm initialization

MAKE_SMOBFUNS(cl_variable);
MAKE_SMOBFUNS(cl_weight);
MAKE_SMOBFUNS(cl_strength);
MAKE_SMOBFUNS(cl_expression);
MAKE_SMOBFUNS(cl_equation);
MAKE_SMOBFUNS(cl_inequality);
MAKE_SMOBFUNS(cl_stay_constraint);
MAKE_SMOBFUNS(cl_solver);

static SCM scm_cls_weak;
static SCM scm_cls_medium;
static SCM scm_cls_strong;
static SCM scm_cls_required;

static void
init_cassowary_scm()
{
  REGISTER_SMOBFUNS(cl_variable);
  REGISTER_SMOBFUNS(cl_weight);
  REGISTER_SMOBFUNS(cl_strength);
  REGISTER_SMOBFUNS(cl_expression);
  REGISTER_SMOBFUNS(cl_equation);
  REGISTER_SMOBFUNS(cl_inequality);
  REGISTER_SMOBFUNS(cl_stay_constraint);
  REGISTER_SMOBFUNS(cl_solver);

  SCM_DEFER_INTS;

  CL_VAR_INIT_PERMANENT(cls_weak,"cls-weak", ScmMakeClStrength(const_cast<ClStrength *> (&ClsWeak())));
  /** The "weak" predefined cl-strength object. */

  CL_VAR_INIT_PERMANENT(cls_medium,"cls-medium", ScmMakeClStrength(const_cast<ClStrength *> (&ClsMedium())));
  /** The "medium" predefined cl-strength object. */

  CL_VAR_INIT_PERMANENT(cls_strong,"cls-strong", ScmMakeClStrength(const_cast<ClStrength *> (&ClsStrong())));
  /** The "strong" predefined cl-strength object. */

  CL_VAR_INIT_PERMANENT(cls_required,"cls-required", ScmMakeClStrength(const_cast<ClStrength *> (&ClsRequired())));
  /** The "required" predefined cl-strength object. */

  SCM_ALLOW_INTS;
#ifndef SCM_MAGIC_SNARFER
#include "cassowary_scm.x"
#endif
}

void scm_init_cassowary_constraints_module()
{
  scm_register_module_xxx("cassowary constraints", init_cassowary_scm);
}

} // extern "C"



/* Local Variables: */
/* tab-width: 8 */
/* c-basic-offset: 2 */
/* End: */
