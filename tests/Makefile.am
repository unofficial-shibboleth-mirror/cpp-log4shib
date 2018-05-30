TESTS = testCategory testFixedContextCategory testNDC testPattern \
	testErrorCollision testPriority testFilter testProperties \
	testConfig testPropertyConfig sscpp706

check_PROGRAMS = $(TESTS)
check_DATA = log4shib.init log4shib.properties testProperties.properties \
	testConfig.log4shib.properties sscpp706.txt

EXTRA_DIST = log4shib.init log4shib.properties testProperties.properties \
	testConfig.log4shib.properties sscpp706.txt \
	testNTEventLog.cpp

noinst_PROGRAMS = testmain testbench sscpp706

AM_CPPFLAGS = -I$(top_srcdir)/include -I$(top_srcdir)/src

sscpp706_SOURCES = sscpp706.cpp
sscpp706_LDADD = $(top_builddir)/src/liblog4shib.la

testmain_SOURCES = testmain.cpp
testmain_LDADD = $(top_builddir)/src/liblog4shib.la

testCategory_SOURCES = testCategory.cpp
testCategory_LDADD = $(top_builddir)/src/liblog4shib.la

testFixedContextCategory_SOURCES = testFixedContextCategory.cpp
testFixedContextCategory_LDADD = $(top_builddir)/src/liblog4shib.la

testNDC_SOURCES = testNDC.cpp
testNDC_LDADD = $(top_builddir)/src/liblog4shib.la

testPattern_SOURCES = testPattern.cpp
testPattern_LDADD = $(top_builddir)/src/liblog4shib.la

testPriority_SOURCES = testPriority.cpp
testPriority_LDADD = $(top_builddir)/src/liblog4shib.la

testConfig_SOURCES = testConfig.cpp
testConfig_LDADD = $(top_builddir)/src/liblog4shib.la

testPropertyConfig_SOURCES = testPropertyConfig.cpp
testPropertyConfig_LDADD = $(top_builddir)/src/liblog4shib.la

testFilter_SOURCES = testFilter.cpp
testFilter_LDADD = $(top_builddir)/src/liblog4shib.la

testProperties_SOURCES = testProperties.cpp
testProperties_LDADD = $(top_builddir)/src/liblog4shib.la

testbench_SOURCES = Clock.cpp Clock.hh testbench.cpp 
testbench_LDADD = $(top_builddir)/src/liblog4shib.la

testErrorCollision_SOURCES = testErrorCollision.cpp
testErrorCollision_LDADD = $(top_builddir)/src/liblog4shib.la

distclean-local:
	$(RM) -f *.log
