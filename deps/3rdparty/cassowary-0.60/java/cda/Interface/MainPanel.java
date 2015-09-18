/*
 * MainPanel.java
 *
 * Main panel of CDA.  Consists of a left subpanel holding two button bars,
 * and the main drawing area to the right.
 *
 * $Id: MainPanel.java,v 1.3 1999/12/16 02:10:02 gjb Exp $
 *
 */

package EDU.Washington.grad.noth.cda;

import java.awt.*;
import java.awt.event.*;
import java.applet.Applet;

class MainPanel extends Panel {

  public DrawPanel drawPanel;
  public PlaceBtns placeBtnsPanel;
  public ConstraintBtns constraintBtnsPanel;
  public GridBagLayout gbl;

  Panel create() {
    drawPanel = new DrawPanel();
    placeBtnsPanel = new PlaceBtns(drawPanel);
    constraintBtnsPanel = new ConstraintBtns(drawPanel);
 
    gbl = new GridBagLayout();
    GridBagConstraints gbc = new GridBagConstraints();

    setLayout(gbl);

    // Place the PlaceBtns panel and ConstraintBtns panel in one row,
    // then the DrawPanel to their right.

    // The placeBtns panel
    gbc.gridx = 0;
    gbc.gridy = 0;
    gbc.anchor = GridBagConstraints.NORTHWEST;
    gbc.insets = new Insets(4, 4, 10, 4);
    gbl.setConstraints(placeBtnsPanel, gbc);
    add(placeBtnsPanel);

    // The constraintBtns panel
    gbc.gridy = 1;
    gbc.insets = new Insets(0, 4, 0, 4);
    gbl.setConstraints(constraintBtnsPanel, gbc);
    add(constraintBtnsPanel);

    // A filler panel below the button panels
    gbc.gridy = 2;
    Panel fillerPanel = new Panel();
    gbc.fill = GridBagConstraints.VERTICAL;
    gbl.setConstraints(fillerPanel, gbc);
    add(fillerPanel);
  
    // The DrawPanel
    gbc.gridy = 0;
    gbc.gridx = 1;
    gbc.weightx = 1.0;
    gbc.weighty = 1.0;
    gbc.gridheight = 2;
    gbc.insets = new Insets(4, 0, 20, 10);
    gbc.anchor = GridBagConstraints.NORTHEAST;
    gbc.fill = GridBagConstraints.BOTH;
    gbl.setConstraints(drawPanel, gbc);
    add(drawPanel);

    return this;
  }

  MainPanel() {
    create();

    // On a resize, tell the DrawPanel it has a new preferred size
    addComponentListener(new MainPanelComponentListener(this));
  
    System.out.println("MainPanel constructor called");
  }

  public void paint(Graphics g) {
/*
    System.out.println("MainPanel.paint invoked");
*/
  }

  public void update(Graphics g) {
/*
    System.out.println("MainPanel.update invoked");
*/
  }
}

/*
 *
 * $Log: MainPanel.java,v $
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
 * Revision 1.2  1998/05/09 00:30:34  gjb
 * Remove cr-s
 *
 * Revision 1.1  1998/05/09 00:11:15  gjb
 * Added
 *
 * Revision 1.9  1998/04/28 20:08:58  Michael
 * Removed dead code and added borders to layout
 *
 * Revision 1.8  1998/04/26 06:16:12  Michael
 * Changed layout
 *
 * Revision 1.7  1998/04/23 09:01:17  Michael
 * Changed layout and default size
 *
 * Revision 1.6  1998/02/17 10:42:01  Michael
 * Split files with multiple classes
 *
 * Revision 1.5  1998/02/17 08:25:15  Michael
 * Integrated ConstraintBtns changes and fixed DrawPanel size
 *
 * Revision 1.4  1998/02/16 10:32:58  Michael
 * Added reference to DrawPanel
 *
 * Revision 1.3  1998/02/09 02:24:02  Michael
 * Added blank panel between btn bars
 *
 * Revision 1.2  1998/02/06 11:13:44  Michael
 * Major changes in layout to handle event propagation and resizing
 *
 * Revision 1.1  1998/02/06 06:17:40  Michael
 * Added parts of interface
 *
 *
 */

