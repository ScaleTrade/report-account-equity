#pragma once

#include <iostream>
#include <sstream>
#include <cmath>
#include <thread>
#include <chrono>
#include <atomic>
#include <string>
#include <iomanip>
#include <unordered_map>

#include "ReportServerInterface.h"
#include "ast/Ast.hpp"
#include "rapidjson/document.h"
#include "validators/RequestValidator.h"
#include "sbxTableBuilder/SBXTableBuilder.hpp"
#include "structures/ReportStructures.h"
#include "structures/ReportType.h"
#include "structures/ValidationResult.h"
#include "utils/Utils.h"

extern "C" {
    int GetReportApiVersion();

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