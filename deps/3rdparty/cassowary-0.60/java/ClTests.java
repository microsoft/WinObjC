// $Id: ClTests.java,v 1.22 1999/11/17 01:34:48 gjb Exp $
//
// Cassowary Incremental Constraint Solver
// Original Smalltalk Implementation by Alan Borning
// This Java Implementation by Greg J. Badros, <gjb@cs.washington.edu>
// http://www.cs.washington.edu/homes/gjb
// (C) 1998, 1999 Greg J. Badros and Alan Borning
// See ../LICENSE for legal details regarding this software
// 
// ClTests.java

package EDU.Washington.grad.gjb.cassowary;

import java.lang.*;
import java.util.Random;

public class ClTests extends CL {
  public ClTests()
  {
    RND = new Random(123456789);
  }

  public final static boolean simple1()
       throws ExCLInternalError, ExCLRequiredFailure
  {
    boolean fOkResult = true;
    ClVariable x = new ClVariable(167);
    ClVariable y = new ClVariable(2);
    ClSimplexSolver solver = new ClSimplexSolver();
      
    //    solver.addStay(x);
    //    solver.addStay(y);

    ClLinearEquation eq = new ClLinearEquation(x,new ClLinearExpression(y));
    solver.addConstraint(eq);
    fOkResult = (x.value() == y.value());

    System.out.println("x == " + x.value());
    System.out.println("y == " + y.value());
    return(fOkResult);
  }

  public final static boolean justStay1()
       throws ExCLInternalError, ExCLRequiredFailure
  {
    boolean fOkResult = true;
    ClVariable x = new ClVariable(5);
    ClVariable y = new ClVariable(10);
    ClSimplexSolver solver = new ClSimplexSolver();
      
    solver.addStay(x);
    solver.addStay(y);
    fOkResult = fOkResult && CL.approx(x,5);
    fOkResult = fOkResult && CL.approx(y,10);
    System.out.println("x == " + x.value());
    System.out.println("y == " + y.value());
    return(fOkResult);
  }
  
  public final static boolean addDelete1()
       throws ExCLInternalError, ExCLRequiredFailure, ExCLConstraintNotFound
  {
    boolean fOkResult = true; 
    ClVariable x = new ClVariable("x");
    ClSimplexSolver solver = new ClSimplexSolver();
      
    solver.addConstraint( new ClLinearEquation( x, 100, ClStrength.weak ) );
      
    ClLinearInequality c10 = new ClLinearInequality(x,CL.LEQ,10.0);
    ClLinearInequality c20 = new ClLinearInequality(x,CL.LEQ,20.0);
      
    solver
      .addConstraint(c10)
      .addConstraint(c20);
      
    fOkResult = fOkResult && CL.approx(x,10.0);
    System.out.println("x == " + x.value());
      
    solver.removeConstraint(c10);
    fOkResult = fOkResult && CL.approx(x,20.0);
    System.out.println("x == " + x.value());

    solver.removeConstraint(c20);
    fOkResult = fOkResult && CL.approx(x,100.0);
    System.out.println("x == " + x.value());

    ClLinearInequality c10again = new ClLinearInequality(x,CL.LEQ,10.0);

    solver
      .addConstraint(c10)
      .addConstraint(c10again);
      
    fOkResult = fOkResult && CL.approx(x,10.0);
    System.out.println("x == " + x.value());
    
    solver.removeConstraint(c10);
    fOkResult = fOkResult && CL.approx(x,10.0);
    System.out.println("x == " + x.value());

    solver.removeConstraint(c10again);
    fOkResult = fOkResult && CL.approx(x,100.0);
    System.out.println("x == " + x.value());

    return(fOkResult);
  } 

  public final static boolean addDelete2()
       throws ExCLInternalError, ExCLRequiredFailure, 
	 ExCLConstraintNotFound, ExCLNonlinearExpression
  {
    boolean fOkResult = true; 
    ClVariable x = new ClVariable("x");
    ClVariable y = new ClVariable("y");
    ClSimplexSolver solver = new ClSimplexSolver();

    solver
      .addConstraint( new ClLinearEquation(x, 100.0, ClStrength.weak))
      .addConstraint( new ClLinearEquation(y, 120.0, ClStrength.strong));
      
    ClLinearInequality c10 = new ClLinearInequality(x,CL.LEQ,10.0);
    ClLinearInequality c20 = new ClLinearInequality(x,CL.LEQ,20.0);
      
    solver
      .addConstraint(c10)
      .addConstraint(c20);
    fOkResult = fOkResult && CL.approx(x,10.0) && CL.approx(y,120.0);
    System.out.println("x == " + x.value() + ", y == " + y.value());

    solver.removeConstraint(c10);
    fOkResult = fOkResult && CL.approx(x,20.0) && CL.approx(y,120.0);
    System.out.println("x == " + x.value() + ", y == " + y.value());
   
    ClLinearEquation cxy = new ClLinearEquation( CL.Times(2.0,x), y);
    solver.addConstraint(cxy);
    fOkResult = fOkResult && CL.approx(x,20.0) && CL.approx(y,40.0);
    System.out.println("x == " + x.value() + ", y == " + y.value());

    solver.removeConstraint(c20);
    fOkResult = fOkResult && CL.approx(x,60.0) && CL.approx(y,120.0);
    System.out.println("x == " + x.value() + ", y == " + y.value());

    solver.removeConstraint(cxy);
    fOkResult = fOkResult && CL.approx(x,100.0) && CL.approx(y,120.0);
    System.out.println("x == " + x.value() + ", y == " + y.value());
      
    return(fOkResult);
  } 

  public final static boolean casso1()
       throws ExCLInternalError, ExCLRequiredFailure
  {
    boolean fOkResult = true; 
    ClVariable x = new ClVariable("x");
    ClVariable y = new ClVariable("y");
    ClSimplexSolver solver = new ClSimplexSolver();

    solver
      .addConstraint( new ClLinearInequality(x,CL.LEQ,y) )
      .addConstraint( new ClLinearEquation(y, CL.Plus(x,3.0)) )
      .addConstraint( new ClLinearEquation(x,10.0,ClStrength.weak) )
      .addConstraint( new ClLinearEquation(y,10.0,ClStrength.weak) )
      ;
   
    fOkResult = fOkResult && 
      ( CL.approx(x,10.0) && CL.approx(y,13.0) ||
	CL.approx(x,7.0) && CL.approx(y,10.0) );
      
    System.out.println("x == " + x.value() + ", y == " + y.value());
    return(fOkResult);
  } 

  public final static boolean inconsistent1()
       throws ExCLInternalError, ExCLRequiredFailure
  {
    try 
      {
      ClVariable x = new ClVariable("x");
      ClSimplexSolver solver = new ClSimplexSolver();
      
      solver
	.addConstraint( new ClLinearEquation(x,10.0) )
	.addConstraint( new ClLinearEquation(x, 5.0) );
      
      // no exception, we failed!
      return(false);
      } 
    catch (ExCLRequiredFailure err)
      {
      // we want this exception to get thrown
      System.out.println("Success -- got the exception");
      return(true);
      }
  }

  public final static boolean inconsistent2()
       throws ExCLInternalError, ExCLRequiredFailure
  {
    try 
      {
      ClVariable x = new ClVariable("x");
      ClSimplexSolver solver = new ClSimplexSolver();
      
      solver
	.addConstraint( new ClLinearInequality(x,CL.GEQ,10.0) )
	.addConstraint( new ClLinearInequality(x,CL.LEQ, 5.0) );

      // no exception, we failed!
      return(false);
      } 
    catch (ExCLRequiredFailure err)
      {
      // we want this exception to get thrown
      System.out.println("Success -- got the exception");
      return(true);
      }
  }

  public final static boolean multiedit()
       throws ExCLInternalError, ExCLRequiredFailure, ExCLError
  {
    try 
      {
      boolean fOkResult = true;

      ClVariable x = new ClVariable("x");
      ClVariable y = new ClVariable("y");
      ClVariable w = new ClVariable("w");
      ClVariable h = new ClVariable("h");
      ClSimplexSolver solver = new ClSimplexSolver();
      
      solver
        .addStay(x)
        .addStay(y)
        .addStay(w)
        .addStay(h);

      solver
        .addEditVar(x)
        .addEditVar(y)
        .beginEdit();

      solver
        .suggestValue(x,10)
        .suggestValue(y,20)
        .resolve();

      System.out.println("x = " + x.value() + "; y = " + y.value());
      System.out.println("w = " + w.value() + "; h = " + h.value());

      fOkResult = fOkResult &&
        CL.approx(x,10) && CL.approx(y,20) &&
        CL.approx(w,0) && CL.approx(h,0);

      solver
        .addEditVar(w)
        .addEditVar(h)
        .beginEdit();

      solver
        .suggestValue(w,30)
        .suggestValue(h,40)
        .endEdit();

      System.out.println("x = " + x.value() + "; y = " + y.value());
      System.out.println("w = " + w.value() + "; h = " + h.value());

      fOkResult = fOkResult &&
        CL.approx(x,10) && CL.approx(y,20) && 
        CL.approx(w,30) && CL.approx(h,40);

      solver
        .suggestValue(x,50)
        .suggestValue(y,60)
        .endEdit();

      System.out.println("x = " + x.value() + "; y = " + y.value());
      System.out.println("w = " + w.value() + "; h = " + h.value());

      fOkResult = fOkResult &&
        CL.approx(x,50) && CL.approx(y,60) &&
        CL.approx(w,30) && CL.approx(h,40);

      return(fOkResult);
      } 
    catch (ExCLRequiredFailure err)
      {
      // we want this exception to get thrown
      System.out.println("Success -- got the exception");
      return(true);
      }
  }


  public final static boolean inconsistent3()
       throws ExCLInternalError, ExCLRequiredFailure
  {
    try 
      {
      ClVariable w = new ClVariable("w");
      ClVariable x = new ClVariable("x");
      ClVariable y = new ClVariable("y");
      ClVariable z = new ClVariable("z");
      ClSimplexSolver solver = new ClSimplexSolver();
      
      solver
	.addConstraint( new ClLinearInequality(w,CL.GEQ,10.0) )
	.addConstraint( new ClLinearInequality(x,CL.GEQ,w) )
	.addConstraint( new ClLinearInequality(y,CL.GEQ,x) )
	.addConstraint( new ClLinearInequality(z,CL.GEQ,y) )
	.addConstraint( new ClLinearInequality(z,CL.GEQ,8.0) )
	.addConstraint( new ClLinearInequality(z,CL.LEQ, 4.0) );

      // no exception, we failed!
      return(false);
      } 
    catch (ExCLRequiredFailure err)
      {
      // we want this exception to get thrown
      System.out.println("Success -- got the exception");
      return(true);
      }
  }


  public final static boolean addDel(int nCns, int nVars, int nResolves)
       throws ExCLInternalError, ExCLRequiredFailure, 
	 ExCLNonlinearExpression, ExCLConstraintNotFound
  {
    Timer timer = new Timer();
    // FIXGJB: from where did .12 come?
    final double ineqProb = 0.12;
    final int maxVars = 3;

    System.out.println("starting timing test. nCns = " + nCns +
        ", nVars = " + nVars + ", nResolves = " + nResolves);
    
    timer.Start();
    ClSimplexSolver solver = new ClSimplexSolver();

    ClVariable[] rgpclv = new ClVariable[nVars];
    for (int i = 0; i < nVars; i++) {
      rgpclv[i] = new ClVariable(i,"x");
      solver.addStay(rgpclv[i]);
    }

    ClConstraint[] rgpcns = new ClConstraint[nCns];
    int nvs = 0;
    int k;
    int j;
    double coeff;
    for (j = 0; j < nCns; j++) {
      // number of variables in this constraint
      nvs = RandomInRange(1,maxVars);
      ClLinearExpression expr = new ClLinearExpression(UniformRandomDiscretized() * 20.0 - 10.0);
      for (k = 0; k < nvs; k++) {
        coeff = UniformRandomDiscretized()*10 - 5;
        int iclv = (int) (UniformRandomDiscretized()*nVars);
        expr.addExpression(CL.Times(rgpclv[iclv], coeff));
      }
      if (UniformRandomDiscretized() < ineqProb) {
        rgpcns[j] = new ClLinearInequality(expr);
      } else {  
        rgpcns[j] = new ClLinearEquation(expr);
      }
      if (fTraceOn) traceprint("Constraint " + j + " is " + rgpcns[j]);
    }

    System.out.println("done building data structures");
    System.out.println("time = " + timer.ElapsedTime());
    timer.Start();
    int cExceptions = 0;
    for (j = 0; j < nCns; j++) {
      // add the constraint -- if it's incompatible, just ignore it
      // FIXGJB: exceptions are extra expensive in C++, so this might not
      // be particularly fair
      try
	{
	  solver.addConstraint(rgpcns[j]);
	}
      catch (ExCLRequiredFailure err)
	{
	  cExceptions++;
	  if (fTraceOn) traceprint("got exception adding " + rgpcns[j]);
	  rgpcns[j] = null;
	}
    }
   // FIXGJB end = Timer.now();
   System.out.println("done adding constraints [" + cExceptions + " exceptions]");
   System.out.println("time = " + timer.ElapsedTime() + "\n");
   timer.Start();

   int e1Index = (int) (UniformRandomDiscretized()*nVars);
   int e2Index = (int) (UniformRandomDiscretized()*nVars);

   System.out.println("indices " + e1Index + ", " + e2Index);
   
   ClEditConstraint edit1 = new ClEditConstraint(rgpclv[e1Index],ClStrength.strong);
   ClEditConstraint edit2 = new ClEditConstraint(rgpclv[e2Index],ClStrength.strong);

   //   CL.fDebugOn = CL.fTraceOn = true;

   solver
     .addConstraint(edit1)
     .addConstraint(edit2);

   System.out.println("done creating edit constraints -- about to start resolves");
   System.out.println("time = " + timer.ElapsedTime() + "\n");
   timer.Start();

   // FIXGJB start = Timer.now();
   for (int m = 0; m < nResolves; m++)
     {
     solver.resolve(rgpclv[e1Index].value() * 1.001,
		    rgpclv[e2Index].value() * 1.001);
     }

   System.out.println("done resolves -- now removing constraints");
   System.out.println("time = " + timer.ElapsedTime() + "\n");

   solver.removeConstraint(edit1);
   solver.removeConstraint(edit2);

   timer.Start();

   for (j = 0; j < nCns; j++)
     {
     if (rgpcns[j] != null)
       {
       solver.removeConstraint(rgpcns[j]);
       }
     }

   System.out.println("done removing constraints and addDel timing test");
   System.out.println("time = " + timer.ElapsedTime() + "\n");

   timer.Start();
   
   return true;
 }

  public final static double UniformRandomDiscretized()
  {
    double n = Math.abs(RND.nextInt());
    return (n/Integer.MAX_VALUE);
  }

  public final static int RandomInRange(int low, int high)
  {
    return (int) UniformRandomDiscretized()*(high-low)+low;
  }
    


  public final static void main( String[] args )
       throws ExCLInternalError, ExCLNonlinearExpression,
	 ExCLRequiredFailure, ExCLConstraintNotFound, ExCLError
  {
    //    try 
    {
      ClTests clt = new ClTests();

      boolean fAllOkResult = true;
      boolean fResult;
      
      System.out.println("simple1:");
      fResult = simple1(); fAllOkResult &= fResult;
      if (!fResult) System.out.println("Failed!");
      if (CL.fGC) System.out.println("Num vars = " + ClAbstractVariable.numCreated() );

      System.out.println("justStay1:");
      fResult = justStay1(); fAllOkResult &= fResult;
      if (!fResult) System.out.println("Failed!");
      if (CL.fGC) System.out.println("Num vars = " + ClAbstractVariable.numCreated() );
	
      System.out.println("addDelete1:");
      fResult = addDelete1(); fAllOkResult &= fResult;
      if (!fResult) System.out.println("Failed!");
      if (CL.fGC) System.out.println("Num vars = " + ClAbstractVariable.numCreated() );
    
      System.out.println("addDelete2:");
      fResult = addDelete2(); fAllOkResult &= fResult;
      if (!fResult) System.out.println("Failed!");
      if (CL.fGC) System.out.println("Num vars = " + ClAbstractVariable.numCreated() );
    
      System.out.println("casso1:");
      fResult = casso1(); fAllOkResult &= fResult;
      if (!fResult) System.out.println("Failed!");
      if (CL.fGC) System.out.println("Num vars = " + ClAbstractVariable.numCreated() );
    
      System.out.println("inconsistent1:");
      fResult = inconsistent1(); fAllOkResult &= fResult;
      if (!fResult) System.out.println("Failed!");
      if (CL.fGC) System.out.println("Num vars = " + ClAbstractVariable.numCreated() );
    
      System.out.println("inconsistent2:");
      fResult = inconsistent2(); fAllOkResult &= fResult;
      if (!fResult) System.out.println("Failed!");
      if (CL.fGC) System.out.println("Num vars = " + ClAbstractVariable.numCreated() );

      System.out.println("inconsistent3:");
      fResult = inconsistent3(); fAllOkResult &= fResult;
      if (!fResult) System.out.println("Failed!");
      if (CL.fGC) System.out.println("Num vars = " + ClAbstractVariable.numCreated() );

      System.out.println("multiedit:");
      fResult = multiedit(); fAllOkResult &= fResult;
      if (!fResult) System.out.println("Failed!");
      if (CL.fGC) System.out.println("Num vars = " + ClAbstractVariable.numCreated() );
      
      System.out.println("addDel:");

      int cns = 900, vars = 900, resolves = 10000;

      if (args.length > 0)
        cns = Integer.parseInt(args[0]);

      if (args.length > 1)
        vars = Integer.parseInt(args[1]);

      if (args.length > 2)
        resolves = Integer.parseInt(args[2]);

      fResult = addDel(cns,vars,resolves);
      // fResult = addDel(300,300,1000);
      // fResult = addDel(30,30,100);
      // fResult = addDel(10,10,30);
      // fResult = addDel(5,5,10);
      fAllOkResult &= fResult;
      if (!fResult) System.out.println("Failed!");
      if (CL.fGC) System.out.println("Num vars = " + ClAbstractVariable.numCreated() );
      
      } 
    //    catch (Exception err)
    //      {
    //      System.err.println("Exception: " + err);
    //      }
  }

  static private Random RND;
}
