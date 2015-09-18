// $Id: ExCLRequiredFailure.java,v 1.6 1999/04/20 00:26:49 gjb Exp $
//
// Cassowary Incremental Constraint Solver
// Original Smalltalk Implementation by Alan Borning
// This Java Implementation by Greg J. Badros, <gjb@cs.washington.edu>
// http://www.cs.washington.edu/homes/gjb
// (C) 1998, 1999 Greg J. Badros and Alan Borning
// See ../LICENSE for legal details regarding this software
//
// ExCLRequiredFailure
//

package EDU.Washington.grad.gjb.cassowary;

public class ExCLRequiredFailure extends ExCLError
{
  public String description()
    { return "(ExCLRequiredFailure) A required constraint cannot be satisfied"; }
}
