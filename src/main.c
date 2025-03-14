#include <gtk/gtk.h>

#include "../include/journal_app.h"

int main (int argc, char **argv){
  return g_application_run (G_APPLICATION (journal_app_new ()), argc, argv);
}