#pragma once

#include <cmath>
#include <ctime>
#include <iomanip>
#include <sstream>
#include <unordered_map>
#include <unordered_set>
#include "Structures.hpp"
#include "structures/PluginStructures.hpp"
#include "ast/Ast.hpp"
#include <rapidjson/document.h>

namespace utils {
    void CreateUI(const ast::Node& node,
              rapidjson::Value& response,
              rapidjson::Document::AllocatorType& allocator);

    std::string FormatTimestampToString(const time_t& timestamp);

    double TruncateDouble(const double& value, const int& digits);
}