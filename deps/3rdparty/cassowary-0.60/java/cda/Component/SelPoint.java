/*
 * Selectable Point class
 * Consists of a Point and a flag indicating if it is currently selected.
 *
 * SelPoints also have a list of CC's and constraint objs that care about
 * them in some way.  For CC's, the interest will usually be owning/sharing
 * the SelPoint.  For constraint objs, the interest will usually be a
 * constraint on the SelPoint.
 *
 * There is also an owner field that indicates which CC, if any, actually
 * owns the SelPoint (IE is responsible for the actual obj, not just refs)
 *
 * $Id: SelPoint.java,v 1.4 1999/12/16 02:09:59 gjb Exp $
 *
 */

package EDU.Washington.grad.noth.cda;

import java.awt.Graphics;
import java.awt.Point;
import java.awt.Rectangle;
import java.awt.Color;
import java.util.Vector;

import EDU.Washington.grad.gjb.cassowary.*;

public class SelPoint implements Cloneable {
  public   int     x, y;
  public   boolean isHighlighted;

  boolean  isSelected;

  public   int id; // Unique ID of each SelPoint
  private static int nextID = 0;

  // Which CC(s) have an interest in this SelPoint?
  protected Vector interCC;
  // Which constraint objs. have an interest in this SelPoint?
  protected Vector interConstr;

  // Which CC owns this SelPoint (IE is in charge of deleting it)
  protected ConstrComponent owner;

  // Reference to the solver
  protected ClSimplexSolver solver;
  // Edit constraints held by this SelPoint
  protected ClEditConstraint  editX, editY;
  // Constraint variables for X, Y position
  protected ClVariable        clX, clY;
  // Stay constraints associated with point
  protected ClStayConstraint stayX, stayY;
  // Constraints associated with left, top window edges
  protected ClLinearInequality leftBorderConstraint, topBorderConstraint;
  // Constraints associated with right, bottom window edges
  protected ClLinearInequality rightBorderConstraint, bottomBorderConstraint;

  // Convert an (x, y) pair plus flags into a SelPoint
  public SelPoint (ClSimplexSolver solver, int x, int y,
    boolean isSelected, boolean isHighlighted, int r, int b) {
    this.solver = solver;
    this.x = x;
    this.y = y;
    this.isSelected = isSelected;
    this.isHighlighted = isHighlighted;
    editX = null;
    editY = null;
    clX = new ClVariable(this.x);
    clY = new ClVariable(this.y);
    rightBorderConstraint = null;
    bottomBorderConstraint = null;
/*
     System.out.println("SP.SP: clX = " + clX + ", clY = " + clY);
*/

    id = nextID++;

    // Initialize ownership, interested lists
    interCC = new Vector(4);
    interConstr = new Vector(4);
    owner = null;

    // Set stay constraints on point
    try {
      stayX = new ClStayConstraint(clX, ClStrength.weak, 1.0);
      stayY = new ClStayConstraint(clY, ClStrength.weak, 1.0);
      solver.addConstraint(stayX);
      solver.addConstraint(stayY);
      // Set within-window constraints on point
      leftBorderConstraint = new ClLinearInequality(clX, CL.GEQ, 3.0);
      topBorderConstraint = new ClLinearInequality(clY, CL.GEQ, 3.0);
      solver.addConstraint(leftBorderConstraint);
      solver.addConstraint(topBorderConstraint);
      setBorderConstraints(r, b);
    } catch (ExCLInternalError e) {
      System.out.println("SelPoint constructor: ExCLInternalError!");
    } catch (ExCLRequiredFailure e) {
      System.out.println("SelPoint constructor: ExCLInternalError!");
    }
  }

  // Convert a Point into a SelPoint
  public SelPoint(ClSimplexSolver solver, Point p) {
    this(solver, p.x, p.y, false, false, 400, 400);
  }

  // Convert an (x, y) pair into a SelPoint
  public SelPoint(ClSimplexSolver solver, int x, int y) {
    this(solver, x, y, false, false, 400, 400);
  }

  // Convert an (x, y) pair into a SelPoint, with window border
  public SelPoint(ClSimplexSolver solver, int x, int y, int r, int b) {
    this(solver, x, y, false, false, r, b);
  }

  // Access functions for ClVariable parts
  public ClVariable X() {
    return clX;
  }

  public ClVariable Y() {
    return clY;
  }
  
  // Change border constraints to keep SelPoint inside window
  public void setBorderConstraints(int r, int b) {
    // Sanity check first
/*
    System.out.println("SP.setBordConstr: Passed (" + r + ", " + b + ")" + 
      " this = " + this);
*/
    if ( (r < 10.0) || (b < 10.0) ) return;
    // Remove old border constraints if applicable
    try {
      if ( rightBorderConstraint != null ) 
        solver.removeConstraint(rightBorderConstraint);
      if ( bottomBorderConstraint != null ) 
        solver.removeConstraint(bottomBorderConstraint);
    } catch (ExCLInternalError e) {
      System.out.println("SelPoint.setBC: CLInternalError!");
    } catch (ExCLConstraintNotFound e) {
      System.out.println("SelPoint.setBC: CLConstraintNotFound!");
    }
    try {
      rightBorderConstraint = new ClLinearInequality(clX, CL.LEQ, (double) r); 
      bottomBorderConstraint = new ClLinearInequality(clY, CL.LEQ, (double) b); 
      solver.addConstraint(rightBorderConstraint);
      solver.addConstraint(bottomBorderConstraint);
    } catch (ExCLInternalError e) {
      System.out.println("SelPoint.setBC: CLInternalError!");
    } catch (ExCLRequiredFailure e) {
      System.out.println("SelPoint.setBC: CLRequiredFailure!");
    }
  }

  // Used for selecting a point.  If the receiver is "close enough" to the
  // parameter, it is considered selectable and returns true.
  public boolean inside(Point sp) {
    if ( this.inside(new Rectangle(sp.x - CDA_G.SELBOXSIZE / 2, 
                                   sp.y - CDA_G.SELBOXSIZE / 2,
                                   CDA_G.SELBOXSIZE, CDA_G.SELBOXSIZE)) )
      return true;
    else
      return false;
  }

  public boolean inside(Rectangle b) {
    if ( (x >= b.x) && (x <= (b.x + b.width)) &&
         (y >= b.y) && (y <= (b.y + b.height)) )
      return true;
    else
      return false;
  }

  // Draw function.  Normally draws nothing, or a box if pt is 
  // selected or highlighted
  public void draw(Graphics g) {
    updateValue();
    if ( isHighlighted && !isSelected ) {
      g.setColor(CDA_G.DARK_GREEN);
      g.drawRect(x - CDA_G.DRAWBOXSIZE / 2, y - CDA_G.DRAWBOXSIZE / 2, 
                 CDA_G.DRAWBOXSIZE, CDA_G.DRAWBOXSIZE);
    } else {
      if ( isSelected ) {
        g.setColor(CDA_G.DARK_GREEN);
        g.fillRect(x - CDA_G.SELBOXSIZE / 2, y - CDA_G.SELBOXSIZE / 2, 
                   CDA_G.SELBOXSIZE + 1, CDA_G.SELBOXSIZE + 1);
      } else {
        g.setColor(Color.blue);
        g.drawRect(x - CDA_G.DRAWBOXSIZE / 2, y - CDA_G.DRAWBOXSIZE / 2, 
                   CDA_G.DRAWBOXSIZE, CDA_G.DRAWBOXSIZE);
      }
    }
  }

  // Additional draw method, to supply a different color for a non-selected pt
  public void draw(Graphics g, Color c) {
    updateValue();
    if ( isSelected || isHighlighted ) {
      g.setColor(CDA_G.DARK_GREEN);
      g.fillRect(x - CDA_G.SELBOXSIZE / 2, y - CDA_G.SELBOXSIZE / 2, 
                 CDA_G.SELBOXSIZE + 1, CDA_G.SELBOXSIZE + 1);
    } else {
      g.setColor(c);
      g.drawRect(x - CDA_G.DRAWBOXSIZE / 2, y - CDA_G.DRAWBOXSIZE / 2, 
                 CDA_G.DRAWBOXSIZE, CDA_G.DRAWBOXSIZE);
    }
  }

  // Set the point as being selected
  // Sets the isSelected flag
  public void setSelected() {
    isSelected = true;
  }

  public void clearSelected() {
    isSelected = false;
  }

  // Set/remove the edit constraints associated with the SelPoint
  public void setEditConstraints() {
    editX = new ClEditConstraint(clX, ClStrength.strong);
    editY = new ClEditConstraint(clY, ClStrength.strong);
    try {
      solver.addConstraint(editX);
      solver.addConstraint(editY);
    } catch (ExCLInternalError e) {
      System.out.println("SelPoint.setEC: CLInternalError!");
    } catch (ExCLRequiredFailure e) {
      System.out.println("SelPoint.setEC: CLRequiredFailure!");
    }
  }

  public void removeEditConstraints() {
    try {
      if ( editX != null )
        solver.removeConstraint(editX);
      if ( editY != null ) 
        solver.removeConstraint(editY);
    } catch (ExCLInternalError e) {
      System.out.println("SelPoint.removeEC: CLInternalError!");
    } catch (ExCLConstraintNotFound e) {
      System.out.println("SelPoint.removeEC: CLConstraintNotFound!");
    }
    editX = null;
    editY = null;
  }

  public boolean getSelected() {
    return isSelected;
  }

  // Helper function that retrieves the updated value from the constraint
  // variables and sets the location
  public void updateValue() {
    x = (int) clX.value();
    y = (int) clY.value();
  }

  // Remove all constraints associated with the point that it manages itself
  public void removeAllConstraints() {
    // Get rid of edit constraints first, if any
    removeEditConstraints();
    // Remove other constraints
    try {
      if ( stayX != null )
        solver.removeConstraint(stayX);
      if ( stayY != null ) 
        solver.removeConstraint(stayY);
      if ( leftBorderConstraint != null ) 
        solver.removeConstraint(leftBorderConstraint);
      if ( topBorderConstraint != null ) 
        solver.removeConstraint(topBorderConstraint);
      if ( rightBorderConstraint != null ) 
        solver.removeConstraint(rightBorderConstraint);
      if ( bottomBorderConstraint != null ) 
        solver.removeConstraint(bottomBorderConstraint);
    } catch (ExCLInternalError e) {
      System.out.println("SelPoint.removeAllC: CLInternalError!");
    } catch (ExCLConstraintNotFound e) {
      System.out.println("SelPoint.removeAllC: CLConstraintNotFound!");
    }
    stayX = null;
    stayY = null;
    leftBorderConstraint = null;
    topBorderConstraint = null;
    rightBorderConstraint = null;
    bottomBorderConstraint = null;
  }

  // Implementation of clone() procedure to make deep copy of point
  protected Object clone() {
    SelPoint s = new SelPoint(this.solver, this.x, this.y, this.isSelected,
                              this.isHighlighted, 400, 400);
    s.owner = this.owner;
    s.interCC = (Vector) this.interCC.clone();
    s.interConstr = (Vector) this.interConstr.clone();

    s.interConstr.removeAllElements();
/*
    System.out.println("***SP.Clone returning " + s.fullInfo());
*/
    return (Object) s;
  }

  // Public function to allow a copy of a SelPoint to be made
  public SelPoint copy() {
    return (SelPoint) this.clone();
  }

  // Return a string containing full information about a SelPoint.
  public String fullInfo() {
    StringBuffer sb = new StringBuffer(this.toString());
    sb.append(" CC { ");

    int a;
    ConstrComponent cc;
    Constraint c;
    for ( a = 0; a < interCC.size(); a++ ) {
      cc = (ConstrComponent) interCC.elementAt(a);
      if ( cc == owner ) 
        sb.append("[" + cc + "]");
      else
        sb.append(cc);
      if ( a != (interCC.size() - 1) )
        sb.append(", "); 
    }
    sb.append("}, Con { ");
    for ( a = 0; a < interConstr.size(); a++ ) {
      c = (Constraint) interConstr.elementAt(a);
      sb.append(c);
      if ( a != (interConstr.size() - 1) )
        sb.append(", "); 
    }
    sb.append("}");
    return sb.toString();
  }

  // Convert a SelPoint to a string.  Contains only basic info.
  public String toString() {
    StringBuffer sb = new StringBuffer("SP " + id);
    sb.append("(" + this.x + ", " + this.y + ")");
    return sb.toString();
  }

  // Clean-up function.  Remove all constraints associated with this point.
  public void cleanUp() {
/*
    System.out.println("SP.cleanUp called on " + this);
    System.out.println("SP.cleanUp: interCC = " + interCC);
    System.out.println("SP.cleanUp: interConstr = " + interConstr);
*/
    int a;
    Constraint c;
    for ( a = 0; a < interConstr.size(); a++ ) {
      c = (Constraint) interConstr.elementAt(a);
      c.notifySPRemoval(this);
    }
    removeAllConstraints();
  }

  public void finalize() {
/*
    System.out.println("SP.finalize called on " + this);
*/
    cleanUp();
  }

  // Accessor functions for owner
  public ConstrComponent getOwner() {
    return owner;
  }

  public void setOwner(ConstrComponent c) {
    owner = c;
  }

  // Accessor functions for interested CC's
  public Vector getInterestedCC() {
    return (Vector) interCC.clone();
  }

  public void addInterestedCC(ConstrComponent c) {
    if ( !interCC.contains(c) )
      interCC.addElement(c);
  }

  public void removeInterestedCC(ConstrComponent c) {
    if ( interCC.contains(c) )
      interCC.removeElement(c);
  }

  public Vector getInterestedConstr() {
    return (Vector) interConstr.clone();
  }

  public void addInterestedConstr(Constraint c) {
    if ( !interConstr.contains(c) )
      interConstr.addElement(c);
  }

  public void removeInterestedConstr(Constraint c) {
    if ( interConstr.contains(c) )
      interConstr.removeElement(c);
  }
  

}

/*
 * $Log: SelPoint.java,v $
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
 * Revision 1.3  1998/06/23 02:08:41  gjb
 * Added import of cassowary package so that the cda doesn't need to be
 * in the same package as the solver.
 *
 * Revision 1.2  1998/05/09 00:30:22  gjb
 * Remove cr-s
 *
 * Revision 1.1  1998/05/09 00:10:57  gjb
 * Added
 *
 * Revision 1.19  1998/04/23 09:00:32  Michael
 * Removed printing msg and changed clone behavior
 *
 * Revision 1.18  1998/04/20 09:53:07  Michael
 * Removed debugging printing
 *
 * Revision 1.17  1998/04/19 04:09:28  Michael
 * Added code for SP removal notification
 *
 * Revision 1.16  1998/04/15 00:08:37  Michael
 * Changed drawing of highlighted points to be hollow green box
 *
 * Revision 1.15  1998/04/08 05:40:42  Michael
 * Commented out printing msgs
 *
 * Revision 1.14  1998/04/01 10:14:33  Michael
 * Added data/functions for interested CC/Constraint obj lists
 * Added unique ID field
 * Changed many data members to protected instead of public access
 *
 * Revision 1.13  1998/03/25 02:46:20  Michael
 * Updated to use CDA_G globals
 *
 * Revision 1.12  1998/03/19 09:17:33  Michael
 * Added additional debugging printouts
 *
 * Revision 1.11  1998/03/19 04:36:17  Michael
 * Added finalize method
 *
 * Revision 1.10  1998/03/02 06:43:27  Michael
 * Added alternate draw method to specify new color
 *
 * Revision 1.9  1998/02/25 10:38:17  Michael
 * Added clone() and copy() methods.
 * Added vars to explicitly store all constraints.
 * Added function to remove all constraints associated with a SelPoint
 *
 * Revision 1.8  1998/02/22 04:59:48  Michael
 * Fixed off-by-one error and made point boxes larger
 *
 * Revision 1.7  1998/02/17 08:28:24  Michael
 * Changed visual appearance of points
 *
 * Revision 1.6  1998/02/16 10:36:00  Michael
 * Added hooks to assist with window resizes
 *
 * Revision 1.5  1998/02/15 11:33:06  Michael
 * Added helper functions for edit constraints
 *
 * Revision 1.4  1998/02/15 07:13:38  Michael
 * Added Cassowary solver hooks
 *
 * Revision 1.3  1998/02/09 02:26:23  Michael
 * Fixed bug in drawing of selection indication rectangle
 *
 * Revision 1.2  1998/02/06 08:36:28  Michael
 * Fixed compile errors
 *
 *
 */
