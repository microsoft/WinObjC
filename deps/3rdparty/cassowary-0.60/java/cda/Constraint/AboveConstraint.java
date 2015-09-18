/*
 * Above relational constraint.  The target CC (the second) is to be 
 * above the first (source) CC at all times, with respect to their bounding
 * boxes.
 *
 * $Id: AboveConstraint.java,v 1.4 1999/12/16 02:10:00 gjb Exp $
 *
 */

package EDU.Washington.grad.noth.cda;

import java.awt.Graphics;
import java.awt.Color;
import java.util.Vector;
//import CDA_G;

import EDU.Washington.grad.gjb.cassowary.*;

public class AboveConstraint extends AdjacencyConstraint {

  public AboveConstraint(ClSimplexSolver solver, ConstrComponent srcCC,
    ConstrComponent targetCC) {

    super(solver, srcCC, targetCC);
  }

  // Add constraints to solver.  This entails establishing a constraint on
  // every SelPoint in the target to be above the highest SelPoint in the src.
  public void addConstraints() {
    int a;
    SelPoint sp;
    ConstrComponent srcCC, targetCC;
    double targval;
    ClLinearInequality cli;

    if ( ccList.size() != 2 ) {
      System.out.println("AboveConstr.addConstr: " + ccList.size() 
        + " CC's, not required 2!");
      return;
    }
    srcCC = (ConstrComponent) ccList.elementAt(0);
    targetCC = (ConstrComponent) ccList.elementAt(1);

    if ( relConstrs.size() != targetCC.selPoints.size() ) {
      // Need to create new constraints
      if ( relConstrs.size() != 0 ) {
        System.out.println("AboveConstr.addConstr: relConstrs = " 
          + relConstrs + "; should be empty!");
        relConstrs.removeAllElements();
        relConstrs.setSize(targetCC.selPoints.size());
      }
      relConstrs.setSize(targetCC.selPoints.size());
      for ( a = 0; a < targetCC.selPoints.size(); a++ ) {
        sp = (SelPoint) targetCC.selPoints.elementAt(a);
        try {
          cli = new ClLinearInequality(sp.Y(), CL.LEQ, srcCC.topSP.Y());
        } catch (ExCLInternalError e) {
          System.out.println("AboveConstr.constructor: ExCLInternalError on #" 
            + a);
          return;
        }
        relConstrs.setElementAt(cli, a);
      }
    } 

    for ( a = 0; a < relConstrs.size(); a++ ) {
      cli = (ClLinearInequality) relConstrs.elementAt(a);
      try { 
        if ( cli != null ) 
          solver.addConstraint(cli);
      } catch (ExCLInternalError e) {
        System.out.println("AboveConstr.addConstr: ExCLInternalError adding #" 
          + a + " = " + cli);
      } catch (ExCLRequiredFailure e) {
        System.out.println("AboveConstr.addConstr: ExCLRequiredFailure "
          + "adding #" + a + " = " + cli);
      }
    }
    
  }
  
  // Method to convert constraint to a string
  public String toString() {
    StringBuffer sb = new StringBuffer("AboveConstraint: ");
    ConstrComponent srcCC, targetCC;
    
    if ( ccList.size() != 2 ) {
      sb.append(" ILL-FORMED CONSTRAINT WITH " + ccList.size());
      sb.append(" INSTEAD OF 2 CC's");
    } else {
      srcCC = (ConstrComponent) ccList.elementAt(0);
      targetCC = (ConstrComponent) ccList.elementAt(1);
      sb.append("srcCC = " + srcCC);
      sb.append(", targetCC = " + targetCC);
    }
    return sb.toString();
  }

}

/*
 * $Log: AboveConstraint.java,v $
 * Revision 1.4  1999/12/16 02:10:00  gjb
 * * java/cda/Makefile.am:  Put Constraint/*, Main/* files into the
 * distribution and build with them.
 *
 * * java/demos/*.java: Move everything into the
 * EDU.Washington.grad.gjb.cassowary_demos package.
 *
 * * java/cda/classes/run.html, java/demos/quaddemo.htm: Fix nl
 * convention, name class explicitly w/ package in front, w/o
 * trailing .class.
 *
 * * java/cda/**: Move everything into the
 * EDU.Washington.grad.noth.cda package.
 *
 * Revision 1.3  1998/06/23 02:08:43  gjb
 * Added import of cassowary package so that the cda doesn't need to be
 * in the same package as the solver.
 *
 * Revision 1.2  1998/05/09 00:30:24  gjb
 * Remove cr-s
 *
 * Revision 1.1  1998/05/09 00:10:59  gjb
 * Added
 *
 * Revision 1.2  1998/04/20 09:51:58  Michael
 * Moved draw method into base class
 *
 * Revision 1.1  1998/04/02 06:58:12  Michael
 * Initial check-in
 *
 */
