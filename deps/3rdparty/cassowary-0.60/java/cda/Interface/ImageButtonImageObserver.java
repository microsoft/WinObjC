/*
 * Image observer that forces an image repaint once image is available
 *
 * $Id: ImageButtonImageObserver.java,v 1.3 1999/12/16 02:10:02 gjb Exp $
 */

package EDU.Washington.grad.noth.cda;

import java.awt.image.ImageObserver;
import java.awt.Image;

// Image observer that handles forcing a repaint once image is available
public class ImageButtonImageObserver implements ImageObserver {
 
  // Reference to the ImageButton
  ImageButton imageButton;

  public ImageButtonImageObserver(ImageButton imageButton) {
    this.imageButton = imageButton;
  }

  public boolean imageUpdate(Image img, int infoflags, int x, int y, 
    int width, int height) {
    if ( (infoflags & ALLBITS) != 0 ) {
      // Finished retrieving the image, so draw it
      // System.out.println("IBIO.iU: ALLBITS true");
      imageButton.repaint();
      return false;
    }
    return true;
  }
}

/*
 * $Log: ImageButtonImageObserver.java,v $
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
 * Revision 1.1  1998/02/17 10:42:00  Michael
 * Split files with multiple classes
 *
 *
 */
