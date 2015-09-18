/*
 * Adjacency relational constraint.  The target CC (the second) is to be 
 * next to the first (source) CC at all times, with respect to their bounding
 * boxes.
 * Used as a base class for the Above, Below, LeftOf, and RightOf constraints.
 * Subclasses need to implement toString and addConstraints.
 *
 * $Id: AdjacencyConstraint.java,v 1.4 1999/12/16 02:10:00 gjb Exp $
 *
 */

package EDU.Washington.grad.noth.cda;

import java.awt.Graphics;
import java.awt.Color;
import java.util.Vector;
//import CDA_G;

import EDU.Washington.grad.gjb.cassowary.*;

public abstract class AdjacencyConstraint extends Constraint {

  // Vector of ClLinearInequality constraints upon the target's SelPoints
  protected Vector relConstrs;

  public AdjacencyConstraint(ClSimplexSolver solver, ConstrComponent srcCC,
    ConstrComponent targetCC) {

    super(solver);
    addCC(srcCC);
    addCC(targetCC);

    int a;
    SelPoint sp;

    // The constraint also needs to be interested in every SelPoint of the
    // target, in case one changes.  It does *not* need to be explicitly
    // concerned about those in the src, as any changes to them will alter
    // its bounding box.
    for ( a = 0; a < targetCC.selPoints.size(); a++ ) {
      sp = (SelPoint) targetCC.selPoints.elementAt(a);
      addSelPoint(sp);
      sp.addInterestedConstr(this);
    }
    srcCC.addInterestedConstr(this);
    targetCC.addInterestedConstr(this);
    relConstrs = new Vector(targetCC.selPoints.size());
    addConstraints();
  }

  // Remove constraints from solver.
  public void removeConstraints() {
    int a;
    ClLinearInequality cli;

    for ( a = 0; a < relConstrs.size(); a++ ) {
      cli = (ClLinearInequality) relConstrs.elementAt(a);
      try { 
        if ( cli != null ) 
          solver.removeConstraint(cli);
      } catch (ExCLInternalError e) {
        System.out.println("AdjConstr.remConstr: ExCLInternalError "
          + "removing #" + a + " = " + cli);
      } catch (ExCLConstraintNotFound e) {
        System.out.println("AdjConstr.remConstr: ExCLConstraintNotFound "
          + "removing #" + a + " = " + cli);
      }
    }

    relConstrs.removeAllElements();
  }

  // Method to replace one SelPoint with another.
  // If SP being replaced is in the srcCC, don't do anything.
  // If SP being replaced is in the targetCC, retract old constraint and
  // establish new one on the new SP.
  public void replaceSelPoint(SelPoint oldsp, SelPoint newsp) {
    ConstrComponent srcCC, targetCC;
    ClLinearInequality cli;
    int oldIdx;

    if ( ccList.size() != 2 ) {
      System.out.println("AdjConstr.repSP: Ill-formed AdjacencyConstraint!");
      return;
    } else {
      srcCC = (ConstrComponent) ccList.elementAt(0);
      targetCC = (ConstrComponent) ccList.elementAt(1);
    }

    if ( srcCC.selPoints.contains(oldsp) ) {
      // Doesn't matter...updating the bounding box of the src CC affects
      // the change.
      return;
    }
 
    if ( targetCC.selPoints.contains(oldsp) ) {

      // Re-establish all constraints
      removeConstraints();
      addConstraints();
    }
  }

  // When the bounding box of the src CC changes, re-establish constraints.
  // This is necessary as the topmost point may have changed...
  public void notifyCCBBoxChange(ConstrComponent c) {
    ConstrComponent srcCC, targetCC;

/*
    System.out.println("AdjConstr.notifyCCBBChange: " + this);
    System.out.println("AdjConstr.notifyCCBBChange: bbox = " + c.bbox);
*/

    if ( ccList.size() != 2 ) {
      System.out.println("AdjConstr.notifyCCBBoxChange: " + ccList.size() 
        + " CC's, not required 2!");
      return;
    }
    removeConstraints();
    addConstraints();
  }

  // An adjacency constraint is relevant only if it has exactly two CC's
  public boolean canDiscard() {
/*
    System.out.println("AdjConstr.canDiscard: ccList = " + ccList);
*/
    if ( ccList.size() != 2 )
      return true;

    return false;
  }

  // When one of the CC's the constraint cares about goes away, it can be
  // discarded.
  public void notifyCCRemoval(ConstrComponent c) {
/*
    System.out.println("AdjConstr.notifyCCRem: Removing " + c 
      + " from " + ccList);
*/
    if ( ccList.contains(c) ) 
      ccList.removeElement(c);
  }

  public void draw(Graphics g) {
    ConstrComponent srcCC, targetCC;
    int srcx, srcy, targx, targy;

    if ( ccList.size() != 2 ) {
      System.out.println("AdjConstr.draw: " + ccList.size() 
        + " CC's, not required 2!");
      return;
    }
    srcCC = (ConstrComponent) ccList.elementAt(0);
    targetCC = (ConstrComponent) ccList.elementAt(1);
 
    srcx = srcCC.bbox.x + srcCC.bbox.width / 2;
    targx = targetCC.bbox.x + targetCC.bbox.width / 2;
    srcy = srcCC.bbox.y + srcCC.bbox.height/ 2;
    targy = targetCC.bbox.y + targetCC.bbox.height / 2;

    g.setColor(Color.red);
    g.drawLine(srcx, srcy, targx, targy);
    g.drawOval(srcx - 4, srcy - 4, 8, 8);

    if ( srcx < targx ) {
      bbox.x = srcx ;
      bbox.width = targx - srcx;
    } else {
      bbox.x = targx; 
      bbox.width = srcx - targx;
    }

    if ( srcy < targy ) {
      bbox.y = srcy;
      bbox.height = targy - srcy;
    } else {
      bbox.y = targy;
      bbox.height = srcy - targy;
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

}

/*
 * $Log: AdjacencyConstraint.java,v $
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
 * Revision 1.3  1998/06/23 02:08:44  gjb
 * Added import of cassowary package so that the cda doesn't need to be
 * in the same package as the solver.
 *
 * Revision 1.2  1998/05/09 00:30:25  gjb
 * Remove cr-s
 *
 * Revision 1.1  1998/05/09 00:10:59  gjb
 * Added
 *
 * Revision 1.6  1998/04/23 08:59:29  Michael
 * Removed printing msgs
 *
 * Revision 1.5  1998/04/23 08:47:26  Michael
 * Fixed SP-replacement bugs
 *
 * Revision 1.4  1998/04/20 09:51:58  Michael
 * Moved draw method into base class
 *
 * Revision 1.3  1998/04/10 01:58:44  Michael
 * Fixed bug preventing AdjConstrs from being flagged removable when they were
 *
 * Revision 1.2  1998/04/08 05:41:40  Michael
 * Commented out printing msgs
 *
 * Revision 1.1  1998/04/02 06:58:12  Michael
 * Initial check-in
 *
 */
