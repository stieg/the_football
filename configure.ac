#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_PREREQ([2.67])
AC_INIT([the-football], [0.1], [andrew.stiegmann@gmail.com])
AC_CONFIG_SRCDIR([the_football.c])
# AC_CONFIG_HEADERS([config.h])
AC_CONFIG_MACRO_DIR([build/m4])

AM_INIT_AUTOMAKE
# AM_MAINTAINER_MODE([enable])

# Checks for programs.
AC_PROG_CC

# Checks for libraries.
AC_CHECK_LIB([usb],
             [usb_init],
             [echo "Found libusb"],
             [echo "libusb is required for this program"
              exit -1])

# Glib check
PKG_CHECK_MODULES(GLIB,     [glib-2.0 >= 2.24.1])

# Checks for header files.

# Checks for typedefs, structures, and compiler characteristics.

# Checks for library functions.

AC_CONFIG_FILES([Makefile])

AC_OUTPUT
