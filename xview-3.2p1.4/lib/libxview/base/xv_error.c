#ifndef lint
#ifdef sccs
static char     sccsid[] = "@(#)xv_error.c 1.36 93/06/28";
#endif
#endif

/*
 *	(c) Copyright 1989 Sun Microsystems, Inc. Sun design patents 
 *	pending in the U.S. and foreign countries. See LEGAL NOTICE 
 *	file for terms of the license.
 */

#include <stdio.h>
#include <xview/pkg_public.h>
#include <X11/Xlib.h>
#include <xview_private/i18n_impl.h>
#include <xview_private/portable.h>

/* Unix system error variables */
extern int      sys_nerr;
extern char    *sys_errlist[];
extern int      errno;

#ifndef __linux
/* Global already defined in xv_init.c */
Xv_private_data char *xv_app_name;
#else
extern Xv_private_data char *xv_app_name;
#endif
Xv_private int (*xv_error_proc) ();

/*
 * xv_error_format - Process the avlist and generate a formatted error message
 * of up to ERROR_MAX_STRING_SIZE characters, which has one NEW LINE character
 * at the end.
 */
Xv_public char *
xv_error_format(object, avlist)
    Xv_object       object;
    Attr_avlist	    avlist;
{
    static char	    msg[ERROR_MAX_STRING_SIZE]; /* formatted error message */

    Attr_avlist     attrs;
#define BUFSIZE 128
    char            buf[BUFSIZE];	/* to hold reason for error */
    Display	   *dpy;
    char	   *error_string = NULL;
    Error_layer	    layer = ERROR_TOOLKIT;
#define LMSGSIZE 128
    char	    layer_msg[LMSGSIZE]; /* to hold layer message */
    char	   *layer_name;
    int		    length;
    char           *pkg_name = NULL;
    char	   *severity = "warning";
    XErrorEvent    *xerror = NULL;

    buf[0] = 0;
    for (attrs = avlist; *attrs; attrs = attr_next(attrs)) {
	switch ((int) attrs[0]) {
	  case ERROR_BAD_ATTR:
	    sprintf(buf, 
		XV_MSG("bad attribute, %s"), 
		attr_name(attrs[1]));
	    break;
	  case ERROR_BAD_VALUE:
	    sprintf(buf, 
		XV_MSG("bad value (0x%x) for attribute %s"), 
		attrs[1],
		attr_name(attrs[2]));
	    break;
	  case ERROR_CANNOT_GET:
	    sprintf(buf, 
		XV_MSG("cannot get %s"), 
		attr_name(attrs[1]));
	    break;
	  case ERROR_CANNOT_SET:
	    sprintf(buf, 
		XV_MSG("cannot set %s"), 
		attr_name(attrs[1]));
	    break;
	  case ERROR_CREATE_ONLY:
	    sprintf(buf, 
		XV_MSG("%s only valid in xv_create"),
		    attr_name(attrs[1]));
	    break;
	  case ERROR_INVALID_OBJECT:
	    sprintf(buf, 
		XV_MSG("invalid object (%s)"), 
		(char *) attrs[1]);
	    break;
	  case ERROR_LAYER:
	    if ((unsigned int) attrs[1] <= (unsigned int) ERROR_PROGRAM)
	        layer = (Error_layer) attrs[1];
	    break;
	  case ERROR_PKG:
	    pkg_name = ((Xv_pkg *) attrs[1])->name;
	    break;
	  case ERROR_SERVER_ERROR:
	    xerror = (XErrorEvent *) attrs[1];
	    break;
	  case ERROR_SEVERITY:
	    if ((Error_severity) attrs[1] == ERROR_NON_RECOVERABLE)
		severity = XV_MSG("error");
	    break;
	  case ERROR_STRING:
	    error_string = (char *) attrs[1];
	    break;
	}
    }

    switch (layer) {
      case ERROR_SYSTEM:
	layer_name = XV_MSG("System");
	if ((int) errno < sys_nerr)
	    sprintf(layer_msg, "%s", sys_errlist[(int) errno]);
	else
	    sprintf(layer_msg, XV_MSG("unix error %d"), 
		(int) errno);
	break;
      case ERROR_SERVER:
	layer_name = XV_MSG("Server");
	if (xerror) {
	    dpy = xerror->display;
	    XGetErrorText(dpy, (int) xerror->error_code, layer_msg, LMSGSIZE);
	} else
	    strcpy(layer_msg, XV_MSG("error unknown"));
	break;
      case ERROR_TOOLKIT:
	layer_name = XV_MSG("XView");
	layer_msg[0] = 0;
	break;
      case ERROR_PROGRAM:
	layer_name = xv_app_name;
	layer_msg[0] = 0;
	break;
    }
    if (!object)
	sprintf(msg, "%s %s:", layer_name, severity);
    else
	sprintf(msg, XV_MSG("%s %s: Object 0x%x,"), 
		layer_name, severity, object);
    if (layer_msg[0]) {
	strcat(msg, " ");
	strcat(msg, layer_msg);
    }
    if (buf[0]) {
	strcat(msg, " ");
	strcat(msg, buf);
    }
    if (error_string) {
	/* Append ERROR_STRING, stripping off trailing New Lines. */
	length = strlen(error_string);
	while (length && error_string[length-1] == '\n')
	    length--;
	if (length) {
	    if (layer_msg[0] || buf[0])
		strcat(msg, ", ");
	    else
		strcat(msg, " ");
	    strncat(msg, error_string, length);
	}
    }
    if (pkg_name)
	sprintf(msg, XV_MSG("%s (%s package)\n"), 
		msg, pkg_name);
    else
	strcat(msg, "\n");
    return msg;
}


/*
 * xv_error_default - default error routine called by xv_error() (below).
 * Print the formatted error message generated by xv_error_format to stderr.
 * If ERROR_SEVERITY is ERROR_RECOVERABLE, xv_error_default returns to the
 * caller with XV_OK.  Otherwise, the program is aborted with an exit(1).
 */
Xv_public int
xv_error_default(object, avlist)
    Xv_object       object;
    Attr_avlist	    avlist;
{
    Attr_attribute *attrs;
    Error_severity severity = ERROR_RECOVERABLE;

    fprintf(stderr, "%s", xv_error_format(object, avlist));

    for (attrs = avlist; *attrs; attrs = attr_next(attrs))
	switch (attrs[0]) {
	  case ERROR_SEVERITY:
	    severity = (Error_severity) attrs[1];
	    break;
	}

    if (severity != ERROR_RECOVERABLE)
	exit(1);
    return XV_OK;
}


Xv_public int
#ifdef ANSI_FUNC_PROTO
xv_error(Xv_object object, ...)
#else
xv_error(object, va_alist)
    Xv_object object;
va_dcl
#endif
{
    va_list         valist;
    AVLIST_DECL;

    VA_START(valist, object);
    MAKE_AVLIST( valist, avlist );
    va_end(valist);

    if (xv_error_proc)
	return ((*xv_error_proc) (object, avlist));
    else
	return (xv_error_default(object, avlist));
}
