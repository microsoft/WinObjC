// $Id: ClSlackVariable.java,v 1.9 1999/04/20 00:26:38 gjb Exp $
//
// Cassowary Incremental Constraint Solver
// Original Smalltalk Implementation by Alan Borning
// This Java Implementation by Greg J. Badros, <gjb@cs.washington.edu>
// http://www.cs.washington.edu/homes/gjb
// (C) 1998, 1999 Greg J. Badros and Alan Borning
// See ../LICENSE for legal details regarding this software
//
// ClSlackVariable
//

package EDU.Washington.grad.gjb.cassowary;

class ClSlackVariable extends ClAbstractVariable
{
  // friend ClTableau;
  // friend ClSimplexSolver;

  public ClSlackVariable(String name)
    {  super(name); }

  public ClSlackVariable()
    {  }
  
  public ClSlackVariable(long number, String prefix)
    { super(number,prefix); }
  
  public String toString()
    { return "[" + name() + ":slack]"; }

  public boolean isExternal()
    { return false; }

  public boolean isPivotable()
    { return true; }

  public boolean isRestricted()
    { return true; }
  
}
