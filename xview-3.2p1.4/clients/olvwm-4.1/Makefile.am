# Copyright (C) 2026 olvwm.xview@gmail.com
# SPDX-License-Identifier: GPL-3.0-only

bin_PROGRAMS = olvwm

AM_CPPFLAGS = $(SYS_INCLUDES) -std=c89 -DMAXPID=32768 -DOW_I18N_L3 -DSHAPE -DSYSV -DIDENT -D_DEFAULT_SOURCE

olvwm_SOURCES = \
	atom.c \
	client.c \
	cmdstream.c \
	cursors.c \
	debug.c \
	defaults.c \
	dsdm.c \
	environ.c \
	error.c \
	evbind.c \
	events.c \
	fontset.c \
	gettext.c \
	gif.c \
	group.c \
	helpsend.c \
	i18n.c \
	images.c \
	info.c \
	kbdfuncs.c \
	list.c \
	mem.c \
	menu.c \
	moveresize.c \
	notice.c \
	ol_button.413.c \
	ol_button.svr4.c \
	olvwmrc.y \
	olwm.c \
	pixmap.c \
	properties.c \
	reduce.c \
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
	virtual.c \
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

olvwm_LDADD = -lfl -lX11 -lXext -L${libdir} -lolgx

olvwmrc.o : parse.c
parse.c : parse.l
	flex -l -t $< > $@
