#include "../../include/views/feed_view.h"
#include "../../include/journal_appwin.h"

void show_feed_view(
    JournalAppWindow *win, 
    TradeFilterType filter G_GNUC_UNUSED, 
    TradeSortType sort G_GNUC_UNUSED
) {
    // Clear previous content using the window method
    journal_app_window_clear_content(win);
    
    GtkWidget *box = gtk_box_new(GTK_ORIENTATION_VERTICAL, 10);
    gtk_widget_set_margin_top(box, 10);
    gtk_widget_set_margin_bottom(box, 10);
    gtk_widget_set_margin_start(box, 10);
    gtk_widget_set_margin_end(box, 10);
    
    GtkWidget *title = gtk_label_new("Trade Feed");
    gtk_label_set_markup(GTK_LABEL(title), "<big><b>Recent Trades</b></big>");
    
    // Example trade feed (would be populated from a database/file in real app)
    GtkWidget *trade1 = gtk_label_new("AAPL - Buy 10 shares at $150.00");
    GtkWidget *trade2 = gtk_label_new("GOOGL - Sell 5 shares at $2500.00");
    
    gtk_box_append(GTK_BOX(box), title);
    gtk_box_append(GTK_BOX(box), trade1);
    gtk_box_append(GTK_BOX(box), trade2);
    
    // Use the window method to get content box
    GtkWidget *content_box = journal_app_window_get_content_box(win);
    gtk_box_append(GTK_BOX(content_box), box);
}