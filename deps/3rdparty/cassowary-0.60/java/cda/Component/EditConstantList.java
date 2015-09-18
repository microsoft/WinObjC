/*
 * EditConstantList class.  Provides a wrapper and interface to a vector
 * of edit constants to be passed to resolve, as well as ensuring ordering
 * of added/removed edit constraints matches the order in the vector.
 *
 * $Id: EditConstantList.java,v 1.4 1999/12/16 02:09:59 gjb Exp $
 */

package EDU.Washington.grad.noth.cda;

import java.util.Vector;
import java.awt.Point;

import EDU.Washington.grad.gjb.cassowary.*;

public class EditConstantList {
  // Vector of edit constants (ClDouble instances)
  Vector ec;
  // Vector listing SelPoint <-> ec associations.  2 * Index in list is 
  // starting index in ec.   
  private Vector selPointAssocList;

  // Default constructor
  public EditConstantList() {
    this(1);
  }

  public EditConstantList(int n) {
    if ( n < 1 )
      n = 1;

    ec = new Vector(n);

    for ( int a = 0; a < n; a++ ) {
      ec.addElement(new ClDouble(0.0));
    }

    selPointAssocList = new Vector(n);
  }

  public void registerDelta(ClVariable v, double delta) { 
    System.out.println("Sorry, not yet implemented.");
  }

  // Record a delta of a point in the next 2 consecutive spots in the vector

  // Record a delta of a SelPoint in the appropriate place
  public void registerDelta(SelPoint sp, Point delta) {

    int spIdx = -1, a;

    // System.out.println("ECP.regDelta: sp = " + sp);
    // System.out.println("ECP.regDelta: selPAL = " +selPointAssocList.size());
    // System.out.println(selPointAssocList);

    for ( a = 0; a < selPointAssocList.size(); a++ ) {
      if ( sp == (SelPoint) selPointAssocList.elementAt(a) ) {
        spIdx = a;
        break;
      }
    }
    if ( spIdx == -1 ) {
      // sp not in assoc list, so add it
      selPointAssocList.addElement(sp);
      spIdx = selPointAssocList.indexOf(sp);
    }
    // System.out.println("ECL.regDelta: spIdx = " + spIdx);

    // Store X at 2 * spIdx, Y at 2 * spIdx + 1

    ClDouble d;
    d = (ClDouble) ec.elementAt(2 * spIdx);
    d.setValue(sp.clX.value() + delta.x);
    d = (ClDouble) ec.elementAt(2 * spIdx + 1);
    d.setValue(sp.clY.value() + delta.y);
    
  }

  // Set the size of the vector to size n, and allocate extra elements
  // if needed.  Also clear the SP association array.
  public void setSize(int n) {
    int oldSize = ec.size();
    int numNewElems = n - oldSize;
    int a;

    ec.setSize(n);

    if ( numNewElems > 0 )
      for ( a = oldSize; a < n; a++ )
        ec.setElementAt(new ClDouble(0.0), a);

    reset();

    selPointAssocList.setSize(0);
  }

  // Convert an ECL to a string
  public final synchronized String toString() {
    String retstr = new String("ECL: size = " + ec.size());
    retstr = retstr.concat(", Elems = [");
    for (int a = 0; a < ec.size() - 1; a++) {
      retstr = retstr.concat(String.valueOf(((ClDouble)
        ec.elementAt(a)).doubleValue()));
      retstr = retstr.concat(", ");
    }
    if ( ec.size() > 0 ) 
      retstr = retstr.concat(String.valueOf(((ClDouble)
        ec.elementAt(ec.size() - 1)).doubleValue()));
   
    retstr = retstr.concat("]");
  
    return retstr;
  }

  public void reset() { 
    // idx = 0;
  }
}

/*
 * $Log: EditConstantList.java,v $
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
 * Revision 1.4  1998/04/02 07:01:43  Michael
 * Removed printing messages
 *
 * Revision 1.3  1998/02/25 10:39:02  Michael
 * Added SelPoint association list to facilitate point sharing
 *
 * Revision 1.2  1998/02/16 10:34:38  Michael
 * Fixed off-by-one bug and added some sanity checks
 *
 * Revision 1.1  1998/02/15 11:35:51  Michael
 * Initial check-in
 *
 *
 */
