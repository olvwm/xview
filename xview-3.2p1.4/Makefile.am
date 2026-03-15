# Copyright (C) 2026 olvwm.xview@gmail.com
# SPDX-License-Identifier: GPL-3.0-only

SUBDIRS = lib

ACLOCAL_AMFLAGS = -I m4

EXTRA_DIST = config/XView.tmpl config/XView.rules config/XView.cf \
             config/XView.lib config/XView.obj config/XView.prog \
             debian/ fonts/ images/ bitmaps/ misc/ util/ contrib/ doc/

install-data-hook:
	@echo "XView installation complete"
	@echo "Set LD_LIBRARY_PATH to include $(libdir)"
