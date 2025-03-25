#pragma once

#include <glib.h>
#include "trade.h"
#include "journal_entry.h"

// Initialize database connection
gboolean initialize_database();

// Trade-related database operations
gboolean save_trade(Trade *trade);
GPtrArray* load_trades();
gboolean delete_trade(int trade_id);

// Journal entry database operations
gboolean save_journal_entry(JournalEntry *entry);
GPtrArray* load_journal_entries();