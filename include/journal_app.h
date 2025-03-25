#pragma once

#include <gtk/gtk.h>

#define JOURNAL_APP_TYPE (journal_app_get_type ())
G_DECLARE_FINAL_TYPE (JournalApp, journal_app, JOURNAL, APP, GtkApplication)

JournalApp *journal_app_new (void);