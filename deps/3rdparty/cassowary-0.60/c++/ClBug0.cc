// $Id: ClBug0.cc,v 1.3 1999/09/19 21:45:10 gjb Exp $

#include "Cl.h"

/* This bug fixed --02/15/99 gjb
   Replaced the parallel vectors for edit constraints
   (the errorPlus..., errorMinus..., prevEditConstants vectors)
   with a ClEditInfo class that is the Value of the _editVarMap map.
   
   Later I realized that I need to go to a _editVars list so that
   multiple edits on the same variable that nest are handled properly.
   --09/19/99 gjb
*/

int main()
{
  ClSimplexSolver solver;

  ClVariable x("x",7);
  ClVariable y("y",8);
  ClVariable z("z",9);

  solver
    .AddStay(x)
    .AddStay(y)
    .AddStay(z);

  try {
    solver.AddEditVar(x);
    solver.AddEditVar(y);
    solver.AddEditVar(z);
    solver.BeginEdit();
    
    solver.SuggestValue(x,1);
    solver.SuggestValue(z,2);
    
    solver.RemoveEditVar(y);

    solver.SuggestValue(x,3);
    solver.SuggestValue(z,4);

    solver.EndEdit();
    
  } catch (ExCLError &e) {
    cerr << e.description() << endl;
  }

  cout << x << endl << y << endl << z <<endl;

}

#if 0 /* Message below */
 From: "Michael Kaufmann" <Michael.Kaufmann@ubs.com> 
 To: <noth@cs.washington.edu> 
 Subject: bugreport 
 Date: Thu, 1 Oct 1998 11:40:55 +0200 
 Message-Id: <000001bded1f$973a2060$230e1fac@itc_mk.sbcs.swissbank.com> 
 Mime-Version: 1.0 
 Content-Type: text/plain; 
       charset="iso-8859-1" 
 Content-Transfer-Encoding: 7bit 
 X-Priority: 3 (Normal) 
 X-Msmail-Priority: Normal 
 X-Mailer: Microsoft Outlook 8.5, Build 4.71.2173.0 
 Importance: Normal 
 X-Mimeole: Produced By Microsoft MimeOLE V4.72.2106.4 
  
 Dear Mr Noth, 
  
 I am currently working with the Java implementation of Cassowary and found 
 the following bug: 
  
 If I Add several editConstraints, remove some of them again later and 
 perform a 'ClSimplexSolver.SuggestValue()', the indices of 
 'ClConstraintAndIndex' in the variable 'cai' are sometimes wrong (see 
 ClSimplexSolver.SuggestValue(ClVariable v, double x), the 3rd line). This is 
 because if you remove an element from a 'java.util.Vector', and the element 
 is somewhere in the middle of the Vector, the indices of the Vector change. 
 (see java.util.Vector.removeElementAt(int index): 
  
     public final synchronized void removeElementAt(int index) { 
       if (index >= elementCount) { 
           throw new ArrayIndexOutOfBoundsException(index + " >= " + 
                                                    elementCount); 
       } 
       else if (index < 0) { 
           throw new ArrayIndexOutOfBoundsException(index); 
       } 
       int j = elementCount - index - 1; 
       if (j > 0) { 
           System.arraycopy(elementData, index + 1, elementData, index, j); 
       } 
       elementCount--; 
       elementData[elementCount] = null; /* to let gc do its work */ 
     } 
  
  
 My workaround now is, that everytime when I remove an EditVariable from the 
 Solver, I have to remove all the EditVariables and Add then the ones again, 
 that I do not want to remove. 
  
#endif
