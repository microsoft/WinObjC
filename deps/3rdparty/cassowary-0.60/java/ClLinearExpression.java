// $Id: ClLinearExpression.java,v 1.31 1999/04/20 00:26:32 gjb Exp $
//
// Cassowary Incremental Constraint Solver
// Original Smalltalk Implementation by Alan Borning
// This Java Implementation by Greg J. Badros, <gjb@cs.washington.edu>
// http://www.cs.washington.edu/homes/gjb
// (C) 1998, 1999 Greg J. Badros and Alan Borning
// See ../LICENSE for legal details regarding this software
//
// ClLinearExpression
//

package EDU.Washington.grad.gjb.cassowary;

import java.util.*;

public class ClLinearExpression extends CL
{

  public ClLinearExpression(ClAbstractVariable clv, double value, double constant)
    {
      if (CL.fGC)
	System.err.println("new ClLinearExpression");

      _constant = new ClDouble(constant);
      _terms = new Hashtable(1);
      if (clv != null)
	_terms.put(clv,new ClDouble(value));
    }

  public ClLinearExpression(double num)
    {
      this(null,0,num);
    }

  public ClLinearExpression()
    {
      this(0);
    }

  public ClLinearExpression(ClAbstractVariable clv, double value)
    {
      this(clv,value,0.0);
    }

  public ClLinearExpression(ClAbstractVariable clv)
    {
      this(clv,1,0);
    }


  // for use by the clone method
  protected ClLinearExpression(ClDouble constant, Hashtable terms)
    {
      if (CL.fGC)
	System.err.println("clone ClLinearExpression");
      _constant = (ClDouble) constant.clone();
      _terms = new Hashtable();
      // need to unalias the ClDouble-s that we clone (do a deep clone)
      for (Enumeration e = terms.keys(); e.hasMoreElements() ; ) {
	ClAbstractVariable clv = (ClAbstractVariable) e.nextElement();
	_terms.put(clv,((ClDouble) terms.get(clv)).clone());
      }
    }


  public ClLinearExpression multiplyMe(double x)
    {
      _constant.setValue(_constant.doubleValue() * x);
      
      for (Enumeration e = _terms.keys() ; e.hasMoreElements(); ) {
        ClAbstractVariable clv = (ClAbstractVariable) e.nextElement();
	ClDouble cld = (ClDouble) _terms.get(clv);
	cld.setValue(cld.doubleValue() * x);
      } 
      return  this;
    }

  public final Object clone()
    {
      return new ClLinearExpression(_constant,_terms);
    }

  public final ClLinearExpression times(double x)
    {
      return ((ClLinearExpression) clone()).multiplyMe(x);
    }

  public final ClLinearExpression times(ClLinearExpression expr) 
       throws ExCLNonlinearExpression
    {
      if (isConstant())
	{
	return expr.times(_constant.doubleValue());
	}
      else if (!expr.isConstant())
	{
	throw new ExCLNonlinearExpression();
	}	
      return times(expr._constant.doubleValue());
    }

  public final ClLinearExpression plus(ClLinearExpression expr)
    {
      return ((ClLinearExpression) clone()).addExpression(expr,1.0);
    }

  public final ClLinearExpression plus(ClVariable var) 
    throws ExCLNonlinearExpression
    { 
      return ((ClLinearExpression) clone()).addVariable(var,1.0);
    }

  public final ClLinearExpression minus(ClLinearExpression expr)
    {
      return ((ClLinearExpression) clone()).addExpression(expr,-1.0);
    }

  public final ClLinearExpression minus(ClVariable var) 
       throws ExCLNonlinearExpression
    { 
      return ((ClLinearExpression) clone()).addVariable(var,-1.0);
    }


  public final ClLinearExpression divide(double x)
    throws ExCLNonlinearExpression
    {
      if (CL.approx(x,0.0))
	{
	throw new ExCLNonlinearExpression();
	}
      return times(1.0/x);
    }

  public final ClLinearExpression divide(ClLinearExpression expr)
    throws ExCLNonlinearExpression
    {
      if (!expr.isConstant())
	{
	throw new ExCLNonlinearExpression();
	}
      return divide(expr._constant.doubleValue());
    }

  public final ClLinearExpression divFrom(ClLinearExpression expr) 
    throws ExCLNonlinearExpression
    {
      if (!isConstant() || CL.approx(_constant.doubleValue(),0.0))
	{
	throw new ExCLNonlinearExpression();
	}
      return expr.divide(_constant.doubleValue());
    }

  public final ClLinearExpression subtractFrom(ClLinearExpression expr)
    { return expr.minus( this); }

  // Add n*expr to this expression from another expression expr.
  // Notify the solver if a variable is added or deleted from this
  // expression.
  public final ClLinearExpression addExpression(ClLinearExpression expr, double n,
						ClAbstractVariable subject, 
						ClTableau solver)
    {
      incrementConstant(n * expr.constant());
      
      for (Enumeration e = expr.terms().keys() ; e.hasMoreElements(); ) {
	ClAbstractVariable clv = (ClAbstractVariable) e.nextElement();
 	double coeff = ((ClDouble) expr.terms().get(clv)).doubleValue();
 	addVariable(clv,coeff*n, subject, solver);
      }
      return this;
    }

  // Add n*expr to this expression from another expression expr.
  public final ClLinearExpression addExpression(ClLinearExpression expr, double n)
    {
      incrementConstant(n * expr.constant());
      
      for (Enumeration e = expr.terms().keys() ; e.hasMoreElements(); ) {
        ClAbstractVariable clv = (ClAbstractVariable) e.nextElement();
	double coeff = ((ClDouble) expr.terms().get(clv)).doubleValue();
	addVariable(clv,coeff*n);
      }
      return this;
    }

  public final ClLinearExpression addExpression(ClLinearExpression expr)
    {
      return addExpression(expr,1.0);
    }

  // Add a term c*v to this expression.  If the expression already
  // contains a term involving v, add c to the existing coefficient.
  // If the new coefficient is approximately 0, delete v.
  public final ClLinearExpression addVariable(ClAbstractVariable v, double c)
    { // body largely duplicated below
      if (fTraceOn) fnenterprint("addVariable:" + v + ", " + c);

      ClDouble coeff = (ClDouble) _terms.get(v);
      if (coeff != null) {
	double new_coefficient = coeff.doubleValue() + c;
	if (CL.approx(new_coefficient,0.0)) {
	  _terms.remove(v);
	}
	else {
	  coeff.setValue(new_coefficient);
	}
      } else {
	if (!CL.approx(c,0.0)) {
	  _terms.put(v,new ClDouble(c));
	}
      }
      return this;
    }

  public final ClLinearExpression addVariable(ClAbstractVariable v)
  { return addVariable(v,1.0); }


  public final ClLinearExpression setVariable(ClAbstractVariable v, double c)
    { 
      //assert(c != 0.0);  
      ClDouble coeff = (ClDouble) _terms.get(v);
      if (coeff != null) 
	coeff.setValue(c);
      else
	_terms.put(v,new ClDouble(c)); 
      return this;
    }

  // Add a term c*v to this expression.  If the expression already
  // contains a term involving v, add c to the existing coefficient.
  // If the new coefficient is approximately 0, delete v.  Notify the
  // solver if v appears or disappears from this expression.
  public final ClLinearExpression addVariable(ClAbstractVariable v, double c,
 					ClAbstractVariable subject, ClTableau solver)
     { // body largely duplicated above
       if (fTraceOn) fnenterprint("addVariable:" + v + ", " + c + ", " + subject + ", ...");

       ClDouble coeff = (ClDouble) _terms.get(v);
       if (coeff != null) {
	 double new_coefficient = coeff.doubleValue() + c;
	 if (CL.approx(new_coefficient,0.0)) {
	   solver.noteRemovedVariable(v,subject);
	   _terms.remove(v);
	 } else { 
	   coeff.setValue(new_coefficient);
	 }
       } else {
	 if (!CL.approx(c,0.0)) {
	   _terms.put(v,new ClDouble(c));
	   solver.noteAddedVariable(v,subject);
	 }
       }
       return this;
     }
  
  // Return a pivotable variable in this expression.  (It is an error
  // if this expression is constant -- signal ExCLInternalError in
  // that case).  Return null if no pivotable variables
  public final ClAbstractVariable anyPivotableVariable() throws ExCLInternalError
    {
      if (isConstant())
	{
	throw new ExCLInternalError("anyPivotableVariable called on a constant");
	}

      for (Enumeration e = _terms.keys() ; e.hasMoreElements(); ) {
        ClAbstractVariable clv = (ClAbstractVariable) e.nextElement();
        if (clv.isPivotable())
          return clv;
      } 

      // No pivotable variables, so just return null, and let the caller
      // error if needed
      return null;
    }

  // Replace var with a symbolic expression expr that is equal to it.
  // If a variable has been added to this expression that wasn't there
  // before, or if a variable has been dropped from this expression
  // because it now has a coefficient of 0, inform the solver.
  // PRECONDITIONS:
  //   var occurs with a non-zero coefficient in this expression.
  public final void substituteOut(ClAbstractVariable var, ClLinearExpression expr, 
 			    ClAbstractVariable subject, ClTableau solver)
  {
    if (fTraceOn) fnenterprint("CLE:substituteOut: " + var + ", " + expr + ", " + subject + ", ...");
    if (fTraceOn) traceprint("this = " + this);

    double multiplier = ((ClDouble) _terms.remove(var)).doubleValue();
    incrementConstant(multiplier * expr.constant());
    
    for (Enumeration e = expr.terms().keys(); e.hasMoreElements(); ) {
      ClAbstractVariable clv = (ClAbstractVariable) e.nextElement();
      double coeff = ((ClDouble) expr.terms().get(clv)).doubleValue();
      ClDouble d_old_coeff = (ClDouble) _terms.get(clv);
      if (d_old_coeff != null) {
	double old_coeff = d_old_coeff.doubleValue();
	double newCoeff = old_coeff + multiplier * coeff;
	if (CL.approx(newCoeff,0.0)) {
	  solver.noteRemovedVariable(clv,subject);
	  _terms.remove(clv);
	} else {
	  d_old_coeff.setValue(newCoeff);
	}
      } else {
	// did not have that variable already
	_terms.put(clv,new ClDouble(multiplier * coeff));
	solver.noteAddedVariable(clv,subject);
      }
    }
    if (fTraceOn) traceprint("Now this is " + this);
  }
  
  // This linear expression currently represents the equation
  // oldSubject=self.  Destructively modify it so that it represents
  // the equation newSubject=self.
  //
  // Precondition: newSubject currently has a nonzero coefficient in
  // this expression.
  //
  // NOTES
  //   Suppose this expression is c + a*newSubject + a1*v1 + ... + an*vn.
  //
  //   Then the current equation is 
  //       oldSubject = c + a*newSubject + a1*v1 + ... + an*vn.
  //   The new equation will be
  //        newSubject = -c/a + oldSubject/a - (a1/a)*v1 - ... - (an/a)*vn.
  //   Note that the term involving newSubject has been dropped.
  public final void changeSubject(ClAbstractVariable old_subject, ClAbstractVariable new_subject)
    {
      ClDouble cld = (ClDouble) _terms.get(old_subject);
      if (cld != null)
	cld.setValue(newSubject(new_subject));
      else
	_terms.put(old_subject,new ClDouble(newSubject(new_subject)));
    }
  
  // This linear expression currently represents the equation self=0.  Destructively modify it so 
  // that subject=self represents an equivalent equation.  
  //
  // Precondition: subject must be one of the variables in this expression.
  // NOTES
  //   Suppose this expression is
  //     c + a*subject + a1*v1 + ... + an*vn
  //   representing 
  //     c + a*subject + a1*v1 + ... + an*vn = 0
  // The modified expression will be
  //    subject = -c/a - (a1/a)*v1 - ... - (an/a)*vn
  //   representing
  //    subject = -c/a - (a1/a)*v1 - ... - (an/a)*vn
  //
  // Note that the term involving subject has been dropped.
  // Returns the reciprocal, so changeSubject can use it, too
  public final double newSubject(ClAbstractVariable subject)
    {
      if (fTraceOn) fnenterprint("newSubject:" + subject);
      ClDouble coeff = (ClDouble) _terms.remove(subject);
      double reciprocal = 1.0 / coeff.doubleValue();
      multiplyMe(-reciprocal);
      return reciprocal;
    }

  // Return the coefficient corresponding to variable var, i.e.,
  // the 'ci' corresponding to the 'vi' that var is:
  //     v1*c1 + v2*c2 + .. + vn*cn + c
  public final double coefficientFor(ClAbstractVariable var)
    { 
      ClDouble coeff = (ClDouble) _terms.get(var);
      if (coeff != null)
	return coeff.doubleValue();
      else
	return 0.0;
    }

  public final double constant()
    { return _constant.doubleValue(); }

  public final void set_constant(double c)
    { 
      _constant.setValue(c);
    }

  public final Hashtable terms()
    { return _terms; }

  public final void incrementConstant(double c)
    { 
      _constant.setValue(_constant.doubleValue() + c);
    }

  public final boolean isConstant()
    { return _terms.size() == 0; }

  public final String toString()
    {
      StringBuffer bstr = new StringBuffer();
      Enumeration e = _terms.keys();

      if (!CL.approx(_constant.doubleValue(),0.0) || _terms.size() == 0) 
	{
	bstr.append(_constant.toString());
	}
      else
	{
	if (_terms.size() == 0)
	  {
	  return bstr.toString();
	  }
	ClAbstractVariable clv = (ClAbstractVariable) e.nextElement();
	ClDouble coeff = (ClDouble) _terms.get(clv);
	bstr.append(coeff.toString() + "*" + clv.toString());
	}
      for (; e.hasMoreElements(); )
	{
	ClAbstractVariable clv = (ClAbstractVariable) e.nextElement();
	ClDouble coeff = (ClDouble) _terms.get(clv);
	bstr.append(" + " + coeff.toString() + "*" + clv.toString());
	}
      return bstr.toString();
    }

  public final static ClLinearExpression Plus(ClLinearExpression e1, ClLinearExpression e2)
    { return e1.plus(e2); }

  public final static ClLinearExpression Minus(ClLinearExpression e1, ClLinearExpression e2)
    { return e1.minus(e2); }

  public final static ClLinearExpression Times(ClLinearExpression e1, ClLinearExpression e2) 
    throws ExCLNonlinearExpression
    { return e1.times(e2); }

  public final static ClLinearExpression Divide(ClLinearExpression e1, ClLinearExpression e2)
    throws ExCLNonlinearExpression
    { return e1.divide(e2); }

  public final static boolean FEquals(ClLinearExpression e1, ClLinearExpression e2)
    { return e1 == e2; }

  private ClDouble _constant;
  private Hashtable _terms; // from ClVariable to ClDouble

}
