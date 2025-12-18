#pragma once

#include <algorithm>
#include <cmath>
#include <ctime>
#include <iomanip>
#include <sstream>
#include <unordered_map>
#include <unordered_set>
#include "Structures.h"
#include "structures/PluginStructures.h"
#include "ast/Ast.hpp"
#include <rapidjson/document.h>

using namespace ast;

namespace utils {
    void CreateUI(const ast::Node& node,
              rapidjson::Value& response,
              rapidjson::Document::AllocatorType& allocator);

    std::string FormatTimestampToString(const time_t& timestamp);

    double TruncateDouble(const double& value, const int& digits);

    std::string FormatDateForChart(const time_t& time);

    JSONArray CreateBalanceChartData(const std::vector<UsdConvertedEquityRecord>& equities);
}