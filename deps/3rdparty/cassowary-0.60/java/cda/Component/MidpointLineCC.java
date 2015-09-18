/*
 * 2-d Line with midpoint Constrained Component.
 * Endpoints and midpoint are constrainable.
 *
 * $Id: MidpointLineCC.java,v 1.4 1999/12/16 02:09:59 gjb Exp $
 *
 */

package EDU.Washington.grad.noth.cda;

import java.awt.Graphics;
import java.awt.Point;
import java.awt.Color;

import EDU.Washington.grad.gjb.cassowary.*;

public class MidpointLineCC extends ConstrComponent {
  // Constrainable parts are the endpoints and midpoint
  public SelPoint p1, p2, mp;

  // Constraints on the midpoint
  ClLinearEquation mpXConstr, mpYConstr;

  // Additional fields for drawing
  Color c;

  // Constructor
  public MidpointLineCC(ClSimplexSolver solver) {
    this(solver, 10, 50, 400, 400);
  }

  // Default constructor, taking initial (x, y) value and window border
  public MidpointLineCC(ClSimplexSolver solver, int sx, int sy, int r, int b) {
    super(solver);
    p1 = new SelPoint(solver, sx, sy, r, b);
    p2 = new SelPoint(solver, sx + 20, sy + 30, r, b);
    mp = new SelPoint(solver, sx + 10, sy + 15, r, b);
    c = Color.black;

    // Add endpoints and midpoint to selectable point vector
    selPoints.addElement(p1);
    selPoints.addElement(p2);
    selPoints.addElement(mp);

    // Set owner of points
    p1.setOwner(this);
    p2.setOwner(this);
    mp.setOwner(this);
    p1.addInterestedCC(this);
    p2.addInterestedCC(this);
    mp.addInterestedCC(this);

    // Establish constraints on midpoint
    mpXConstr = null;
    mpYConstr = null;
    establishMPConstraints();
  }

  // p2 is the end SP for placement purposes
  public SelPoint getEndSP() {
    return p2;
  }
  
  // Initialize and establish constraints on the midpoint of the line.
  // Old constraints will *not* be removed by this method!
  private void establishMPConstraints() {
    ClLinearExpression cle;
    try {
      cle = new ClLinearExpression(p1.X());
      cle = (cle.plus(p2.X())).divide(2.0);
      mpXConstr = new ClLinearEquation(mp.X(), cle);
      solver.addConstraint(mpXConstr); 
      cle = new ClLinearExpression(p1.Y());
      cle = (cle.plus(p2.Y())).divide(2.0);
      mpYConstr = new ClLinearEquation(mp.Y(), cle);
      solver.addConstraint(mpYConstr); 
    } catch (ExCLNonlinearExpression e) {
      System.out.println("MidpointCC.constructor: ExCLNonlinearExpression!");
    } catch (ExCLRequiredFailure e) {
      System.out.println("MidpointCC.constructor: ExCLRequiredFailure!");
    } catch (ExCLInternalError e) {
      System.out.println("MidpointCC.constructor: ExCLInternalError!");
    }
  }

  // Remove the midpoint constraints, if any
  private void removeMPConstraints() {
    try {
      if ( mpXConstr != null )
        solver.removeConstraint(mpXConstr);
      if ( mpYConstr != null )
        solver.removeConstraint(mpYConstr);
    } catch (ExCLInternalError e) {
      System.out.println("MLCC.remMPC: CLInternalError!");
    } catch (ExCLConstraintNotFound e) {
      System.out.println("MLCC.remMPC: CLConstraintNotFound!");
    }
    mpXConstr = null;
    mpYConstr = null;
  }

  // Implementation of draw method
  public void draw(Graphics g) {
    super.draw(g);
    g.setColor(c);
    g.drawLine(p1.x, p1.y, p2.x, p2.y);
  }

  // Performs necessary updates when the SelPoint at index idx is to be 
  // replaced with newsp.
  protected void notifySelPointReplacement(int idx, SelPoint newsp) {
    SelPoint sp = (SelPoint) selPoints.elementAt(idx);

/*
    System.out.println("ML: Replacing idx " + idx + " with " + newsp);
*/

    if ( p1 == sp ) {
      p1 = newsp;
/*
      System.out.println("ML: p1 replaced");
*/
    }

    if ( p2 == sp ) {
      p2 = newsp;
/*
      System.out.println("ML: p2 replaced");
*/
    }
    
    if ( mp == sp ) {
      mp = newsp;
/*
      System.out.println("ML: mp replaced");
*/
    }

    // Need to update constraints at this point
    removeMPConstraints();
    establishMPConstraints();
  }

  // Clean-up function
  public void cleanUp() {
/*
    System.out.println("MidpointLineCC.cleanUp invoked on " + this);
*/
    removeMPConstraints();
  }

  public void finalize() {
/*
    System.out.println("MidpointLineCC.finalize invoked on " + this);
*/
    cleanUp();
  }

  // Return a string version of the component
  public String toString() {
    StringBuffer sb = new StringBuffer(super.toString());
    sb.append(" => [" + p1 + ", " + mp + ", " + p2 + "]");
    return sb.toString();
  }
}
    
/*
 * $Log: MidpointLineCC.java,v $
 * Revision 1.4  1999/12/16 02:09:59  gjb
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
 * Revision 1.3  1998/06/23 02:08:39  gjb
 * Added import of cassowary package so that the cda doesn't need to be
 * in the same package as the solver.
 *
 * Revision 1.2  1998/05/09 00:30:21  gjb
 * Remove cr-s
 *
 * Revision 1.1  1998/05/09 00:10:56  gjb
 * Added
 *
 * Revision 1.9  1998/04/10 01:59:11  Michael
 * Added getEndSP method
 *
 * Revision 1.8  1998/04/08 05:40:41  Michael
 * Commented out printing msgs
 *
 */
  

