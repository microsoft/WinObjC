/*
 * Key event listener for the DrawPanel.  
 *
 * $Id: DPKeyListener.java,v 1.3 1999/12/16 02:10:01 gjb Exp $
 *
 */

package EDU.Washington.grad.noth.cda;

import java.awt.event.KeyAdapter;
import java.awt.event.KeyListener;
import java.awt.event.KeyEvent;
import java.applet.Applet;
import java.awt.Dimension;


public final class DPKeyListener extends KeyAdapter 
  implements KeyListener {
  // Reference to DrawPanel
  DrawPanel drawPanel;
  
  public DPKeyListener(DrawPanel drawPanel) {
    this.drawPanel = drawPanel;
  }

  public void keyPressed(KeyEvent e) {
    // System.out.println("DPKL.kP: " + e.getKeyChar());
  }

  public void keyReleased(KeyEvent e) {
    // System.out.println("DPKL.kR: " + e.getKeyChar());

    switch ( e.getKeyCode() ) {
      case KeyEvent.VK_ESCAPE: // Cancel current action
        if ( drawPanel.placingComponent ) {
          drawPanel.stopPlacingComponent();
        }
        if ( drawPanel.pickingTargetCC ) { 
          drawPanel.stopPickingTargetCC();
        }
        drawPanel.unselectAll();
        break;
      case KeyEvent.VK_S: // Query size of DrawPanel
        Dimension d = drawPanel.getSize();
        System.out.println("DrawPanel size is " + d.width + ", " 
          + d.height);
        break; 
      case KeyEvent.VK_I: // Display app state info
        drawPanel.displayAppInfo();
        break;
      case KeyEvent.VK_F: // Display full app. state info
        drawPanel.displayFullInfo();
        break;
      case KeyEvent.VK_Q: // Clear the display (remove everything)
        drawPanel.removeAll();
        break;
      case KeyEvent.VK_D: // Delete currently selected CC(s)
        drawPanel.deleteCC();
        break;

      // CC Creation Shortcuts
      case KeyEvent.VK_L: // Create a Line CC
        drawPanel.createNewCC("LineCC");
        break;
      case KeyEvent.VK_O: // Create a Circle (oval) CC
        drawPanel.createNewCC("CircleCC");
        break;
      case KeyEvent.VK_M: // Create a MidpointLine CC
        drawPanel.createNewCC("MidpointLineCC");
        break;
      case KeyEvent.VK_R: // Create a Rectangle CC
        drawPanel.createNewCC("RectangleCC");
        break;

      // Constraint Shortcuts
      case KeyEvent.VK_A: // Establish anchor constraint
        drawPanel.createNewConstraint("Anchor");
        break;
      case KeyEvent.VK_C: // Establish colocation constraint
        drawPanel.createNewConstraint("Colocation");
        break;
   }
  }
}

/*
 * $Log: DPKeyListener.java,v $
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
 * Revision 1.2  1998/04/15 00:09:58  Michael
 * Added keyboard shortcuts to create CC's and anchor, coloc. constrs
 *
 * Revision 1.1  1998/04/01 10:16:41  Michael
 * Shortened names
 *
 * Revision 1.3  1998/03/27 06:24:52  Michael
 * Added code to allow picking a target CC for relational constraints
 *
 * Revision 1.2  1998/03/02 06:45:29  Michael
 * Added clear and delete keys
 *
 * Revision 1.1  1998/02/17 10:42:00  Michael
 * Split files with multiple classes
 *
 *
 */

