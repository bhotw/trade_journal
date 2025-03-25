#pragma once

#include "../models/trade.h"

// Add a new trade
gboolean add_trade(Trade *trade);

// Retrieve trades
GPtrArray* get_all_trades();
GPtrArray* filter_trades(
    const char *symbol, 
    GDateTime *start_date, 
    GDateTime *end_date,
    const char *position_type
);

// Calculate trade statistics
typedef struct {
    int total_trades;
    double total_profit;
    double win_rate;
    double average_profit_per_trade;
} TradeStatistics;

TradeStatistics calculate_trade_statistics(GPtrArray *trades);