#include "file_storage.h"
#include <stdio.h>
#include <stdlib.h>

#define FILE_NAME "entries.txt"

void write_to_file(const char *text) {
    FILE *file = fopen(FILE_NAME, "a");
    if (file) {
        fprintf(file, "%s\n", text);
        fclose(file);
    }
}

void load_from_file(GtkTextBuffer *buffer) {
    FILE *file = fopen(FILE_NAME, "r");
    if (!file) return;

    GtkTextIter iter;
    gtk_text_buffer_get_end_iter(buffer, &iter);

    char line[256];
    while (fgets(line, sizeof(line), file)) {
        gtk_text_buffer_insert(buffer, &iter, line, -1);
    }
    fclose(file);

}