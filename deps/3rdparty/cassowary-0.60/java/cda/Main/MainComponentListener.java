/*
 * Component listener to pass resize events from Main to MainPanel
 *
 * $Id: MainComponentListener.java,v 1.3 1999/12/16 02:10:03 gjb Exp $
 */

package EDU.Washington.grad.noth.cda;

import java.awt.event.ComponentAdapter;
import java.awt.event.ComponentEvent;

public class MainComponentListener extends ComponentAdapter {

  // Reference to main panel
  MainPanel mainPanel;

  public MainComponentListener(MainPanel mainPanel) {
    this.mainPanel = mainPanel;
  }

  public void componentResized(ComponentEvent e) {
/*
    System.out.println("Main.cR invoked, str= " + e.paramString() + "'");
*/
    mainPanel.dispatchEvent(e);
  }
}

/*
 * $Log: MainComponentListener.java,v $
 * Revision 1.3  1999/12/16 02:10:03  gjb
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
 * Revision 1.2  1998/05/09 00:30:37  gjb
 * Remove cr-s
 *
 * Revision 1.1  1998/05/09 00:11:18  gjb
 * Added
 *
 * Revision 1.2  1998/04/28 20:08:26  Michael
 * Removed debugging code
 *
 * Revision 1.1  1998/02/17 10:42:13  Michael
 * Split files with multiple classes
 *
 *
 */
