/*
 * PlaceBtns.java
 *
 * Place primitive button(s) and associated layout component
 *
 * $Id: PlaceBtns.java,v 1.3 1999/12/16 02:10:02 gjb Exp $
 *
 */

package EDU.Washington.grad.noth.cda;

import java.awt.*;
import java.awt.event.*;

public class PlaceBtns extends Panel {

  // Reference to the DrawPanel
  DrawPanel drawPanel;

  PlaceBtnsActionListener pbal;

  Panel create() {
    Button b = null;
    pbal = new PlaceBtnsActionListener(drawPanel);
    setLayout(new GridLayout(2,2));

    b = new ImageButton("P1", "LineCC");
    b.addActionListener(pbal);
    add(b);
    b = new ImageButton("P2", "MidLineCC");
    b.addActionListener(pbal);
    add(b);
    b = new ImageButton("P3", "RectangleCC");
    b.addActionListener(pbal);
    add(b);
    b = new ImageButton("P4", "CircleCC");
    b.addActionListener(pbal);
    add(b);
/*
    b = new ImageButton("P5", "Blank");
    b.addActionListener(pbal);
    add(b);
    b = new ImageButton("P6", "Blank");
    b.addActionListener(pbal);
    add(b);
    b = new ImageButton("P7", "Blank");
    b.addActionListener(pbal);
    add(b);
    b = new ImageButton("P8", "Blank");
    b.addActionListener(pbal);
    add(b);
*/

    return this;
  }

  // Constructor    
  PlaceBtns(DrawPanel dp) {
    drawPanel = dp;
    create();
  }

}


/*
 * $Log: PlaceBtns.java,v $
 * Revision 1.3  1999/12/16 02:10:02  gjb
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
 * Revision 1.2  1998/05/09 00:30:35  gjb
 * Remove cr-s
 *
 * Revision 1.1  1998/05/09 00:11:16  gjb
 * Added
 *
 * Revision 1.10  1998/04/26 06:15:49  Michael
 * Removed 4 blank btns
 *
 * Revision 1.9  1998/04/05 03:12:21  Michael
 * Added circle CC
 *
 * Revision 1.8  1998/03/19 09:18:50  Michael
 * Added hooks for rectangle CC
 *
 * Revision 1.7  1998/02/24 08:48:25  Michael
 * Changed unused placement buttons to be blank
 *
 * Revision 1.6  1998/02/17 10:42:01  Michael
 * Split files with multiple classes
 *
 * Revision 1.5  1998/02/17 08:25:47  Michael
 * Removed unneeded import
 *
 * Revision 1.4  1998/02/16 10:33:20  Michael
 * Added names of line, midpoint line CC to buttons
 *
 * Revision 1.3  1998/02/12 07:55:51  Michael
 * Changed buttons to ImageButtons and hooked in actionListener
 *
 * Revision 1.2  1998/02/06 11:13:44  Michael
 * Major changes in layout to handle event propagation and resizing
 *
 * Revision 1.1  1998/02/06 06:17:40  Michael
 * Added parts of interface
 *
 *
 */

