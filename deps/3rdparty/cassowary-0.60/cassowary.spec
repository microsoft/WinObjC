# Note that this is NOT a relocatable package
%define ver 0.60
%define rel 1
%define prefix /usr

Name: cassowary
Summary: A Linear Arithmetic Constraint Solving Library.
Version: %ver
Release: %rel
Source: http://www.cs.washington.edu/research/constraints/cassowary/cassowary-%ver.tar.gz
Group: Development/Libraries
BuildRoot: /tmp/cassowary-%ver-build
Copyright: Copyright (C) 1998,1999 Greg J. Badros
Packager: Greg J. Badros <gjb@cs.washington.edu>
URL: http://www.cs.washington.edu/research/constraints/cassowary
Requires: guile >= 1.3.4
Requires: GTL >= 0.3.1
Provides: cassowary-constraint-solver

%description

Cassowary is an advanced incremental constraint solving toolkit that
efficiently solves systems of linear equalities and inequalities.
Constraints may be either requirements or preferences.  Client code
specifies the constraints to be maintained, and the solver updates the
constrained variables to have values that satisfy the constraints.

%changelog
* Tue Sep 7 1999 Greg J. Badros <gjb@cs.washington.edu)
- added provides virtual package "cassowary-constraint-solver" so that
  both this .spec and cassowary.spec can provide it

* Sat Sep 4 1999 Greg J. Badros <gjb@cs.washington.edu)
- Use -fpermissive if it is available, fix --enable-warnings

* Wed Aug 25 1999 Greg J. Badros <gjb@cs.washington.edu>
- Rework spec file.

* Wed Apr 14 1999 Greg J. Badros <gjb@cs.washington.edu>

- Initial release of this package.

%prep

%setup

%build
ln -sf . ./c++/cassowary

%ifarch alpha
fake_root_for_install=$RPM_BUILD_ROOT ./configure --host=alpha-linux --prefix=%prefix --with-gtl=%prefix --enable-fd-solver --enable-fsstd --enable-permissive
%else
fake_root_for_install=$RPM_BUILD_ROOT ./configure --prefix=%prefix --with-gtl=%prefix --enable-fd-solver --enable-fsstd --enable-permissive
%endif

make

%install
make prefix=$RPM_BUILD_ROOT%{prefix} fake_root_for_install=$RPM_BUILD_ROOT install-strip

%clean
rm -rf $RPM_BUILD_ROOT

%post

%postun

%files
%defattr(-, root, root)

%{prefix}/bin/*
%{prefix}/lib/*
%{prefix}/include/*

%doc ANNOUNCE AUTHORS COPYING IMPORTANT INSTALL LICENSE NEWS README THANKS
%doc ChangeLog docs/cassowary-tr.pdf docs/cassowary-tr.ps.gz
%doc guile/cassowary_scm-procedures.txt guile/cassowary_scm-variables.txt
%doc guile/cassowary_scm.sgml
