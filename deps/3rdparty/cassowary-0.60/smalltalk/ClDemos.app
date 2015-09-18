

Application create: #ClDemos with:
    (#( ClKernel)
        collect: [:each | Smalltalk at: each ifAbsent: [
            Application errorPrerequisite: #ClDemos missing: each]])!

ClDemos becomeDefault!
Object subclass: #ClDemoWindow
    instanceVariableNames: 'shell main form da gc gcw buffer grabPoint dragPoint cs errorPixel editX editY '
    classVariableNames: ''
    poolDictionaries: 'CwConstants CgConstants ClConstants '!

ClDemos becomeDefault!
ClDemoWindow subclass: #ClBinaryTreeDemo
    instanceVariableNames: 'nodes lines height '
    classVariableNames: ''
    poolDictionaries: ''!

ClDemos becomeDefault!
ClDemoWindow subclass: #ClBoundedLineDemo
    instanceVariableNames: 'p1 p2 '
    classVariableNames: ''
    poolDictionaries: ''!

ClDemos becomeDefault!
ClBoundedLineDemo subclass: #ClElasticBoundedLineDemo
    instanceVariableNames: ''
    classVariableNames: ''
    poolDictionaries: ''!

ClDemos becomeDefault!
ClDemoWindow subclass: #ClBoxesDemo
    instanceVariableNames: 'p1 p2 p3 p4 p5 '
    classVariableNames: ''
    poolDictionaries: ''!

ClDemos becomeDefault!
ClDemoWindow subclass: #ClCrossedQuadDemo
    instanceVariableNames: 'p1 p2 p3 p4 m1 m2 m3 m4 center '
    classVariableNames: ''
    poolDictionaries: ''!

ClDemos becomeDefault!
ClDemoWindow subclass: #ClLineDemo
    instanceVariableNames: 'p1 p2 '
    classVariableNames: ''
    poolDictionaries: ''!

ClDemos becomeDefault!
ClDemoWindow subclass: #ClMidpointDemo
    instanceVariableNames: 'p1 p2 m1 '
    classVariableNames: ''
    poolDictionaries: ''!

ClDemos becomeDefault!
ClDemoWindow subclass: #ClQuadDemo
    instanceVariableNames: 'p1 p2 p3 p4 m1 m2 m3 m4 '
    classVariableNames: ''
    poolDictionaries: ''!

ClDemos becomeDefault!
ClQuadDemo subclass: #ClBoundedQuadDemo
    instanceVariableNames: ''
    classVariableNames: ''
    poolDictionaries: ''!

ClDemos becomeDefault!
ClBoundedQuadDemo subclass: #ClElasticQuadDemo
    instanceVariableNames: ''
    classVariableNames: ''
    poolDictionaries: ''!

ClDemos becomeDefault!
Application subclass: #ClDemos
    instanceVariableNames: ''
    classVariableNames: ''
    poolDictionaries: ''!


ClDemos becomeDefault!

!ClBinaryTreeDemo class publicMethods !

height: h
		| demo |
	demo := self basicNew.
	demo height: h.
	demo initialize.
	^demo
! !

!ClBinaryTreeDemo publicMethods !

childrenAndParentsDo: block
	"evaluate a block for all children and parents, starting with leaves and going up the tree"
		| parentcount left right parent |
	height to: 2 by: -1 do: [:h |
		parentcount := 2 raisedTo: h-2.
		1 to: parentcount do: [:i | 
			left := nodes at: (100*h)+(2*i)-1.
			right := nodes at: (100*h)+(2*i).
			parent := nodes at: (100*(h-1))+i.
			block value: left value: right value: parent]]
!

constraintPointsDo: aBlock

	nodes do: [:each | aBlock value: each]!

createConstraints
		| sorted inset spacing winWidth winHeight root |

	"Add stays on each node.  Accumulate the nodes children first, so that the weights
		on the parents are stronger than those on the children."
	sorted := OrderedCollection new.
	self childrenAndParentsDo: [:lc :rc :p |
		(sorted includes: lc) ifFalse: [sorted add: lc].
		(sorted includes: rc) ifFalse: [sorted add: lc].
		root := p  "we need this at the end"].
	sorted add: root.
	cs addPointStays: sorted.

	inset := self inset.
	spacing := self spacing.
	winWidth := self initialExtent x.
	winHeight := self initialExtent y.
	self childrenAndParentsDo: [:lc :rc :p |
		"we need the root at the end"   root := p.
		"children are at equal height"
		cs addConstraint: (lc y cnEqual: rc y).
		"children are below parents"
		cs addConstraint: (p y + spacing cnLEQ: lc y).
		cs addConstraint: (p y + spacing cnLEQ: rc y).
		"parent is centered in the x coordinate between children"
		cs addConstraint: ( (0.5*lc x) + (0.5*rc x) cnEqual: p x).
		"each node lies within the window"
		cs addBounds: lc x lowerBound: inset upperBound: winWidth-inset.
		cs addBounds: rc x lowerBound: inset upperBound: winWidth-inset.
		cs addBounds: lc y lowerBound: inset upperBound: winHeight-inset.
		cs addBounds: rc y lowerBound: inset upperBound: winHeight-inset].
	cs addBounds: root x lowerBound: inset upperBound: winWidth-inset.
	cs addBounds: root y lowerBound: inset upperBound: winHeight-inset.
!

drawArea

	self setForegroundColor: 0.
	lines do: [:each |
		buffer
			drawLine: gc
			x1: each first x value rounded
			y1: each first y value rounded
			x2: each last x value rounded
			y2: each last y value rounded].
	self setForegroundColor: 5.
	nodes do: [:each |
		buffer
			fillRectangle: gc
			x: (each x value rounded - 5)
			y: (each y value rounded - 5)
			width: 10
			height: 10]!

height: h
	height := h!

initialExtent
	"ACTION
		Return the initial size for the overall window.
	"

	^500 @ 300!

initialize
		| xspace yspace index nleaves nodecount left right px |
	xspace :=20.  
	yspace := 20.

	super initialize.
	nodes := LookupTable new.
	
	"create the leaves"
	nleaves := 2 raisedTo: height-1.
	1 to: nleaves do: [:i | index := 100*height + i.  nodes at: index put: 
			((ClVariable newWith: (xspace*i) asFloat name: 'n' , index printString , 'x') @ 
			  (ClVariable newWith: (yspace*height) asFloat name: 'n' , index printString , 'y'))].

	"create the other nodes"
	height-1 to: 1 by: -1 do: [:h |
		nodecount := 2 raisedTo: h-1.
		1 to: nodecount do: [:i | 
			left := nodes at: (100*(h+1))+(2*i)-1.  
			right := nodes at: (100*(h+1))+(2*i).
			px := (left x value + right x value) * 0.5.
			index := 100*h+ i.  nodes at: index put: 
			((ClVariable newWith: px name: 'n' , index printString , 'x') @ 
			  (ClVariable newWith: yspace*h name: 'n' , index printString , 'y'))]].

	lines := OrderedCollection new.
	self childrenAndParentsDo: [:lc :rc :p | 
		lines add: (Array with: p with: lc).
		lines add: (Array with: p with: rc)].

	self createConstraints.
!

inset
	^10.0
!

spacing
	^10.0
!

title

	^'Binary Tree Demo'! !

!ClBoundedLineDemo publicMethods !

constraintPointsDo: aBlock

	aBlock value: p1.
	aBlock value: p2!

drawArea

	self setForegroundColor: 0.
	buffer
		drawLine: gc
		x1: p1 x value rounded
		y1: p1 y value rounded
		x2: p2 x value rounded
		y2: p2 y value rounded!

initialize
		| offset box left right top bottom |

	super initialize.
	p1 := (ClVariable newWith: 10.0 name: 'p1x') @ (ClVariable newWith: 20.0 name: 'p1y').
	p2 := (ClVariable newWith: 110.0 name: 'p2x') @ (ClVariable newWith: 220.0 name: 'p2y').

	offset := 10.0.
	box := 0 @ 0 corner: 300 @ 300.
	left := box origin x asFloat + offset.
	right := box corner x asFloat - offset.
	top := box origin y asFloat + offset.
	bottom := box corner y asFloat - offset.

	cs addStay: p1 x.
	cs addStay: p1 y.
	cs addStay: p2 x.
	cs addStay: p2 y.

	cs addConstraint: (p1 x cnGEQ: left).  cs addConstraint: (p1 x cnLEQ: right).
	cs addConstraint: (p1 y cnGEQ: top).  cs addConstraint: (p1 y cnLEQ: bottom).
	cs addConstraint: (p2 x cnGEQ: left).  cs addConstraint: (p2 x cnLEQ: right).
	cs addConstraint: (p2 y cnGEQ: top).  cs addConstraint: (p2 y cnLEQ: bottom).
!

title

	^'Bounded Line Demo'! !

!ClBoundedQuadDemo publicMethods !

addAdditionalConstraints

	| offset box left right top bottom |

	offset := 2.0.
	box := 0 @ 0 corner: 300 @ 300.
	left := box origin x asFloat + offset.
	right := box corner x asFloat - offset.
	top := box origin y asFloat + offset.
	bottom := box corner y asFloat - offset.

	cs addConstraint: (p1 x cnGEQ: left).  cs addConstraint: (p1 x cnLEQ: right).
	cs addConstraint: (p1 y cnGEQ: top).  cs addConstraint: (p1 y cnLEQ: bottom).
	cs addConstraint: (p2 x cnGEQ: left).  cs addConstraint: (p2 x cnLEQ: right).
	cs addConstraint: (p2 y cnGEQ: top).  cs addConstraint: (p2 y cnLEQ: bottom).
	cs addConstraint: (p3 x cnGEQ: left).  cs addConstraint: (p3 x cnLEQ: right).
	cs addConstraint: (p3 y cnGEQ: top).  cs addConstraint: (p3 y cnLEQ: bottom).
	cs addConstraint: (p4 x cnGEQ: left).  cs addConstraint: (p4 x cnLEQ: right).
	cs addConstraint: (p4 y cnGEQ: top).  cs addConstraint: (p4 y cnLEQ: bottom).
!

title

	^'Bounded Quadrilateral Demo'! !

!ClBoxesDemo publicMethods !

constraintPointsDo: aBlock

	aBlock value: p1.
	aBlock value: p2.
	aBlock value: p3.
	aBlock value: p4.
	aBlock value: p5!

drawArea

	self setForegroundColor: 12.
	buffer fillRectangle: gc x: p1 x value rounded - 20 y: 160 width: 40 height: 40.
	buffer fillRectangle: gc x: p2 x value rounded - 20 y: 160 width: 40 height: 40.
	buffer fillRectangle: gc x: p3 x value rounded - 20 y: 160 width: 40 height: 40.
	buffer fillRectangle: gc x: p4 x value rounded - 20 y: 160 width: 40 height: 40.
	buffer fillRectangle: gc x: p5 x value rounded - 20 y: 160 width: 40 height: 40!

initialExtent
	"ACTION
		Return the initial size for the overall window.
	"

	^600 @ 300!

initialize

	super initialize.
	p1 := (ClVariable newWith: 50.0) @ (ClVariable newWith: 200.0).
	p2 := (ClVariable newWith: 100.0) @ (ClVariable newWith: 200.0).
	p3 := (ClVariable newWith: 150.0) @ (ClVariable newWith: 200.0).
	p4 := (ClVariable newWith: 200.0) @ (ClVariable newWith: 200.0).
	p5 := (ClVariable newWith: 250.0) @ (ClVariable newWith: 200.0).

	p1 x name: 'p1x'.
	p1 y name: 'p1y'.
	p2 x name: 'p2x'.
	p2 y name: 'p2y'.
	p3 x name: 'p3x'.
	p3 y name: 'p3y'.
	p4 x name: 'p4x'.
	p4 y name: 'p4y'.
	p5 x name: 'p5x'.
	p5 y name: 'p5y'.

	cs addStay: p1 x.
	cs addStay: p2 x.
	cs addStay: p3 x.
	cs addStay: p4 x.
	cs addStay: p5 x.

	cs addStay: p1 y strength: ClStrength required.
	cs addStay: p2 y strength: ClStrength required.
	cs addStay: p3 y strength: ClStrength required.
	cs addStay: p4 y strength: ClStrength required.
	cs addStay: p5 y strength: ClStrength required.

	cs addConstraint: (p1 x cnGEQ: 24.0).
	cs addConstraint: (p5 x cnLEQ: 576.0).

	cs addConstraint: (p1 x + 44.0 cnLEQ: p2 x).
	cs addConstraint: (p2 x + 44.0 cnLEQ: p3 x).
	cs addConstraint: (p3 x + 44.0 cnLEQ: p4 x).
	cs addConstraint: (p4 x + 44.0 cnLEQ: p5 x).

!

title

	^'Boxcars Demo'! !

!ClCrossedQuadDemo publicMethods !

addAdditionalConstraints
	"no additional constraints for this version"
!

constraintPointsDo: aBlock

	aBlock value: p1.
	aBlock value: p2.
	aBlock value: p3.
	aBlock value: p4.

	aBlock value: m1.
	aBlock value: m2.
	aBlock value: m3.
	aBlock value: m4.

	aBlock value: center!

drawArea

	self setForegroundColor: 0.

	"draw the four sides of the quadrilateral"
	buffer
		drawLine: gc
		x1: p1 x value rounded
		y1: p1 y value rounded
		x2: p2 x value rounded
		y2: p2 y value rounded.
	buffer
		drawLine: gc
		x1: p2 x value rounded
		y1: p2 y value rounded
		x2: p3 x value rounded
		y2: p3 y value rounded.
	buffer
		drawLine: gc
		x1: p3 x value rounded
		y1: p3 y value rounded
		x2: p4 x value rounded
		y2: p4 y value rounded.
	buffer
		drawLine: gc
		x1: p4 x value rounded
		y1: p4 y value rounded
		x2: p1 x value rounded
		y2: p1 y value rounded.

	"draw the lines between the midpoints"
	buffer
		drawLine: gc
		x1: m1 x value rounded
		y1: m1 y value rounded
		x2: m2 x value rounded
		y2: m2 y value rounded.
	buffer
		drawLine: gc
		x1: m2 x value rounded
		y1: m2 y value rounded
		x2: m3 x value rounded
		y2: m3 y value rounded.
	buffer
		drawLine: gc
		x1: m3 x value rounded
		y1: m3 y value rounded
		x2: m4 x value rounded
		y2: m4 y value rounded.
	buffer
		drawLine: gc
		x1: m4 x value rounded
		y1: m4 y value rounded
		x2: m1 x value rounded
		y2: m1 y value rounded.

	"draw the cross lines"
	buffer
		drawLine: gc
		x1: m1 x value rounded
		y1: m1 y value rounded
		x2: m3 x value rounded
		y2: m3 y value rounded.
	buffer
		drawLine: gc
		x1: m2 x value rounded
		y1: m2 y value rounded
		x2: m4 x value rounded
		y2: m4 y value rounded!

initialize

	super initialize.
	p1 := (ClVariable newWith: 110.0) @ (ClVariable newWith: 10.0).
	p2 := (ClVariable newWith: 210.0) @ (ClVariable newWith: 110.0).
	p3 := (ClVariable newWith: 110.0) @ (ClVariable newWith: 210.0).
	p4 := (ClVariable newWith: 10.0) @ (ClVariable newWith: 110.0).

	m1 := (ClVariable newWith: 160.0) @ (ClVariable newWith: 60.0).
	m2 := (ClVariable newWith: 160.0) @ (ClVariable newWith: 160.0).
	m3 := (ClVariable newWith: 60.0) @ (ClVariable newWith: 160.0).
	m4 := (ClVariable newWith: 60.0) @ (ClVariable newWith: 60.0).

	center := (ClVariable newWith: 110.0) @ (ClVariable newWith: 110.0).

	p1 x name: 'p1x'.
	p1 y name: 'p1y'.
	p2 x name: 'p2x'.
	p2 y name: 'p2y'.
	p3 x name: 'p3x'.
	p3 y name: 'p3y'.
	p4 x name: 'p4x'.
	p4 y name: 'p4y'.

	m1 x name: 'm1x'.
	m1 y name: 'm1y'.
	m2 x name: 'm2x'.
	m2 y name: 'm2y'.
	m3 x name: 'm3x'.
	m3 y name: 'm3y'.
	m4 x name: 'm4x'.
	m4 y name: 'm4y'.

	center x name: 'cx'.
	center y name: 'cy'.

	"add stays on the corner points"
	cs addPointStays: (Array with: p1 with: p2 with: p3 with: p4).

	"set up the midpoint constraints"
	cs addConstraint: (p1 x + p2 x cnEqual: 2.0 * m1 x).
	cs addConstraint: (p2 x + p3 x cnEqual: 2.0 * m2 x).
	cs addConstraint: (p3 x + p4 x cnEqual: 2.0 * m3 x).
	cs addConstraint: (p4 x + p1 x cnEqual: 2.0 * m4 x).
	cs addConstraint: (p1 y + p2 y cnEqual: 2.0 * m1 y).
	cs addConstraint: (p2 y + p3 y cnEqual: 2.0 * m2 y).
	cs addConstraint: (p3 y + p4 y cnEqual: 2.0 * m3 y).
	cs addConstraint: (p4 y + p1 y cnEqual: 2.0 * m4 y).

	"set up the centerpoint constraints"
	cs addConstraint: (m1 x + m3 x cnEqual: 2.0 * center x).
	cs addConstraint: (m1 y + m3 y cnEqual: 2.0 * center y).
	cs addConstraint: (m2 x + m4 x cnEqual: 2.0 * center x).
	cs addConstraint: (m2 y + m4 y cnEqual: 2.0 * center y).

	self addAdditionalConstraints.
!

title

	^'Crossed Quadrilateral Demo'! !

!ClDemoWindow class publicMethods !

makeDemos

	"statements to build various demos"

	ClBoundedLineDemo new open.
	ClElasticBoundedLineDemo new open.
	ClQuadDemo new open.
	ClMidpointDemo new open.
	ClBoundedQuadDemo new open.
	ClCrossedQuadDemo new open.
	ClElasticQuadDemo new open.
	ClTreeDemo1 new open.
	ClTreeDemo2 new open.
	ClBoxesDemo new open.
	ClSequenceDiagramDemo1 new open.
	(ClBinaryTreeDemo height: 4) open.
!

new

	^super new initialize! !

!ClDemoWindow publicMethods !

beginManipulation
	"ACTION
		This method is called when a constrainable point is starting to
		be manipulated, i.e., upon mouse down.  The constrainable
		point is stored in the 'dragPoint' instance variable, and the
		corresponding plan for moving that point is stored in the 'plan'
		instance variable.

		The order of messages is:
			1. #beginManipulation
			2-N. #manipulationMoveTo:
			N+1. #endManipulation
	"

	self constraintPointsDo: [:p |
		dragPoint == p ifTrue: [
			cs addEditVar: p x strength: ClStrength strong.
			cs addEditVar: p y strength: ClStrength strong.
			cs beginEdit.
			^nil]].

	 "drag point not found"
	self error 
!

button1Motion: aWidget clientData: clientData callData: callData

	dragPoint isNil ifTrue: [^self].
	self manipulationMoveTo: callData point!

buttonPress: aWidget clientData: clientData callData: callData

	grabPoint isNil ifTrue: [^self].
	self drawGrabBox.
	dragPoint := grabPoint.
	grabPoint := nil.

	self beginManipulation!

buttonRelease: aWidget clientData: clientData callData: callData

	dragPoint isNil ifTrue: [^self].
	dragPoint := nil.

	self endManipulation!

constraintPointsDo: aBlock
	"ACTION
		Evaluate this block for each of the constrainable points in this demo.
		Constrainable points are those that can be manipulated by the mouse.
		A constraint point is a Point object whose x and y instance variables
		hold instances of ClVariable.

	PARAMETERS
		aBlock <[:<Point of <ClVariable>> | ...]>
	"
!

createForm

	da := form createDrawingArea: 'da' argBlock: nil.
	da manageChild.
	da setValuesBlock: [:w |
		w
			bottomAttachment: XmATTACHFORM;
			topAttachment: XmATTACHFORM;
			rightAttachment: XmATTACHFORM;
			leftAttachment: XmATTACHFORM].
	da
		addCallback: XmNexposeCallback
			receiver: self
			selector: #exposeArea:clientData:callData:
			clientData: nil;
		addCallback: XmNresizeCallback
			receiver: self
			selector: #resizeArea:clientData:callData:
			clientData: nil;
		addEventHandler: Button1MotionMask
			receiver: self
			selector: #button1Motion:clientData:callData:
			clientData: nil;
		addEventHandler: ButtonPressMask
			receiver: self
			selector: #buttonPress:clientData:callData:
			clientData: nil;
		addEventHandler: ButtonReleaseMask
			receiver: self
			selector: #buttonRelease:clientData:callData:
			clientData: nil;
		addEventHandler: PointerMotionMask
			receiver: self
			selector: #pointerMotion:clientData:callData:
			clientData: nil!

createWindow

	shell :=
		CwTopLevelShell
			createApplicationShell: 'shell'
			argBlock: [:w |
				w
					title: self title;
					width: self initialExtent x;
					height: self initialExtent y].
	main := shell createMainWindow: 'main' argBlock: nil.
	main manageChild.
	form := main createForm: 'form' argBlock: nil.
	form manageChild.
	shell
		addCallback: XmNdestroyCallback
		receiver: self
		selector: #destroyWindow:clientData:callData:
		clientData: nil.
	self createForm!

destroy
	"ACTION
		This method is called when the window is closing.
	"
!

destroyWindow: aWidget clientData: clientData callData: callData

	gc isNil
		ifFalse: [
			gc freeGC.
			gc := nil].
	gcw isNil
		ifFalse: [
			gcw freeGC.
			gcw := nil].
	buffer isNil
		ifFalse: [
			buffer freePixmap.
			buffer := nil].
	self destroy!

drawArea
	"ACTION
		Draw the demo.
	"
!

drawBackground
	"ACTION
		Draw the background of the demo.
	"

	gc setForeground: 15.
	buffer fillRectangle: gc x: 0 y: 0 width: buffer width height: buffer height!

drawGrabBox

	| r pv |

	pv := grabPoint x value rounded @ grabPoint y value rounded.
	gcw
		setFunction: GXhighlight;
		setLineAttributes: 3 lineStyle: LineSolid capStyle: CapButt joinStyle: JoinMiter;
		setForeground: 0.
	r := (pv - self grabThreshold) corner: (pv + self grabThreshold).
	da window drawRectangle: gcw x: r origin x y: r origin y width: r width height: r height.
	gcw setFunction: GXcopy!

endManipulation
	"ACTION
		This method is called when a constrainable point is ending
		being manipulated, i.e., upon mouse up.  The constrainable
		point is stored in the 'dragPoint' instance variable, and the
		corresponding plan for moving that point is stored in the 'plan'
		instance variable.

		The order of messages is:
			1. #beginManipulation
			2-N. #manipulationMoveTo:
			N+1. #endManipulation
	"
	cs endEdit.
	self redraw.
!

exposeArea: aWidget clientData: clientData callData: callData

	buffer isNil ifTrue: [self resizeArea: aWidget clientData: clientData callData: nil].
	buffer
		copyArea: aWidget window
		gc: gcw
		srcX: 0
		srcY: 0
		width: buffer width
		height: buffer height
		destX: 0
		destY: 0.
	grabPoint := nil!

grabThreshold

	^7 @ 7!

initialExtent
	"ACTION
		Return the initial size for the overall window.
	"

	^300 @ 300!

initialize
	"ACTION
		Initialize the demo structures before the widgets are created.
	"

	cs := ClSimplexSolver new.
	errorPixel := nil

!

manipulationMoveTo: aPoint
	"ACTION
		This method is called when a constrainable point is manipulated
		using the mouse, i.e., during mouse motion.  aPoint is the
		location of the mouse and thus the new requested location of
		the constrainable point.  The constrainable
		point is stored in the 'dragPoint' instance variable, and the
		corresponding plan for moving that point is stored in the 'plan'
		instance variable.

		The order of messages is:
			1. #beginManipulation
			2-N. #manipulationMoveTo:
			N+1. #endManipulation

	PARAMETERS
		aPoint <Point of <Number>>
	"
	cs suggestValue: dragPoint x newValue: aPoint x asFloat.
	cs suggestValue: dragPoint y newValue: aPoint y asFloat.
	cs resolve.
	self redraw
!

open

	self createWindow.
	shell realizeWidget!

pointerMotion: aWidget clientData: clientData callData: callData

	| r |

	dragPoint isNil
		ifTrue: [
			self constraintPointsDo: [:p | | pv th |
				th := self grabThreshold * 2.
				pv := p x value rounded @ p y value rounded.
				(((pv - th) corner: (pv + th)) containsPoint: callData point)
					ifTrue: [
						grabPoint == p ifTrue: [^self].
						grabPoint notNil ifTrue: [self drawGrabBox].
						grabPoint := p.
						self drawGrabBox.
						^self].
				grabPoint notNil ifTrue: [self drawGrabBox].
				grabPoint := nil]]!

redraw

	self drawBackground.
	self drawArea.
	self exposeArea: da clientData: nil callData: nil!

resizeArea: aWidget clientData: clientData callData: callData

	buffer isNil
		ifFalse: [
			buffer freePixmap.
			buffer := nil].
	gc isNil
		ifFalse: [
			gc freeGC.
			gc := nil].
	gcw isNil ifTrue: [gcw := aWidget window createGC: None values: nil].
	buffer :=
		aWidget window createPixmap: aWidget width height: aWidget height depth: aWidget window depth.
	gc := buffer createGC: None values: nil.
	self drawBackground.
	self drawArea!

setForegroundColor: c

	gc setForeground: (errorPixel isNil ifTrue: [c] ifFalse: [errorPixel])

!

title
	"ACTION
		Return the title for the overall window.
	"

	^'demo'! !

!ClElasticBoundedLineDemo publicMethods !

initialize

	super initialize.
	cs addConstraint: (p2 y - p1 y cnEqual: 200.0 strength: ClStrength medium).
! !

!ClElasticQuadDemo publicMethods !

addAdditionalConstraints

	super addAdditionalConstraints.
	"add constraints to keep it from turning inside out"
	cs addConstraint: (p4 x+10 cnLEQ: p3 x).
	cs addConstraint: (p4 x+10 cnLEQ: p1 x).
	cs addConstraint: (p3 x+10 cnLEQ: p2 x).
	cs addConstraint: (p1 x+10 cnLEQ: p2 x).

	cs addConstraint: (p1 y+10 cnLEQ: p2 y).
	cs addConstraint: (p1 y+10 cnLEQ: p4 y).
	cs addConstraint: (p4 y+10 cnLEQ: p3 y).
	cs addConstraint: (p2 y+10 cnLEQ: p3 y).

	"add medium constraints to keep the quadrilateral's original shape"
	cs addConstraint: (p2 y cnEqual: p4 y strength: ClStrength medium).
	cs addConstraint: (p2 x - p4 x cnEqual: 200.0 strength: ClStrength medium).
	cs addConstraint: (p1 x cnEqual: p3 x strength: ClStrength medium).
	cs addConstraint: (p3 y - p1 y cnEqual: 200.0 strength: ClStrength medium).
!

title

	^'Elastic Quadrilateral Demo'! !

!ClLineDemo publicMethods !

constraintPointsDo: aBlock

	aBlock value: p1.
	aBlock value: p2!

drawArea

	self setForegroundColor: 0.
	buffer
		drawLine: gc
		x1: p1 x value rounded
		y1: p1 y value rounded
		x2: p2 x value rounded
		y2: p2 y value rounded!

initialize

	super initialize.
	p1 := (ClVariable newWith: 10.0 name: 'p1x') @ (ClVariable newWith: 20.0 name: 'p1y').
	p2 := (ClVariable newWith: 110.0 name: 'p2x') @ (ClVariable newWith: 220.0 name: 'p2y').
	cs addStay: p1 x.
	cs addStay: p1 y.
	cs addStay: p2 x.
	cs addStay: p2 y.
!

title

	^'Line Demo'! !

!ClMidpointDemo publicMethods !

constraintPointsDo: aBlock

	aBlock value: p1.
	aBlock value: p2.
	aBlock value: m1.
!

drawArea

	self setForegroundColor: 0.

	buffer
		drawLine: gc
		x1: p1 x value rounded
		y1: p1 y value rounded
		x2: p2 x value rounded
		y2: p2 y value rounded.
	buffer
		drawLine: gc
		x1: m1 x value rounded
		y1: m1 y value rounded -1
		x2: m1 x value rounded
		y2: m1 y value rounded +1.!

initialize

	super initialize.
	p1 := (ClVariable newWith: 100.0) @ (ClVariable newWith: 100.0).
	p2 := (ClVariable newWith: 200.0) @ (ClVariable newWith: 100.0).
	m1 := (ClVariable newWith: 150.0) @ (ClVariable newWith: 100.0).

	p1 x name: 'p1x'.
	p1 y name: 'p1y'.
	p2 x name: 'p2x'.
	p2 y name: 'p2y'.
	m1 x name: 'm1x'.
	m1 y name: 'm1y'.

	"add stays on the corner points"
	cs addPointStays: (Array with: p1 with: p2).

	"set up the midpoint constraints"
	cs addConstraint: (p1 x + p2 x cnEqual: 2.0 * m1 x).
	cs addConstraint: (p1 y + p2 y cnEqual: 2.0 * m1 y).!

title

	^'Midpoint Demo'! !

!ClQuadDemo publicMethods !

addAdditionalConstraints
	"no additional constraints for this version"
!

constraintPointsDo: aBlock

	aBlock value: p1.
	aBlock value: p2.
	aBlock value: p3.
	aBlock value: p4.

	aBlock value: m1.
	aBlock value: m2.
	aBlock value: m3.
	aBlock value: m4!

drawArea

	self setForegroundColor: 0.

	"draw the four sides of the quadrilateral"
	buffer
		drawLine: gc
		x1: p1 x value rounded
		y1: p1 y value rounded
		x2: p2 x value rounded
		y2: p2 y value rounded.
	buffer
		drawLine: gc
		x1: p2 x value rounded
		y1: p2 y value rounded
		x2: p3 x value rounded
		y2: p3 y value rounded.
	buffer
		drawLine: gc
		x1: p3 x value rounded
		y1: p3 y value rounded
		x2: p4 x value rounded
		y2: p4 y value rounded.
	buffer
		drawLine: gc
		x1: p4 x value rounded
		y1: p4 y value rounded
		x2: p1 x value rounded
		y2: p1 y value rounded.

	"draw the lines between the midpoints"
	buffer
		drawLine: gc
		x1: m1 x value rounded
		y1: m1 y value rounded
		x2: m2 x value rounded
		y2: m2 y value rounded.
	buffer
		drawLine: gc
		x1: m2 x value rounded
		y1: m2 y value rounded
		x2: m3 x value rounded
		y2: m3 y value rounded.
	buffer
		drawLine: gc
		x1: m3 x value rounded
		y1: m3 y value rounded
		x2: m4 x value rounded
		y2: m4 y value rounded.
	buffer
		drawLine: gc
		x1: m4 x value rounded
		y1: m4 y value rounded
		x2: m1 x value rounded
		y2: m1 y value rounded


!

initialize

	super initialize.
	p1 := (ClVariable newWith: 110.0) @ (ClVariable newWith: 10.0).
	p2 := (ClVariable newWith: 210.0) @ (ClVariable newWith: 110.0).
	p3 := (ClVariable newWith: 110.0) @ (ClVariable newWith: 210.0).
	p4 := (ClVariable newWith: 10.0) @ (ClVariable newWith: 110.0).

	m1 := (ClVariable newWith: 160.0) @ (ClVariable newWith: 60.0).
	m2 := (ClVariable newWith: 160.0) @ (ClVariable newWith: 160.0).
	m3 := (ClVariable newWith: 60.0) @ (ClVariable newWith: 160.0).
	m4 := (ClVariable newWith: 60.0) @ (ClVariable newWith: 60.0).

	p1 x name: 'p1x'.
	p1 y name: 'p1y'.
	p2 x name: 'p2x'.
	p2 y name: 'p2y'.
	p3 x name: 'p3x'.
	p3 y name: 'p3y'.
	p4 x name: 'p4x'.
	p4 y name: 'p4y'.

	m1 x name: 'm1x'.
	m1 y name: 'm1y'.
	m2 x name: 'm2x'.
	m2 y name: 'm2y'.
	m3 x name: 'm3x'.
	m3 y name: 'm3y'.
	m4 x name: 'm4x'.
	m4 y name: 'm4y'.

	"add stays on the corner points"
	cs addPointStays: (Array with: p1 with: p2 with: p3 with: p4).

	"set up the midpoint constraints"
	cs addConstraint: (p1 x + p2 x cnEqual: 2.0 * m1 x).
	cs addConstraint: (p2 x + p3 x cnEqual: 2.0 * m2 x).
	cs addConstraint: (p3 x + p4 x cnEqual: 2.0 * m3 x).
	cs addConstraint: (p4 x + p1 x cnEqual: 2.0 * m4 x).
	cs addConstraint: (p1 y + p2 y cnEqual: 2.0 * m1 y).
	cs addConstraint: (p2 y + p3 y cnEqual: 2.0 * m2 y).
	cs addConstraint: (p3 y + p4 y cnEqual: 2.0 * m3 y).
	cs addConstraint: (p4 y + p1 y cnEqual: 2.0 * m4 y).

	self addAdditionalConstraints.
!

title

	^'Quadrilateral Demo'! !

ClDemoWindow initializeAfterLoad!
ClBinaryTreeDemo initializeAfterLoad!
ClBoundedLineDemo initializeAfterLoad!
ClElasticBoundedLineDemo initializeAfterLoad!
ClBoxesDemo initializeAfterLoad!
ClCrossedQuadDemo initializeAfterLoad!
ClLineDemo initializeAfterLoad!
ClMidpointDemo initializeAfterLoad!
ClQuadDemo initializeAfterLoad!
ClBoundedQuadDemo initializeAfterLoad!
ClElasticQuadDemo initializeAfterLoad!
ClDemos initializeAfterLoad!

ClDemos loaded!