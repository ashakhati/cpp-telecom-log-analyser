#pragma once

#include "LogEvent.h"
#include <vector>
#include <unordered_map>

struct UEStats
{
	int total =0;
	int successful = 0;
	int failed = 0;
};

class LogAnalyzer
{
public:
    void analyze(const std::vector<LogEvent>& events);

    int totalHandovers() const;
    int successfulHandovers() const;
    int failedHandovers() const;
    void printUEStats() const;

private:
    int totalHandovers_ = 0;
    int successfulHandovers_ = 0;
    int failedHandovers_ = 0;
    std::unordered_map<int, UEStats> ueStats;
};
