# $Id: Makefile.am,v 1.8 1999/12/16 03:32:08 gjb Exp $
## Process this file with automake to create Makefile.in



INTERFACE_FILES = \
  Interface/MainPanel.java \
  Interface/MainPanelComponentListener.java \
  Interface/PlaceBtns.java \
  Interface/PlaceBtnsActionListener.java \
  Interface/ConstraintBtns.java \
  Interface/ConstraintBtnsActionListener.java \
  Interface/DrawPanel.java \
  Interface/DPKeyListener.java \
  Interface/DPMouseMotionListener.java \
  Interface/ImageButton.java \
  Interface/ImageButtonImageObserver.java

COMPONENT_FILES = \
  Component/SelPoint.java \
  Component/EditConstantList.java \
  Component/ConstrComponent.java \
  Component/LineCC.java \
  Component/MidpointLineCC.java \
  Component/RectangleCC.java \
  Component/CircleCC.java \
  Component/CDA_G.java 

CONSTRAINT_FILES = \
  Constraint/AboveConstraint.java \
  Constraint/AdjacencyConstraint.java \
  Constraint/AlignmentConstraint.java \
  Constraint/AnchorConstraint.java \
  Constraint/BelowConstraint.java \
  Constraint/ColocationConstraint.java \
  Constraint/Constraint.java \
  Constraint/LeftOfConstraint.java \
  Constraint/RightOfConstraint.java

MAIN_FILES = \
  Main/Main.java \
  Main/MainComponentListener.java

ALL_FILES = $(INTERFACE_FILES) $(COMPONENT_FILES) $(CONSTRAINT_FILES) $(MAIN_FILES)


if HAVE_JAVA
java_JAVA = $(ALL_FILES)
else
classjava.stamp:
	echo timestamp > classjava.stamp

install-javaJAVA:
	echo "Not installing java .class files since Java build was disabled"
endif

ICON_BMPS = \
  LineCC.bmp \
  MidLineCC.bmp \
  RectangleCC.bmp \
  CircleCC.bmp \
  Anchor.bmp \
  Colocation.bmp \
  LeftOf.bmp \
  RightOf.bmp \
  Above.bmp \
  Below.bmp \
  LeftAlign.bmp \
  RightAlign.bmp \
  TopAlign.bmp \
  BottomAlign.bmp \
  Blank.bmp 


ALL_ICON_FILES = $(ICON_BMPS:%.bmp=Icons/%.bmp)

ICON_GIFS = $(ICON_BMPS:%.bmp=classes/%.gif)

EXTRA_DIST = $(ALL_FILES) $(ICON_GIFS) classes/run.html

demo: all
	tar -cf cdademo.tar $(ALL_CLASSES) $(ICON_GIFS) classes/*.htm*

run:
	cd classes && appletviewer run.html
