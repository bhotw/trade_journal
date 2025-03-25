#pragma once

#include <gtk/gtk.h>
#include "../../include/journal_appwin.h"
#include "../models/trade.h"

// Show add trade form
void show_add_trade_view(JournalAppWindow *win);

// Callback for saving trade
void on_save_trade(GtkButton *button, gpointer user_data);

// Create image selector widget
GtkWidget* create_trade_image_selector();