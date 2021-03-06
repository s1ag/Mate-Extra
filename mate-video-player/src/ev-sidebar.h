/* ev-sidebar.h
 *  this file is part of evince, a mate document viewer
 * 
 * Copyright (C) 2004 Red Hat, Inc.
 *
 * Author:
 *   Jonathan Blandford <jrb@alum.mit.edu>
 *
 * Evince is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * Evince is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02110-1301  USA.
 *
 * Thursday 03 May 2007: Bastien Nocera: Add exception clause.
 * See license_change file for details.
 *
 */

#ifndef __EV_SIDEBAR_H__
#define __EV_SIDEBAR_H__

#include <gtk/gtk.h>

G_BEGIN_DECLS

typedef struct _EvSidebar EvSidebar;
typedef struct _EvSidebarClass EvSidebarClass;
typedef struct _EvSidebarPrivate EvSidebarPrivate;

#define EV_TYPE_SIDEBAR		     (ev_sidebar_get_type())
#define EV_SIDEBAR(object)	     (G_TYPE_CHECK_INSTANCE_CAST((object), EV_TYPE_SIDEBAR, EvSidebar))
#define EV_SIDEBAR_CLASS(klass)	     (G_TYPE_CHECK_CLASS_CAST((klass), EV_TYPE_SIDEBAR, EvSidebarClass))
#define EV_IS_SIDEBAR(object)	     (G_TYPE_CHECK_INSTANCE_TYPE((object), EV_TYPE_SIDEBAR))
#define EV_IS_SIDEBAR_CLASS(klass)   (G_TYPE_CHECK_CLASS_TYPE((klass), EV_TYPE_SIDEBAR))
#define EV_SIDEBAR_GET_CLASS(object) (G_TYPE_INSTANCE_GET_CLASS((object), EV_TYPE_SIDEBAR, EvSidebarClass))

struct _EvSidebar {
	GtkVBox base_instance;

	EvSidebarPrivate *priv;
};

struct _EvSidebarClass {
	GtkVBoxClass base_class;

	void (*closed) (EvSidebar *sidebar);
};

GType      ev_sidebar_get_type     (void);
GtkWidget *ev_sidebar_new          (void);
void       ev_sidebar_add_page     (EvSidebar   *ev_sidebar,
				    const gchar *page_id,
				    const gchar *title,
				    GtkWidget   *main_widget);
void       ev_sidebar_set_current_page
				   (EvSidebar *ev_sidebar,
				    const char *page_id);
char      *ev_sidebar_get_current_page
				   (EvSidebar *ev_sidebar);
void        ev_sidebar_remove_page (EvSidebar   *ev_sidebar,
				    const gchar *page_id);

G_END_DECLS

#endif /* __EV_SIDEBAR_H__ */


