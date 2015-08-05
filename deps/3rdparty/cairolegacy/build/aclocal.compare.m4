dnl @synopsis AX_COMPARE_VERSION(VERSION_A, OP, VERSION_B, [ACTION-IF-TRUE], [ACTION-IF-FALSE])
dnl
dnl This macro compares two version strings. It is used heavily in the
dnl macro _AX_PATH_BDB for library checking. Due to the various number
dnl of minor-version numbers that can exist, and the fact that string
dnl comparisons are not compatible with numeric comparisons, this is
dnl not necessarily trivial to do in a autoconf script. This macro
dnl makes doing these comparisons easy.
dnl
dnl The six basic comparisons are available, as well as checking
dnl equality limited to a certain number of minor-version levels.
dnl
dnl The operator OP determines what type of comparison to do, and can
dnl be one of:
dnl
dnl  eq  - equal (test A == B)
dnl  ne  - not equal (test A != B)
dnl  le  - less than or equal (test A <= B)
dnl  ge  - greater than or equal (test A >= B)
dnl  lt  - less than (test A < B)
dnl  gt  - greater than (test A > B)
dnl
dnl Additionally, the eq and ne operator can have a number after it to
dnl limit the test to that number of minor versions.
dnl
dnl  eq0 - equal up to the length of the shorter version
dnl  ne0 - not equal up to the length of the shorter version
dnl  eqN - equal up to N sub-version levels
dnl  neN - not equal up to N sub-version levels
dnl
dnl When the condition is true, shell commands ACTION-IF-TRUE are run,
dnl otherwise shell commands ACTION-IF-FALSE are run. The environment
dnl variable 'ax_compare_version' is always set to either 'true' or
dnl 'false' as well.
dnl
dnl Examples:
dnl
dnl   AX_COMPARE_VERSION([3.15.7],[lt],[3.15.8])
dnl   AX_COMPARE_VERSION([3.15],[lt],[3.15.8])
dnl
dnl would both be true.
dnl
dnl   AX_COMPARE_VERSION([3.15.7],[eq],[3.15.8])
dnl   AX_COMPARE_VERSION([3.15],[gt],[3.15.8])
dnl
dnl would both be false.
dnl
dnl   AX_COMPARE_VERSION([3.15.7],[eq2],[3.15.8])
dnl
dnl would be true because it is only comparing two minor versions.
dnl
dnl   AX_COMPARE_VERSION([3.15.7],[eq0],[3.15])
dnl
dnl would be true because it is only comparing the lesser number of
dnl minor versions of the two values.
dnl
dnl Note: The characters that separate the version numbers do not
dnl matter. An empty string is the same as version 0. OP is evaluated
dnl by autoconf, not configure, so must be a string, not a variable.
dnl
dnl The author would like to acknowledge Guido Draheim whose advice
dnl about the m4_case and m4_ifvaln functions make this macro only
dnl include the portions necessary to perform the specific comparison
dnl specified by the OP argument in the final configure script.
dnl
dnl @category Misc
dnl @author Tim Toolan <toolan@ele.uri.edu>
dnl @version 2004-03-01
dnl @license GPLWithACException

dnl #########################################################################
AC_DEFUN([AX_COMPARE_VERSION], [
  # Used to indicate true or false condition
  ax_compare_version=false

  # Convert the two version strings to be compared into a format that
  # allows a simple string comparison.  The end result is that a version
  # string of the form 1.12.5-r617 will be converted to the form
  # 0001001200050617.  In other words, each number is zero padded to four
  # digits, and non digits are removed.
  AS_VAR_PUSHDEF([A],[ax_compare_version_A])
  A=`echo "$1" | sed -e 's/\([[0-9]]*\)/Z\1Z/g' \
                     -e 's/Z\([[0-9]]\)Z/Z0\1Z/g' \
                     -e 's/Z\([[0-9]][[0-9]]\)Z/Z0\1Z/g' \
                     -e 's/Z\([[0-9]][[0-9]][[0-9]]\)Z/Z0\1Z/g' \
                     -e 's/[[^0-9]]//g'`

  AS_VAR_PUSHDEF([B],[ax_compare_version_B])
  B=`echo "$3" | sed -e 's/\([[0-9]]*\)/Z\1Z/g' \
                     -e 's/Z\([[0-9]]\)Z/Z0\1Z/g' \
                     -e 's/Z\([[0-9]][[0-9]]\)Z/Z0\1Z/g' \
                     -e 's/Z\([[0-9]][[0-9]][[0-9]]\)Z/Z0\1Z/g' \
                     -e 's/[[^0-9]]//g'`

  dnl # In the case of le, ge, lt, and gt, the strings are sorted as necessary
  dnl # then the first line is used to determine if the condition is true.
  dnl # The sed right after the echo is to remove any indented white space.
  m4_case(m4_tolower($2),
  [lt],[
    ax_compare_version=`echo "x$A
x$B" | sed 's/^ *//' | sort -r | sed "s/x${A}/false/;s/x${B}/true/;1q"`
  ],
  [gt],[
    ax_compare_version=`echo "x$A
x$B" | sed 's/^ *//' | sort | sed "s/x${A}/false/;s/x${B}/true/;1q"`
  ],
  [le],[
    ax_compare_version=`echo "x$A
x$B" | sed 's/^ *//' | sort | sed "s/x${A}/true/;s/x${B}/false/;1q"`
  ],
  [ge],[
    ax_compare_version=`echo "x$A
x$B" | sed 's/^ *//' | sort -r | sed "s/x${A}/true/;s/x${B}/false/;1q"`
  ],[
    dnl Split the operator from the subversion count if present.
    m4_bmatch(m4_substr($2,2),
    [0],[
      # A count of zero means use the length of the shorter version.
      # Determine the number of characters in A and B.
      ax_compare_version_len_A=`echo "$A" | awk '{print(length)}'`
      ax_compare_version_len_B=`echo "$B" | awk '{print(length)}'`

      # Set A to no more than B's length and B to no more than A's length.
      A=`echo "$A" | sed "s/\(.\{$ax_compare_version_len_B\}\).*/\1/"`
      B=`echo "$B" | sed "s/\(.\{$ax_compare_version_len_A\}\).*/\1/"`
    ],
    [[0-9]+],[
      # A count greater than zero means use only that many subversions
      A=`echo "$A" | sed "s/\(\([[0-9]]\{4\}\)\{m4_substr($2,2)\}\).*/\1/"`
      B=`echo "$B" | sed "s/\(\([[0-9]]\{4\}\)\{m4_substr($2,2)\}\).*/\1/"`
    ],
    [.+],[
      AC_WARNING(
        [illegal OP numeric parameter: $2])
    ],[])

    # Pad zeros at end of numbers to make same length.
    ax_compare_version_tmp_A="$A`echo $B | sed 's/./0/g'`"
    B="$B`echo $A | sed 's/./0/g'`"
    A="$ax_compare_version_tmp_A"

    # Check for equality or inequality as necessary.
    m4_case(m4_tolower(m4_substr($2,0,2)),
    [eq],[
      test "x$A" = "x$B" && ax_compare_version=true
    ],
    [ne],[
      test "x$A" != "x$B" && ax_compare_version=true
    ],[
      AC_WARNING([illegal OP parameter: $2])
    ])
  ])

  AS_VAR_POPDEF([A])dnl
  AS_VAR_POPDEF([B])dnl

  dnl # Execute ACTION-IF-TRUE / ACTION-IF-FALSE.
  if test "$ax_compare_version" = "true" ; then
    m4_ifvaln([$4],[$4],[:])dnl
    m4_ifvaln([$5],[else $5])dnl
  fi
]) dnl AX_COMPARE_VERSION
