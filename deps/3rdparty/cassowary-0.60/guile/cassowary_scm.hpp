// $Id: cassowary_scm.hpp,v 1.10 2000/02/13 04:34:37 gjb Exp $
// By Greg J. Badros -- 18 July 1998
//
// A Guile Scheme wrapper for the Cassowary Constraint Solving Toolkit
//
// The C++ header file, for extending the set of Cl primitives
//

#ifndef CASSOWARY_SCM_HPP__
#define CASSOWARY_SCM_HPP__

#if defined(HAVE_CONFIG_H) && !defined(CONFIG_H_INCLUDED) && !defined(CONFIG_INLINE_H_INCLUDED)
#include <cassowary/config-inline.h>
#define CONFIG_INLINE_H_INCLUDED
#endif

#include <guile/gh.h>

#include <iostream.h>
#include <assert.h>
#include <strstream.h>
#include "cl-snarf.h"

//// ClVariable wrapper
class ClVariable;

#define SCMTYPEID scm_tc16_cl_variable

extern long SCMTYPEID;

inline bool FIsClVariableScm(SCM scm) 
{ return SCM_NIMP(scm) && SCM_CAR(scm) == (SCM) SCMTYPEID; }

inline ClVariable *PclvFromScm(SCM scm)
{ return (ClVariable *)(SCM_CDR(scm)); }

inline SCM ScmMakeClVariable(ClVariable *pclv) {
  SCM answer;
  
  SCM_DEFER_INTS;
  SCM_NEWCELL(answer);
  SCM_SETCAR(answer, (SCM) SCMTYPEID);
  SCM_SETCDR(answer, (SCM) pclv);
  SCM_ALLOW_INTS;

  return answer;
}

//// ClSymbolicWeight wrapper
class ClSymbolicWeight;

#undef SCMTYPEID
#define SCMTYPEID scm_tc16_cl_weight

extern long SCMTYPEID;

inline bool FIsClSymbolicWeightScm(SCM scm) 
{ return SCM_NIMP(scm) && SCM_CAR(scm) == (SCM) SCMTYPEID; }


inline ClSymbolicWeight *PclswFromScm(SCM scm)
{ return (ClSymbolicWeight *)(SCM_CDR(scm)); }

//// ClStrength wrapper
class ClStrength;

#undef SCMTYPEID
#define SCMTYPEID scm_tc16_cl_strength

extern long SCMTYPEID;

inline bool FIsClStrengthScm(SCM scm) 
{ return SCM_NIMP(scm) && SCM_CAR(scm) == (SCM) SCMTYPEID; }

inline ClStrength *PclsFromScm(SCM scm)
{ return (ClStrength *)(SCM_CDR(scm)); }

//// ClLinearExpression wrapper
#include "cassowary/ClLinearExpression_fwd.h"

#undef SCMTYPEID
#define SCMTYPEID scm_tc16_cl_expression

extern long SCMTYPEID;

inline bool FIsClLinearExpressionScm(SCM scm) 
{ return SCM_NIMP(scm) && SCM_CAR(scm) == (SCM) SCMTYPEID; }

inline ClLinearExpression *PexprFromScm(SCM scm)
{ return (ClLinearExpression *)(SCM_CDR(scm)); }

inline SCM ScmMakeClLinearExpression(const ClLinearExpression *pexpr) {
  SCM answer;
  
  SCM_DEFER_INTS;
  SCM_NEWCELL(answer);
  SCM_SETCAR(answer, (SCM) SCMTYPEID);
  SCM_SETCDR(answer, (SCM) pexpr);
  SCM_ALLOW_INTS;

  return answer;
}

//// ClLinearEquation wrapper
class ClLinearEquation;

#undef SCMTYPEID
#define SCMTYPEID scm_tc16_cl_equation

extern long SCMTYPEID;

inline bool FIsClLinearEquationScm(SCM scm) 
{ return SCM_NIMP(scm) && SCM_CAR(scm) == (SCM) SCMTYPEID; }

inline ClLinearEquation *PeqFromScm(SCM scm)
{ return (ClLinearEquation *)(SCM_CDR(scm)); }

inline SCM ScmMakeClLinearEquation(const ClLinearEquation *peq) {
  SCM answer;
  
  SCM_DEFER_INTS;
  SCM_NEWCELL(answer);
  SCM_SETCAR(answer, (SCM) SCMTYPEID);
  SCM_SETCDR(answer, (SCM) peq);
  SCM_ALLOW_INTS;

  return answer;
}

//// ClLinearInequality wrapper
class ClLinearInequality;

#undef SCMTYPEID
#define SCMTYPEID scm_tc16_cl_inequality

extern long SCMTYPEID;

inline bool FIsClLinearInequalityScm(SCM scm) 
{ return SCM_NIMP(scm) && SCM_CAR(scm) == (SCM) SCMTYPEID; }

inline ClLinearInequality *PineqFromScm(SCM scm)
{ return (ClLinearInequality *)(SCM_CDR(scm)); }

inline SCM ScmMakeClLinearInequality(const ClLinearInequality *pineq) {
  SCM answer;
  
  SCM_DEFER_INTS;
  SCM_NEWCELL(answer);
  SCM_SETCAR(answer, (SCM) SCMTYPEID);
  SCM_SETCDR(answer, (SCM) pineq);
  SCM_ALLOW_INTS;

  return answer;
}


//// ClStayConstraint wrapper
class ClStayConstraint;

#undef SCMTYPEID
#define SCMTYPEID scm_tc16_cl_stay_constraint

extern long SCMTYPEID;

inline bool FIsClStayConstraintScm(SCM scm) 
{ return SCM_NIMP(scm) && SCM_CAR(scm) == (SCM) SCMTYPEID; }

inline ClStayConstraint *PstaycnFromScm(SCM scm)
{ return (ClStayConstraint *)(SCM_CDR(scm)); }

inline SCM ScmMakeClStayConstraint(const ClStayConstraint *pstaycn) {
  SCM answer;
  
  SCM_DEFER_INTS;
  SCM_NEWCELL(answer);
  SCM_SETCAR(answer, (SCM) SCMTYPEID);
  SCM_SETCDR(answer, (SCM) pstaycn);
  SCM_ALLOW_INTS;

  return answer;
}

//// cl-constraint -- a wrapper for cl-equation and cl-inequality
/// NOT a new SMOB type, just for convenience
class ClConstraint;

inline bool FIsClConstraintScm(SCM scm) {
  if (!SCM_NIMP(scm)) return false; 
  SCM car = SCM_CAR(scm);

  if (car == (SCM) scm_tc16_cl_equation) return true;
  if (car == (SCM) scm_tc16_cl_inequality) return true;
  if (car == (SCM) scm_tc16_cl_stay_constraint) return true;

  return false;
}

inline ClConstraint *PcnFromScm(SCM scm)
{ return (ClConstraint *)(SCM_CDR(scm)); }

inline SCM ScmMakeClConstraint(const ClConstraint *pcn, SCM id) {
  SCM answer;
  
  SCM_DEFER_INTS;
  SCM_NEWCELL(answer);
  SCM_SETCAR(answer, id);
  SCM_SETCDR(answer, (SCM) pcn);
  SCM_ALLOW_INTS;

  return answer;
}


//// ClSimplexSolver wrapper
class ClSimplexSolver;

#undef SCMTYPEID
#define SCMTYPEID scm_tc16_cl_solver

extern long SCMTYPEID;

inline bool FIsClSimplexSolverScm(SCM scm) 
{ return SCM_NIMP(scm) && SCM_CAR(scm) == (SCM) SCMTYPEID; }

inline ClSimplexSolver *PsolverFromScm(SCM scm)
{ return (ClSimplexSolver *)(SCM_CDR(scm)); }

inline void *PvFromScm(SCM scm)
{ return reinterpret_cast<void *>(scm); }

inline SCM ScmFromPv(const void *pv)
{ return reinterpret_cast<SCM>(pv); }

#endif


/* Local Variables: */
/* tab-width: 8 */
/* c-basic-offset: 2 */
/* End: */
