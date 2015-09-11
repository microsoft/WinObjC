/*
 * The basic Constrained Component class.  
 * Every Constrained Component consists of several parts:
 * 1) A private internal representation of points/scalars, as appropriate for
 *  the component.
 * 2) A collection of export variables.  These are all public variables
 *  and can be constrained.
 * 3) A collection of constraints on (2) 
 * 4) A customized draw() method that makes use of values from parts
 *  (1) and/or (2)
 * 5) A customized moveBy() method that requests the object's center move by
 *  the specified amount
 * 6) A vector of points that are currently selected, which will be affected
 *  by moveBy messages
 * 7) A vector of constraint objs that care about this CC's state.  Typically,
 *  this will entail interest in the bounding box of this CC.
 *
 * $Id: ConstrComponent.java,v 1.4 1999/12/16 02:09:59 gjb Exp $
 *
 */

package EDU.Washington.grad.noth.cda;

import java.awt.Graphics;
import java.awt.Point;
import java.awt.Rectangle;
import java.awt.Color;
import java.util.Vector;

import EDU.Washington.grad.gjb.cassowary.*;

public abstract class ConstrComponent {
  // Reference to the solver
  public ClSimplexSolver solver;

  // Set of selectable points
  public Vector selPoints;

  // Flags indicating if the CC is selected or highlighted
  protected boolean isSelected, isHighlighted;
  // Bounding box for the CC
  public Rectangle bbox;
  // The SelPoint that is on each of the 4 borders of the bbox
  public SelPoint topSP, bottomSP, leftSP, rightSP;

  // List of constraint objs. that care about the state of this one
  protected Vector interConstr;

  // Default constructor
  public ConstrComponent(ClSimplexSolver solver) {
    this.solver = solver;
    selPoints = new Vector(5);
    bbox = new Rectangle();
    isHighlighted = false;
    isSelected = false;
    interConstr = new Vector(4);
 
    topSP = null;
    bottomSP = null;
    leftSP = null;
    rightSP = null;
  }

  // Draw method
  public void draw(Graphics g) { 
    for ( int a = 0; a < selPoints.size(); a++ ) {
      ((SelPoint) selPoints.elementAt(a)).draw(g);
    }

    // If CC is highlighted or selected, draw bounding box
    if ( isSelected ) {
      g.setColor(CDA_G.DARK_GREEN);
      g.drawRect(bbox.x, bbox.y, bbox.width, bbox.height);
    } else if ( isHighlighted ) {
      g.setColor(CDA_G.DARK_BLUE);
      g.drawRect(bbox.x, bbox.y, bbox.width, bbox.height);
      g.drawRect(bbox.x+1, bbox.y+1, bbox.width-2, bbox.height-2);
    }
  }

  // Helper method to set up edit constraints for the component
  // Returns the # of edit constraints registered.
  public int setEditConstraints() {
    int      nec = 0;
    SelPoint cp;

    for (int a = 0; a < selPoints.size(); a++ ) {
      cp = (SelPoint) selPoints.elementAt(a);
      if ( cp.getSelected() ) {
        cp.setEditConstraints();
        nec += 2;
      }
    }
    return nec;
  }

  // Helper method to remove all edit constraints associated with the comp.
  public void removeEditConstraints() {
    SelPoint cp;

    for (int a = 0; a < selPoints.size(); a++ ) {
      cp = (SelPoint) selPoints.elementAt(a);
      if ( cp.getSelected() ) {
        cp.removeEditConstraints();
      }
    }
  }

  // MoveBy method
  // Iterate over CC's constrainable parts and record the target edit constant
  // values into the ECL.  MUST iterate over constrainable parts in the
  // same order as the set/removeEditConstraints methods.
  public void moveBy(Point delta, EditConstantList editConstantList) {
    SelPoint cp = null;
    for ( int a = 0; a < selPoints.size(); a++ ) {
      cp = (SelPoint) selPoints.elementAt(a);
      if ( cp.getSelected() ) {
        editConstantList.registerDelta(cp, delta);
      }
    }
  }

  // Update internal variables of the CC by querying the ClVariables,
  // which reflect any change made due to a resolve by the solver.
  // Order of iteration does not matter.
  // Also update the bounding box.
  public void updateEditConstants() {
    SelPoint cp = null;
    for ( int a = 0; a < selPoints.size(); a++ ) {
      cp = (SelPoint) selPoints.elementAt(a);
      cp.updateValue();
    }
    updateBoundingBox();
  }

  // Methods for picking/selecting 
  // Select at a single (x, y) point.  accum indicates if the set of selected
  // points should be accumulated (toggling applicable point(s) only), or
  // reset to just the applicable point(s).
  public void select(Point p, boolean accum) {
    SelPoint sp = null;
    int      a;

    if ( accum == false ) {
      // Unselect anything currently selected
      unselect();
    }
    for (a = 0; a < selPoints.size(); a++ ) {
      sp = (SelPoint) selPoints.elementAt(a);
      if ( sp.inside(p) ) 
        sp.setSelected();
    }
    updateIsSelected();
  }
  
  // Clear selection on every point
  public void unselect() {
    for (int a = 0; a < selPoints.size(); a++ ) {
      ((SelPoint) selPoints.elementAt(a)).clearSelected();
    }
    updateIsSelected();
  }

  // Select inside a box.  accum is as for above method.
  public void select(Rectangle b, boolean accum) {
    SelPoint sp = null;
    int      a;

    if ( accum == false ) {
      // Unselect anything currently selected
      for (a = 0; a < selPoints.size(); a++ ) {
        ((SelPoint) selPoints.elementAt(a)).clearSelected();
      }
    }
    for (a = 0; a < selPoints.size(); a++ ) {
      sp = (SelPoint) selPoints.elementAt(a);
      if ( sp.inside(b) ) 
        sp.setSelected();
    }
    updateIsSelected();
  }

  // Query all points at the (x, y) point position.  Modifies the vector
  // passed as a parameter.
  public void getSelPointsAt(Point p, Vector retv) {
    SelPoint sp = null;
    int      a;

    for (a = 0; a < selPoints.size(); a++ ) {
      sp = (SelPoint) selPoints.elementAt(a);
      if ( sp.inside(p) ) 
        retv.addElement(sp);
    }
  }

  // Updates the isSelected flag based on if all SelPoints are selected
  public void updateIsSelected() {
    isSelected = true;
    int a;
    SelPoint sp;

    for ( a = 0; a < selPoints.size(); a++ ) {
      sp = (SelPoint) selPoints.elementAt(a);
      if ( !sp.getSelected() ) {
        isSelected = false;
        return;
      }
    }
  }

  // Method for highlighting point as mouse moves
  public void highlight(Point p, boolean isShiftDown) {
    SelPoint sp = null;
    int      a;

    // Un-highlight anything that is only highlighted (vs selected)
    for (a = 0; a < selPoints.size(); a++ ) {
      ((SelPoint) selPoints.elementAt(a)).isHighlighted = false; 
    }

    for (a = 0; a < selPoints.size(); a++ ) {
      sp = (SelPoint) selPoints.elementAt(a);
      if ( sp.inside(p) ) 
        sp.isHighlighted = true;
    }

    if ( bbox.contains(p) && isShiftDown ) 
      isHighlighted = true;
    else
      isHighlighted = false;
  }

  public void highlight(Rectangle r) {
    SelPoint sp = null;
    int      a;

    // Un-highlight anything that is only highlighted (vs selected)
    for (a = 0; a < selPoints.size(); a++ ) {
      ((SelPoint) selPoints.elementAt(a)).isHighlighted = false; 
    }

    for (a = 0; a < selPoints.size(); a++ ) {
      sp = (SelPoint) selPoints.elementAt(a);
      if ( sp.inside(r) ) 
        sp.isHighlighted = true;
    }
  }

  // Return the first SelPoint the given point hits, or null if none
  public SelPoint getSelPointAt(Point p) {
    int a;
    SelPoint sp;
    for (a = 0; a < selPoints.size(); a++ ) {
      sp = (SelPoint) selPoints.elementAt(a);
      if ( sp.inside(p) ) 
        return sp;
    }
    return null;
  }

  // Method to update any within-window constraints the CC or its SelPoints
  // have.  Called upon a DrawPanel resize.
  public void setBorderConstraints(int r, int b) {
    SelPoint sp = null;
    int      a;

    for (a = 0; a < selPoints.size(); a++ ) {
      ((SelPoint) selPoints.elementAt(a)).setBorderConstraints(r, b);
    }
  }

  // Method to return a list of all selected SelPoints the component contains.
  public Vector getAllSelectedSelPoints() {
    Vector v = new Vector(2);
    int a;
    SelPoint sp;
    for (a = 0; a < selPoints.size(); a++ ) {
      sp = (SelPoint) selPoints.elementAt(a);
      if ( sp.getSelected() )
        v.addElement(sp);
    }
 
    return v;
  }

  // Method to return a reference to the "end SP" of the component.  The
  // SelPoint returned is the one that is dragged about upon a CC placement.
  public abstract SelPoint getEndSP(); 

  // Method to replace all instances of the given SelPoint with another.
  // It is assumed that the replacement SelPoint has any necessary
  // constraints already established.
  // It is *not* safe to remove constraints associated with the point being 
  // replaced, as it might be a reference to a shared point.  Instead,
  // constraints associated with the replaced SelPoint are removed elsewhere,
  // when it is known the point is not shared.
  // If ownership of the point needs to be changed, it will be handled
  // elsewhere.
  // The original point loses interest in this CC, and the new point
  // gains interest.
  public final void replaceSelPoint(SelPoint origsp, SelPoint newsp) {
    SelPoint sp;
    int      a;
/*
    System.out.println("CC.repSP: Before replacement, selPoints = " 
      + selPoints);
*/
    for (a = 0; a < selPoints.size(); a++ ) {
      sp = (SelPoint) selPoints.elementAt(a);
      if ( sp == origsp ) { // Compare pointers
        // Allow notification to subclass that a point has been replaced,
        // so it can establish any constraints on it that are subclass-
        // specific (IE mark new pt as midpoint of line, etc.)
        // When this call returns, there should be no constraints associated
        // with the given point left in the receiver; they should have been
        // replaced with equivalent constraints on the new SP
        notifySelPointReplacement(a, newsp);
        // Replace the reference in the array
        selPoints.setElementAt(newsp, a);

        // Update the interested-in lists of each point
        sp.removeInterestedCC(this);
        newsp.addInterestedCC(this);
      }
    }

    // Better update the bounding box of the CC
    updateBoundingBox();

/*
    System.out.println("CC.repSP: After replacement, selPoints = " 
      + selPoints);
    System.out.println("CC.repSP: After, bbox = " + bbox);
*/
  }

  // Helper function called when a SelPoint at a specified index is
  // replaced with a new one.  All constraints involving the point at the
  // index should be removed and reestablished using newsp instead.
  // Should be subclassed by all classes that have any constraint
  // relationships between their SelPoints.
  protected void notifySelPointReplacement(int idx, SelPoint newsp) {
    System.out.println("CC.notifySPReplacement invoked");
    return;
  }

  // Returns true if component has SelPoint sp, false otherwise
  public boolean hasSelPoint(SelPoint sp) {
    for ( int a = 0; a < selPoints.size(); a++ ) {
      if ( sp == (SelPoint) selPoints.elementAt(a) ) 
        return true;
    }
    return false;
  }

  // Update the bounding box of the component.  Also notify all concerned
  // constraints that this component's bbox has changed.
  public void updateBoundingBox() {
    int minx, miny, maxx, maxy, a;
    SelPoint sp;
    SelPoint oldLeftSP, oldRightSP, oldTopSP, oldBottomSP;

    minx = 50000; miny = 50000;
    maxx = -50000; maxy = -50000;
   
    oldLeftSP = leftSP;
    oldRightSP = rightSP;
    oldTopSP = topSP;
    oldBottomSP = bottomSP;

    for ( a = 0; a < selPoints.size(); a++ ) {
      sp = (SelPoint) selPoints.elementAt(a);

      if ( sp.x < minx ) {
        minx = sp.x;
        leftSP = sp;
      }
      if ( sp.y < miny ) {
        miny = sp.y;
        topSP = sp;
      }
      if ( sp.x > maxx ) {
        maxx = sp.x;
        rightSP = sp;
      }
      if ( sp.y > maxy ) {
        maxy = sp.y;
        bottomSP = sp;
      }
    }

    bbox.x = minx;
    bbox.y = miny;
    bbox.width = (maxx - minx);
    bbox.height = (maxy - miny);

    // Notify each constraint about bbox change, if any
    if ( (leftSP != oldLeftSP) || (rightSP != oldRightSP) ||
         (topSP != oldTopSP) || (bottomSP != oldBottomSP) ) {
      // MORE WORK HERE
      Constraint c;
      for ( a = 0; a < interConstr.size(); a++ ) {
        c = (Constraint) interConstr.elementAt(a);
        c.notifyCCBBoxChange(this);
      }   
    }
  }

  // Access functions for selection
  public boolean getisSelected() {
    return isSelected;
  }

  public void setisSelected(boolean value) {
    int      a;
    SelPoint sp;

    isSelected = value;
    if ( value == true ) {
      // Select every SelPoint of component
      for ( a = 0; a < selPoints.size(); a++ ) {
        sp = (SelPoint) selPoints.elementAt(a);
        sp.isSelected = true;
      } 
    }
  }

  // Access functions for interested Constraint obj list
  public void addInterestedConstr(Constraint c) {
    if ( !interConstr.contains(c) )
      interConstr.addElement(c);
  }

  public Vector getInterestedConstr() {
    return (Vector) interConstr.clone();
  }

  public void removeInterestedConstr(Constraint c) {
/*
    System.out.println("CC.remInterConstr: Removing " + c + " from " 
      + interConstr);
*/
    if ( interConstr.contains(c) ) 
      interConstr.removeElement(c);
  }

  // Clean up function.  Should remove all CC-specific constraints.
  // By default, does nothing.  Should be overridden by any class that
  // has constraints beyond those internal to SelPoints.
  public void cleanUp() {
  }

  public void finalize() {
    cleanUp();
  }
}

/*
 * $Log: ConstrComponent.java,v $
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
 * Revision 1.3  1998/06/23 02:08:37  gjb
 * Added import of cassowary package so that the cda doesn't need to be
 * in the same package as the solver.
 *
 * Revision 1.2  1998/05/09 00:30:19  gjb
 * Remove cr-s
 *
 * Revision 1.1  1998/05/09 00:10:55  gjb
 * Added
 *
 * Revision 1.17  1998/04/20 09:53:31  Michael
 * Removed debugging msg
 *
 * Revision 1.16  1998/04/19 04:09:49  Michael
 * Increased thickness of blue selection box
 *
 * Revision 1.15  1998/04/15 00:09:29  Michael
 * Added function to accumulate vector of SP's at a point
 *
 * Revision 1.14  1998/04/10 01:59:11  Michael
 * Added getEndSP method
 *
 * Revision 1.13  1998/04/08 05:44:57  Michael
 * Commented out printing stmts and changed interface to highlight
 *
 * Revision 1.12  1998/04/02 07:01:28  Michael
 * Added bounding box change notification
 *
 * Revision 1.11  1998/04/01 10:13:19  Michael
 * Added data and functions for interested Constraint obj back-ptrs
 *
 * Revision 1.10  1998/03/27 06:27:38  Michael
 * Added helper function to update entire CC selection status
 *
 * Revision 1.9  1998/03/25 02:46:39  Michael
 * Added bounding box functions
 *
 * Revision 1.8  1998/03/19 09:16:06  Michael
 * Fixed logic bug where constraints on a shared SelPoint may be removed
 *
 * Revision 1.7  1998/02/25 10:40:01  Michael
 * Added functions for replacing a SelPoint (used for sharing)
 *
 * Revision 1.6  1998/02/17 08:27:17  Michael
 * Added method to return set of all selected point
 *
 * Revision 1.5  1998/02/16 10:34:19  Michael
 * Added method to help with changing constraints on window resize
 *
 * Revision 1.4  1998/02/15 11:34:04  Michael
 * Modified internals to facilitate integration with Cassowary
 *
 * Revision 1.3  1998/02/15 07:12:42  Michael
 * Added highlight method and moved to access function model for selection
 *
 * Revision 1.2  1998/02/06 08:36:40  Michael
 * Fixed compile errors
 *
 *
 */  
  
