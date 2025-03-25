#pragma once

#include <glib.h>
#include <time.h>

typedef struct {
    int id;
    char *symbol;
    GDateTime *entry_date;
    GDateTime *entry_time;
    GDateTime *exit_date;
    GDateTime *exit_time;
    
    // Trade details
    char *position_type;  // Long/Short
    double size;
    double entry_price;
    double exit_price;
    double stop_loss;
    double target;
    
    // Additional notes
    char *execution_notes;
    
    // Image paths
    GPtrArray *image_paths;
} Trade;

// Constructor
Trade* trade_new();

// Destructor
void trade_free(Trade *trade);

// Validation
gboolean trade_validate(Trade *trade, GError **error);

// Serialization
char* trade_to_json(Trade *trade);
Trade* trade_from_json(const char *json_str);