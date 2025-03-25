#include "../../include/controllers/trade_controller.h"
#include "../../include/models/database.h"

gboolean add_trade(Trade *trade) {
    // Validate trade
    GError *error = NULL;
    if (!trade_validate(trade, &error)) {
        g_warning("Trade validation failed: %s", error->message);
        g_error_free(error);
        return FALSE;
    }

    // Save to database
    return save_trade(trade);
}

GPtrArray* filter_trades(
    const char *symbol, 
    GDateTime *start_date, 
    GDateTime *end_date,
    const char *position_type
) {
    GPtrArray *all_trades = get_all_trades();
    GPtrArray *filtered_trades = g_ptr_array_new();

    for (guint i = 0; i < all_trades->len; i++) {
        Trade *trade = g_ptr_array_index(all_trades, i);
        
        // Apply filters
        gboolean match = TRUE;
        
        if (symbol && g_strcmp0(trade->symbol, symbol) != 0)
            match = FALSE;
        
        if (position_type && g_strcmp0(trade->position_type, position_type) != 0)
            match = FALSE;
        
        if (start_date && g_date_time_compare(trade->exit_date, start_date) < 0)
            match = FALSE;
        
        if (end_date && g_date_time_compare(trade->exit_date, end_date) > 0)
            match = FALSE;
        
        if (match)
            g_ptr_array_add(filtered_trades, trade);
    }

    return filtered_trades;
}