# Copyright (C) 2021-2026 olvwm.xview@gmail.com
# SPDX-License-Identifier: GPL-3.0-only

all : libs olvwm clients

install : install-libs install-olvwm install-clients

dep :
	bash -x install_deps
libs :
	(cd xview-3.2p1.4; bash Build-LinuxXView.bash libs)

install-libs :
	(cd xview-3.2p1.4; make SUBDIRS='lib' install)

olvwm :
	(cd xview-3.2p1.4; bash Build-LinuxXView.bash olvwm)

install-olvwm :
	(cd xview-3.2p1.4/clients; make SUBDIRS='olvwm-4.1' install)

clients :
	(cd xview-3.2p1.4; bash Build-LinuxXView.bash clients)

install-clients :
	(cd xview-3.2p1.4; make SUBDIRS='clients' install)

olgxauto : ../build/lib/libolgx.so

../build/lib/libolgx.so : xview-3.2p1.4/lib/libolgx/.libs/libolgx.so
	(cd xview-3.2p1.4/lib/libolgx ; make install)

xview-3.2p1.4/lib/libolgx/.libs/libolgx.so : xview-3.2p1.4/lib/libolgx/Makefile ../build/include/olgx/olgx.h
	(cd xview-3.2p1.4/lib/libolgx ; make)

xview-3.2p1.4/lib/libolgx/Makefile : xview-3.2p1.4/configure
	(cd xview-3.2p1.4 ; ./configure --prefix=$$(realpath ../../build))

xview-3.2p1.4/configure : xview-3.2p1.4/m4/libtool.m4 xview-3.2p1.4/configure.ac
	(cd xview-3.2p1.4 ; autoreconf -i)

xview-3.2p1.4/m4/libtool.m4 : xview-3.2p1.4/configure.ac
	(cd xview-3.2p1.4 ; libtoolize --copy)

../build/include/olgx/olgx.h : xview-3.2p1.4/lib/libolgx/olgx.h
	(cd xview-3.2p1.4/lib/libolgx ; mkdir -p ../../../../build/include/olgx)
	(cd xview-3.2p1.4/lib/libolgx ; make $$(realpath ../../../../build/include/olgx/olgx.h))

autoclean :
	git clean -fdx

clean :
	(cd xview-3.2p1.4; make clean distclean Clean)
	(cd xview-3.2p1.4; bash Build-LinuxXView.bash clean)
	rm -rf xview-3.2p1.4/build
