#include "Utils.hpp"

namespace utils {
    void CreateUI(const ast::Node& node,
                  rapidjson::Value& response,
                  rapidjson::Document::AllocatorType& allocator) {
        // Content
        Value node_object(kObjectType);
        to_json(node, node_object, allocator);

        Value content_array(kArrayType);
        content_array.PushBack(node_object, allocator);

        // Header
        Value header_array(kArrayType);

        {
            Value space_object(kObjectType);
            space_object.AddMember("type", "Space", allocator);

            Value children(kArrayType);

            Value text_object(kObjectType);
            text_object.AddMember("type", "#text", allocator);

            Value props(kObjectType);
            props.AddMember("value", "Account Equity report", allocator);

            text_object.AddMember("props", props, allocator);
            children.PushBack(text_object, allocator);

            space_object.AddMember("children", children, allocator);

            header_array.PushBack(space_object, allocator);
        }

        // Footer
        Value footer_array(kArrayType);

        {
            Value space_object(kObjectType);
            space_object.AddMember("type", "Space", allocator);

            Value props_space(kObjectType);
            props_space.AddMember("justifyContent", "space-between", allocator);
            space_object.AddMember("props", props_space, allocator);

            Value children(kArrayType);

            Value btn_object(kObjectType);
            btn_object.AddMember("type", "Button", allocator);

            Value btn_props_object(kObjectType);
            btn_props_object.AddMember("className", "form_action_button", allocator);
            btn_props_object.AddMember("borderType", "danger", allocator);
            btn_props_object.AddMember("buttonType", "outlined", allocator);

            btn_props_object.AddMember("onClick", "{\"action\":\"CloseModal\"}", allocator);

            btn_object.AddMember("props", btn_props_object, allocator);

            Value btn_children(kArrayType);

            Value text_object(kObjectType);
            text_object.AddMember("type", "#text", allocator);

            Value text_props_object(kObjectType);
            text_props_object.AddMember("value", "Close", allocator);

            text_object.AddMember("props", text_props_object, allocator);
            btn_children.PushBack(text_object, allocator);

            btn_object.AddMember("children", btn_children, allocator);

            children.PushBack(btn_object, allocator);

            space_object.AddMember("children", children, allocator);

            footer_array.PushBack(space_object, allocator);
        }

        // Modal
        Value model_object(kObjectType);
        model_object.AddMember("size", "xxxl", allocator);
        model_object.AddMember("headerContent", header_array, allocator);
        model_object.AddMember("footerContent", footer_array, allocator);
        model_object.AddMember("content", content_array, allocator);


        // UI
        Value ui_object(kObjectType);
        ui_object.AddMember("modal", model_object, allocator);

        response.SetObject();
        response.AddMember("ui", ui_object, allocator);
    }

    std::string FormatTimestampToString(const time_t& timestamp) {
        std::tm tm{};
        localtime_r(&timestamp, &tm);

        std::ostringstream oss;
        oss << std::put_time(&tm, "%Y.%m.%d %H:%M:%S");
        return oss.str();
    }

    double TruncateDouble(const double& value, const int& digits) {
        const double factor = std::pow(10.0, digits);
        return std::trunc(value * factor) / factor;
    }

    std::string FormatDateForChart(const time_t& time) {
        std::tm tm{};
        #ifdef _WIN32
                localtime_s(&tm, &t);
        #else
                localtime_r(&time, &tm);
        #endif
                std::ostringstream oss;
                oss << std::put_time(&tm, "%Y.%m.%d");
                return oss.str();
    }

    JSONArray CreateBalanceChartData(const std::vector<UsdConvertedEquityRecord>& equities) {
        std::map<std::string, BalanceChartDataPoint> daily_data;

        for (const auto& equity : equities) {
            std::string date = FormatDateForChart(equity.create_time);

            auto& data_point = daily_data[date];
            data_point.date = date;
            data_point.balance = equity.balance;
            data_point.credit  = equity.credit;
            data_point.equity  = equity.equity;
            data_point.profit  = equity.profit;
        }

        std::vector<BalanceChartDataPoint> data_points;
        for (const auto& [date, data_point] : daily_data) {
            data_points.push_back(data_point);
        }

        std::sort(data_points.begin(), data_points.end(),
                [](const BalanceChartDataPoint& a,const BalanceChartDataPoint& b) {
                        return a.date < b.date;
                 });

        JSONArray chart_data;
        for (const auto& data_point : data_points) {
            JSONObject point;
            point["day"]   = JSONValue(data_point.date);
            point["balance"] = JSONValue(static_cast<double>(data_point.balance));
            point["credit"] = JSONValue(static_cast<double>(data_point.credit));
            point["equity"] = JSONValue(static_cast<double>(data_point.equity));
            point["profit"] = JSONValue(static_cast<double>(data_point.profit));

            chart_data.emplace_back(point);
        }

        return chart_data;
    }
}
