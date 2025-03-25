#pragma once

#include <gtk/gtk.h>
#include "journal_app.h"

#define JOURNAL_TYPE_APP_WINDOW (journal_app_window_get_type())
G_DECLARE_FINAL_TYPE(JournalAppWindow, journal_app_window, JOURNAL, APP_WINDOW, GtkApplicationWindow)

// Add these function declarations
GtkWidget* journal_app_window_get_content_box(JournalAppWindow *win);
void journal_app_window_clear_content(JournalAppWindow *win);

JournalAppWindow *journal_app_window_new(JournalApp *app);
void journal_app_window_open(JournalAppWindow *win, GFile *file);