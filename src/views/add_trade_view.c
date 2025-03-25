#include "../../include/views/add_trade_view.h"
#include "../../include/journal_appwin.h"

void show_add_trade_view(JournalAppWindow *win) {
    // Clear previous content
    journal_app_window_clear_content(win);
    
    GtkWidget *box = gtk_box_new(GTK_ORIENTATION_VERTICAL, 10);
    gtk_widget_set_margin_top(box, 10);
    gtk_widget_set_margin_bottom(box, 10);
    gtk_widget_set_margin_start(box, 10);
    gtk_widget_set_margin_end(box, 10);
    
    GtkWidget *title = gtk_label_new("Add Trade");
    gtk_label_set_markup(GTK_LABEL(title), "<big><b>New Trade Entry</b></big>");
    
    // Trade entry form
    GtkWidget *symbol_label = gtk_label_new("Symbol:");
    GtkWidget *symbol_entry = gtk_entry_new();
    
    GtkWidget *date_label = gtk_label_new("Date:");
    GtkWidget *date_entry = gtk_entry_new();
    
    GtkWidget *save_button = gtk_button_new_with_label("Save Trade");
    
    gtk_box_append(GTK_BOX(box), title);
    gtk_box_append(GTK_BOX(box), symbol_label);
    gtk_box_append(GTK_BOX(box), symbol_entry);
    gtk_box_append(GTK_BOX(box), date_label);
    gtk_box_append(GTK_BOX(box), date_entry);
    gtk_box_append(GTK_BOX(box), save_button);
    
    // Use the window method to get content box
    GtkWidget *content_box = journal_app_window_get_content_box(win);
    gtk_box_append(GTK_BOX(content_box), box);
}