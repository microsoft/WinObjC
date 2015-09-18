/*
 * ColocationConstraint class.  Causes two SelPoints to be colocated
 * (the second to be located at the same location as the first)
 *
 * $Id: ColocationConstraint.java,v 1.4 1999/12/16 02:10:00 gjb Exp $
 *
 */

package EDU.Washington.grad.noth.cda;

import java.awt.Graphics;
import java.awt.Color;
//import CDA_G;

import EDU.Washington.grad.gjb.cassowary.*;

public class ColocationConstraint extends Constraint {

  int ox, oy;

  public ColocationConstraint(ClSimplexSolver solver, SelPoint sharedSP) {
    super(solver);
    addSelPoint(sharedSP);

    ox = sharedSP.x;
    oy = sharedSP.y;
    bbox.x = ox - 8;
    bbox.y = oy - 9;
    bbox.width = 16;
    bbox.height = 14; 
  }

  public void draw(Graphics g) {
    x = (int) ((SelPoint) selPointList.elementAt(0)).X().value();
    y = (int) ((SelPoint) selPointList.elementAt(0)).Y().value();
    g.setColor(CDA_G.DARK_RED);
    g.drawOval(x - 5, y - 5, 10, 10);
    // Draw inward-pointing arrows
    g.drawLine(x - 8, y - 9, x - 4, y - 5);
    g.drawLine(x - 6, y - 5, x - 4, y - 5);
    g.drawLine(x - 4, y - 7, x - 4, y - 5);
    g.drawLine(x + 8, y - 9, x + 4, y - 5);
    g.drawLine(x + 6, y - 5, x + 4, y - 5);
    g.drawLine(x + 4, y - 7, x + 4, y - 5);

    if ( (ox != x) || (oy != y) ) {
      ox = x;
      oy = y;
      bbox.x = ox - 8;
      bbox.y = oy - 9;
    }

    if ( isSelected ) {
      g.setColor(CDA_G.DARK_GREEN);
      g.drawRect(bbox.x, bbox.y, bbox.width, bbox.height);
    } else if ( isHighlighted ) {
      g.setColor(CDA_G.DARK_BLUE);
      g.drawRect(bbox.x, bbox.y, bbox.width, bbox.height);
      g.drawRect(bbox.x-1, bbox.y-1, bbox.width+2, bbox.height+2);
    }
     
  }

  // Add constraints to solver.  Note that for a colocation constraint,
  // the actual constraints are *implicit* in the reuse of a SelPoint.
  public void addConstraints() {
  }
  
  // Remove constraints from solver.  As the constraints are implicit, nothing
  // need be done.
  public void removeConstraints() {
  }

  // Method to convert constraint to a string
  public String toString() {
    if ( selPointList.size() < 1 ) {
      return new String("ColocationConstr at [], interestedCC = " + ccList);
    } else {
      SelPoint sp = (SelPoint) selPointList.elementAt(0);
      String s = new String("ColocationConstr at " + sp + ", interestedCC = " 
        + ccList);
      return s;
    }
  }

  // Method to replace one SelPoint with another.  As the constraints are
  // implicit, don't need to do anything.
  public void replaceSelPoint(SelPoint oldsp, SelPoint newsp) {
  }

  // When a CC associated with a colocation constraint goes away,
  // update the appropriate data structures.
  public void notifyCCRemoval(ConstrComponent cc) {
    if ( ccList.contains(cc) )
      ccList.removeElement(cc);

/*
    System.out.println("ColocConstr.notifyCCRem: List now " + ccList);
*/
  }

  // When a SelPoint associated with a colocation constraint goes away,
  // update the appropriate data structures.
  public void notifySPRemoval(SelPoint sp) {
    if ( selPointList.contains(sp) ) {
/*
      System.out.println("ColocConstr.notSPRem: Removing " + sp + " from "
        + selPointList);
*/
      selPointList.removeElement(sp);
    }
  }

  // A colocation constraint is relevant when it's caring about more than
  // one CC.  Note that this will prevent a colocation constraint from
  // being imposed on points in the same CC!
  public boolean canDiscard() {
    if ( (ccList.size() < 2) || (selPointList.size() < 1) )
      return true;

    return false;
  }

}

/*
 * $Log: ColocationConstraint.java,v $
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
 * Revision 1.7  1998/04/20 09:52:44  Michael
 * Added code for selection/highlighting
 *
 * Revision 1.6  1998/04/19 04:11:17  Michael
 * Updated canDiscard conditions
 *
 * Revision 1.5  1998/04/08 23:39:46  Michael
 * Changes so a colocation constraint is discardable when only one CC
 * cares about it.
 *
 * Revision 1.4  1998/04/01 10:20:36  Michael
 * Added methods for new functionality
 *
 * Revision 1.3  1998/03/27 06:29:26  Michael
 * Changed Coloc. constraint to be placeholder for icon; constraints are in group
 *
 */
