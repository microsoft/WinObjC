// $Id: ClEditInfo.java,v 1.3 1999/04/20 00:26:29 gjb Exp $
//
// Cassowary Incremental Constraint Solver
// Original Smalltalk Implementation by Alan Borning
// This Java Implementation by Greg J. Badros, <gjb@cs.washington.edu>
// http://www.cs.washington.edu/homes/gjb
// (C) 1998, 1999 Greg J. Badros and Alan Borning
// See ../LICENSE for legal details regarding this software
//
// ClEditInfo
// 

package EDU.Washington.grad.gjb.cassowary;

import java.util.*;

// ClEditInfo is a privately-used class
// that just wraps a constraint, its positive and negative
// error variables, and its prior edit constant.
// It is used as values in _editVarMap, and replaces
// the parallel vectors of error variables and previous edit
// constants from the smalltalk version of the code.
class ClEditInfo {
  public ClEditInfo(ClConstraint cn_, 
                    ClSlackVariable eplus_, ClSlackVariable eminus_,
                    double prevEditConstant_, int i_)
  { 
    cn = cn_; clvEditPlus = eplus_; clvEditMinus = eminus_;
    prevEditConstant = prevEditConstant_; i=i_; 
  }

  public int Index()
  { return i; }

  public ClConstraint Constraint()
  { return cn; }

  public ClSlackVariable ClvEditPlus()
  { return clvEditPlus; }

  public ClSlackVariable ClvEditMinus()
  { return clvEditMinus; }

  public double PrevEditConstant()
  { return prevEditConstant; }

  public void SetPrevEditConstant(double prevEditConstant_ )
  { prevEditConstant = prevEditConstant_; }

  private ClConstraint cn;
  private ClSlackVariable clvEditPlus;
  private ClSlackVariable clvEditMinus;
  private double prevEditConstant;
  private int i;
  
}
