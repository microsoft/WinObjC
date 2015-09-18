// $Id: ClEditOrStayConstraint.java,v 1.11 1999/04/20 00:26:30 gjb Exp $
//
// Cassowary Incremental Constraint Solver
// Original Smalltalk Implementation by Alan Borning
// This Java Implementation by Greg J. Badros, <gjb@cs.washington.edu>
// http://www.cs.washington.edu/homes/gjb
// (C) 1998, 1999 Greg J. Badros and Alan Borning
// See ../LICENSE for legal details regarding this software
//
// ClEditOrStayConstraint
//

package EDU.Washington.grad.gjb.cassowary;

abstract class ClEditOrStayConstraint extends ClConstraint
{

  public ClEditOrStayConstraint(ClVariable var,
				ClStrength strength,
				double weight)
  {
    super(strength, weight);
    _variable = var;
    _expression = new ClLinearExpression(_variable, -1.0, _variable.value());
  }

  public ClEditOrStayConstraint(ClVariable var,
				ClStrength strength)
  {
    this(var,strength,1.0);
  }

  public ClEditOrStayConstraint(ClVariable var)
  {
    this(var,ClStrength.required,1.0);
    _variable = var;
  }
  
  public ClVariable variable()
    { return  _variable; }

  public ClLinearExpression expression()
    { return _expression; }

  private void setVariable(ClVariable v)
    { _variable = v; }

  protected ClVariable  _variable;
  // cache the expresion
  private ClLinearExpression _expression;

}
