/*
 * Circle constrainable component.  Can constrain the center or a point
 * on the circle.
 *
 * $Id: CircleCC.java,v 1.4 1999/12/16 02:09:59 gjb Exp $
 *
 */

package EDU.Washington.grad.noth.cda;

import java.awt.Graphics;
import java.awt.Point;
import java.awt.Color;

import EDU.Washington.grad.gjb.cassowary.*;

public class CircleCC extends ConstrComponent {
  // Constrainable parts are the edge points
  protected SelPoint upperLeft, lowerRight;

  // Additional fields for drawing
  Color c;

  // Default constructor
  public CircleCC(ClSimplexSolver solver) {
    this(solver, 10, 50, 400, 400);
  }
  
  // Constructor that takes border dims to set up border constraints
  public CircleCC(ClSimplexSolver solver, int sx, int sy, int r, int b) {
    super(solver);
    upperLeft = new SelPoint(solver, sx, sy, r, b);
    lowerRight = new SelPoint(solver, sx + 10, sy + 10, r, b);
    c = Color.black;
    // Add bbox corners
    selPoints.addElement(upperLeft);
    selPoints.addElement(lowerRight);
    // Keep track of who owns the points
    upperLeft.setOwner(this);
    upperLeft.addInterestedCC(this);
    lowerRight.setOwner(this);
    lowerRight.addInterestedCC(this);
    
  }

  // The lowerRight corner SP is the end SP for placement purposes
  public SelPoint getEndSP() {
    return lowerRight;
  }

  // Implementation of draw method
  public void draw(Graphics g) {
    super.draw(g);
    g.setColor(c);
    g.drawOval(bbox.x, bbox.y, bbox.width, bbox.height);
  }

  // Performs necessary updates when the SelPoint at index idx is to be
  // replaced with newsp.  Just check to see which one of the edge points
  // have been replaced, and update it accordingly.
  protected void notifySelPointReplacement(int idx, SelPoint newsp) {
    SelPoint sp = (SelPoint) selPoints.elementAt(idx);

/*
    System.out.println("Replacing idx " + idx + " with " + newsp);
*/
   
    if ( upperLeft == sp ) {
      upperLeft = newsp;
/*
      System.out.println("upperLeft replaced");
*/
    }
    if ( lowerRight == sp ) {
      lowerRight = newsp;
/*
      System.out.println("lowerRight replaced");
*/
    }
  }

  // Return a string version of the CircleCC
  public String toString() {
    StringBuffer sb = new StringBuffer(super.toString());
    sb.append(" => ");
    sb.append("UL: " + upperLeft + ", LR: " + lowerRight);
    return sb.toString();
  }

  // Clean-up function
  public void finalize() {
/*
    System.out.println("CircleCC.finalize called on " + this);
*/
  }

}

/* 
 * $Log: CircleCC.java,v $
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
 * Revision 1.3  1998/06/23 02:08:36  gjb
 * Added import of cassowary package so that the cda doesn't need to be
 * in the same package as the solver.
 *
 * Revision 1.2  1998/05/09 00:30:19  gjb
 * Remove cr-s
 *
 * Revision 1.1  1998/05/09 00:10:55  gjb
 * Added
 *
 * Revision 1.3  1998/04/10 01:59:10  Michael
 * Added getEndSP method
 *
 * Revision 1.2  1998/04/08 05:41:17  Michael
 * Commented out printing msgs
 * Changed circle to be constrained by 2 corners of bounding box
 *
 * Revision 1.1  1998/04/05 03:12:07  Michael
 * Initial check-in
 *
 */
