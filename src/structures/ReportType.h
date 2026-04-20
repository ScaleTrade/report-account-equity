#pragma once

enum class ReportType {
    NONE,               // report without filter
    RANGE,              // report filter with time range
    DAILY,              // report filter by one day
    ACCOUNT,            // report filter by account
    SYMBOL,             // report filter by account
    GROUP,              // report filter with group mask
    RANGE_GROUP,        // report filter one day and group mask
    DAILY_GROUP,        // report filter one day and group mask
    RANGE_ACCOUNT,      // report filter with time range and account
    DAILY_ACCOUNT,      // report filter by one day and account
    RANGE_SYMBOL,       // report filter with time range and account
    DAILY_SYMBOL,       // report filter by one day and account
    RANGE_GROUP_SYMBOL, // report filter with time range and group and symbols
    DAILY_GROUP_SYMBOL  // report filter by one day and groups and symbols
};