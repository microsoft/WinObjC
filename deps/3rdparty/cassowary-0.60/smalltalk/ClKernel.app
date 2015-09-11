

"$COMPATIBLE-DECLARATIONS-START$"
Smalltalk declarePoolDictionary: 'ClConstants'.
Smalltalk declareVariable: 'ExCLError' poolName: 'ClConstants'.
Smalltalk declareVariable: 'ExCLInternalError' poolName: 'ClConstants'.
Smalltalk declareVariable: 'ExCLNotEnoughStays' poolName: 'ClConstants'.
Smalltalk declareVariable: 'ExCLRequiredFailure' poolName: 'ClConstants'.
Smalltalk declareVariable: 'ExCLTooDifficult' poolName: 'ClConstants'.
Smalltalk declareVariable: 'ExCLNonlinearExpression' poolName: 'ClConstants'.
Smalltalk declareVariable: 'ClEpsilon' poolName: 'ClConstants'.
"$COMPATIBLE-DECLARATIONS-END$"!

Application create: #ClKernel with:
    (#( Kernel)
        collect: [:each | Smalltalk at: each ifAbsent: [
            Application errorPrerequisite: #ClKernel missing: each]])!

ClKernel becomeDefault!
Object subclass: #ClAbstractVariable
    instanceVariableNames: 'name '
    classVariableNames: ''
    poolDictionaries: 'ClConstants '!

ClKernel becomeDefault!
ClAbstractVariable subclass: #ClDummyVariable
    instanceVariableNames: ''
    classVariableNames: ''
    poolDictionaries: ''!

ClKernel becomeDefault!
ClAbstractVariable subclass: #ClObjectiveVariable
    instanceVariableNames: ''
    classVariableNames: ''
    poolDictionaries: ''!

ClKernel becomeDefault!
ClAbstractVariable subclass: #ClSlackVariable
    instanceVariableNames: ''
    classVariableNames: ''
    poolDictionaries: ''!

ClKernel becomeDefault!
ClAbstractVariable subclass: #ClVariable
    instanceVariableNames: 'value '
    classVariableNames: ''
    poolDictionaries: ''!

ClKernel becomeDefault!
Object subclass: #ClConstraint
    instanceVariableNames: 'strength weight '
    classVariableNames: ''
    poolDictionaries: 'ClConstants '!

ClKernel becomeDefault!
ClConstraint subclass: #ClEditOrStayConstraint
    instanceVariableNames: 'variable '
    classVariableNames: ''
    poolDictionaries: ''!

ClKernel becomeDefault!
ClEditOrStayConstraint subclass: #ClEditConstraint
    instanceVariableNames: ''
    classVariableNames: ''
    poolDictionaries: ''!

ClKernel becomeDefault!
ClEditOrStayConstraint subclass: #ClStayConstraint
    instanceVariableNames: ''
    classVariableNames: ''
    poolDictionaries: ''!

ClKernel becomeDefault!
ClConstraint subclass: #ClLinearConstraint
    instanceVariableNames: 'expression '
    classVariableNames: ''
    poolDictionaries: ''!

ClKernel becomeDefault!
ClLinearConstraint subclass: #ClLinearEquation
    instanceVariableNames: ''
    classVariableNames: ''
    poolDictionaries: ''!

ClKernel becomeDefault!
ClLinearConstraint subclass: #ClLinearInequality
    instanceVariableNames: ''
    classVariableNames: ''
    poolDictionaries: ''!

ClKernel becomeDefault!
Object subclass: #ClLinearExpression
    instanceVariableNames: 'constant terms '
    classVariableNames: ''
    poolDictionaries: 'ClConstants '!

ClKernel becomeDefault!
Object subclass: #ClSimplexSolver
    instanceVariableNames: 'rows columns objective infeasibleRows stayPlusErrorVars stayMinusErrorVars editVars editConstraints editPlusErrorVars editMinusErrorVars prevEditConstants newEditConstants markerVars errorVars slackCounter artificialCounter dummyCounter '
    classVariableNames: ''
    poolDictionaries: 'ClConstants '!

ClKernel becomeDefault!
Object subclass: #ClStrength
    instanceVariableNames: 'name symbolicWeight '
    classVariableNames: 'MediumStrength RequiredStrength StrongStrength WeakStrength '
    poolDictionaries: ''!

ClKernel becomeDefault!
Object variableSubclass: #ClSymbolicWeight
    instanceVariableNames: ''
    classVariableNames: 'Zero '
    poolDictionaries: 'ClConstants '!

ClKernel becomeDefault!
Application subclass: #ClKernel
    instanceVariableNames: ''
    classVariableNames: ''
    poolDictionaries: 'ClConstants '!


ClKernel becomeDefault!

!ClAbstractVariable class publicMethods !

newNamed: n
	"ACTION
		Create a new variable named n.

	PARAMETERS
		n <String>

	RETURNS
		new
	"

	^self new
		name: n;
		yourself! !

!ClAbstractVariable publicMethods !

isDummy
	"ACTION
		Return true if this a dummy variable (used as a marker variable for required equality constraints).  Such 
		variables aren't allowed to enter the basis when pivoting.

	RETURNS
		<Boolean>
	"

	^false
!

isExternal
	"ACTION
		Return true if this a variable known outside the solver.  (We need to give such variables a value after solving
		is complete.)

	RETURNS
		<Boolean>
	"

	self subclassResponsibility
!

isPivotable
	"ACTION
		Return true if we can pivot on this variable.

	RETURNS
		<Boolean>
	"

	self subclassResponsibility
!

isRestricted
	"ACTION
		Return true if this is a restricted (or slack) variable.  Such variables are constrained to be 
		non-negative and occur only internally to the simplex solver.

	RETURNS
		<Boolean>
	"

	self subclassResponsibility
!

name
	"RETURNS
		<String> | nil
	"
	^name!

name: n
	"PARAMETERS
		n <String>
	"
	name := n!

printOn: aStream
	"ACTION
		Prints a semi-descriptive representation to the stream, using the
		name if there is one, and otherwise the hash number of this object.

	EXAMPLES
		x[10.0]					- - w/ name
		x[0.0,100]			-- w/ name, bounds but no value yet
		CV#345(10.0)		- - w/o name

	PARAMETERS
		aStream <WriteStream on <String>>
	"

	self name isNil
		ifTrue: [aStream nextPutAll: 'CV#' , self basicHash printString]
		ifFalse: [aStream nextPutAll: self name].
! !

!ClConstraint publicMethods !

expression
	"ACTION
		Return my linear expression.  (For linear equations, this constraint represents
		expression=0; for linear inequalities it represents expression>=0.)
	RETURNS
		<ClLinearExpression>
	"
	self subclassResponsibility
!

isEditConstraint
	"RETURNS
		<Boolean>
	"
	^false
!

isInequality
	"ACTION
		Return true if this is an inequality constraint and false if it is an equality constraint.  The default is that it is not.
	RETURNS
		<Boolean>
	"
	^false
!

isRequired
	"ACTION
		Return true if my strength is 'required'.

	RETURNS
		<Boolean>
	"

	^self strength isRequired!

isStayConstraint
	"RETURNS
		<Boolean>
	"
	^false
!

strength
	"RETURNS
		<ClStrength>
	"

	^strength!

weight
	"RETURNS
		<Float>
	"

	^weight
! !

!ClConstraint privateMethods !

strength: s
	"PARAMETERS
		s <ClStrength>
	"

	strength := s!

weight: w
	"PARAMETERS
		w <Float>
	"

	weight := w
! !

!ClDummyVariable publicMethods !

isDummy
	"ACTION
		Return true if this a dummy variable (used as a marker variable for required equality constraints).  Such 
		variables aren't allowed to enter the basis when pivoting.

	RETURNS
		<Boolean>
	"

	^true
!

isExternal
	"ACTION
		Return true if this a variable known outside the solver.  (We need to give such variables a value after solving
		is complete.)

	RETURNS
		<Boolean>
	"

	^false
!

isPivotable
	"ACTION
		Return true if we can pivot on this variable.

	RETURNS
		<Boolean>
	"

	^false
!

isRestricted
	"ACTION
		Return true if this is a restricted (or slack) variable.  Such variables are constrained to be 
		non-negative and occur only internally to the simplex solver.

	RETURNS
		<Boolean>
	"

	^true
! !

!ClEditConstraint class publicMethods !

variable: aVariable value: aValue strength: aStrength

	^(self variable: aVariable strength: aStrength)
		value: aValue;
		yourself! !

!ClEditConstraint publicMethods !

isEditConstraint
	"RETURNS
		<Boolean>
	"
	^true
! !

!ClEditOrStayConstraint class publicMethods !

variable: v strength: s
	^self variable: v strength: s weight: 1.0
!

variable: v strength: s weight: w
		| cn |
	cn := self new.
	cn variable: v; strength: s; weight: w.
	^cn
! !

!ClEditOrStayConstraint publicMethods !

expression
		| e |
	e := ClLinearExpression new.
	e constant: self variable value.
	e terms at: self variable put: -1.0.
	^e
!

variable
	^variable
! !

!ClEditOrStayConstraint privateMethods !

variable: v
	variable := v
! !

!ClKernel class publicMethods !

_PRAGMA_ClConstants

	"%%PRAGMA DECLARE  
		(name: ClConstants isPool: true isConstant: false)
		(name: ExCLError pool: ClConstants)
		(name: ExCLInternalError pool: ClConstants)
		(name: ExCLNotEnoughStays pool: ClConstants)
		(name: ExCLRequiredFailure pool: ClConstants)
		(name: ExCLTooDifficult pool: ClConstants)
		(name: ExCLNonlinearExpression pool: ClConstants)
		(name: ClEpsilon pool: ClConstants)
	"!

initializeExceptions
	"ACTION
		Note that a variable must be declared for each exception to reside
		in.  The variables are declared in the toBeLoadedCode.
	"

	ExCLError isNil
		ifTrue: [
			ExCLError :=
				(ExError newChild)
					description: '(ExCLError) An error has occured in CL';
					yourself].
	ExCLInternalError isNil
		ifTrue: [ 
			ExCLInternalError :=
				(ExCLError newChild)
					description: '(ExCLInternalError) An internal error has occurred';
					yourself].
	ExCLTooDifficult isNil
		ifTrue: [
			ExCLTooDifficult :=
				(ExCLError newChild)
					description: '(ExCLTooDifficult) The constraints are too difficult to solve';
					yourself].
	ExCLRequiredFailure isNil
		ifTrue: [
			ExCLRequiredFailure :=
				(ExCLError newChild)
					description: '(ExCLRequiredFailure) A required constraint cannot be satisfied';
					yourself].
	ExCLNotEnoughStays isNil
		ifTrue: [
			ExCLNotEnoughStays :=
				(ExCLError newChild)
					description: '(ExCLNotEnoughStays) There are not enough stays to give specific values to every variable';
					yourself].
	ExCLNonlinearExpression isNil
		ifTrue: [
			ExCLNonlinearExpression :=
				(ExCLError newChild)
					description: '(ExCLNonlinearExpression) The resulting expression would be nonlinear';
					yourself].
!

loaded
	"ACTION
		Set up the exceptions.
	"
	super loaded.
	self initializeExceptions.
	self setEpsilon.

!

setEpsilon
	"ACTION
		Set the shared fudge factor for use in testing floats for equality, symbolic weights for
		non-negativity, etc.  This could be changed if an application uses numbers with a very
		different scale.
	"
	ClEpsilon := 1.0e-8.


! !

!ClLinearConstraint publicMethods !

expression
	"ACTION
		Return my linear expression.  (For linear equations, this constraint represents
		expression=0; for linear inequalities it represents expression>=0.)
	RETURNS
		<ClLinearExpression>
	"
	^expression
! !

!ClLinearConstraint privateMethods !

expression: expr
	expression := expr
! !

!ClLinearEquation publicMethods !

printOn: strm
	self strength printOn: strm.
	strm nextPutAll: '('.
	expression printOn: strm.
	strm nextPutAll: '=0)'.
! !

!ClLinearExpression class publicMethods !

new

	^super new
		initialize;
		yourself!

newWithSymbolicWeight
		| x |
	x := self new.
	x constant: ClSymbolicWeight zero.
	^x
! !

!ClLinearExpression publicMethods !

* x
	"ACTION
		Return a new linear expression formed by multiplying self by x.  (Note that this result must be linear.)

	RETURNS
		<ClLinearExpression>
	"
		| expr n result |
	"if this expression is just a constant then we can just multiply by it"
	self isConstant ifTrue: [^x*self constant].
	"otherwise multiply by x"
	x isNumber ifTrue: [n := x asFloat]
		ifFalse: [expr := x asLinearExpression.
			x isConstant ifFalse: [ExCLNonlinearExpression signal  "result would be non-linear"].
			n := x constant].
	result := ClLinearExpression new.
	result constant: n*self constant.
	self terms keysAndValuesDo: [:v :c | result terms at: v put: n*c].
	^result
!

+ x
	"ACTION
		Return a new linear expression formed by adding x to self.

	RETURNS
		<ClLinearExpression>
	"
		| expr result |
	expr := x asLinearExpression.
	"make a new linear expression to hold the result"
	result := ClLinearExpression new.
	result constant: self constant + expr constant.
	self terms keysAndValuesDo: [:v :c | result terms at: v put: c].
	expr variablesAndCoefficientsDo: [:v :c | result addVariable: v coefficient: c].
	^result
!

- x
	"ACTION
		Return a new linear expression formed by subtracting x from self.

	RETURNS
		<ClLinearExpression>
	"
		| expr result |
	expr := x asLinearExpression.
	"make a new linear expression to hold the result"
	result := ClLinearExpression new.
	result constant: self constant - expr constant.
	self terms keysAndValuesDo: [:v :c | result terms at: v put: c].
	expr variablesAndCoefficientsDo: [:v :c | result addVariable: v coefficient: 0.0-c].
	^result
!

/ x
	"ACTION
		Return a new linear expression formed by dividing self by x.  (Note that this result must be linear.)

	RETURNS
		<ClLinearExpression>
	"
		| expr |
	expr := x asLinearExpression.
	expr isConstant ifFalse: [ExCLNonlinearExpression signal  "result would be non-linear"].
	^self * (1.0/expr constant)
!

addExpression: expr times: n
	"ACTION
		Add n*expr to this expression for another expression expr.

	PARAMETERS
		expr <ClLinearExpression>
		n <Number>
	"
	self incrementConstant: n*expr constant.
	expr terms keysAndValuesDo: [:v :c |
		self addVariable: v coefficient: n*c].
!

addExpression: expr times: n subject: subject solver: solver
	"ACTION
		Add n*expr to this expression for another expression expr.  Notify the solver if
		a variable is added or deleted from this expression.

	PARAMETERS
		expr <ClLinearExpression>
		n <Number>
		subject: <ClAbstractVariable>
		solver <ClSimplexSolver | nil>
	"
	self incrementConstant: n*expr constant.
	expr terms keysAndValuesDo: [:v :c |
		self addVariable: v coefficient: n*c subject: subject solver: solver].
!

addVariable: v coefficient: c
	"ACTION
		Add a term c*v to this expression.  If the expression already contains a
		term involving v, add c to the existing coefficient.  If the new coefficient
		is approximately 0, delete v.

	PARAMETERS
		v <ClVariable>
		c <Number>
	"

	| newCoeff |

	(self terms includesKey: v)
		ifTrue: [
			newCoeff := c + (self terms at: v).
			(newCoeff clApproxZero)
				ifTrue: [
					self terms removeKey: v.
					^self]
				ifFalse: [self terms at: v put: newCoeff]]
		ifFalse: [self terms at: v put: c].!

addVariable: v coefficient: c subject: subject solver: solver
	"ACTION
		Add a term c*v to this expression.  If the expression already contains a
		term involving v, add c to the existing coefficient.  If the new coefficient
		is approximately 0, delete v.  Notify the solver if v appears or disappears from this
		expression.

	PARAMETERS
		v <ClVariable>
		c <Number>
		subject <ClAbstractVariable>
		solver <ClSimplexSolver>
	"

	| newCoeff |

	(self terms includesKey: v)
		ifTrue: [
			newCoeff := c + (self terms at: v).
			newCoeff clApproxZero
				ifTrue: [
					self terms removeKey: v.
					solver noteRemovedVariable: v subject: subject.
					^self]
				ifFalse: [self terms at: v put: newCoeff]]
		ifFalse: [
			self terms at: v put: c.
			solver noteAddedVariable: v subject: subject].!

anyVariable
	"ACTION
		Return a variable in this expression.  (It is an error if this expression is constant).

	Returns
		<ClAbstractVariable>
	"

	self terms keysDo: [:v | ^v].
	"signal an error if this expression is constant"
	ExCLInternalError signal
!

asLinearExpression
	^self
!

changeSubject: oldSubject newSubject: newSubject
	"ACTION
		This linear expression currently represents the equation oldSubject=self.
		Destructively modify it so that it represents the equation newSubject=self.
		Precondition: newSubject currently has a nonzero coefficient in this expression.
	PARAMETERS
		oldSubject <ClAbstractVariable>
		newSubject <ClAbstractVariable>
	NOTES
		Suppose this expression is c + a*newSubject + a1*v1 + ... + an*vn.
		Then the current equation is oldSubject = c + a*newSubject + a1*v1 + ... + an*vn.
		The new equation will be newSubject = -c/a + oldSubject/a - (a1/a)*v1 - ... - (an/a)*vn.
		Note that the term involving newSubject has been dropped.
	"
		| reciprocal nreciprocal |
	"remove newSubject from my dictionary of terms, saving the reciprocal of its coefficient"
	reciprocal := 1.0 / (self terms removeKey: newSubject).
	nreciprocal := 0.0 - reciprocal.
	self constant: nreciprocal * self constant.
	self terms keysAndValuesDo: [:v :c | self terms at: v put: c*nreciprocal].
	self terms at: oldSubject put: reciprocal.
!

cnEqual: expr
	"ACTION
		Return a linear constraint self=expr with strength=required and weight=1.

	PARAMETERS
		expr <ClLinearExpression | ClVariable | Number>

	RETURNS
		<ClLinearEquation>
	"
	^self cnEqual: expr strength: ClStrength required weight: 1.0

!

cnEqual: expr strength: s
	"ACTION
		Return a linear constraint self=expr of strength s and weight=1.

	PARAMETERS
		expr <ClLinearExpression | ClVariable | Number>
		s <ClStrength>

	RETURNS
		<ClLinearEquation>
	"

	^self cnEqual: expr strength: s weight: 1.0
!

cnEqual: expr strength: s weight: w
	"ACTION
		Return a linear constraint self=expr of strength s and weight w.

	PARAMETERS
		expr <ClLinearExpression | ClVariable | Number>
		st <ClStrength>
		w <Float>

	RETURNS
		<ClLinearEquation>
	"
		| cn |
	cn := ClLinearEquation new.
	cn expression: self-expr; strength: s; weight: w.
	^cn
!

cnGEQ: expr
	"ACTION
		Return a linear constraint self>=expr with strength=required and weight=1.

	PARAMETERS
		expr <ClLinearExpression | ClVariable | Number>

	RETURNS
		<ClLinearInequality>
	"
	^self cnGEQ: expr strength: ClStrength required weight: 1.0
!

cnGEQ: expr strength: s
	"ACTION
		Return a linear constraint self>=expr of strength s and weight=1.

	PARAMETERS
		expr <ClLinearExpression | ClVariable | Number>
		s <ClStrength>

	RETURNS
		<ClLinearInequality>
	"
	^self cnGEQ: expr strength: s weight: 1.0
!

cnGEQ: expr strength: s weight: w
	"ACTION
		Return a linear constraint self>=expr of strength s and weight w.

	PARAMETERS
		expr <ClLinearExpression | ClVariable | Number>
		st <ClStrength>
		w <Float>

	RETURNS
		<ClLinearEquation>
	"
		| cn |
	cn := ClLinearInequality new.
	cn expression: self-expr; strength: s; weight: w.
	^cn
!

cnLEQ: expr
	"ACTION
		Return a linear constraint self<=expr with strength=required and weight=1.

	PARAMETERS
		expr <ClLinearExpression | ClVariable | Number>

	RETURNS
		<ClLinearInequality>
	"
	^self cnLEQ: expr strength: ClStrength required weight: 1.0

!

cnLEQ: expr strength: s
	"ACTION
		Return a linear constraint self<=expr of strength s and weight 1.

	PARAMETERS
		expr <ClLinearExpression | ClVariable | Number>
		s <ClStrength>

	RETURNS
		<ClLinearInequality>
	"
	^self cnLEQ: expr strength: s weight: 1.0

!

cnLEQ: expr strength: s weight: w
	"ACTION
		Return a linear constraint self<=expr of strength s and weight w.

	PARAMETERS
		expr <ClLinearExpression | ClVariable | Number>
		st <ClStrength>
		w <Float>

	RETURNS
		<ClLinearEquation>
	"
		| cn |
	cn := ClLinearInequality new.
	cn expression: expr-self; strength: s; weight: w.
	^cn
!

coefficientFor: var
	"ACTION
		Return the coefficient corresponding to variable var, i.e.,
		the 'ci' corresponding to the 'vi' that var is:
			v1*c1 + v2*c2 + .. + vn*cn + c

	PARAMETERS
		var <ClVariable>

	RETURNS
		<Number>
	"

	^self terms at: var ifAbsent: [0.0]
!

constant
	"ACTION
		Return the constant part of this expression, i.e., the 'c' in:
			c + a1*v1 + a2*v2 + .. + an*vn

	RETURNS
		<Number>
	"

	^constant
!

constant: c
	"ACTION
		See #constant

	PARAMETERS
		c <Number>
	"
	constant := c
!

divFrom: aNumber
	"ACTION
		Return a new linear expression (aNumber/self).  Since the result must be linear, this is permissible
		only if self is a constant.

	RETURNS
		<ClLinearExpression>
	"
	self isConstant ifTrue: [^aNumber / self constant].
	"result would be non-linear"
	ExCLNonlinearExpression signal
!

incrementConstant: c
	"ACTION
		Increment the constant part of this expression by c.

	PARAMETERS
		c <Number>
	"

	self constant: self constant + c!

isConstant
	"ACTION
		Return true if this expression is a constant (i.e. it contains no variables).

	RETURNS
		<Boolean>
	"

	^self terms isEmpty!

newSubject: subject
	"ACTION
		This linear expression currently represents the equation self=0.  Destructively modify it so 
		that subject=self represents an equivalent equation.  Precondition: subject must be one
		of the variables in this expression.
	PARAMETERS
		subject <ClAbstractVariable>
	NOTES
		Suppose this expression is c + a*subject + a1*v1 + ... + an*vn, representing 
		c + a*subject + a1*v1 + ... + an*vn = 0.
		The modified expression will be subject = -c/a - (a1/a)*v1 - ... - (an/a)*vn, representing
		subject = -c/a - (a1/a)*v1 - ... - (an/a)*vn.
		Note that the term involving subject has been dropped.
	"
		| nreciprocal |
	"remove subject from my dictionary of terms, saving the negative of the reciprocal of its coefficient"
	nreciprocal := 0.0 - (1.0 / (self terms removeKey: subject)).
	self constant: nreciprocal * self constant.
	self terms keysAndValuesDo: [:v :c | self terms at: v put: c*nreciprocal].
!

printOn: strm
		| sortedKeys |
	self constant printOn: strm.
	sortedKeys := self terms keys asSortedCollection: 
		[:v1 :v2 | v1 name isNil or: [v2 name isNil or: [v1 name <= v2 name]]].
	sortedKeys do: [:v |
		strm nextPut: $+.
		(self terms at: v) printOn: strm.
		strm nextPut: $*.
		v printOn: strm].
!

substituteOut: var expr: expr subject: subject solver: solver
	"ACTION
		Replace var with a symbolic expression expr that is equal to it.  If a variable has been added to this
		expression that wasn't there before, or if a variable has been dropped from this expression 
		because it now has a coefficient of 0, inform the solver.

	PRECONDITIONS
		var occurs with a non-zero coefficient in this expression.

	PARAMETERS
		var <ClAbstractVariable>
		expr <ClLinearExpression>
		subject <ClAbstractVariable>
		solver <ClSimplexSolver>
	"
		| multiplier oldCoeff newCoeff |
	multiplier := self terms removeKey: var.
	self incrementConstant: multiplier * expr constant.
	expr terms keysAndValuesDo: [:v :c |
		oldCoeff := self terms at: v ifAbsent: [nil].
		oldCoeff isNil 
			ifTrue: [
				self terms at: v put: multiplier*c.  solver noteAddedVariable: v subject: subject]
			ifFalse: [
				newCoeff := oldCoeff + (multiplier*c).
				(newCoeff clApproxZero)
					ifTrue: [self terms removeKey: v.  solver noteRemovedVariable: v subject: subject]
					ifFalse: [self terms at: v put: newCoeff]]].
!

subtractFrom: aNumber
	"ACTION
		Return a new linear expression (aNumber-self).

	RETURNS
		<ClLinearExpression>
	"
	^ -1.0*self + aNumber!

variablesAndCoefficientsDo: aBlock
	"ACTION
		Evaluate aBlock with each variable-coefficient pair as arguments.

	PARAMETERS
		aBlock <Block [ClConstrainableVariable,Number] >
	"

	self terms keysAndValuesDo: [:v :c | aBlock value: v value: c]
! !

!ClLinearExpression privateMethods !

initialize
	"ACTION
		Initialize this linear expression to 0.
	"

	self
		constant: 0.0;
		terms: LookupTable new.
	^self!

terms
	"ACTION
		Return the 'terms' dictionary.  The keys in the dictionary will be
		variables and the values will be numbers (the corresponding
		coefficients).  If 'terms' contains variables v1, ... , vn and 
		coefficients a1, ... an, then this object represents the linear expression
			constant + a1*v1 + ... + an*vn
		Note that the coefficients should all be non-zero -- if there
		were going to be a zero coefficient, that term should be dropped 
		from the linear expression.

	RETURNS
		<LookupTable of <ClVariable> -> <Number>>
	"

	^terms!

terms: t
	"ACTION
		See #terms

	PARAMETERS
		<LookupTable>
	"
	terms := t! !

!ClLinearInequality publicMethods !

isInequality
	"ACTION
		Return true if this is an inequality constraint and false if it is an equality constraint.
	RETURNS
		<Boolean>
	"
	^true
!

printOn: strm
	self strength printOn: strm.
	strm nextPutAll: '('.
	expression printOn: strm.
	strm nextPutAll: '>=0)'.
! !

!ClObjectiveVariable publicMethods !

isExternal
	"ACTION
		Return true if this a variable known outside the solver.  (We need to give such variables a value after solving
		is complete.)

	RETURNS
		<Boolean>
	"

	^false
!

isPivotable
	"ACTION
		Return true if we can pivot on this variable.

	RETURNS
		<Boolean>
	"

	^false
!

isRestricted
	"ACTION
		Return true if this is a restricted (or slack) variable.  Such variables are constrained to be 
		non-negative and occur only internally to the simplex solver.

	RETURNS
		<Boolean>
	"

	^false
! !

!ClSimplexSolver class publicMethods !

epsilon
	"this is declared as  a method for the benefit of Float, which otherwise doesn't have
		access to this constant.  (Maybe I'm doing something wrong ...)"
	^ClEpsilon! !

!ClSimplexSolver class privateMethods !

new
	^super new initialize
! !

!ClSimplexSolver publicMethods !

addBounds: var lowerBound: lower upperBound: upper
	"ACTION
		Add constraints so that lower<=var<=upper.  (nil means no  bound.)
	PARAMETERS
		var <ClVariable>
		lower <Number | nil>
		upper <Number | nil>
	"
	lower notNil ifTrue: [self addConstraint: (lower cnLEQ: var)].
	upper notNil ifTrue: [self addConstraint: (var cnLEQ: upper)].
!

addConstraint: cn
	"ACTION
		Add the constraint cn to the tableau.
	PARAMETERS
		cn <ClLinearConstraint>
	"
		| expr |
	"Make a new linear expression representing the constraint, replacing any basic variables 
		with their defining expressions, and adding slack and error variables as needed.  Also add
		error variables to the objective function, and index the constraint with its marker variable."
	expr := self makeExpression: cn.
	"If possible add expr directly to the appropriate tableau by choosing a subject for expr 
		(a variable to become basic) from among the current variables in expr.  If this doesn't work
		use an artificial variable.  After adding expr re-optimize."
	(self tryAddingDirectly: expr) ifFalse: [self addWithArtificialVariable: expr].
	self optimize: self objective.
	self setExternalVariables.
!

addEditVar: v strength: s
	"ACTION
		Add v to the collection of variables being edited.
	PARAMETERS
		v <ClVariable>
		s <ClStrength>
	"
	self addConstraint: (ClEditConstraint variable: v strength: s)
!

addPointStays: points
	"ACTION
		Add weak stays to the x and y parts of each point.  These have declining weights
		so that the solver will try to satisfy the x and y stays on the same point, rather than
		the x stay on one and the y stay on another.
	PARAMETERS
		v <ClVariable>
	"
		| w mult |
	mult := 2.0.  "amount to multiply by the weight each time"
	w := 1.0.
	points do: [:p |
		self addConstraint: (ClStayConstraint variable: p x strength: ClStrength weak weight: w).
		self addConstraint: (ClStayConstraint variable: p y strength: ClStrength weak weight: w).
		w := w*mult]
!

addStay: v
	"ACTION
		Add a weak stay to v.
	PARAMETERS
		v <ClVariable>
	"
	self addStay: v strength: ClStrength weak
!

addStay: v strength: s
	"ACTION
		Add a stay to v at the given strength.
	PARAMETERS
		v <ClVariable>
	"
	self addConstraint: (ClStayConstraint variable: v strength: s).
!

beginEdit
	"ACTION
		Do any needed setup to begin editing.  The sequence of calls should be:
					solver addEditVar: v1; addEditVar: v2;  ... etc.
					solver beginEdit.
	Then repeat each time new values are provided for the editted variables:
					solver suggestValue: v1 newvalue: nv1.
					solver suggestValue: v2 newvalue: nv2.
					solver resolve.
		Then to terminate editing:
					solver endEdit.

	"

	self newEditConstants: (Array new: self editVars size).

!

endEdit
	"ACTION
		Do any needed cleanup after editing.  (See beginEdit for the sequence of calls.)
	"

	self editConstraints do: [:cn | self removeConstraint: cn].
	self editVars: #( ).
	self editConstraints: #( ).
!

removeConstraint: cn
	"ACTION
		Remove the constraint cn to the tableau.  Also remove any error variables associated with cn.

	PARAMETERS
		cn <ClLinearConstraint>
	"
		| eVars zRow obj marker col minRatio expr coeff r exitVar 
				oldEditMinusErrorVars oldEditPlusErrorVars oldPrevEditConstants oldSize index |
	"We are about to remove a constraint.  There may be some stay constraints that were unsatisfied previously --
		if we just removed the constraint these could come into play.  Instead, reset all of the stays so that things
		should stay where they are at the moment."
	self resetStayConstants.

	"remove any error variables from the objective function"
	eVars := self errorVars removeKey: cn ifAbsent: [#( )].
	zRow := self objective.
	obj := self rows at: zRow.
	eVars do: [:v | 
		expr := self rows at: v ifAbsent: [nil].
		expr isNil
			ifTrue: [obj addVariable: v coefficient: -1.0*cn weight*cn strength symbolicWeight subject: zRow solver: self]
			ifFalse: [obj addExpression: expr times: -1.0*cn weight*cn strength symbolicWeight subject: zRow solver: self]].

	marker := self markerVars removeKey: cn.
	"try to make the marker variable basic if it isn't already"
	(self rows includesKey: marker) ifFalse: [
		"Choose which variable to move out of the basis.  Only consider restricted basic variables."
		col := self columns at: marker.
		col do: [:v | v isRestricted ifTrue: [
			expr := self rows at: v.
			coeff := expr coefficientFor: marker.
			"only consider negative coefficients"
			coeff < 0.0 ifTrue: [
				r := 0.0 - (expr constant / coeff).
				(exitVar isNil or: [r<minRatio]) ifTrue: [minRatio := r.  exitVar := v]]]].
		"If exitVar is still nil at this point, then either the marker variable has a positive coefficient in all equations,
			or it only occurs in equations for unrestricted variables.  If it does occur in an equation for a restricted
			variable, pick the equation that gives the smallest ratio.  (The row with the marker variable will become 
			infeasible, but all the other rows will still be feasible; and we will be dropping the row with the marker 
			variable.  In effect we are removing the non-negativity restriction on the marker variable.)"
		exitVar isNil ifTrue: [
			col do: [:v | v isRestricted ifTrue: [
				expr := self rows at: v.
				coeff := expr coefficientFor: marker.
				r := expr constant / coeff.
				(exitVar isNil or: [r<minRatio]) ifTrue: [minRatio := r.  exitVar := v]]]].
		exitVar isNil
			ifTrue: [
				"exitVar is still nil.  If col is empty, then exitVar doesn't occur in any equations, so just remove it.
				  Otherwise pick an exit var from among the unrestricted variables whose equation involves the 
				  marker var."
				col isEmpty
					ifTrue: [self removeParametricVar: marker]
					ifFalse: [exitVar := col asOrderedCollection first]].
			exitVar notNil ifTrue: [self pivot: marker exitVar: exitVar]].

	(self rows includesKey: marker) ifTrue: [self removeRow: marker].
	"Delete any error variables.  If cn is an inequality, it also contains a slack variable; but we use that as the
		marker variable and so it has been deleted when we removed its row."
	eVars do: [:v | v=marker ifFalse: [self removeParametricVar: v]].
	cn isStayConstraint ifTrue: [
		self stayPlusErrorVars: (self stayPlusErrorVars reject: [:v | eVars includes: v]).
		self stayMinusErrorVars: (self stayMinusErrorVars reject: [:v | eVars includes: v])].
	cn isEditConstraint ifTrue: [
		"find the index in editPlusErrorVars of the error variable for this constraint"
		index := self findEditErrorIndex: eVars.
		oldSize := self editPlusErrorVars size.
		"remove the error variables from editPlusErrorVars and editMinusErrorVars"
		oldEditPlusErrorVars := self editPlusErrorVars.
		self editPlusErrorVars: (Array new: oldSize-1).
		1 to: index-1 do: [:i | self editPlusErrorVars at: i put: (oldEditPlusErrorVars at: i)].
		index+1 to: oldSize do: [:i | self editPlusErrorVars at: i-1 put: (oldEditPlusErrorVars at: i)].
		oldEditMinusErrorVars := self editMinusErrorVars.
		self editMinusErrorVars: (Array new: oldSize-1).
		1 to: index-1 do: [:i | self editMinusErrorVars at: i put: (oldEditMinusErrorVars at: i)].
		index+1 to: oldSize do: [:i | self editMinusErrorVars at: i-1 put: (oldEditMinusErrorVars at: i)].
		"remove the constants from prevEditConstants"
		oldPrevEditConstants := self prevEditConstants.
		self prevEditConstants: (Array new: oldSize-1).
		1 to: index-1 do: [:i | self prevEditConstants at: i put: (oldPrevEditConstants at: i)].
		index+1 to: oldSize do: [:i | self prevEditConstants at: i-1 put: (oldPrevEditConstants at: i)]].

	self optimize: zRow.
	self setExternalVariables.
!

reset
	"ACTION
		Re-initialize this solver from the original constraints, thus getting rid of any accumulated 
		numerical problems.  (Actually I haven't observed any such problems yet, but here's the
		method anyway.)
	"
		| edits stays others i |
	edits := Array new: self editPlusErrorVars size.
	stays := OrderedCollection new.
	others := OrderedCollection new.
	self markerVars keysAndValuesDo: [:cn :v | 
		cn isEditConstraint
			ifTrue: [
				"put the edit constraint in the same place in 'edits' as it is in the current
				  array of edit error vars"
				i := self editPlusErrorVars indexOf: v ifAbsent: [self editMinusErrorVars indexOf: v ].
				edits at: i put: cn]
			ifFalse: [
				cn isStayConstraint ifTrue: [stays add: cn] ifFalse: [others add: cn]]].
	self initialize.
	"add the stays first so that variables keep their old values"
	stays do: [:cn | self addConstraint: cn].
	"add the edits in the same order they were in originally"
	edits do: [:cn | self addConstraint: cn].
	others do: [:cn | self addConstraint: cn]
!

resolve
	"ACTION
		Re-solve the current collection of constraints for the new values in newEditConstants.
	"

	self infeasibleRows: OrderedCollection new.
	self resetStayConstants.
	self resetEditConstants.
	self dualOptimize.
	self setExternalVariables.
!

suggestValue: var newValue: val
	"ACTION
		We should be editting var.  Suggest a new value for it.
	PARAMETERS
		var <ClVariable>
		val <Float>
	"
	1 to: self editVars size do: [:i | 
		(editVars at: i) == var ifTrue: [self newEditConstants at: i put: val.  ^self]].
	ExCLInternalError signal: 'variable not currently being edited'
! !

!ClSimplexSolver privateMethods !

addRow: var expr: expr
	"ACTION
		Add the constraint var=expr to the tableau.  var is now a basic variable.  Update the column cross-indices.
	PARAMETERS
		var <ClAbstractVariable>
		expr <ClLinearExpresson>
	"
	self rows at: var put: expr.
	expr variablesAndCoefficientsDo: [:v :c | 
		(self columns at: v ifAbsentPut: [Set new]) add: var]
!

addWithArtificialVariable: expr
	"ACTION
		Add the constraint expr=0 to the inequality tableau using an artificial variable.  To do this, create an
		artificial variable av and add av=expr to the inequality tableau, then make av be 0.  (Raise an exception if
		we can't attain av=0.)
	PARAMETERS
		expr <ClLinearExpresson>
	"
		| av az azRow entryVar |
	artificialCounter := artificialCounter + 1.
 	av := ClSlackVariable newNamed: 'a' , artificialCounter printString.
	az := ClObjectiveVariable newNamed: 'az'.
	azRow := ClLinearExpression new.
	"the artificial objective is av, which we know is equal to expr (which contains only parametric variables)"
	azRow constant: expr constant.
	expr terms keysAndValuesDo: [:v :c | azRow terms at: v put: c].
	self addRow: az expr: azRow.
	self addRow: av expr: expr.
	"try to optimize av to 0"
	self optimize: az.
	"Check that we were able to make the objective value 0.  If not, the original constraint was unsatisfiable."
	(azRow constant clApproxZero) ifFalse: [ExCLRequiredFailure signal].
	"see if av is a basic variable"
	self rows at: av ifPresent: [:e |
		"Find another variable in this row and pivot, so that av becomes parametric.  If there isn't another variable
			in the row then the tableau contains the equation av=0 -- just delete av's row."
		e isConstant ifTrue: [self removeRow: av.  ^nil].
		entryVar := e anyVariable.
		self pivot: entryVar exitVar: av].
	"av should be parametric at this point"
	self removeParametricVar: av.
	"remove the temporary objective function"
	self removeRow: az.

!

chooseSubject: expr
	"ACTION
		We are trying to add the constraint expr=0 to the tableaux.  Try to choose a subject 
		(a variable to become basic) from among the current variables
		in expr.  If expr contains any unrestricted variables, then we must choose 
		an unrestricted variable as the subject.  Also, if the
		subject is new to the solver we won't have to do any substitutions, so we prefer new variables
		to ones that are currently noted as parametric.  If expr contains only restricted 
		variables, if there is a restricted variable with a negative coefficient that is new to the solver
		we can make that the subject.  Otherwise 
		we can't find a subject, so return nil.  (In this last case we have to add an artificial variable
		and use that variable as the subject -- this is done outside this method though.)

		Note:  in checking for variables that are new to the solver, we ignore whether a variable occurs
		in the objective function, since new slack variables are added to the objective function by 
		'makeExpression:', which is called before this method.

	PARAMETERS
		expr <ClLinearExpression>
	RETURNS
		<ClAbstractVariable | nil>
	"
		| subject foundUnrestricted foundNewRestricted col coeff |
	"The temporaries are as follows:
		subject <ClAbstractVariable | nil> -- nil or the current best subject
		foundUnrestricted <Boolean> -- true if we have found a subject that is an unrestricted variable
		foundNewRestricted <Boolean> -- true if we have found a restricted variable that is new to the solver
			(except for being in the objective function) and that has a negative coefficient."

	foundUnrestricted := false.  foundNewRestricted := false.
	expr variablesAndCoefficientsDo: [:v :c | 
		foundUnrestricted 
			ifTrue: [
				"We have already found an unrestricted variable.  The only time we will want to use v instead of
					the current choice 'subject' is if v is unrestricted and new to the solver and 'subject' isn't new.
					If this is the case just pick v immediately and return."
				v isRestricted ifFalse: [(self columns includesKey: v) ifFalse: [^v]]]
			ifFalse: [
				"we haven't found an unrestricted variable yet"
				v isRestricted 
					ifTrue: [
						"v is restricted.  If we have already found a suitable restricted variable just stick with that.
							Otherwise, if v is new to the solver and has a negative coefficient pick it.  Regarding being
							new to the solver -- if the variable occurs only in the objective function we regard it as being
							new to the solver, since error variables are added to the objective function when we make
							the expression.  We also never pick a dummy variable here."
						(foundNewRestricted not and: [v isDummy not and: [c<0.0]]) ifTrue: [
							col := self columns at: v ifAbsent: [nil].
							(col isNil or: [col size=1 and: [col includes: self objective]]) ifTrue: [
								subject := v.
								foundNewRestricted := true]]]
					ifFalse: [
						"v is unrestricted.  If v is also new to the solver just pick it now"
						(self columns includesKey: v) ifFalse: [^v].
						subject := v.
						foundUnrestricted := true]]].

	subject isNil ifFalse: [^subject].
	"subject is nil.  Make one last check -- if all of the variables in expr are dummy 
		variables, then we can pick a dummy variable as the subject."
	expr variablesAndCoefficientsDo: [:v :c | 
		v isDummy ifFalse: [^nil   "nope - no luck"].
		"if v is new to the solver tentatively make it the subject"
		(self columns includesKey: v) ifFalse: [subject := v.  coeff := c]].
	"If we get this far, all of the variables in the expression should be dummy variables.  If the
		constant is nonzero we are trying to add an unsatisfiable required constraint.  (Remember
		that dummy variables must take on a value of 0.)  Otherwise, if the constant is zero, 
		multiply by -1 if necessary to make the coefficient for the subject negative."
	(expr constant clApproxZero) ifFalse: [ExCLRequiredFailure signal].
	coeff > 0 ifTrue: [
		expr terms keysAndValuesDo: [:v :c | expr terms at: v put: 0.0-c]].
	^subject
!

columns
	"ACTION
		Return the dictionary of column cross-indices.  The keys are parametric variables and the values are 
		sets of basic variables.  For each parametric variable p, the set should include all the basic variables
		whose expression includes p.  The columns may be either restricted or unrestricted variables (they
		are intermixed in the one tableau).
	RETURNS
		<LookupTable keys: ClAbstractVariable values: (Set of ClAbstractVariable)>
	"	
	^columns
!

columns: cols
	"ACTION
		See 'columns'.
	PARAMETERX
		cols <LookupTable keys: ClAbstractVariable values: (Set of ClAbstractVariable)>
	"	
	columns := cols
!

deltaEditConstant: delta plusErrorVar: plusErrorVar minusErrorVar: minusErrorVar
	"first check if the plusErrorVar is basic"
	self rows at: plusErrorVar ifPresent: [:expr | 
		expr incrementConstant: delta.
		"error variables are always restricted -- so the row is infeasible if the constant is negative"
		expr constant < 0.0 ifTrue: [self infeasibleRows add: plusErrorVar].
		^nil].
	"check if minusErrorVar is basic"
	self rows at: minusErrorVar ifPresent: [:expr | 
		expr incrementConstant: 0.0-delta.
		expr constant < 0.0 ifTrue: [self infeasibleRows add: minusErrorVar].
		^nil].
	"Neither is basic.  So they must both be nonbasic, and will both occur in exactly the same expressions.
	 Find all the expressions in which they occur by finding the column for the minusErrorVar (it doesn't matter
	 whether we look for that one or for plusErrorVar).  Fix the constants in these expressions."
	(self columns at: minusErrorVar) do: [:basicVar || expr c |
		expr := self rows at: basicVar.
		c := expr coefficientFor: minusErrorVar.
		expr incrementConstant: c*delta.
		(basicVar isRestricted and: [expr constant < 0.0]) ifTrue: [self infeasibleRows add: basicVar]].
!

dualOptimize
	"We have set new values for the constants in the edit constraints.  Re-optimize using the dual simplex algorithm."
		| zRow exitVar entryVar ratio r zc |
	zRow := self rows at: objective.
	[self infeasibleRows isEmpty] whileFalse: [
		exitVar := self infeasibleRows removeFirst.
		"exitVar might have become basic after some other pivoting, so allow for the case 
		  of its not being there any longer"
		self rows at: exitVar ifPresent: [:expr |
			"make sure the row is still not feasible"
			expr constant < 0.0 ifTrue: [
				ratio := nil.
				expr variablesAndCoefficientsDo: [:v :c |
					(c>0.0 and: [v isPivotable]) ifTrue: [
						zc := zRow terms at: v ifAbsent: [nil].
						r := zc isNil ifTrue: [ClSymbolicWeight zero] ifFalse: [zc/c].
						(ratio isNil or: [r < ratio]) ifTrue: [entryVar := v.  ratio := r]]].
				ratio isNil ifTrue: [ExCLInternalError signal].
				self pivot: entryVar exitVar: exitVar]]]!

editConstraints
	"An array of ClEditConstraints for the variables being edited.  These must be in the 
		same order as editVars, editPlusErrorVars, and editMinusErrorVars."
	^editConstraints
!

editConstraints: cns
	editConstraints := cns
!

editMinusErrorVars
	"The array of negative error vars for the edit constraints.  These must be in the same order
		as editPlusErrorVars, editVars, and editConstraints."
	^editMinusErrorVars
!

editMinusErrorVars: s
	editMinusErrorVars := s
!

editPlusErrorVars
	"The array of positive error vars for the edit constraints.  These must be in the same order
		as editMinusErrorVars, editVars, and editConstraints."
	^editPlusErrorVars

!

editPlusErrorVars: s
	editPlusErrorVars := s
!

editVars
	"The array of variables being edited.  These must be in the same order as editConstraints,
		editPlusErrorVars, and editMinusErrorVars."
	^editVars
!

editVars: evars
	"ACTION
		See editVars
	"
	editVars := evars
!

errorVars
	"ACTION
		Return a lookup table giving the error variables for a non-required constraint.

	RETURNS
		<LookupTable keys: <ClConstraint> values: <Array of: ClSlackVariable>>
	"
	^errorVars
!

errorVars: evars
	"ACTION
		See errorVars
	"
	errorVars := evars
!

findEditErrorIndex: eVars
	"find the index in editPlusErrorVars of one of the variables in eVars"
		| index |
	eVars do: [:v |
		index := self editPlusErrorVars indexOf: v.
		index > 0 ifTrue: [^index]].
	ExCLInternalError signal  "didn't find a variable"
!

infeasibleRows
	"ACTION
		Return the collection of basic variables that have infeasible rows (used when re-optimizing).
	RETURNS
		<OrderedCollection of ClSlackVariable>
	"	
	^infeasibleRows
!

infeasibleRows: r
	"ACTION
		See 'infeasibleRows'
	PARAMETERS
		r <OrderedCollection of ClSlackVariable>
	"	
	infeasibleRows := r
!

initialize
		| zRow |
	zRow := ClLinearExpression newWithSymbolicWeight.
	self rows: LookupTable new;
		columns: LookupTable new;
		objective: (ClObjectiveVariable newNamed: 'z');
		infeasibleRows: OrderedCollection new;
		prevEditConstants: Array new;
		stayPlusErrorVars: Array new;
		stayMinusErrorVars: Array new;
		editVars: Array new;
		editConstraints: Array new;
		editPlusErrorVars: Array new;
		editMinusErrorVars: Array new;
		markerVars: LookupTable new;
		errorVars: LookupTable new.
	self rows at: self objective put: zRow.
	slackCounter :=0.  artificialCounter := 0.  dummyCounter := 0.
!

makeExpression: cn
	"ACTION
		Make a new linear expression representing the constraint cn, replacing any basic variables 
		with their defining expressions.  Normalize if necessary so that the constant is non-negative.
		If the constraint is non-required give its error variables an appropriate weight in the objective function.

	PARAMETERS
		cn <ClLinearConstraint>
	"
		| expr cnExpr e slackVar dummyVar eplus eminus zRow |
	expr := ClLinearExpression new.
	cnExpr := cn expression.
	expr constant: cnExpr constant.
	cnExpr variablesAndCoefficientsDo: [:v :c |
		e := self rows at: v ifAbsent: [nil].
		e isNil ifTrue: [expr addVariable: v coefficient: c] ifFalse: [expr addExpression: e times: c]].
	"add slack and error variables as needed"
	cn isInequality 
		ifTrue: [
			"cn is an inequality, so add a slack variable.  The original constraint is expr>=0, so that the 
				resulting equality is expr-slackVar=0.  If cn is also non-required add a negative error variable,
				giving expr-slackVar = -errorVar, in other words expr-slackVar+errorVar=0.  Since both of these
				variables are newly created we can just add them to the expression (they can't be basic)."
			slackCounter := slackCounter + 1.
			slackVar := ClSlackVariable newNamed: 's' , slackCounter printString.
			expr terms at: slackVar put: -1.0.
			"index the constraint under its slack variable"
			self markerVars at: cn put: slackVar.
			cn isRequired ifFalse: 
				[slackCounter := slackCounter + 1.
				eminus := ClSlackVariable newNamed: 'em' , slackCounter printString.
				expr terms at: eminus put: 1.0.
				"add eminus to the objective function with the appropriate weight"
				zRow := self rows at: self objective.
				zRow terms at: eminus put: cn strength symbolicWeight * cn weight.
				self errorVars at: cn put: (Array with: eminus).
				self noteAddedVariable: eminus subject: self objective]]
		ifFalse: ["cn is an equality"
			cn isRequired 
				ifTrue: [
					"Add a dummy variable to the expression to serve as a marker for this constraint.  The dummy variable
						is never allowed to enter the basis when pivoting."
					dummyCounter := dummyCounter + 1.
					dummyVar := ClDummyVariable newNamed: 'd' , dummyCounter printString.
					expr terms at: dummyVar put: 1.0.
					self markerVars at: cn put: dummyVar]
				ifFalse: [
					"cn is a non-required equality.  Add a positive and a negative error variable, making the
						resulting constraint expr = eplus - eminus, in other words expr-eplus+eminus=0"
					slackCounter := slackCounter + 1.
					eplus := ClSlackVariable newNamed: 'ep' , slackCounter printString.
					eminus := ClSlackVariable newNamed: 'em' , slackCounter printString.
					expr terms at: eplus put: -1.0.
					expr terms at: eminus put: 1.0.
					"index the constraint under one of the error variables"
					self markerVars at: cn put: eplus.
					zRow := self rows at: self objective.
					zRow terms at: eplus put: cn strength symbolicWeight * cn weight.
					self noteAddedVariable: eplus subject: self objective.
					zRow terms at: eminus put: cn strength symbolicWeight * cn weight.
					self errorVars at: cn put: (Array with: eplus with: eminus).
					self noteAddedVariable: eminus subject: self objective.
					cn isStayConstraint ifTrue: [
						self stayPlusErrorVars: (self stayPlusErrorVars copyWith: eplus).
						self stayMinusErrorVars: (self stayMinusErrorVars copyWith: eminus)].
					cn isEditConstraint ifTrue: [
						self editVars: (self editVars copyWith: cn variable).
						self editConstraints: (self editConstraints copyWith: cn).
						self editPlusErrorVars: (self editPlusErrorVars copyWith: eplus).
						self editMinusErrorVars: (self editMinusErrorVars copyWith: eminus).
						self prevEditConstants: (self prevEditConstants copyWith: cnExpr constant)]]].
	"The constant in the expression should be non-negative.  If necessary normalize the expression
		by multiplying by -1."
	expr constant < 0 ifTrue: [
		expr constant: 0.0-expr constant.
		expr terms keysAndValuesDo: [:v :c | expr terms at: v put: 0.0-c]].
	^expr
!

markerVars
	"ACTION
		Return a lookup table giving the marker variable for each constraint (used when deleting a constraint).
	RETURNS
		<LookupTable keys: <ClConstraint> values: <ClAbstractVariable>
	"
	^markerVars
!

markerVars: m
	"ACTION
		See markerVars.
	PARAMETERS
		m <LookupTable keys: <ClConstraint> values: <ClAbstractVariable>
	"
	markerVars := m
!

newEditConstants
	"The array of constants for the edit constraints for the next iteration.  These must be in the same order
		as editPlusErrorVars and editMinusErrorVars"
	^newEditConstants
!

newEditConstants: n
	newEditConstants := n
!

noteAddedVariable: var subject: subject
	"ACTION
		Variable var has been added to an expression.  If the expression is in a tableau the corresponding
		basic variable is subject (or if subject is nil then it's in the objective function).  Update the column cross-indices.
	PARAMETERS
		var <ClAbstractVariable>
		subject <ClAbstractVariable | nil>
	"
	subject notNil ifTrue: [(self columns at: var ifAbsentPut: [Set new]) add: subject]
!

noteRemovedVariable: var subject: subject
	"ACTION
		Variable var has been removed from an expression.  If the expression is in a tableau the corresponding
		basic variable is subject (or if subject is nil then it's in the objective function).  Update the column cross-indices.
	PARAMETERS
		var <ClAbstractVariable>
		subject <ClAbstractVariable | nil>
	"
	subject notNil ifTrue: [(self columns at: var) remove: subject]
!

objective
	"ACTION
		Return the objective function.
	RETURNS
		<ClLinearExpression>
	"
	^objective
!

objective: expr
	"ACTION
		Set the objective function.
	PARAMETERS
		expr <ClLinearExpression>
	"
	objective := expr
!

optimize: zVar
	"ACTION
		Minimize the value of the objective.  (The tableau should already be feasible.)
	PARAMETERS
		zVar <ClObjectiveVariable>
	"
		| zRow objectiveCoeff minRatio exitVar entryVar r expr coeff |
	zRow := self rows at: zVar.
	[true] whileTrue: [
		"Find the most negative coefficient in the objective function (ignoring dummy variables).
		  If all coefficients are positive we're done"
		objectiveCoeff := nil.
		zRow variablesAndCoefficientsDo: [:v :c | 
			(v isPivotable and: [objectiveCoeff isNil or: [c < objectiveCoeff]]) ifTrue: [objectiveCoeff := c.  entryVar := v]].
		"if all coefficients were positive (or if the objective function has no pivotable variables) we are at optimum"
		objectiveCoeff isNil ifTrue: [^nil].
		objectiveCoeff approxNonNegative ifTrue: [^nil].
		"Choose which variable to move out of the basis.  Only consider pivotable basic variables (that is,
			restricted, non-dummy variables)."
		minRatio := nil.
		(self columns at: entryVar) do: [:v | v isPivotable ifTrue: [
			expr := self rows at: v.
			coeff := expr coefficientFor: entryVar.
			"only consider negative coefficients"
			coeff < 0.0 ifTrue: [
				r := 0.0 - (expr constant / coeff).
				(minRatio isNil or: [r<minRatio]) ifTrue: [minRatio := r.  exitVar := v]]]].
		"If minRatio is still nil at this point, it means that the objective function is unbounded, i.e. it can 
			become arbitrarily negative.  This should never happen in this application."
		minRatio isNil ifTrue: [ExCLInternalError signal].
		self pivot: entryVar exitVar: exitVar]

!

pivot: entryVar exitVar: exitVar
	"Do a pivot.  Move entryVar into the basis (i.e. make it a basic variable), and move exitVar out of the basis 
	 (i.e. make it a parametric variable)."
		| expr |
	"expr is the expression for the exit variable (about to leave the basis) -- so that the old tableau includes the
	 equation exitVar = expr"
	expr := self removeRow: exitVar.
	"Compute an expression for the entry variable.  Since expr has been deleted from the tableau we can
	  destructively modify it to build this expression."
	expr changeSubject: exitVar newSubject: entryVar.
	self substituteOut: entryVar expr: expr.
	self addRow: entryVar expr: expr.
!

prevEditConstants
	"The array of constants for the edit constraints on the previous iteration.  These must be in the same order
		as editPlusErrorVars and editMinusErrorVars"
	^prevEditConstants
!

prevEditConstants: p
	prevEditConstants := p
!

removeParametricVar: var
	"ACTION
		Remove the parametric variable var, updating the appropriate column and row entries.
	PARAMETERS
		var <ClAbstractVariable>
	"
		| set |
	set := self columns removeKey: var.
	set do: [:v | (self rows at: v) terms removeKey: var]
!

removeRow: var 
	"ACTION
		var should be a basic variable, so that the tableau contains the constraint var=expr.  Remove this row,
		and update the column cross-indices.  Also remove it from infeasibleRows if present.  Return expr.
	PARAMETERS
		var <ClAbstractVariable>
	RETURNS
		<ClLinearExpression>
	"
		| expr |
	expr := self rows removeKey: var.
	expr terms keysDo: [:v | (self columns at: v) remove: var].
	self infeasibleRows remove: var ifAbsent: [ ].
	^expr
!

resetEditConstants
	"ACTION
		Each of the non-required edits will be represented by an equation of the form
			v = c + eplus - eminus
		where v is the variable with the edit, c is the previous edit value, and eplus and eminus 
		are slack variables that hold the error in satisfying the edit constraint.  We are about to
		change something, and we want to fix the constants in the equations representing the
		edit constraints.  If one of eplus and eminus is basic, the other must occur only in the
		expression for that basic error variable.  (They can't both be basic.)  Fix the constant in
		this expression.  Otherwise they are both nonbasic.  Find all of the expressions in which
		they occur, and fix the constants in those.  See the UIST paper for details.
	"
		| delta nn pp |
	self newEditConstants size = self editPlusErrorVars size ifFalse: [
		"number of edit constants doesn't match the number of edit error variables"
		ExCLInternalError signal].
	1 to: self newEditConstants size do: [:i |


nn := self newEditConstants.
pp := self prevEditConstants.
nn isNil ifTrue: [self halt].
self prevEditConstants isNil ifTrue: [self halt].
 (self newEditConstants at: i)  isNil ifTrue: 
[Transcript cr; show: self newEditConstants printString.
self halt].
 (self prevEditConstants at: i) isNil ifTrue: [self halt].


		delta := (self newEditConstants at: i) - (self prevEditConstants at: i).
		self prevEditConstants at: i put: (self newEditConstants at: i).
		self 
			deltaEditConstant: delta
			plusErrorVar: (self editPlusErrorVars at: i)
			minusErrorVar: (self editMinusErrorVars at: i)].
!

resetStayConstants
	"ACTION
		Each of the non-required stays will be represented by an equation of the form
			v = c + eplus - eminus
		where v is the variable with the stay, c is the previous value of v, and eplus and eminus 
		are slack variables that hold the error in satisfying the stay constraint.  We are about to
		change something, and we want to fix the constants in the equations representing the stays.
		If both eplus and eminus are nonbasic they have value 0 in the current solution, meaning the 
		previous stay was exactly satisfied.  In this case nothing needs to be changed.  Otherwise one
		of them is basic, and the other must occur only in the expression for that basic error variable.
		Reset the constant in this expression to 0.
	"
		| expr |
	1 to: self stayPlusErrorVars size do: [:i | 
		expr := self rows at: (self stayPlusErrorVars at: i) ifAbsent: [
				self rows at: (self stayMinusErrorVars at: i) ifAbsent: [nil]].
		expr notNil ifTrue: [expr constant: 0.0]]
!

resolve: cs
	"ACTION
		Re-solve the current collection of constraints for new values for the constants of the edit variables.
	PARAMETERS
		cs <Array of Float>
	"

	self newEditConstants: cs.
	self resolve.!

rows
	"ACTION
		Return the dictionary of rows in the tableau.  The keys are basic variables and the values are 
		the corresponding expressions.  Both unrestricted and restricted variables are included in the one tableau
		(i.e. the keys may be either restricted or unrestricted variables).
	RETURNS
		<LookupTable keys: ClAbstractVariable values: ClLinearExpression>
	"	
	^rows
!

rows: r
	"ACTION
		See 'rows'.
	PARAMETERS
		r <LookupTable keys: ClAbstractVariable values: ClLinearExpression>
	"	
	rows := r
!

setExternalVariables
	"ACTION
		Set the external variables known to this solver to their appropriate values.

	PARAMETERS
	"

	"Set each external basic variable to its value, and set each external parametric variable to 0.
		(It isn't clear that we will ever have external parametric variables -- every external variable
		should either have a stay on it, or have an equation that defines it in terms of other external
		variables that do have stays.  For the moment I'll put this in though.)  Variables that are internal
		to the solver don't actually store values -- their values are just implicit in the tableu -- so
		we don't need to set them."
	self rows keysAndValuesDo: [:var :expr | var isExternal ifTrue: [var value: expr constant]].
	self columns keysDo: [:var | var isExternal ifTrue: [var value: 0.0]].
!

stayMinusErrorVars
	"an array of negative error variables for the stay constraints.  The
	 corresponding positive error is in the same place in stayPlusErrorVars"
	^stayMinusErrorVars!

stayMinusErrorVars: vs
	stayMinusErrorVars := vs
!

stayPlusErrorVars
	"an array of plus error variables for the stay constraints.  The
	 corresponding negative error is in the same place in stayMinusErrorVars"
	^stayPlusErrorVars!

stayPlusErrorVars: vs
	stayPlusErrorVars := vs
!

substituteOut: oldVar expr: expr
	"replace all occurrences of oldVar with expr (including in the objective function), and update the 
	  column cross-references.  oldVar should now be a basic variable."
		| col row |
	col := self columns removeKey: oldVar.
	col do: [:v | 
		row := self rows at: v.
		row substituteOut: oldVar expr: expr subject: v solver: self.
		(v isRestricted and: [row constant<0.0]) ifTrue: [self infeasibleRows add: v]].
!

tryAddingDirectly: expr
	"ACTION
		We are trying to add the constraint expr=0 to the appropriate tableau.  Try to add expr directly to the tableax
		without creating an artificial variable.  Return true if successful and false if not.
	PARAMETERS
		expr <ClLinearExpresson>
	RETURNS
		<Boolean>
	"
		| subject |		
	"If possible choose a subject for expr (a variable to become basic) from among the current variables
		in expr.  If this isn't possible, add an artificial variable and use that variable as the subject."
	subject := self chooseSubject: expr.
	subject isNil ifTrue: [^false].
	expr newSubject: subject.
	(self columns includesKey: subject) ifTrue: [self substituteOut: subject expr: expr].
	self addRow: subject expr: expr.
	^true
! !

!ClSlackVariable publicMethods !

isExternal
	"ACTION
		Return true if this a variable known outside the solver.  (We need to give such variables a value after solving
		is complete.)

	RETURNS
		<Boolean>
	"

	^false
!

isPivotable
	"ACTION
		Return true if we can pivot on this variable.

	RETURNS
		<Boolean>
	"

	^true
!

isRestricted
	"ACTION
		Return true if this is a restricted (or slack) variable.  Such variables are constrained to be 
		non-negative and occur only internally to the simplex solver.

	RETURNS
		<Boolean>
	"

	^true
! !

!ClStayConstraint publicMethods !

isStayConstraint
	"RETURNS
		<Boolean>
	"
	^true
! !

!ClStrength class publicMethods !

medium

	^MediumStrength!

nLevels
	"return the number of non-required strengths"
	^3
!

required

	^RequiredStrength!

strengthsDo: block
	"ACTION
		Evaluation the block for each defined strength, strongest to weakest.

	PARAMETERS
		block <Block value: ClStrength>
	"

	block
		value: RequiredStrength;
		value: StrongStrength;
		value: MediumStrength;
		value: WeakStrength
!

strong

	^StrongStrength!

weak

	^WeakStrength! !

!ClStrength class privateMethods !

initializeAfterLoad
	"ACTION
		Initialize the class variables to the pre-defined strengths.
	"
		| s m w |

	RequiredStrength := self new.  
	RequiredStrength name: 'required'.

	s := ClSymbolicWeight new.  s at: 1 put: 1.0.  s at: 2 put: 0.0.  s at: 3 put: 0.0.
	StrongStrength := self new.
	StrongStrength name: 'strong'; symbolicWeight: s.

	m := ClSymbolicWeight new.  m at: 1 put: 0.0.  m at: 2 put: 1.0.  m at: 3 put: 0.0.
	MediumStrength := self new.
	MediumStrength name: 'medium'; symbolicWeight: m.

	w := ClSymbolicWeight new.  w at: 1 put: 0.0.  w at: 2 put: 0.0.  w at: 3 put: 1.0.
	WeakStrength := self new.
	WeakStrength name: 'weak'; symbolicWeight: w.
! !

!ClStrength publicMethods !

isRequired

	^self == RequiredStrength!

printOn: strm

	strm nextPutAll: self name!

symbolicWeight	
	^symbolicWeight
! !

!ClStrength privateMethods !

name
	^name!

name: n
	name := n!

symbolicWeight: w
	symbolicWeight := w
! !

!ClSymbolicWeight class publicMethods !

new
	^self basicNew: ClStrength nLevels
!

zero
	^Zero
! !

!ClSymbolicWeight class privateMethods !

initializeAfterLoad
	"ACTION
		Initialize the class variables to the pre-defined strengths.
	"

	Zero := self new.
	1 to: Zero size do: [:i | Zero at: i put: 0.0].

! !

!ClSymbolicWeight publicMethods !

* n
	"Multiply this symbolic weight by n (n should be a number)"
		| result |
	n isNumber ifFalse: [ExCLInternalError signal].
	result := self class new.
	1 to: self size do: [:i | result at: i put: n*(self at: i)].
	^result
!

+ n
	"Add this symbolic weight to n (which must also be a symbolic weight)"
		| result |
	n isSymbolicWeight  ifFalse: [ExCLInternalError signal].
	result := self class new.
	1 to: self size do: [:i | result at: i put: (self at: i) + (n at: i)].
	^result
!

- n
	"Subtract n from this symbolic weight (n must also be a symbolic weight)"
		| result |
	n isSymbolicWeight  ifFalse: [ExCLInternalError signal].
	result := self class new.
	1 to: self size do: [:i | result at: i put: (self at: i) - (n at: i)].
	^result
!

/ n
	"Divide this symbolic weight by n (n should be a number)"
		| result |
	n isNumber ifFalse: [ExCLInternalError signal].
	result := self class new.
	1 to: self size do: [:i | result at: i put: (self at: i)/n].
	^result
!

< n
		| a b |
	n isSymbolicWeight  ifFalse: [ExCLInternalError signal].
	1 to: self size do: [:i | 
		a := self at: i.  
		b := n at: i.
		a<b ifTrue: [^true].
		a>b ifTrue: [^false]
		"they're equal ... keep going"].
	"all elements were equal"
	^false!

<= n
		| a b |
	n isSymbolicWeight  ifFalse: [ExCLInternalError signal].
	1 to: self size do: [:i | 
		a := self at: i.  
		b := n at: i.
		a<b ifTrue: [^true].
		a>b ifTrue: [^false]
		"they're equal ... keep going"].
	"all elements were equal"
	^true
!

= n
	n isSymbolicWeight  ifFalse: [^false].
	1 to: self size do: [:i | 
		(self at: i) = (n at: i) ifFalse: [^false]].
	"all elements were equal"
	^true
!

> n
		| a b |
	n isSymbolicWeight  ifFalse: [ExCLInternalError signal].
	1 to: self size do: [:i | 
		a := self at: i.  
		b := n at: i.
		a>b ifTrue: [^true].
		a<b ifTrue: [^false]
		"they're equal ... keep going"].
	"all elements were equal"
	^false!

>= n
		| a b |
	n isSymbolicWeight  ifFalse: [ExCLInternalError signal].
	1 to: self size do: [:i | 
		a := self at: i.  
		b := n at: i.
		a>b ifTrue: [^true].
		a<b ifTrue: [^false]
		"they're equal ... keep going"].
	"all elements were equal"
	^true
!

approxNonNegative
	"return true if this symbolic weight is non-negative.  Allow coefficients that are within epsilon of
		0 to count as 0"
		| a nepsilon |
	nepsilon := 0.0 - ClEpsilon.
	1 to: self size do: [:i | 
		a := self at: i.  
		a<nepsilon ifTrue: [^false].
		a>ClEpsilon ifTrue: [^true]].
	^true
!

clApprox: s
	"Return true if this symbolic weight is approximately equal to s. 
		The argument s must be another symbolic weight -- we can't
		compare symbolic weights with ordinary numbers."
	s isSymbolicWeight ifFalse: [ExCLInternalError signal].
	1 to: self size do: [:i | 
		((self at: i) clApprox: (s at: i)) ifFalse: [^false]].
	^true
!

clApproxZero
	"return true if this symbolic weight is approximately zero"
	^self clApprox: Zero
!

isSymbolicWeight
	^true
!

printOn: strm
	strm nextPutAll: '['.
	(self at: 1) printOn: strm.
	2 to: self size do: [:i | strm nextPutAll: ','.  (self at: i) printOn: strm].
	strm nextPutAll: ']'
! !

!ClVariable class publicMethods !

newWith: val
	"ACTION
		Create a new variable with val as its initial value.

	PARAMETERS
		val <Object>

	RETURNS
		new
	"

	^self new
		value: val;
		yourself!

newWith: val name: n
	"ACTION
		Create a new variable with val as its initial value and name n.

	PARAMETERS
		val <Object>
		n <String>

	RETURNS
		new
	"

	^self new
		value: val;
		name: n;
		yourself! !

!ClVariable publicMethods !

* expr
	^self asLinearExpression * expr
!

+ expr
	^self asLinearExpression + expr
!

- expr
	^self asLinearExpression - expr
!

/ expr
	^self asLinearExpression / expr
!

@ obj
	"ACTION
		A convenience method for creating point pairs of
		constrainable variables.  Mostly used in graphic
		constraints where the x and y dimensions are
		constrained separately.

	PARAMETERS
		obj <Object>

	RETURNS
		<Point of <self> obj>
	"

	^Point x: self y: obj!

asLinearExpression
	"ACTION
		Coerce this variable to be a linear expression.

	RETURNS
		<ClLinearExpression>
	"
		| expr |
	expr := ClLinearExpression new.
	expr terms at: self put: 1.0.
	^expr
!

cnEqual: expr
	"ACTION
		Return a linear constraint self=expr with strength=required and weight=1.

	PARAMETERS
		expr <ClLinearExpression | ClVariable | Number>

	RETURNS
		<ClLinearEquation>
	"
	^self cnEqual: expr strength: ClStrength required weight: 1.0

!

cnEqual: expr strength: s
	"ACTION
		Return a linear constraint self=expr of strength s and weight=1.

	PARAMETERS
		expr <ClLinearExpression | ClVariable | Number>
		s <ClStrength>

	RETURNS
		<ClLinearEquation>
	"

	^self cnEqual: expr strength: s weight: 1.0
!

cnEqual: expr strength: s weight: w
	"ACTION
		Return a linear constraint self=expr of strength s and weight w.

	PARAMETERS
		expr <ClLinearExpression | ClVariable | Number>
		st <ClStrength>
		w <Float>

	RETURNS
		<ClLinearEquation>
	"
		| cn |
	cn := ClLinearEquation new.
	cn expression: self-expr; strength: s; weight: w.
	^cn
!

cnGEQ: expr
	"ACTION
		Return a linear constraint self>=expr with strength=required and weight=1.

	PARAMETERS
		expr <ClLinearExpression | ClVariable | Number>

	RETURNS
		<ClLinearInequality>
	"
	^self cnGEQ: expr strength: ClStrength required weight: 1.0
!

cnGEQ: expr strength: s
	"ACTION
		Return a linear constraint self>=expr of strength s and weight=1.

	PARAMETERS
		expr <ClLinearExpression | ClVariable | Number>
		s <ClStrength>

	RETURNS
		<ClLinearInequality>
	"
	^self cnGEQ: expr strength: s weight: 1.0
!

cnGEQ: expr strength: s weight: w
	"ACTION
		Return a linear constraint self>=expr of strength s and weight w.

	PARAMETERS
		expr <ClLinearExpression | ClVariable | Number>
		st <ClStrength>
		w <Float>

	RETURNS
		<ClLinearEquation>
	"
		| cn |
	cn := ClLinearInequality new.
	cn expression: self-expr; strength: s; weight: w.
	^cn
!

cnLEQ: expr
	"ACTION
		Return a linear constraint self<=expr with strength=required and weight=1.

	PARAMETERS
		expr <ClLinearExpression | ClVariable | Number>

	RETURNS
		<ClLinearInequality>
	"
	^self cnLEQ: expr strength: ClStrength required weight: 1.0

!

cnLEQ: expr strength: s
	"ACTION
		Return a linear constraint self<=expr of strength s and weight 1.

	PARAMETERS
		expr <ClLinearExpression | ClVariable | Number>
		s <ClStrength>

	RETURNS
		<ClLinearInequality>
	"
	^self cnLEQ: expr strength: s weight: 1.0

!

cnLEQ: expr strength: s weight: w
	"ACTION
		Return a linear constraint self<=expr of strength s and weight w.

	PARAMETERS
		expr <ClLinearExpression | ClVariable | Number>
		st <ClStrength>
		w <Float>

	RETURNS
		<ClLinearEquation>
	"
		| cn |
	cn := ClLinearInequality new.
	cn expression: expr-self; strength: s; weight: w.
	^cn
!

divFrom: aNumber
	"ACTION
		We should return a new linear expression (aNumber/self) -- but since the result must be linear, 
		this is always an error.

	RETURNS
		<ClLinearExpression>
	"
	ExCLNonlinearExpression signal
!

isExternal
	"ACTION
		Return true if this a variable known outside the solver.  (We need to give such variables a value after solving
		is complete.)

	RETURNS
		<Boolean>
	"

	^true
!

isPivotable
	"ACTION
		Return true if we can pivot on this variable.

	RETURNS
		<Boolean>
	"

	^false
!

isRestricted
	"ACTION
		Return true if this is a restricted (or slack) variable.  Such variables are constrained to be 
		non-negative and occur only internally to the simplex solver.

	RETURNS
		<Boolean>
	"

	^false
!

printOn: aStream
	"ACTION
		See superclass method.
	PARAMETERS
		aStream <WriteStream on <String>>
	"

	super printOn: aStream.
	aStream nextPutAll: '['.  self value printOn: aStream.  aStream nextPutAll: ']'
!

subtractFrom: aNumber
	"ACTION
		Return a new linear expression (aNumber-self).

	RETURNS
		<ClLinearExpression>
	"
	^ -1.0*self + aNumber!

value
	"ACTION
		Return the current value I hold.

	RETURNS
		<Number>
	"

	^value
!

value: v
	"ACTION
		Set my value.

	PARAMETERS
		v <Number>
	"

	value := v
! !

!Float publicMethods !

approxNonNegative
	^self > (0.0 - ClSimplexSolver epsilon)
!

clApprox: x
	"ACTION
		Test whether I am approximately equal to the argument.

	PARAMETERS
		x <Float>

	RETURNS
		<Boolean>
	"

	| epsilon |

	epsilon := ClSimplexSolver epsilon.
	self = 0.0 ifTrue: [^x abs < epsilon].
	x = 0.0 ifTrue: [^self abs < epsilon].
	^(self - x) abs < (self abs * epsilon)!

clApproxZero
	"ACTION
		Test whether I am approximately zero.

	RETURNS
		<Boolean>
	"

	^self clApprox: 0.0
! !

!Number publicMethods !

asLinearExpression
	"ACTION
		Coerce this number to a linear expression.

	RETURNS
		<ClLinearExpression>
	"
		| expr |
	expr := ClLinearExpression new.
	expr constant: self asFloat.
	^expr
!

cnEqual: expr
	"ACTION
		Return a linear constraint self=expr with strength=required and weight=1.

	PARAMETERS
		expr <ClLinearExpression | ClVariable | Number>

	RETURNS
		<ClLinearEquation>
	"
	^self cnEqual: expr strength: ClStrength required weight: 1.0

!

cnEqual: expr strength: s
	"ACTION
		Return a linear constraint self=expr of strength s and weight=1.

	PARAMETERS
		expr <ClLinearExpression | ClVariable | Number>
		s <ClStrength>

	RETURNS
		<ClLinearEquation>
	"

	^self cnEqual: expr strength: s weight: 1.0
!

cnEqual: expr strength: s weight: w
	"ACTION
		Return a linear constraint self=expr of strength s and weight w.

	PARAMETERS
		expr <ClLinearExpression | ClVariable | Number>
		st <ClStrength>
		w <Float>

	RETURNS
		<ClLinearEquation>
	"
		| cn |
	cn := ClLinearEquation new.
	cn expression: self-expr; strength: s; weight: w.
	^cn
!

cnGEQ: expr
	"ACTION
		Return a linear constraint self>=expr with strength=required and weight=1.

	PARAMETERS
		expr <ClLinearExpression | ClVariable | Number>

	RETURNS
		<ClLinearInequality>
	"
	^self cnGEQ: expr strength: ClStrength required weight: 1.0
!

cnGEQ: expr strength: s
	"ACTION
		Return a linear constraint self>=expr of strength s and weight=1.

	PARAMETERS
		expr <ClLinearExpression | ClVariable | Number>
		s <ClStrength>

	RETURNS
		<ClLinearInequality>
	"
	^self cnGEQ: expr strength: s weight: 1.0
!

cnGEQ: expr strength: s weight: w
	"ACTION
		Return a linear constraint self>=expr of strength s and weight w.

	PARAMETERS
		expr <ClLinearExpression | ClVariable | Number>
		st <ClStrength>
		w <Float>

	RETURNS
		<ClLinearEquation>
	"
		| cn |
	cn := ClLinearInequality new.
	cn expression: self-expr; strength: s; weight: w.
	^cn
!

cnLEQ: expr
	"ACTION
		Return a linear constraint self<=expr with strength=required and weight=1.

	PARAMETERS
		expr <ClLinearExpression | ClVariable | Number>

	RETURNS
		<ClLinearInequality>
	"
	^self cnLEQ: expr strength: ClStrength required weight: 1.0

!

cnLEQ: expr strength: s
	"ACTION
		Return a linear constraint self<=expr of strength s and weight 1.

	PARAMETERS
		expr <ClLinearExpression | ClVariable | Number>
		s <ClStrength>

	RETURNS
		<ClLinearInequality>
	"
	^self cnLEQ: expr strength: s weight: 1.0

!

cnLEQ: expr strength: s weight: w
	"ACTION
		Return a linear constraint self<=expr of strength s and weight w.

	PARAMETERS
		expr <ClLinearExpression | ClVariable | Number>
		st <ClStrength>
		w <Float>

	RETURNS
		<ClLinearEquation>
	"
		| cn |
	cn := ClLinearInequality new.
	cn expression: expr-self; strength: s; weight: w.
	^cn
! !

!Object publicMethods !

clApprox: x
	"ACTION
		Test whether I am approximately equal to the argument.

	PARAMETERS
		x <Object>

	RETURNS
		<Boolean>

	NOTES
		The default is just an equality test."

	^self = x!

isSymbolicWeight
	^false
! !

ClKernel toBeLoadedCode: '"$COMPATIBLE-DECLARATIONS-START$"
Smalltalk declarePoolDictionary: ''ClConstants''.
Smalltalk declareVariable: ''ExCLError'' poolName: ''ClConstants''.
Smalltalk declareVariable: ''ExCLInternalError'' poolName: ''ClConstants''.
Smalltalk declareVariable: ''ExCLNotEnoughStays'' poolName: ''ClConstants''.
Smalltalk declareVariable: ''ExCLRequiredFailure'' poolName: ''ClConstants''.
Smalltalk declareVariable: ''ExCLTooDifficult'' poolName: ''ClConstants''.
Smalltalk declareVariable: ''ExCLNonlinearExpression'' poolName: ''ClConstants''.
Smalltalk declareVariable: ''ClEpsilon'' poolName: ''ClConstants''.
"$COMPATIBLE-DECLARATIONS-END$"'!

ClKernel wasRemovedCode: '"$COMPATIBLE-DECLARATIONS-START$"
Smalltalk undeclare: ''ClConstants''.
"$COMPATIBLE-DECLARATIONS-END$"'!

ClAbstractVariable initializeAfterLoad!
ClDummyVariable initializeAfterLoad!
ClObjectiveVariable initializeAfterLoad!
ClSlackVariable initializeAfterLoad!
ClVariable initializeAfterLoad!
ClConstraint initializeAfterLoad!
ClEditOrStayConstraint initializeAfterLoad!
ClEditConstraint initializeAfterLoad!
ClStayConstraint initializeAfterLoad!
ClLinearConstraint initializeAfterLoad!
ClLinearEquation initializeAfterLoad!
ClLinearInequality initializeAfterLoad!
ClLinearExpression initializeAfterLoad!
ClSimplexSolver initializeAfterLoad!
ClStrength initializeAfterLoad!
ClSymbolicWeight initializeAfterLoad!
ClKernel initializeAfterLoad!

ClKernel loaded!