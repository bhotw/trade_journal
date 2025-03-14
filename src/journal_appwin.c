#include <gtk/gtk.h>

#include "../include/journal_appwin.h"
#include "../include/journal_app.h"

struct _JournalAppWindow
{
  GtkApplicationWindow parent;
};

G_DEFINE_TYPE(JournalAppWindow, journal_app_window, GTK_TYPE_APPLICATION_WINDOW);

static void journal_app_window_init (JournalAppWindow *win)
{
  gtk_widget_init_template (GTK_WIDGET (win));
}



static void journal_app_window_class_init (JournalAppWindowClass *class) {
    gtk_widget_class_set_template_from_resource(GTK_WIDGET_CLASS(class), "/journal_app/ui/window.ui");
}


JournalAppWindow *journal_app_window_new(JournalApp *app) {
    return g_object_new (JOURNAL_TYPE_APP_WINDOW, "application", app, NULL);
}

void journal_app_window_open(JournalAppWindow *win, GFile * file) {
}