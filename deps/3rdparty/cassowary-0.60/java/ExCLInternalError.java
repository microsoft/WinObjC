// $Id: ExCLInternalError.java,v 1.7 1999/04/20 00:26:47 gjb Exp $
//
// Cassowary Incremental Constraint Solver
// Original Smalltalk Implementation by Alan Borning
// This Java Implementation by Greg J. Badros, <gjb@cs.washington.edu>
// http://www.cs.washington.edu/homes/gjb
// (C) 1998, 1999 Greg J. Badros and Alan Borning
// See ../LICENSE for legal details regarding this software
//
// ExCLInternalError
//

package EDU.Washington.grad.gjb.cassowary;

public class ExCLInternalError extends ExCLError
{
  public ExCLInternalError(String s) {
    description_ = s;
  }
  public String description()
    { return "(ExCLInternalError) " + description_; }

  private String description_;
}
