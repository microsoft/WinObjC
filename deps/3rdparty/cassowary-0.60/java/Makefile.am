## $Id: Makefile.am,v 1.8 1999/12/16 19:11:11 gjb Exp $
## Process this file with automake to create Makefile.in

JAVAFILES = \
	ClAbstractVariable.java \
	ClDummyVariable.java \
	ClObjectiveVariable.java \
	ClSlackVariable.java \
	ClConstraint.java \
	ClEditConstraint.java \
	ClEditInfo.java \
	ClEditOrStayConstraint.java \
	ClLinearConstraint.java \
	ClLinearEquation.java \
	ClLinearExpression.java \
	ClLinearInequality.java \
	ClStayConstraint.java \
	ClStrength.java \
	ClSymbolicWeight.java \
	ClVariable.java \
	ClPoint.java \
	ClDouble.java \
	ClTableau.java \
	ClSimplexSolver.java \
	ExCLConstraintNotFound.java \
	ExCLError.java \
	ExCLInternalError.java \
	ExCLNonlinearExpression.java \
	ExCLNotEnoughStays.java \
	ExCLRequiredFailure.java \
	ExCLTooDifficult.java \
	CL.java \
        ClTests.java \
	Set.java \
	parser.java \
	sym.java \
	Yylex.java \
	ClParseTest.java \
	Timer.java

# Force prefix ordering
SUBDIRS=. demos cda

EXTRA_DIST=$(JAVAFILES) ClReader.cup ClReader.lex

if HAVE_JAVA
java_JAVA = $(JAVAFILES)

demos: ../EDU


test:
	java EDU.Washington.grad.gjb.cassowary.ClTests

parser.java sym.java: ClReader.cup
	java java_cup.Main < $<

Yylex.java: ClReader.lex
	java JLex.Main $< && \
	mv ClReader.lex.java Yylex.java

else
classjava.stamp:
	echo timestamp > classjava.stamp

install-javaJAVA:
	echo "Not installing java .class files since Java build was disabled"
endif
