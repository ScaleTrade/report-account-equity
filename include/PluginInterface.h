#pragma once

#include "Structures.h"
#include "ReportServerInterface.h"

#include <iostream>
#include <sstream>
#include <cmath>
#include <thread>
#include <chrono>
#include <atomic>
#include <string>
#include <iomanip>
#include <unordered_map>

#include "ast/Ast.hpp"
#include "rapidjson/document.h"
#include "sbxTableBuilder/SBXTableBuilder.hpp"
#include "structures/ReportStructures.h"
#include "structures/ReportType.h"
#include "utils/Utils.h"

extern "C" {
    void AboutReport(rapidjson::Value& request,
                     rapidjson::Value& response,
                     rapidjson::Document::AllocatorType& allocator,
                     ReportServerInterface* server);

    void DestroyReport();

    void CreateReport(rapidjson::Value& request,
                     rapidjson::Value& response,
                     rapidjson::Document::AllocatorType& allocator,
                     ReportServerInterface* server);
}