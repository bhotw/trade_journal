#include <gtk/gtk.h>
#include <file_storage.h>

GtkWidget *text_view;
GtkWidget *entry;
void refresh_entries();

void save_entry(GtkWidget *widget, gpointer data) {
    const char *text = gtk_entry_get_text(GTK_ENTRY(entry));
    if (text[0] == '\0') return;

    write_to_file(text);
    gtk_entry_set_text(GTK_ENTRY(entry), ""); // Clear input
    refresh_entries();
}

void refresh_entries() {
    GtkTextBuffer *buffer = gtk_text_view_get_buffer(GTK_TEXT_VIEW(text_view));
    gtk_text_buffer_set_text(buffer, "", -1);
    load_from_file(buffer);
}

void activate_ui(GtkApplication *app, gpointer user_data) {
    GtkWidget *window;
    GtkWidget *vbox;
    GtkWidget *navbar_frame, *navbar_box;
    GtkWidget *contnet_frame;
    GtkWidget *dashboard_btn, *feed_btn, *add_trade_btn, *add_journal_btn, *username_btn;
    GtkWidget *save_button;
    GtkWidget *scroll;
    GtkWidget *content_area;

    // Create a new window
    window = gtk_application_window_new(app);
    gtk_window_set_title(GTK_WINDOW(window), "Journal App");
    gtk_window_set_default_size(GTK_WINDOW(window), 800, 600);

    // Create a vertical box to hold the widgets
    vbox = gtk_box_new(GTK_ORIENTATION_VERTICAL, 5);
    gtk_container_add(GTK_CONTAINER(window), vbox);

    // === Navbar ===
    navbar_frame = gtk_frame_new(NULL);
    gtk_frame_set_shadow_type(GTK_FRAME(navbar_frame), GTK_SHADOW_IN);  
    gtk_box_pack_start(GTK_BOX(vbox), navbar_frame, FALSE, FALSE, 0);

    navbar_box = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 10);
    gtk_container_add(GTK_CONTAINER(navbar_frame), navbar_box);

    // Create Naviattion buttons
    dashboard_btn = gtk_button_new_with_label("Dashboard");
    feed_btn = gtk_button_new_with_label("Feed");
    add_trade_btn = gtk_button_new_with_label("Add Trade");
    add_journal_btn = gtk_button_new_with_label("Add Journal");
    username_btn = gtk_button_new_with_label("Username");

    // Add buttons to the navbar
    gtk_box_pack_start(GTK_BOX(navbar_box), dashboard_btn, TRUE, TRUE, 0);
    gtk_box_pack_start(GTK_BOX(navbar_box), feed_btn, TRUE, TRUE, 0);
    gtk_box_pack_start(GTK_BOX(navbar_box), add_trade_btn, TRUE, TRUE, 0);
    gtk_box_pack_start(GTK_BOX(navbar_box), add_journal_btn, TRUE, TRUE, 0);
    gtk_box_pack_start(GTK_BOX(navbar_box), username_btn, TRUE, TRUE, 0);

    // Main Content Area
    contnet_frame = gtk_frame_new(NULL);
    gtk_frame_set_shadow_type(GTK_FRAME(contnet_frame), GTK_SHADOW_IN);
    gtk_box_pack_start(GTK_BOX(vbox), contnet_frame, TRUE, TRUE, 0);

    content_area = gtk_text_view_new();
    gtk_container_add(GTK_CONTAINER(contnet_frame), content_area);


    // Create an entry widget (for user input)
    // entry = gtk_entry_new();
    // gtk_box_pack_start(GTK_BOX(vbox), entry, FALSE, FALSE, 0);

    // Create a save button and connect the save function
    // save_button = gtk_button_new_with_label("Save Entry");
    // g_signal_connect(save_button, "clicked", G_CALLBACK(save_entry), NULL);
    // gtk_box_pack_start(GTK_BOX(vbox), save_button, FALSE, FALSE, 0);

    // Create a text view to display saved entries
    // text_view = gtk_text_view_new();
    // gtk_text_view_set_editable(GTK_TEXT_VIEW(text_view), FALSE);
    // scroll = gtk_scrolled_window_new(NULL, NULL);
    // gtk_container_add(GTK_CONTAINER(scroll), text_view);
    // gtk_box_pack_start(GTK_BOX(vbox), scroll, TRUE, TRUE, 0);

    // Refresh entries (if any)
    refresh_entries();

    // Show all widgets
    gtk_widget_show_all(window);
}
