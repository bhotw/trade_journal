#pragma once

#include <gtk/gtk.h>
#include "../../include/journal_appwin.h"

// Enum for filter types
typedef enum {
    FILTER_ALL,
    FILTER_LONG,
    FILTER_SHORT,
    FILTER_PROFITABLE,
    FILTER_LOSS
} TradeFilterType;

// Enum for sort types
typedef enum {
    SORT_BY_EXIT_DATE,
    SORT_BY_PROFIT,
    SORT_BY_SYMBOL
} TradeSortType;

// Change to non-static declaration
void show_feed_view(
    JournalAppWindow *win, 
    TradeFilterType filter, 
    TradeSortType sort
);