AUTOMAKE_OPTIONS = gnu
SUBDIRS = . src


check-local: all
#       We build gtest this way, instead of using SUBDIRS, because with that,
#       gtest's own tests would be run and that would slow us down.
	@cd src/gtest && $(MAKE) $(AM_MAKEFLAGS) lib/libgtest.a lib/libgtest_main.a
#       exercise cli tools
#        $(srcdir)/src/test/run-cli-tests '$(top_builddir)/src/test'

# "make distclean" both runs this and recurses into src/gtest, if
# gtest is in DIST_SUBDIRS. Take extra care to not fail when
# effectively cleaned twice.
clean-local:
	@if test -e src/gtest/Makefile; then \
	  echo "Making clean in src/gtest"; \
	  cd src/gtest && $(MAKE) $(AM_MAKEFLAGS) clean; \
	fi