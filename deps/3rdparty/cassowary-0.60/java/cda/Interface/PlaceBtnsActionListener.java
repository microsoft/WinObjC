/*
 * Mouse event handler for PlaceBtns panel
 *
 * $Id: PlaceBtnsActionListener.java,v 1.4 1999/12/16 02:10:02 gjb Exp $
 *
 */

package EDU.Washington.grad.noth.cda;

import java.awt.event.ActionListener;
import java.awt.event.ActionEvent;

public final class PlaceBtnsActionListener implements ActionListener {

  // Reference to DrawPanel
  DrawPanel drawPanel;
  
  public void actionPerformed(ActionEvent e) {
    ImageButton ib = (ImageButton) e.getSource();
    ib.repaint();

    if ( e.getActionCommand().equals("P1") ) {
      drawPanel.createNewCC("LineCC");
      return;
    }
    if ( e.getActionCommand().equals("P2") ) {
      drawPanel.createNewCC("MidpointLineCC");
      return;
    }
    if ( e.getActionCommand().equals("P3") ) {
      drawPanel.createNewCC("RectangleCC");
      return;
    }
    if ( e.getActionCommand().equals("P4") ) {
      drawPanel.createNewCC("CircleCC");
      return;
    }
  }

  public PlaceBtnsActionListener(DrawPanel drawPanel) {
    this.drawPanel = drawPanel;
  }
}

/*
 * $Log: PlaceBtnsActionListener.java,v $
 * Revision 1.4  1999/12/16 02:10:02  gjb
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
 * Revision 1.3  1998/05/14 23:40:06  gjb
 * Patch from noth to redraw the buttons after they are clicked to fix
 * the disappearing icon bug that appears (only) on linux
 *
 * Revision 1.2  1998/05/09 00:30:35  gjb
 * Remove cr-s
 *
 * Revision 1.1  1998/05/09 00:11:16  gjb
 * Added
 *
 * Revision 1.4  1998/04/08 05:39:55  Michael
 * Removed printing msg
 *
 * Revision 1.3  1998/04/05 03:12:21  Michael
 * Added circle CC
 *
 * Revision 1.2  1998/03/19 09:18:50  Michael
 * Added hooks for rectangle CC
 *
 * Revision 1.1  1998/02/17 10:42:01  Michael
 * Split files with multiple classes
 *
 *
 */
