/*
 * Constraint class.
 * Base class for all CC-independent constraints.
 * Consists of a list of SelPoints and a list of constraints applicable 
 * to them.
 *
 * Each subclass must do the following:
 * 1) Have a variable declared for each constraint it adds, so that it can 
 *    remove them later.
 * 2) Implement the draw() method to produce a visible representation of
 *    the constraint.
 * 3) Implement the addConstraints() and removeConstraints() methods
 *
 * $Id: Constraint.java,v 1.4 1999/12/16 02:10:00 gjb Exp $
 *
 */

package EDU.Washington.grad.noth.cda;

import java.awt.Graphics;
import java.awt.Point;
import java.util.Vector;
import java.awt.Rectangle;

import EDU.Washington.grad.gjb.cassowary.*;

public abstract class Constraint {
  public   int     x, y;

  // Reference to the solver
  ClSimplexSolver solver;
  
  // List of SelPoints being constrained 
  Vector selPointList;

  // List of CC's being constrained
  Vector ccList;

  // Bounding box of the CC
  public Rectangle bbox;
  // Flag for being selected
  protected boolean isSelected;
  protected boolean isHighlighted;

  // Create a new, empty constraint
  public Constraint(ClSimplexSolver solver) {
    this.solver = solver;
    selPointList = new Vector(10);
    ccList = new Vector(10);

    isSelected = false;
    isHighlighted = false;
    bbox = new Rectangle(0, 0, 0, 0);
  }

  // Add a SelPoint to the list of SelPoints being constrained
  public void addSelPoint(SelPoint sp) {
    // Make sure a given SelPoint can only appear once
    if ( !selPointList.contains(sp) )
      selPointList.addElement(sp);
  }

  // Add a CC to the list of CC's being constrained
  public void addCC(ConstrComponent c) {
    if ( !ccList.contains(c) )
      ccList.addElement(c);
  }

  // Add a vector of SelPoints to list
  public void addSelPoint(Vector v) {
    SelPoint sp;
    int      a;

    for ( a = 0; a < v.size(); a++ ) {
      sp = (SelPoint) v.elementAt(a);
      if ( !(sp instanceof SelPoint) ) {
        System.out.println("C.addSP: Element " + a + " not a SelPoint!");
        return;
      }
      addSelPoint(sp);
    }
  }

  // Add constraints to solver, creating them if necessary.
  public abstract void addConstraints();
  
  // Remove constraints from solver
  public abstract void removeConstraints();
 
  // Draw the representation of the constraint
  public abstract void draw(Graphics g);

  // Method to replace all instances of the given SelPoint with another.
  // It is assumed that any SelPoint-internal constraints have already
  // beeen established.
  // This method should retract/extend constraints as appropriate to
  // each subclass, using the new point.
  public abstract void replaceSelPoint(SelPoint oldsp, SelPoint newsp);

  // Method to notify the constraint that a given CC is going away.
  // A constraint can ignore this or choose to remove constraints,
  // as appropriate.  Default version does nothing.
  public void notifyCCRemoval(ConstrComponent c) {
  }

  // Method to notify the constraint that a given SelPoint is going away.
  // A constraint can ignore this or choose to remove constraints, as 
  // appropriate.  Default version does nothing.
  public void notifySPRemoval(SelPoint sp) {
  }

  // Method to notify the constraint that a bounding box of a CC it is
  // interested in has changed.  Mainly of use to relational constraints.
  // Default behavior is to do nothing.
  public void notifyCCBBoxChange(ConstrComponent c) {
  }

  // Method that determines if the constraint can be discarded.
  // This is needed as a call to replaceSelPoint or notifyCCRemoval
  // could conceiveably render a constraint obj. no longer relevant.
  public abstract boolean canDiscard();

  // Clean up function.  By default, removes all constraints and clears out
  // the list of interested CC's and SP's.
  public void cleanUp() {
    int a;
    ConstrComponent cc;
    SelPoint sp;

    removeConstraints();

    for ( a = 0; a < selPointList.size(); a++ ) {
      sp = (SelPoint) selPointList.elementAt(a);
      sp.removeInterestedConstr(this);
    }
    selPointList.removeAllElements();
 
    for ( a = 0; a < ccList.size(); a++ ) {
      cc = (ConstrComponent) ccList.elementAt(a);
      cc.removeInterestedConstr(this);
    }
    ccList.removeAllElements(); 
  }

  // Method for highlighting as the mouse moves
  // Just highlights the bbox of the constraint
  public void highlight(Point p, boolean isShiftDown) {
    if ( bbox.contains(p) && isShiftDown )
      isHighlighted = true;
    else
      isHighlighted = false;
  }

  public void highlight(Rectangle r) {
    if ( (bbox.x >= r.x) && (bbox.y >= r.y) &&
         ((bbox.x + bbox.width) <= (r.x + r.width)) &&
         ((bbox.y + bbox.height) <= (r.y + r.height)) )
      isHighlighted = true;
    else
      isHighlighted = false;
  }

  public void unselect() {
    isSelected = false;
  }

  public boolean getisSelected() {
    return isSelected;
  }

  public void setisSelected(boolean state) {
    isSelected = state;
  }

}

/*
 * $Log: Constraint.java,v $
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
 * Revision 1.3  1998/06/23 02:08:48  gjb
 * Added import of cassowary package so that the cda doesn't need to be
 * in the same package as the solver.
 *
 * Revision 1.2  1998/05/09 00:30:27  gjb
 * Remove cr-s
 *
 * Revision 1.1  1998/05/09 00:11:01  gjb
 * Added
 *
 * Revision 1.6  1998/04/26 06:17:54  Michael
 * Changed default highlighting
 *
 * Revision 1.5  1998/04/20 09:52:21  Michael
 * Added code for highlighting/selection
 *
 * Revision 1.4  1998/04/19 04:10:23  Michael
 * Added SP removal update method
 *
 * Revision 1.3  1998/04/02 06:59:04  Michael
 * Added cleanup function
 *
 * Revision 1.2  1998/04/01 10:20:04  Michael
 * Added replaceSelPoint, notifyCCRemoval, and canDiscard methods
 * Added fields to allow a Constraint obj to be over CC's as well as SelPoints
 *
 * Revision 1.1  1998/02/17 08:22:37  Michael
 * Initial check-in
 *
 *
 */
