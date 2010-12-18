ACLOCAL_AMFLAGS = -I build/m4 ${ACLOCAL_FLAGS}
# DISTCHECK_CONFIGURE_FLAGS = --enable-maintainer-flags --enable-gtk-doc --enable-introspection

AUTOMAKE_OPTIONS = foreign

bin_PROGRAMS = the-football

the_football_SOURCES = the_football.c
the_football_CFLAGS=-Wall -I/usr/local/include -I/usr/include $(GLIB_CFLAGS)
the_football_LDFLAGS=-L/usr/local/lib -lusb $(GLIB_LIBS)

