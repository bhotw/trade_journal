#include "../../include/views/dashboard_view.h"
#include "../../include/journal_appwin.h"

void show_dashboard_view(JournalAppWindow *win) {
    // Use the new clear content function
    journal_app_window_clear_content(win);
    
    GtkWidget *box = gtk_box_new(GTK_ORIENTATION_VERTICAL, 10);
    gtk_widget_set_margin_top(box, 10);
    gtk_widget_set_margin_bottom(box, 10);
    gtk_widget_set_margin_start(box, 10);
    gtk_widget_set_margin_end(box, 10);
    
    GtkWidget *title = gtk_label_new("Dashboard");
    gtk_label_set_markup(GTK_LABEL(title), "<big><b>Dashboard</b></big>");
    
    GtkWidget *summary_label = gtk_label_new("Trade Summary");
    
    // Example trade statistics
    GtkWidget *total_trades_label = gtk_label_new("Total Trades: 0");
    GtkWidget *profit_label = gtk_label_new("Total Profit: $0.00");
    
    gtk_box_append(GTK_BOX(box), title);
    gtk_box_append(GTK_BOX(box), summary_label);
    gtk_box_append(GTK_BOX(box), total_trades_label);
    gtk_box_append(GTK_BOX(box), profit_label);
    
    // Use the new get content box function
    gtk_box_append(GTK_BOX(journal_app_window_get_content_box(win)), box);
}