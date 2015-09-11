/*
 * Alignment relational constraint.  All constrained CC's are to have the 
 * appropriate edge of their bounding boxes aligned.
 * This is done much like an adjacency constraint, by forcing the target's
 * bbox to conform to the source CC's.
 *
 * $Id: AlignmentConstraint.java,v 1.4 1999/12/16 02:10:00 gjb Exp $
 *
 */

package EDU.Washington.grad.noth.cda;

import java.awt.Graphics;
import java.awt.Color;
import java.awt.Rectangle;
import java.util.Vector;
//import CDA_G;

import EDU.Washington.grad.gjb.cassowary.*;

public class AlignmentConstraint extends Constraint {

  // Vector of ClLinearEquation constraints upon the appropriate edge of
  // the CC's
  protected Vector relConstrs;

  // What type of alignment is it? (IE which side of bbox)
  public static final int TOP_ALIGN = 0; 
  public static final int BOTTOM_ALIGN = 1; 
  public static final int LEFT_ALIGN = 2; 
  public static final int RIGHT_ALIGN = 3; 

  protected int align;

  // The SelPoint to align with
  protected SelPoint targetSP;

  public AlignmentConstraint(ClSimplexSolver solver, Vector ccVector,
    int alignment) {

    super(solver);

    int a;
    SelPoint sp;
    ConstrComponent cc;
    for ( a = 0; a < ccVector.size(); a++ ) {
      cc = (ConstrComponent) ccVector.elementAt(a);
      addCC(cc);
      cc.addInterestedConstr(this);
    }

    align = alignment;

/*
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
*/

    targetSP = null;
    relConstrs = new Vector(1);
    addConstraints();
  }

  // Remove constraints from solver.
  public void removeConstraints() {
    int a;
    ClLinearEquation cle;

    for ( a = 0; a < relConstrs.size(); a++ ) {
      cle = (ClLinearEquation) relConstrs.elementAt(a);
      try { 
        if ( cle != null ) 
          solver.removeConstraint(cle);
      } catch (ExCLInternalError e) {
        System.out.println("AlignConstr.remConstr: ExCLInternalError "
          + "removing #" + a + " = " + cle);
      } catch (ExCLConstraintNotFound e) {
        System.out.println("AlignConstr.remConstr: ExCLConstraintNotFound "
          + "removing #" + a + " = " + cle);
      }
    }

    relConstrs.removeAllElements();

    targetSP = null;
  }

  // Method to replace one SelPoint with another.
  // If SP being replaced is in the srcCC, don't do anything.
  // If SP being replaced is in the targetCC, retract old constraint and
  // establish new one on the new SP.

  // Don't need to do anything if a SelPoint is replaced, as we're just
  // monitoring the bounding boxes.
  public void replaceSelPoint(SelPoint oldsp, SelPoint newsp) {
/*
    ConstrComponent srcCC, targetCC;
    ClLinearEquation cle;
    int oldIdx;

    if ( ccList.size() != 2 ) {
      System.out.println("AlignConstr.repSP: Ill-formed AlignConstraint!");
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
      // Remove constraint on that SP
      oldIdx = targetCC.selPoints.indexOf(oldsp);
      cle = (ClLinearEquation) relConstrs.elementAt(oldIdx);
      try { 
        if ( cle != null ) 
          solver.removeConstraint(cle);
      } catch (ExCLInternalError e) {
        System.out.println("AlignConstr.repSP: ExCLInternalError "
          + "removing #" + oldIdx + " = " + cle);
      } catch (ExCLConstraintNotFound e) {
        System.out.println("AlignConstr.repSP: ExCLConstraintNotFound "
          + "removing #" + oldIdx + " = " + cle);
      }

      // Create a new constraint to take its place
      try {
        cli = new ClLinearInequality(newsp.X(), CL.LEQ, srcCC.topSP.Y());
      } catch (ExCLInternalError e) {
        System.out.println("AlignConstr.repSP: ExCLInternalError replacing #" 
          + oldIdx);
      }
      relConstrs.setElementAt(cli, oldIdx);
      try { 
        if ( cli != null ) 
          solver.addConstraint(cli);
      } catch (ExCLInternalError e) {
        System.out.println("AlignConstr.repSP: ExCLInternalError adding #" 
          + oldIdx + " = " + cli);
      } catch (ExCLRequiredFailure e) {
        System.out.println("AlignConstr.repSP: ExCLRequiredFailure "
          + "adding #" + oldIdx + " = " + cli);
      }
    }
*/
  }

  // When the bounding box of the src CC changes, re-establish constraints.
  // This is necessary as the edge point has definitely changed.
  public void notifyCCBBoxChange(ConstrComponent c) {
    ConstrComponent srcCC, targetCC;

/*
    System.out.println("AlignConstr.notifyCCBBChange: " + this);
    System.out.println("AlignConstr.notifyCCBBChange: bbox = " + c.bbox);
*/

    // Re-establish constraints, to be safe
    removeConstraints();
    addConstraints();
  }

  // An alignment constraint is relevant only if it has more than 1 CC
  public boolean canDiscard() {
/*
    System.out.println("AlignConstr.canDiscard: ccList = " + ccList);
*/
    if ( ccList.size() < 2 )
      return true;

    return false;
  }

  // When one of the CC's the constraint cares about goes away, it can be
  // discarded.
  // Make sure that if the going-away CC contained the targetSP, 
  // pick a new targetSP!
  public void notifyCCRemoval(ConstrComponent c) {
/*
    System.out.println("AlignConstr.notifyCCRem: Removing " + c 
      + " from " + ccList);
*/
    if ( ccList.contains(c) ) 
      ccList.removeElement(c);

    if ( c.selPoints.contains(targetSP) ) {
      removeConstraints();
      addConstraints();
    }

  }

  public void draw(Graphics g) {
    ConstrComponent cc;
    int lowx, lowy, highx, highy, a, px, py;
    Rectangle bb;

    lowx = 5000;
    lowy = 5000;
    highx = -5000;
    highy = -5000;

    for ( a = 0; a < ccList.size(); a++ ) {
      cc = (ConstrComponent) ccList.elementAt(a);
      bb = cc.bbox;
      // Expand the bbox of the constraint based on appropriate 2 corners
      // of a CC's bbox
      switch ( align ) {
        case TOP_ALIGN:
          // Top-left and top-right
          px = bb.x;
          py = bb.y;
          break;
        case BOTTOM_ALIGN:
          // Bottom-left and bottom-right
          px = bb.x;
          py = bb.y + bb.height;
          break;
        case LEFT_ALIGN:
          // Top-left and bottom-left
          px = bb.x;
          py = bb.y;
          break;
        case RIGHT_ALIGN:
          // Top-right and bottom-right
          px = bb.x + bb.width;
          py = bb.y;
          break;
        default:
          System.out.println("AlignConstr.draw:  Unknown type " + align);
          px = 0;
          py = 0;
      }

      if ( lowx > px )
        lowx = px;
      if ( lowy > py )
        lowy = py;
      if ( highx < px )
        highx = px;
      if ( highy < py )
        highy = py; 

      switch ( align ) {
        case TOP_ALIGN:
          // Top-left and top-right
          px = bb.x + bb.width;
          py = bb.y;
          break;
        case BOTTOM_ALIGN:
          // Bottom-left and bottom-right
          px = bb.x + bb.width;
          py = bb.y + bb.height;
          break;
        case LEFT_ALIGN:
          // Top-left and bottom-left
          px = bb.x;
          py = bb.y + bb.height;
          break;
        case RIGHT_ALIGN:
          // Top-right and bottom-right
          px = bb.x + bb.width;
          py = bb.y + bb.height;
          break;
        default:
          System.out.println("AlignConstr.draw:  Unknown type " + align);
          px = 0;
          py = 0;
      }

      if ( lowx > px )
        lowx = px;
      if ( lowy > py )
        lowy = py;
      if ( highx < px )
        highx = px;
      if ( highy < py )
        highy = py; 
    }

    g.setColor(Color.gray);
    g.drawLine(lowx, lowy, highx, highy);

    bbox.x = lowx - 2;
    bbox.y = lowy - 2;
    bbox.width = (highx - lowx) + 4;
    bbox.height = (highy - lowy) + 4;

    if ( isSelected ) {
      g.setColor(CDA_G.DARK_GREEN);
      g.drawRect(bbox.x, bbox.y, bbox.width, bbox.height);
     
    } else if ( isHighlighted ) {
      g.setColor(CDA_G.DARK_BLUE);
      g.drawRect(bbox.x, bbox.y, bbox.width, bbox.height);
      g.drawRect(bbox.x-1, bbox.y-1, bbox.width+2, bbox.height+2);
    }
  }

  // Method to create (if necessary) and add the constraints to the solver.
  // Sets up equality constraints for the appropriate direction (X or Y)
  // on the appropriate edge point of each CC.
  public void addConstraints() {
/*
    System.out.println("AlignConstr.addConstr: invoked");
*/

    // Appropriate edge 
    SelPoint sp;
    ClLinearExpression cle;
    ClLinearEquation cleq;

    ConstrComponent cc;

    int minx, miny, maxx, maxy, a;
    minx = 5000;
    miny = 5000;
    maxx = -5000;
    maxy = -5000;

    if ( relConstrs.size() != ccList.size() ) {
      // Need to create new constraints
      if ( relConstrs.size() != 0 ) { 
        System.out.println("AlignConstr.addConstr: relConstrs = " + relConstrs
          + ", should be empty!");
        relConstrs.removeAllElements();
      }

      relConstrs.setSize(ccList.size());
      for ( a = 0; a < ccList.size(); a++ ) {
        cc = (ConstrComponent) ccList.elementAt(a);

        // Get the target SP to align with
        switch ( align ) {
          case LEFT_ALIGN:
            sp = cc.leftSP;
            if ( sp.x < minx ) {
              minx = sp.x;
              targetSP = sp;
            }
            break;
          case RIGHT_ALIGN:
            sp = cc.rightSP;
            if ( sp.x > maxx ) {
              maxx = sp.x;
              targetSP = sp;
            }
            break;
          case TOP_ALIGN:
            sp = cc.topSP;
            if ( sp.y < miny ) {
              miny = sp.y;
              targetSP = sp;
            }
            break;
          case BOTTOM_ALIGN:
            sp = cc.bottomSP;
            if ( sp.y > maxy ) {
              maxy = sp.y;
              targetSP = sp;
            }
            break;
          default:
            System.out.println("AlignConstr.addConstr: Unknown type " + align);
            return;
        } 
      }
    
      // Establish a constraint between the outlying pt of each CC and the
      // appropriate coord of the target SP
      for ( a = 0; a < ccList.size(); a++ ) {
        cc = (ConstrComponent) ccList.elementAt(a);

        switch ( align ) {
          case LEFT_ALIGN:
            sp = cc.leftSP;
            try {
              cle = new ClLinearExpression(sp.X());
              cleq = new ClLinearEquation(targetSP.X(), cle);
              relConstrs.setElementAt(cleq, a);
              solver.addConstraint(cleq);
            } catch (ExCLRequiredFailure e) {
              System.out.println("AlignConstr.addCon: ExCLRequiredFailure!");
            } catch (ExCLInternalError e ) {
              System.out.println("AlignConstr.addCon: ExCLInternalError!");
            }
            break;
          case RIGHT_ALIGN:
            sp = cc.rightSP;
            try {
              cle = new ClLinearExpression(sp.X());
              cleq = new ClLinearEquation(targetSP.X(), cle);
              relConstrs.setElementAt(cleq, a);
              solver.addConstraint(cleq);
            } catch (ExCLRequiredFailure e) {
              System.out.println("AlignConstr.addCon: ExCLRequiredFailure!");
            } catch (ExCLInternalError e ) {
              System.out.println("AlignConstr.addCon: ExCLInternalError!");
            }
            break;
          case TOP_ALIGN:
            sp = cc.topSP;
            try {
              cle = new ClLinearExpression(sp.Y());
              cleq = new ClLinearEquation(targetSP.Y(), cle);
              relConstrs.setElementAt(cleq, a);
              solver.addConstraint(cleq);
            } catch (ExCLRequiredFailure e) {
              System.out.println("AlignConstr.addCon: ExCLRequiredFailure!");
            } catch (ExCLInternalError e ) {
              System.out.println("AlignConstr.addCon: ExCLInternalError!");
            }
            break;
          case BOTTOM_ALIGN:
            sp = cc.bottomSP;
            try {
              cle = new ClLinearExpression(sp.Y());
              cleq = new ClLinearEquation(targetSP.Y(), cle);
              relConstrs.setElementAt(cleq, a);
              solver.addConstraint(cleq);
            } catch (ExCLRequiredFailure e) {
              System.out.println("AlignConstr.addCon: ExCLRequiredFailure!");
            } catch (ExCLInternalError e ) {
              System.out.println("AlignConstr.addCon: ExCLInternalError!");
            }
            break;
        } 
      }
    }
  }

  // Helper method to convert constraint to a string
  public String toString() {
    StringBuffer sb = new StringBuffer("AlignConstr: targetSP = " + targetSP);
    sb.append("\nccList = ");
    for ( int a = 0; a < ccList.size(); a++ ) {
      sb.append(ccList.elementAt(a) + "\n");
    }
  
    return sb.toString();
  }

}

/*
 * $Log: AlignmentConstraint.java,v $
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
 * Revision 1.3  1998/06/23 02:08:45  gjb
 * Added import of cassowary package so that the cda doesn't need to be
 * in the same package as the solver.
 *
 * Revision 1.2  1998/05/09 00:30:25  gjb
 * Remove cr-s
 *
 * Revision 1.1  1998/05/09 00:11:00  gjb
 * Added
 *
 * Revision 1.3  1998/04/26 06:19:29  Michael
 * Changed how highlighting is drawn
 *
 * Revision 1.2  1998/04/23 08:59:30  Michael
 * Removed printing msgs
 *
 * Revision 1.1  1998/04/23 08:47:37  Michael
 * Initial check-in
 *
 *
 */
