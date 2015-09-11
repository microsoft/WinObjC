/*
 * 2-d Line Constrained Component, whose endpoints are constrainable.
 *
 * $Id: LineCC.java,v 1.4 1999/12/16 02:09:59 gjb Exp $
 *
 */

package EDU.Washington.grad.noth.cda;

import java.awt.Graphics;
import java.awt.Point;
import java.awt.Color;

import EDU.Washington.grad.gjb.cassowary.*;

public class LineCC extends ConstrComponent {
  // Constrainable parts are the endpoints, which are also selectable
  public SelPoint p1, p2;

  // Additional fields for drawing
  Color c;

  // Default constructor
  public LineCC(ClSimplexSolver solver) {
    this(solver, 10, 50, 400, 400);
  }
  
  // Constructor that takes border dims to set up border constraints
  public LineCC(ClSimplexSolver solver, int sx, int sy, int r, int b) {
    super(solver);
    p1 = new SelPoint(solver, sx, sy, r, b);
    p2 = new SelPoint(solver, sx + 10, sy + 20, r, b);
    c = Color.black;
    // Add p1 and p2 to selectable points vector
    selPoints.addElement(p1);
    selPoints.addElement(p2);
    // Keep track of who owns the points
    p1.setOwner(this);
    p2.setOwner(this);
    p1.addInterestedCC(this);
    p2.addInterestedCC(this);
  }

  // p2 is the end SelPoint, for placement purposes
  public SelPoint getEndSP() {
    return p2;
  }

  // Implementation of draw method
  public void draw(Graphics g) {
    super.draw(g);
    g.setColor(c);
    g.drawLine(p1.x, p1.y, p2.x, p2.y);
  }

  // Performs necessary updates when the SelPoint at index idx is to be
  // replaced with newsp.  Just check to see which one of the endpoints
  // got replaced, and update p1 or p2 accordingly.
  protected void notifySelPointReplacement(int idx, SelPoint newsp) {
    SelPoint sp = (SelPoint) selPoints.elementAt(idx);

/*
    System.out.println("Replacing idx " + idx + " with " + newsp);
*/
   
    if ( p1 == sp ) {
      p1 = newsp;
/*
      System.out.println("p1 replaced");
*/
    }
 
    if ( p2 == sp ) {
      p2 = newsp;
/*
      System.out.println("p2 replaced");
*/
    }
  }

  // Return a string version of the LineCC
  public String toString() {
    StringBuffer sb = new StringBuffer(super.toString());
    sb.append(" => ");
    sb.append("[" + p1 + ", " + p2 + "]");
    return sb.toString();
  }

  // Clean-up function
  public void finalize() {
/*
    System.out.println("LineCC.finalize called on " + this);
*/
  }

}
    
  
/*
 * $Log: LineCC.java,v $
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
 * Revision 1.3  1998/06/23 02:08:38  gjb
 * Added import of cassowary package so that the cda doesn't need to be
 * in the same package as the solver.
 *
 * Revision 1.2  1998/05/09 00:30:20  gjb
 * Remove cr-s
 *
 * Revision 1.1  1998/05/09 00:10:56  gjb
 * Added
 *
 * Revision 1.13  1998/04/10 01:59:11  Michael
 * Added getEndSP method
 *
 * Revision 1.12  1998/04/08 05:40:41  Michael
 * Commented out printing msgs
 *
 * Revision 1.11  1998/04/05 03:12:01  Michael
 * Added log tag
 *
 */
