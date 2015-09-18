## $Id: Makefile.am,v 1.6 1999/12/16 03:14:00 gjb Exp $
## Process this file with automake to create Makefile.in

JAVAFILES = DraggableBox.java QuadDemo.java

if HAVE_JAVA
java_JAVA = $(JAVAFILES)
else
classjava.stamp:
	echo timestamp > classjava.stamp

install-javaJAVA:
	echo "Not installing java .class files since Java build was disabled"
endif

EXTRA_DIST=$(JAVAFILES) quaddemo.htm

run:
	appletviewer quaddemo.htm
