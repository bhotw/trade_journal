#ifndef STORAGE_H
#define STORAGE_H

#include <gtk/gtk.h>

void write_to_file(const char *text);
void load_from_file(GtkTextBuffer *buffer);

#endif 