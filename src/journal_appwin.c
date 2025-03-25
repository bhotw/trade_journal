#include <gtk/gtk.h>
#include "../include/journal_appwin.h"
#include "../include/journal_app.h"
#include "../include/views/dashboard_view.h"
#include "../include/views/feed_view.h"
#include "../include/views/add_trade_view.h"
#include "../include/views/add_journal_view.h"

struct _JournalAppWindow {
    GtkApplicationWindow parent;
    
    // Main content area
    GtkWidget *content_box;
    
    // Buttons for switching views
    GtkWidget *btn_dashboard;
    GtkWidget *btn_feed;
    GtkWidget *btn_add_trade;
    GtkWidget *btn_add_journal;
};

G_DEFINE_TYPE(JournalAppWindow, journal_app_window, GTK_TYPE_APPLICATION_WINDOW)

// Add these functions
GtkWidget* 
journal_app_window_get_content_box(JournalAppWindow *win) {
    return win->content_box;
}

void 
journal_app_window_clear_content(JournalAppWindow *win) {
    GtkWidget *child;
    while ((child = gtk_widget_get_first_child(win->content_box))) {
        gtk_box_remove(GTK_BOX(win->content_box), child);
    }
}

// Button click handlers
static void
on_dashboard_clicked(GtkButton *button, gpointer user_data) {
    JournalAppWindow *win = JOURNAL_APP_WINDOW(user_data);
    show_dashboard_view(win);
}

static void
on_feed_clicked(GtkButton *button, gpointer user_data) {
    JournalAppWindow *win = JOURNAL_APP_WINDOW(user_data);
    show_feed_view(win, FILTER_ALL, SORT_BY_EXIT_DATE);
}

static void
on_add_trade_clicked(GtkButton *button, gpointer user_data) {
    JournalAppWindow *win = JOURNAL_APP_WINDOW(user_data);
    show_add_trade_view(win);
}

static void
on_add_journal_clicked(GtkButton *button, gpointer user_data) {
    JournalAppWindow *win = JOURNAL_APP_WINDOW(user_data);
    show_add_journal_view(win);
}

// Window initialization
static void
journal_app_window_init(JournalAppWindow *win) {
    // Create main window layout
    GtkWidget *main_box = gtk_box_new(GTK_ORIENTATION_VERTICAL, 0);
    
    // Create button box
    GtkWidget *button_box = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 10);
    gtk_box_set_homogeneous(GTK_BOX(button_box), TRUE);
    gtk_widget_set_margin_top(button_box, 10);
    gtk_widget_set_margin_bottom(button_box, 10);
    
    // Create buttons
    win->btn_dashboard = gtk_button_new_with_label("Dashboard");
    win->btn_feed = gtk_button_new_with_label("Feed");
    win->btn_add_trade = gtk_button_new_with_label("Add Trade");
    win->btn_add_journal = gtk_button_new_with_label("Add Journal");
    
    // Connect button signals
    g_signal_connect(win->btn_dashboard, "clicked", G_CALLBACK(on_dashboard_clicked), win);
    g_signal_connect(win->btn_feed, "clicked", G_CALLBACK(on_feed_clicked), win);
    g_signal_connect(win->btn_add_trade, "clicked", G_CALLBACK(on_add_trade_clicked), win);
    g_signal_connect(win->btn_add_journal, "clicked", G_CALLBACK(on_add_journal_clicked), win);
    
    // Add buttons to button box
    gtk_box_append(GTK_BOX(button_box), win->btn_dashboard);
    gtk_box_append(GTK_BOX(button_box), win->btn_feed);
    gtk_box_append(GTK_BOX(button_box), win->btn_add_trade);
    gtk_box_append(GTK_BOX(button_box), win->btn_add_journal);
    
    // Create content box
    win->content_box = gtk_box_new(GTK_ORIENTATION_VERTICAL, 10);
    
    // Add button box and content box to main box
    gtk_box_append(GTK_BOX(main_box), button_box);
    gtk_box_append(GTK_BOX(main_box), gtk_separator_new(GTK_ORIENTATION_HORIZONTAL));
    gtk_box_append(GTK_BOX(main_box), win->content_box);
    
    // Set the main box as the child of the window
    gtk_window_set_child(GTK_WINDOW(win), main_box);
    
    // Show dashboard by default
    show_dashboard_view(win);
}

static void 
journal_app_window_class_init(JournalAppWindowClass *class) {
    // No additional class initialization needed
}

// Constructors
JournalAppWindow *
journal_app_window_new(JournalApp *app) {
    return g_object_new(JOURNAL_TYPE_APP_WINDOW, 
                        "application", app, 
                        "title", "Trade Journal",
                        "default-width", 800,
                        "default-height", 600,
                        NULL);
}

void
journal_app_window_open(JournalAppWindow *win, GFile *file) {
    // Placeholder for file opening functionality
}