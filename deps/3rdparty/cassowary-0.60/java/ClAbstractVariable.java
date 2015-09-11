// $Id: ClAbstractVariable.java,v 1.13 1999/04/20 00:26:25 gjb Exp $
//
// Cassowary Incremental Constraint Solver
// Original Smalltalk Implementation by Alan Borning
// This Java Implementation by Greg J. Badros, <gjb@cs.washington.edu>
// http://www.cs.washington.edu/homes/gjb
// (C) 1998, 1999 Greg J. Badros and Alan Borning
// See ../LICENSE for legal details regarding this software
//
// ClAbstractVariable

package EDU.Washington.grad.gjb.cassowary;

import java.lang.*;

public abstract class ClAbstractVariable
{
  public ClAbstractVariable(String name)
    {
      //hash_code = iVariableNumber;
      _name = name;
      iVariableNumber++;
    }

  public ClAbstractVariable()
    {
      //hash_code = iVariableNumber;
      _name = "v" + iVariableNumber;
      iVariableNumber++;
    }

  public ClAbstractVariable(long varnumber, String prefix)
    {
      //hash_code = iVariableNumber;
      _name = prefix + varnumber;
      iVariableNumber++;
    }

  public String name()
    { return _name; }
  
  public void setName(String name)
    { _name = name; }
  
  public boolean isDummy()
    { return false; }
  
  public abstract boolean isExternal();

  public abstract boolean isPivotable();

  public abstract boolean isRestricted();

  public abstract String toString();

  public static int numCreated() 
    { return iVariableNumber; }

  // for debugging
  //  public final int hashCode() { return hash_code; }

  private String _name;

  // for debugging
  // private int hash_code;

  private static int iVariableNumber;

}
