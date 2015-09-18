/*
 * Mouse event handler for the DrawPanel.
 *
 * $Id: DPMouseMotionListener.java,v 1.3 1999/12/16 02:10:01 gjb Exp $
 *
 */

package EDU.Washington.grad.noth.cda;

import java.awt.event.MouseAdapter;
import java.awt.event.MouseMotionListener;
import java.awt.event.MouseEvent;
import java.util.Vector;

public final class DPMouseMotionListener extends MouseAdapter
  implements MouseMotionListener {

  // Reference to DrawPanel
  DrawPanel drawPanel;

  // Constructor
  public DPMouseMotionListener(DrawPanel drawPanel) {
    super();
    this.drawPanel = drawPanel;
  }

  // Invoked when mouse enters container.  Used to shift keyboard input
  // focus to the DrawPanel so it can catch keypresses.
  public void mouseEntered(MouseEvent e) {
    // System.out.println("DPMML.mouseEntered invoked");
    drawPanel.requestFocus();
  }

  // Invoked when mouse leaves container
  public void mouseExited(MouseEvent e) {
    // System.out.println("DPMML.mouseExited invoked");
  }

  // Invoked when mouse is moved without any buttons pressed
  public void mouseMoved(MouseEvent e) {
    drawPanel.notifyMousePosition(e);
  }

  // Invoked when mouse is dragged
  public void mouseDragged(MouseEvent e) {
    drawPanel.mouseDragged(e);
  }

  // Invoked when mouse is pressed
  public void mousePressed(MouseEvent e) {

  //   System.out.println("DPMML.mousePressed invoked, mouse at ("
  //     + e.getX() + ", " + e.getY() + ")"); 
    drawPanel.mousePressed(e);

  }

  // Invoked when mouse is released.  Removes all edit constraints. 
  // If a selection box was being drawn, select everything in it.
  public void mouseReleased(MouseEvent e) {
  //   System.out.println("DPMML.mouseReleased invoked, mouse at ("
  //     + e.getX() + ", " + e.getY() + ")"); 

    drawPanel.mouseReleased(e);
  }
}

/*
 * $Log: DPMouseMotionListener.java,v $
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
 * Revision 1.2  1998/05/09 00:30:31  gjb
 * Remove cr-s
 *
 * Revision 1.1  1998/05/09 00:11:13  gjb
 * Added
 *
 * Revision 1.2  1998/04/08 05:38:27  Michael
 * Removed printing msgs and changed interface to mouse motion callback
 *
 * Revision 1.1  1998/04/01 10:16:41  Michael
 * Shortened names
 *
 * Revision 1.6  1998/03/27 06:24:52  Michael
 * Added code to allow picking a target CC for relational constraints
 *
 * Revision 1.5  1998/03/25 02:47:19  Michael
 * Added CC selection functions
 *
 * Revision 1.4  1998/03/19 09:18:49  Michael
 * Added hooks for rectangle CC
 *
 * Revision 1.3  1998/03/02 06:45:07  Michael
 * Extensive changes to move to CCG-based list of parts
 *
 * Revision 1.2  1998/02/25 10:40:43  Michael
 * Added first cut of internal grouping for point sharing
 *
 * Revision 1.1  1998/02/17 10:42:00  Michael
 * Split files with multiple classes
 *
 *
 */
