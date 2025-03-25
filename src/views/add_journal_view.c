#include "../../include/views/add_journal_view.h"
#include "../../include/journal_appwin.h"

void show_add_journal_view(JournalAppWindow *win) {
    // Clear previous content
    journal_app_window_clear_content(win);
    
    GtkWidget *box = gtk_box_new(GTK_ORIENTATION_VERTICAL, 10);
    gtk_widget_set_margin_top(box, 10);
    gtk_widget_set_margin_bottom(box, 10);
    gtk_widget_set_margin_start(box, 10);
    gtk_widget_set_margin_end(box, 10);
    
    GtkWidget *title = gtk_label_new("Add Journal Entry");
    gtk_label_set_markup(GTK_LABEL(title), "<big><b>New Journal Entry</b></big>");
    
    GtkWidget *date_label = gtk_label_new("Date:");
    GtkWidget *date_entry = gtk_entry_new();
    
    GtkWidget *title_label = gtk_label_new("Title:");
    GtkWidget *title_entry = gtk_entry_new();
    
    GtkWidget *notes_label = gtk_label_new("Notes:");
    GtkWidget *notes_view = gtk_text_view_new();
    GtkWidget *notes_scroll = gtk_scrolled_window_new();
    gtk_scrolled_window_set_child(GTK_SCROLLED_WINDOW(notes_scroll), notes_view);
    gtk_widget_set_vexpand(notes_scroll, TRUE);
    
    GtkWidget *image_label = gtk_label_new("Attach Images:");
    GtkWidget *image_button = gtk_button_new_with_label("Select Images");
    
    GtkWidget *save_button = gtk_button_new_with_label("Save Journal Entry");
    
    gtk_box_append(GTK_BOX(box), title);
    gtk_box_append(GTK_BOX(box), date_label);
    gtk_box_append(GTK_BOX(box), date_entry);
    gtk_box_append(GTK_BOX(box), title_label);
    gtk_box_append(GTK_BOX(box), title_entry);
    gtk_box_append(GTK_BOX(box), notes_label);
    gtk_box_append(GTK_BOX(box), notes_scroll);
    gtk_box_append(GTK_BOX(box), image_label);
    gtk_box_append(GTK_BOX(box), image_button);
    gtk_box_append(GTK_BOX(box), save_button);
    
    // Use the window method to get content box
    GtkWidget *content_box = journal_app_window_get_content_box(win);
    gtk_box_append(GTK_BOX(content_box), box);
}