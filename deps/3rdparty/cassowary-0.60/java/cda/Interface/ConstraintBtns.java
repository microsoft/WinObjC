/*
 * ConstraintBtns.java
 *
 * Constraint button(s) and associated layout component
 *
 * $Id: ConstraintBtns.java,v 1.3 1999/12/16 02:10:01 gjb Exp $
 *
 */

package EDU.Washington.grad.noth.cda;

import java.awt.*;
import java.awt.event.*;

public class ConstraintBtns extends Panel {

  // Reference to the DrawPanel
  DrawPanel drawPanel;

  ConstraintBtnsActionListener cbal;

  Panel create() {
    Button b = null;
    cbal = new ConstraintBtnsActionListener(drawPanel);
    setLayout(new GridLayout(5,2));

    b = new ImageButton("C1", "Anchor");
    b.addActionListener(cbal);
    add(b);
    b = new ImageButton("C2", "Colocation");
    b.addActionListener(cbal);
    add(b);
    b = new ImageButton("C3", "Above");
    b.addActionListener(cbal);
    add(b);
    b = new ImageButton("C4", "Below");
    b.addActionListener(cbal);
    add(b);
    b = new ImageButton("C5", "LeftOf");
    b.addActionListener(cbal);
    add(b);
    b = new ImageButton("C6", "RightOf");
    b.addActionListener(cbal);
    add(b);
    b = new ImageButton("C7", "LeftAlign");
    b.addActionListener(cbal);
    add(b);
    b = new ImageButton("C8", "TopAlign");
    b.addActionListener(cbal);
    add(b);
    b = new ImageButton("C9", "RightAlign");
    b.addActionListener(cbal);
    add(b);
    b = new ImageButton("C10", "BottomAlign");
    b.addActionListener(cbal);
    add(b);

    return this;
  }

  // Constructor    
  ConstraintBtns(DrawPanel dp) {
    drawPanel = dp;
    create();
  }
 
}


/*
 * $Log: ConstraintBtns.java,v $
 * Revision 1.3  1999/12/16 02:10:01  gjb
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
 * Revision 1.2  1998/05/09 00:30:30  gjb
 * Remove cr-s
 *
 * Revision 1.1  1998/05/09 00:11:12  gjb
 * Added
 *
 * Revision 1.7  1998/04/23 09:00:55  Michael
 * Added alignment constraint buttons
 *
 * Revision 1.6  1998/03/27 06:23:34  Michael
 * Added new buttons for relational constraints
 *
 * Revision 1.5  1998/02/17 10:41:59  Michael
 * Split files with multiple classes
 *
 * Revision 1.4  1998/02/17 08:24:42  Michael
 * Added hooks for constraint button functionality
 *
 * Revision 1.3  1998/02/15 07:14:53  Michael
 * Changed buttons to ImageButtons
 *
 * Revision 1.2  1998/02/06 11:13:44  Michael
 * Major changes in layout to handle event propagation and resizing
 *
 * Revision 1.1  1998/02/06 06:17:40  Michael
 * Added parts of interface
 *
 *
 */

