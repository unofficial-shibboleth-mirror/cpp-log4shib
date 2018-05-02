AUTOMAKE_OPTIONS = foreign dist-zip dist-bzip2
ACLOCAL_AMFLAGS = -I m4

if DOC
SUBDIRS = config src include tests doc 
else
SUBDIRS = config src include tests
endif

DIST_SUBDIRS = config src include doc tests

bin_SCRIPTS = log4shib-config

m4datadir = $(datadir)/aclocal
m4data_DATA = log4shib.m4

pkgconfigdir = $(libdir)/pkgconfig
pkgconfig_DATA = log4shib.pc

EXTRA_DIST = \
	log4shib.spec.in \
	log4shib.spec \
	log4shib.m4 \
	Portfile.in \
	Portfile \
	debian \
	msvc10 \
	msvc15

.PHONY: check rpm docs doc-dist

distclean-local:
	$(RM) CONTENTS TAGS log4shib-config

CONTENTS::
	find $(top_srcdir) \( ! -type l -a -name '*.cpp' -o -name '*.hh' -o -name Makefile.am \) > $@

TAGS:: CONTENTS
	etags `cat $<`

rpm: dist
	rpmbuild -ta $(PACKAGE)-$(VERSION).tar.gz
	mv -f /usr/src/redhat/SRPMS/$(PACKAGE)-$(VERSION)-*.rpm $(top_srcdir)
	mv -f /usr/src/redhat/RPMS/*/$(PACKAGE)-$(VERSION)-*.rpm $(top_srcdir)
	mv -f /usr/src/redhat/RPMS/*/$(PACKAGE)-devel-$(VERSION)-*.rpm \
		$(top_srcdir)
	mv -f /usr/src/redhat/RPMS/*/$(PACKAGE)-doc-$(VERSION)-*.rpm \
		$(top_srcdir)

debian:
	chmod a+x $(top_srcdir)/debian/rules
	dpkg-buildpackage -rfakeroot -sa -us -uc -tc 

docs:
	$(MAKE) -C doc

doc-dist: docs
	tar -zcf $(PACKAGE)-docs-$(VERSION).tar.gz -C $(top_srcdir)/doc/html . 
 
