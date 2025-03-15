#include <gtk/gtk.h>

#include "../include/journal_app.h"
#include "../include/journal_appwin.h"


struct _JournalApp
{
  GtkApplication parent;
};

G_DEFINE_TYPE(JournalApp, journal_app, GTK_TYPE_APPLICATION);

static void
journal_app_init (JournalApp *app)
{
}

static void preferences_activated (GSimpleAction *action, GVariant *parameter, gpointer app) 
{

}

static void quit_activated (GSimpleAction *action, GVariant *parameter, gpointer app) 
{
  g_application_quit (G_APPLICATION (app));
}

static GActionEntry app_entries[] = {
  { "preferences", preferences_activated, NULL, NULL, NULL },
  { "quit", quit_activated, NULL, NULL, NULL }
};

static void journal_app_startup (GApplication *app)
{
  const char *quit_accels[] = { "<Ctrl>Q", NULL };

  G_APPLICATION_CLASS (journal_app_parent_class)->startup (app);

  g_action_map_add_action_entries (G_ACTION_MAP (app), app_entries, G_N_ELEMENTS (app_entries), app);

  gtk_application_set_accels_for_action (GTK_APPLICATION (app), "app.quit", quit_accels);
}

static void
journal_app_activate (GApplication *app)
{
  JournalAppWindow *win;

  win = journal_app_window_new (JOURNAL_APP (app));
  gtk_window_present (GTK_WINDOW (win));
}

static void
journal_app_open (GApplication  *app,
                  GFile        **files,
                  int            n_files,
                  const char    *hint)
{
  GList *windows;
  JournalAppWindow *win;
  int i;

  windows = gtk_application_get_windows (GTK_APPLICATION (app));
  if (windows)
    win = JOURNAL_APP_WINDOW (windows->data);
  else
    win = journal_app_window_new (JOURNAL_APP (app));

  for (i = 0; i < n_files; i++)
    journal_app_window_open (win, files[i]);

  gtk_window_present (GTK_WINDOW (win));
}

static void
journal_app_class_init (JournalAppClass *class)
{
  G_APPLICATION_CLASS (class)->startup = journal_app_startup;
  G_APPLICATION_CLASS (class)->activate = journal_app_activate;
  G_APPLICATION_CLASS (class)->open = journal_app_open;
}

JournalApp *
journal_app_new (void)
{
  return g_object_new (JOURNAL_APP_TYPE,
                       "application-id", "org.gtk.journalapp",
                       "flags", G_APPLICATION_HANDLES_OPEN,
                       NULL);
}
