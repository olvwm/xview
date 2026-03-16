# Copyright (C) 2026 olvwm.xview@gmail.com
# SPDX-License-Identifier: GPL-3.0-only

bin_PROGRAMS = olwm

AM_CPPFLAGS = $(SYS_INCLUDES) -std=c89 -DMAXPID=32768 -DOW_I18N_L3 -DSHAPE -DSYSV -DIDENT -D_DEFAULT_SOURCE

olwm_SOURCES = \
	atom.c \
	client.c \
	cmdstream.c \
	debug.c \
	defaults.c \
	dsdm.c \
	environ.c \
	error.c \
	evbind.c \
	events.c \
	fontset.c \
	gettext.c \
	group.c \
	helpsend.c \
	i18n.c \
	info.c \
	kbdfuncs.c \
	list.c \
	mem.c \
	menu.c \
	moveresize.c \
	notice.c \
	olwm.c \
	properties.c \
	resources.c \
	screen.c \
	selection.c \
	services.c \
	slave.c \
	slots.c \
	states.c \
	st.c \
	usermenu.c \
	usleep.c \
	winbusy.c \
	winbutton.c \
	win.c \
	wincolor.c \
	winframe.c \
	wingframe.c \
	winicon.c \
	winipane.c \
	winmenu.c \
	winnofoc.c \
	winpane.c \
	winpinmenu.c \
	winpush.c \
	winresize.c \
	winroot.c

olwm_LDADD = -lX11 -lXext -L${libdir} -lolgx
