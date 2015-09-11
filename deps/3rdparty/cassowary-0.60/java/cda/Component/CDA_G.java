/*
 * Global constants, etc. for the CDA.
 *
 * $Id: CDA_G.java,v 1.3 1999/12/16 02:09:59 gjb Exp $
 *
 */

package EDU.Washington.grad.noth.cda;

import java.awt.Color;

public class CDA_G {
  public static final Color DARK_GREEN = new Color(0, 160, 0);
  public static final Color DARK_RED = new Color(160, 0, 0);
  public static final Color DARK_BLUE = new Color(0, 0, 160);

  // Constants for size of box around a selectable point
  public static final int SELBOXSIZE = 8;
  public static final int DRAWBOXSIZE = 6;
}


/*
 * $Log: CDA_G.java,v $
 * Revision 1.3  1999/12/16 02:09:59  gjb
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
 * Revision 1.2  1998/05/09 00:30:18  gjb
 * Remove cr-s
 *
 * Revision 1.1  1998/05/09 00:10:54  gjb
 * Added
 *
 * Revision 1.2  1998/03/27 06:27:46  Michael
 * Added dark red color
 *
 * Revision 1.1  1998/03/25 02:45:43  Michael
 * Initial check-in
 *
 *
 */
