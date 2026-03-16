#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.
#
# Copyright (C) 2026 olvwm.xview@gmail.com
# SPDX-License-Identifier: GPL-3.0-only

AC_INIT([xview], [3.2p1.4], [olvwm.xview@gmail.com])
AC_CONFIG_SRCDIR([lib/libolgx/ol_button.c])
AC_CONFIG_HEADERS([config.h])

AM_INIT_AUTOMAKE([-Wall -Werror foreign subdir-objects])
AC_CONFIG_MACRO_DIRS([m4])

# Checks for programs.
AC_PROG_AWK
AC_PROG_YACC
AC_PROG_CPP
AC_PROG_CXX
AC_PROG_CC
AC_PROG_LEX([yywrap])
AC_PROG_INSTALL
AC_PROG_MAKE_SET
AC_PROG_LN_S

AM_PROG_AR

# Check for libtool (for shared libraries)
LT_INIT

# Compiler flags
AC_SUBST([CFLAGS], ["-O2 -fPIC"])
SYS_INCLUDES="-isystem ${prefix}/include"
AC_SUBST([SYS_INCLUDES])

# Checks for header files.
AC_PATH_X
AC_PATH_XTRA
if test "$no_x" = yes; then
  AC_MSG_ERROR([X development libraries not found])
fi

AC_CHECK_HEADERS([fcntl.h malloc.h netdb.h netinet/in.h strings.h sys/file.h sys/ioctl.h sys/param.h sys/socket.h sys/systeminfo.h sys/time.h termio.h termios.h unistd.h utmp.h utmpx.h values.h])

# Checks for typedefs, structures, and compiler characteristics.
AC_CHECK_HEADER_STDBOOL
AC_TYPE_UID_T
AC_TYPE_OFF_T
AC_TYPE_PID_T
AC_TYPE_SIZE_T
AC_CHECK_MEMBERS([struct stat.st_rdev])

# Checks for library functions.
AC_FUNC_FORK
AC_FUNC_MALLOC
AC_FUNC_MMAP
AC_FUNC_REALLOC
AC_FUNC_STRTOD
AC_CHECK_FUNCS([bzero dup2 getcwd gethostname getpagesize gettimeofday isascii iswprint mblen memchr memmove memset pathconf putenv regcomp rint select setenv setlocale strchr strdup strerror strpbrk strrchr strspn strtol sysinfo uname])

# Add X11 flags to global variables
CPPFLAGS="$CPPFLAGS $X_CFLAGS"
LIBS="$LIBS $X_LIBS -lX11"

AC_CONFIG_FILES([
	Makefile
	lib/Makefile
	lib/libolgx/Makefile
	clients/olvwm-4.1/Makefile
])

AC_OUTPUT
