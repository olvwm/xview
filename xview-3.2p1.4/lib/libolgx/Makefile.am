# Copyright (C) 2026 olvwm.xview@gmail.com
# SPDX-License-Identifier: GPL-3.0-only

lib_LTLIBRARIES = libolgx.la

libolgx_la_LDFLAGS = -version-number 3:2:4

libolgx_la_SOURCES = \
    ol_button.c \
    ol_color.c \
    ol_draw.c \
    ol_init.c \
    ol_misc.c \
    ol_sb.c \
    ol_slider.c

AM_CPPFLAGS = $(SYS_INCLUDES) -std=c89

${includedir}/olgx/olgx.h : olgx.h
	cp -a $< $@
