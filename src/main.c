#include <gtk/gtk.h>
#include <ui.h>

void activate(GtkApplication *app, gpointer user_data) {
    GtkWidget *window;
    GtkWidget *label;  // Declare label

    // Create a new window
    window = gtk_application_window_new(app);
    gtk_window_set_title(GTK_WINDOW(window), "Journal App");
    gtk_window_set_default_size(GTK_WINDOW(window), 400, 300);

    // Create a label and add it to the window
    label = gtk_label_new("Hello, GTK!");
    
#if GTK_MAJOR_VERSION == 4
    gtk_window_set_child(GTK_WINDOW(window), label);  // For GTK 4
#else
    gtk_container_add(GTK_CONTAINER(window), label);  // For GTK 3
#endif

    // Show everything
    gtk_widget_show_all(window);
}


int main(int argc, char **argv) {
    GtkApplication *app;
    int status;

    app = gtk_application_new("com.example.journal", G_APPLICATION_DEFAULT_FLAGS);
    g_signal_connect(app, "activate", G_CALLBACK(activate_ui), NULL);

    status = g_application_run(G_APPLICATION(app), argc, argv);
    g_object_unref(app);
    
    return status;
}