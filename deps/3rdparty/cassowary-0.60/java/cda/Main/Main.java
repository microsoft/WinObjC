/* Main.java

   Main application class for Constraint-based Drawing Application

  $VERSION$

*/
package EDU.Washington.grad.noth.cda;

import java.awt.*;
import java.awt.event.*;
import java.applet.Applet;
//import MainPanel;

public class Main extends java.applet.Applet { 

    MainPanel  mainPanel;

    public Main() {
      // Everything is actually done inside init()!
    }

    public void init() {
      mainPanel = new MainPanel();

      BorderLayout bl = new BorderLayout();
      setLayout(bl);
      
      add(mainPanel);

      // Add event listener(s)
      // Pass along resize messages to underlying main panel
      addComponentListener(new MainComponentListener(mainPanel));
    }

    public static void main(String args[]) {
      Frame f = new Frame("Constraint-Based Drawing");
      Main mainInstance = new Main();

      f.add(mainInstance);
      f.pack();
      f.setSize(400, 400);
      f.show();
    }

}

/*
 *
 * $Log: Main.java,v $
 * Revision 1.4  1999/12/16 02:10:03  gjb
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
 * Revision 1.3  1998/05/14 22:34:47  gjb
 * Remove reference to unused class "RedirectingMMListener"
 *
 * Revision 1.2  1998/05/09 00:30:37  gjb
 * Remove cr-s
 *
 * Revision 1.1  1998/05/09 00:11:18  gjb
 * Added
 *
 * Revision 1.8  1998/04/28 20:08:14  Michael
 * Moved initialization code to init()
 *
 * Revision 1.7  1998/04/26 06:15:25  Michael
 * Removed code
 *
 * Revision 1.6  1998/02/17 10:42:13  Michael
 * Split files with multiple classes
 *
 * Revision 1.5  1998/02/16 10:36:17  Michael
 * Added stop method (not used)
 *
 * Revision 1.4  1998/02/09 02:27:07  Michael
 * Changed default size
 *
 * Revision 1.3  1998/02/06 11:15:22  Michael
 * Major changes to handle event propagation
 *
 * Revision 1.2  1998/02/06 08:37:50  Michael
 * Skeletal version of main
 *
 * Revision 1.1.1.1  1998/02/01 06:44:37  Michael
 * Initial check-in
 *
 *
 */
