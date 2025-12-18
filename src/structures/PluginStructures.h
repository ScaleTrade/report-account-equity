#pragma once

#include <string>
#include <Structures.h>

struct Total {
    std::string currency;
    double equity;
    double credit;
    double floating_pl;
    double profit;
    double prevbalance;
    double balance;
    double storage;
    double commission;
    double margin;
    double margin_free;
};

struct UsdConvertedEquityRecord {
    time_t create_time;
    double equity;
    double credit;
    double profit;
    double balance;
    double margin;
    double margin_free;
};

struct BalanceChartDataPoint {
    std::string date;
    double balance = 0.0;
    double credit  = 0.0;
    double equity  = 0.0;
    double profit  = 0.0;
};