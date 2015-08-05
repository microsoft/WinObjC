dnl
dnl These are the facilities for enable/disabling various features,
dnl and for collecting CFLAGS/LIBS and generating per feature .pc
dnl files, assembling list of source files to compile, creating
dnl cairo-features.h and other generated files, etc...
dnl

dnl ===========================================================================

dnl
dnl Define a macro to enable features
dnl  - Macro: _CAIRO_ENABLE (ID, NAME, WHAT, DEFAULT, COMMANDS)
dnl
dnl where:
dnl
dnl	ID is the sub-namespace in function names, eg. "ft" for cairo_ft_...
dnl	NAME is the human-readable name of the feature, eg. "FreeType font"
dnl	WHAT is the type of feature:
dnl		"surface" for surface backends
dnl		"font" for font backends
dnl		"functions" for set of functions
dnl		"" for private configurations
dnl	DEFAULT is the default state of the feature:
dnl		"no" for experimental features, eg. your favorite new backend
dnl		"yes" for recommended features, eg. png functions
dnl		"auto" for other supported features, eg. xlib surface backend
dnl		"always" for mandatory features (can't be disabled), eg. image surface backend
dnl	COMMANDS are run to check whether the feature can be enabled.
dnl		They should set use_$(ID) to something other than yes if the
dnl		feature cannot be built, eg. "no (requires SomeThing)".  It then
dnl		should also set $(ID)_REQUIRES/CFLAGS/LIBS/...
dnl		appropriately.  Look at the macro definition for more details,
dnl		or ask if in doubt.
dnl
AC_DEFUN([_CAIRO_ENABLE],
[dnl
	dnl Sanity check ID
	m4_if(
		[$1],
		m4_tolower(AS_TR_SH([$1])),
		,
		[m4_fatal([invalid feature name `$1'])]
	)dnl
	m4_pushdef([cr_feature], [$1])dnl
	m4_pushdef([cr_feature_name], m4_normalize([$2]))dnl
	m4_pushdef([cr_feature_what], m4_normalize([$3]))dnl
	m4_pushdef([cr_feature_default], m4_normalize([$4]))dnl
	m4_pushdef([cr_feature_commands], [$5])dnl
	dnl
	m4_pushdef([cr_feature_arg], m4_translit([$1],_,-))dnl
	dnl
	dnl Sanity check default
	m4_case(
		cr_feature_default,
		[no],,
		[yes],,
		[auto],,
		[always],,
		[m4_fatal([Invalid default value `]cr_feature_default[' for feature `]cr_feature['])]
	)dnl
	dnl
	m4_if(cr_feature_default, [always],
	[dnl
		enable_$1=yes
	],[dnl
		AC_ARG_ENABLE(cr_feature_arg,
			      AS_HELP_STRING([--enable-]cr_feature_arg[=@<:@no/auto/yes@:>@],
					     [Enable cairo's ]cr_feature_name[ feature @<:@default=]cr_feature_default[@:>@]),
			      enable_$1=$enableval, enable_$1=cr_feature_default)
	])dnl
	dnl
	AS_CASE([$enable_$1],
	[no],[dnl
		use_$1="no (disabled, use --enable-cr_feature_arg to enable)"
	],dnl
	[yes|auto],[dnl
		AC_MSG_CHECKING([for cairo's ]cr_feature_name[ feature])
		echo

		use_[]$1=yes
		CAIRO_FEATURE_VARS_FOREACH(cr_var, [cr_feature[_]cr_var[=]_CAIRO_SH_ESCAPE_UNQUOTED(m4_do([cr_var_default_]cr_var[_value]))]m4_newline)

		cr_feature_commands

		AC_MSG_CHECKING([whether cairo's ]cr_feature_name[ feature could be enabled])
		AC_MSG_RESULT([$use_$1])

		AS_IF([test "x$enable_$1" = "xyes" -a "x$use_$1" != xyes],
		[dnl
			AC_MSG_ERROR(
				m4_case(cr_feature_default,
					[always],	[mandatory],
					[yes],		[recommended],
					,		[requested]
				) cr_feature_name[ feature could not be enabled])
		])dnl
	],dnl
	[dnl	
		AC_MSG_ERROR([invalid argument passed to --enable-]cr_feature_arg[: `$use_$1', should be one of @<:@no/auto/yes@:>@])
	])dnl

	AS_IF([test "x$use_$1" = "xyes"],
	[dnl
		CAIRO_ACCUMULATED_FEATURE_VARS_FOREACH([cr_var],
		[dnl
			CAIRO_ACCUMULATE_UNQUOTED_BEFORE(cr_var, [$]cr_feature[_]cr_var)
		])dnl
	],[dnl
		dnl If not enabled, empty the vars so no one accidentally uses them.
		CAIRO_FEATURE_VARS_FOREACH([cr_var], [unset cr_feature[_]cr_var]m4_newline)
	])dnl

	_CAIRO_FEATURE_HOOKS(cr_feature, cr_feature_name, cr_feature_default, cr_feature_what)dnl

	m4_popdef([cr_feature])dnl
	m4_popdef([cr_feature_name])dnl
	m4_popdef([cr_feature_what])dnl
	m4_popdef([cr_feature_default])dnl
	m4_popdef([cr_feature_commands])dnl
	m4_popdef([cr_feature_arg])dnl
])


dnl ===========================================================================

m4_define([_CAIRO_FEATURE_VARS])

dnl
dnl CAIRO_FEATURE_VARS_REGISTER(VARS, DEFAULT-VALUE=[])
dnl
dnl Registers variables to be collected from feature-enabling code segments.
dnl VARS should be a whitespace-separate list of variable names.
dnl
dnl DEFAULT-VALUE is m4 macros to set default value of VARS
dnl
AC_DEFUN([CAIRO_FEATURE_VARS_REGISTER],
[dnl
	m4_foreach_w([cr_var], [$1],
		     [m4_append_uniq([_CAIRO_FEATURE_VARS], cr_var, [ ],,
				     [m4_fatal([Feature variable `]cr_var[' already registered])])])dnl
	m4_foreach_w([cr_var], [$1],
	[dnl
		m4_define([cr_var_default_]cr_var[_value], m4_default([$2],[[$ac_env_[]]cr_feature[[]_]]cr_var[[_value]]))dnl
	])dnl
])

dnl
dnl CAIRO_FEATURE_VARS_FOREACH(VAR, COMMANDS)
dnl 
dnl Run COMMANDS for each registered feature variable.
dnl Defines VAR to the variable being processed.
dnl
AC_DEFUN([CAIRO_FEATURE_VARS_FOREACH],
[dnl
	m4_foreach_w([$1], _CAIRO_FEATURE_VARS, [$2])dnl
])


dnl ===========================================================================

m4_define([_CAIRO_ACCUMULATORS])dnl

m4_define([_CAIRO_ACCUMULATORS_REGISTER],
[dnl
	m4_foreach_w([cr_var], [$1],
		     [m4_append_uniq([_CAIRO_ACCUMULATORS], cr_var, [ ],,
				     [m4_fatal([Accumulator `]cr_var[' already registered])])])dnl
	m4_foreach_w([cr_var], [$1], [m4_define([cr_acc_]cr_var[_sep], [$2])])dnl
	m4_foreach_w([cr_var], [$1], [[CAIRO_]cr_var[=$3]]m4_newline)dnl
	m4_foreach_w([cr_var], [$1], [m4_pattern_allow([CAIRO_]cr_var)])dnl
])dnl

m4_define([_CAIRO_SH_ESCAPE],['m4_bpatsubst([$1],['],[\\'])'])dnl
m4_define([_CAIRO_SH_ESCAPE_UNQUOTED],["m4_bpatsubst([$1],["],[\\"])"])dnl

dnl
dnl CAIRO_ACCUMULATORS_REGISTER(VARS, SEPARATOR=[], INITIAL-VALUE=[])
dnl
dnl Registers accumulators.  An accumulator is a shell variable that can
dnl be accumulated to.  The macros take care of adding a SEPARATOR between
dnl accumulated values.
dnl
dnl VARS should be a whitespace-separate list of variable names.  The actual
dnl shell variable resulting for each variable is prefixed with CAIRO_.
dnl
AC_DEFUN([CAIRO_ACCUMULATORS_REGISTER],
[dnl
	_CAIRO_ACCUMULATORS_REGISTER([$1],[$2],_CAIRO_SH_ESCAPE([$3]))dnl
])dnl

dnl
dnl Like CAIRO_ACCUMULATORS_REGISTER but INITIAL-VALUE is left unquoted,
dnl so it can reference other shell variables for example.
dnl
AC_DEFUN([CAIRO_ACCUMULATORS_REGISTER_UNQUOTED],
[dnl
	_CAIRO_ACCUMULATORS_REGISTER([$1],[$2],_CAIRO_SH_ESCAPE_UNQUOTED([$3]))dnl
])dnl

m4_define([_CAIRO_ACCUMULATOR_CHECK],
[dnl
        m4_ifdef([cr_acc_$1_sep],,[m4_fatal([Accumulator `]$1[' not defined.])])dnl
])dnl

m4_define([_CAIRO_ACCUMULATE],
[dnl
	_CAIRO_ACCUMULATOR_CHECK([$1])dnl
	m4_ifval([$2], [$3]m4_newline)dnl
])dnl

dnl
dnl CAIRO_ACCUMULATE(VAR, VALUE)
dnl
dnl Appends VALUE to accumulator VAR
dnl
AC_DEFUN([CAIRO_ACCUMULATE],
[dnl
	_CAIRO_ACCUMULATE([$1], [$2], [CAIRO_$1="${CAIRO_$1}]m4_do([cr_acc_$1_sep])["_CAIRO_SH_ESCAPE([$2])])dnl
])dnl

dnl
dnl CAIRO_ACCUMULATE_BEFORE(VAR, VALUE)
dnl
dnl Prepends VALUE to accumulator VAR
dnl
AC_DEFUN([CAIRO_ACCUMULATE_BEFORE],
[dnl
	_CAIRO_ACCUMULATE([$1], [$2], [CAIRO_$1=_CAIRO_SH_ESCAPE([$2])"]m4_do([cr_acc_$1_sep])[${CAIRO_$1}"])dnl
])dnl

m4_define([_CAIRO_ACCUMULATE_UNQUOTED],
[dnl
	_CAIRO_ACCUMULATOR_CHECK([$1])dnl
	m4_ifval([$2], [m4_bmatch([$2],[[$]],[test -n "$2" &&]) $3]m4_newline)dnl
])dnl

dnl
dnl CAIRO_ACCUMULATE_UNQUOTED(VAR, VALUE)
dnl
dnl Like CAIRO_ACCUMULATE but VALUE is left unquoted,
dnl so it can reference other shell variables for example.
dnl
AC_DEFUN([CAIRO_ACCUMULATE_UNQUOTED],
[dnl
	_CAIRO_ACCUMULATE_UNQUOTED([$1], [$2], [CAIRO_$1="${CAIRO_$1}]m4_do([cr_acc_$1_sep])["]_CAIRO_SH_ESCAPE_UNQUOTED([$2]))dnl
])dnl

dnl
dnl CAIRO_ACCUMULATE_UNQUOTED_BEFORE(VAR, VALUE)
dnl
dnl Like CAIRO_ACCUMULATE_BEFORE but VALUE is left unquoted,
dnl so it can reference other shell variables for example.
dnl
AC_DEFUN([CAIRO_ACCUMULATE_UNQUOTED_BEFORE],
[dnl
	_CAIRO_ACCUMULATE_UNQUOTED([$1], [$2], [CAIRO_$1=]_CAIRO_SH_ESCAPE_UNQUOTED([$2])["]m4_do([cr_acc_$1_sep])[${CAIRO_$1}"])dnl
])dnl

dnl
dnl CAIRO_ACCUMULATE_UNQUOTED_UNCHECKED(VAR, VALUE)
dnl
dnl Like CAIRO_ACCUMULATE_UNQUOTED but VALUE is not tested for emptiness.
dnl
AC_DEFUN([CAIRO_ACCUMULATE_UNQUOTED_UNCHECKED],
[dnl
	_CAIRO_ACCUMULATE([$1], [$2], [CAIRO_$1="${CAIRO_$1}]m4_do([cr_acc_$1_sep])["]_CAIRO_SH_ESCAPE_UNQUOTED([$2]))dnl
])dnl

dnl
dnl CAIRO_ACCUMULATE_UNQUOTED_UNCHECKED_BEFORE(VAR, VALUE)
dnl
dnl Like CAIRO_ACCUMULATE_UNQUOTED_BEFORE but VALUE is not tested for emptiness.
dnl
AC_DEFUN([CAIRO_ACCUMULATE_UNQUOTED_BEFORE],
[dnl
	_CAIRO_ACCUMULATE([$1], [$2], [CAIRO_$1=]_CAIRO_SH_ESCAPE_UNQUOTED([$2])["]m4_do([cr_acc_$1_sep])[${CAIRO_$1}"])dnl
])dnl

dnl
dnl CAIRO_ACCUMULATORS_FOREACH(VAR, COMMANDS)
dnl 
dnl Run COMMANDS for each registered accumulator.
dnl Defines VAR to the accumulator being processed.
dnl
AC_DEFUN([CAIRO_ACCUMULATORS_FOREACH],
[dnl
	m4_foreach_w([$1], _CAIRO_ACCUMULATORS, [$2])dnl
])dnl


dnl ===========================================================================

m4_define([_CAIRO_ACCUMULATED_FEATURE_VARS])dnl

dnl
dnl CAIRO_ACCUMULATED_FEATURE_VARS_REGISTER(VARS, DEFAULT-VALUE=[], SEPARATOR=[], INITIAL-VALUE=[])
dnl
dnl Defines VARS as feature variables and accumulators.  Also accumulates
dnl (prepending, not appending) feature values for VARS.
dnl
AC_DEFUN([CAIRO_ACCUMULATED_FEATURE_VARS_REGISTER],
[dnl
	m4_foreach_w([cr_var], [$1],
		     [m4_append_uniq([_CAIRO_ACCUMULATED_FEATURE_VARS], cr_var, [ ],,
				     [m4_fatal([Accumulated feature variable `]cr_var[' already registered])])])dnl
	CAIRO_FEATURE_VARS_REGISTER([$1],[$2])dnl
	CAIRO_ACCUMULATORS_REGISTER_UNQUOTED([$1],[$3],[$4])dnl
])dnl

dnl
dnl CAIRO_ACCUMULATED_FEATURE_VARS_FOREACH(VAR, COMMANDS)
dnl 
dnl Run COMMANDS for each registered accumulated feature variable.
dnl Defines VAR to the variable being processed.
dnl
AC_DEFUN([CAIRO_ACCUMULATED_FEATURE_VARS_FOREACH],
[dnl
	m4_foreach_w([$1], _CAIRO_ACCUMULATED_FEATURE_VARS, [$2])dnl
])dnl

dnl ===========================================================================

dnl
dnl CAIRO_FEATURE_IF_ENABLED(FEATURE=cr_feature, COMMANDS)
dnl
dnl Run COMMANDS if FEATURE is enabled.
dnl
AC_DEFUN([CAIRO_FEATURE_IF_ENABLED],
[dnl
	AS_IF([test "x$use_]m4_default([$1], cr_feature)[" = xyes], [$2], [$3])dnl
])dnl

m4_define([_CAIRO_FEATURE_HOOK_MATCH_SH_BOOL],
[dnl
	m4_case([$1],
		[*],	[$3],
		[no],	[AS_IF([test "x$2" != xyes], [:m4_newline()$3])],
		[yes],	[AS_IF([test "x$2" = xyes], [:m4_newline()$3])],
			[m4_fatal([Invalid ENABLED value `]$1['])])dnl
])dnl

m4_define([_CAIRO_FEATURE_HOOK_MATCH_M4],
[dnl
	m4_case([$1],
		[*],	[$3],
		[$2],	[$3],
		[!$2],	,
			[m4_bmatch([$1], [^!], [$3])])dnl
])dnl

m4_define([_CAIRO_FEATURE_HOOKS])dnl

dnl
dnl CAIRO_FEATURE_HOOK_REGISTER(ENABLED, DEFAULT, WHAT, COMMANDS)
dnl
dnl	ENABLED is the feature enabledness to match
dnl	DEFAULT is the default value of features to match
dnl	WHAT is the type of features to match
dnl	COMMANDS is commands to run for matched features.
dnl
dnl Runs COMMANDS for features matching ENABLED, DEFAULT, and WHAT.
dnl Hooks are run for each feature in the order they are added.
dnl
dnl DEFAULT and WHAT are matched like this:
dnl	[*]	matches all values
dnl	[val]	matches [val]
dnl	[!val]	matches anything other than [val]
dnl
dnl ENABLED is matched like this:
dnl 	[yes]	matches enabled features
dnl 	[no]	matches disabled features
dnl 	[*]	matches all features
dnl
dnl The following macros can be used in COMMANDS:
dnl
dnl	cr_feature expands to the feature id, eg "ft"
dnl	cr_feature_name	expands to the human-readable name of the feature, eg. "FreeType font"
dnl	cr_feature_default expands to the default state of the feature:
dnl		"no" for experimental features, eg. your favorite new backend
dnl		"yes" for recommended features, eg. png functions
dnl		"auto" for other supported features, eg. xlib surface backend
dnl		"always" for mandatory features (can't be disabled), eg. image surface backend
dnl	cr_what expands to the type of feature:
dnl		"surface" for surface backends
dnl		"font" for font backends
dnl		"functions" for set of functions
dnl		"" for private configurations
dnl
dnl These four values are also set as $1 to $4.  To know if feature was
dnl enabled from within COMMANDS, use CAIRO_FEATURE_IF_ENABLED:
dnl
dnl	CAIRO_FEATURE_IF_ENABLED($1, [IF-ENABLED], [IF-DISABLED])
dnl
dnl or compare $use_$1 to string "yes".  As in:
dnl
dnl	AS_IF([test "x$use_$1" = "xyes"], [IF-ENABLED], [IF-DISABLED])
dnl
AC_DEFUN([CAIRO_FEATURE_HOOK_REGISTER],
[dnl
	m4_append([_CAIRO_FEATURE_HOOKS],
	[dnl
		_CAIRO_FEATURE_HOOK_MATCH_M4([$2], cr_feature_default,
		[_CAIRO_FEATURE_HOOK_MATCH_M4([$3], cr_feature_what,
		 [_CAIRO_FEATURE_HOOK_MATCH_SH_BOOL([$1], [$use_]cr_feature,
		  [$4]
		)])])dnl
	], m4_newline)dnl
])dnl

