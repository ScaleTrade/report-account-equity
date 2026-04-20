#pragma once

#include <ctime>
#include <rapidjson/document.h>
#include <string>
#include <vector>

#include "Structures.h"
#include "model/ReportAccount.hpp"
#include "model/ReportCandle.hpp"
#include "model/ReportGroup.hpp"
#include "model/ReportLog.hpp"
#include "model/ReportSymbol.hpp"
#include "model/ReportTrade.hpp"

class Core;

inline int REPORT_SERVER_API = 1;

class ReportServerInterface {
public:
    ReportServerInterface(Core* st, const std::string& name);
    ~ReportServerInterface();

    static int GetApiVersion() { return REPORT_SERVER_API; }

    virtual int GetLogs(time_t from, time_t to, const std::string& type, const std::string& filter, std::vector<ReportServerLog>* logs);

    virtual int GetAccountsByGroup(const std::string& group, std::vector<ReportAccountRecord>* accounts);
    virtual int GetAccountByLogin(int login, ReportAccountRecord* account);
    virtual int GetAccountBalanceByLogin(int login, ReportMarginLevel* margin);
    virtual int GetMarginLevelByGroup(const std::string& group, std::vector<ReportMarginLevel>* margins);
    virtual int GetAccountsEquitiesByGroup(time_t from, time_t to, const std::string& group_filter, std::vector<ReportEquityRecord>* equities);
    virtual int GetAccountsEquitiesByLogin(time_t from, time_t to, int login, std::vector<ReportEquityRecord>* equities);

    virtual int GetOpenTradesByLogin(int login, std::vector<ReportTradeRecord>* trades);
    virtual int GetPendingTradesByLogin(int login, std::vector<ReportTradeRecord>* trades);
    virtual int GetOpenTradesByMagic(int magic, std::vector<ReportTradeRecord>* trades);
    virtual int GetOpenTradeByOrder(int order, ReportTradeRecord* trade);
    virtual int GetOpenTradeByGwUUID(const std::string& gw_uuid, ReportTradeRecord* trade);
    virtual int GetCloseTradeByGwUUID(const std::string& gw_uuid, ReportTradeRecord* trade);
    virtual int GetOpenTradeByGwOrder(int gw_order, ReportTradeRecord* trade);
    virtual int GetCloseTradeByGwOrder(int gw_order, ReportTradeRecord* trade);
    virtual int GetCloseTradesByLogin(int login, std::vector<ReportTradeRecord>* trades);
    virtual int GetCloseTradesByGroup(const std::string& filter_group, time_t from, time_t to, std::vector<ReportTradeRecord>* trades);
    virtual int GetPendingTradesByGroup(const std::string& filter_group, time_t from, time_t to, std::vector<ReportTradeRecord>* trades);
    virtual int GetOpenTradesByGroup(const std::string& filter_group, time_t from, time_t to, std::vector<ReportTradeRecord>* trades);
    virtual int GetAllOpenTrades(std::vector<ReportTradeRecord>* trades);
    virtual int GetTransactionsByGroup(const std::string& filter_group, time_t from, time_t to, std::vector<ReportTradeRecord>* trades);
    virtual int GetTransactionsByLogin(int login, time_t from, time_t to, std::vector<ReportTradeRecord>* trades);

    virtual int CalculateCommission(const ReportTradeRecord& trade, double* calculated_commission);
    virtual int CalculateSwap(const ReportTradeRecord& trade, double* calculated_swap);
    virtual int CalculateProfit(const ReportTradeRecord& trade, double* calculated_profit);
    virtual int CalculateMargin(const ReportTradeRecord& trade, double* calculated_margin);
    virtual int CalculateConvertRateByCurrency(const std::string& from_cur, const std::string& to_cur, int cmd, double* multiplier);

    virtual int GetSymbol(const std::string& symbol, ReportSymbolRecord* cs);
    virtual int GetGroup(const std::string& group_name, ReportGroupRecord* group);
    virtual int GetAllGroups(std::vector<ReportGroupRecord>* groups);

    virtual int GetCandles(const std::string& symbol, const std::string& frame, time_t from, time_t to, std::vector<ReportCandleRecord>* candles);

private:
    Core* St;
    std::string report_name;
};
