// $Id: ClStrength.java,v 1.11 1999/04/20 00:26:39 gjb Exp $
//
// Cassowary Incremental Constraint Solver
// Original Smalltalk Implementation by Alan Borning
// This Java Implementation by Greg J. Badros, <gjb@cs.washington.edu>
// http://www.cs.washington.edu/homes/gjb
// (C) 1998, 1999 Greg J. Badros and Alan Borning
// See ../LICENSE for legal details regarding this software
//
// ClStrength

package EDU.Washington.grad.gjb.cassowary;

public class ClStrength
{
  public ClStrength(String name, ClSymbolicWeight symbolicWeight)
    {  _name = name;	_symbolicWeight = symbolicWeight; }

  public ClStrength(String name, double w1, double w2, double w3)
    {
      _name = name;
      _symbolicWeight = new ClSymbolicWeight(w1,w2,w3);
    }

  public boolean isRequired()
    { return (this == required); }

  public String toString()
    { return name () + (!isRequired()? (":" + symbolicWeight()) : ""); }

  public ClSymbolicWeight symbolicWeight()
    { return _symbolicWeight; }

  public String name()
    { return _name; }

  public void set_name(String name)
    { _name = name; }

  public void set_symbolicWeight(ClSymbolicWeight symbolicWeight)
    { _symbolicWeight = symbolicWeight; }

  public static final ClStrength required = new ClStrength("<Required>", 1000, 1000, 1000);

  public static final ClStrength strong = new ClStrength("strong", 1.0, 0.0, 0.0);

  public static final ClStrength medium = new ClStrength("medium", 0.0, 1.0, 0.0);

  public static final ClStrength weak = new ClStrength("weak", 0.0, 0.0, 1.0);

  private String _name;

  private ClSymbolicWeight _symbolicWeight;
  
}
